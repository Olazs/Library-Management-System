#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h> // Ha nemtalalja akkor VS-ben: Project Properties -> Configuration Properties -> C/C++ -> General -> Additional Include Directories és itt hozzaadni

struct library {
    char title[32];
    char author[32];
    int pages;
    float price;
};

void finish_with_error(MYSQL *con) {
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
}

int main() {
    MYSQL *con = mysql_init(NULL);

    if (con == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        exit(1);
    }

    if (mysql_real_connect(con, "localhost", "root", "password", "konyvtar", 0, NULL, 0) == NULL) {
        finish_with_error(con);
    }

    struct library lib;
    char author_name[32];
    int operator = 0;

    while (operator != 5) {
        printf("\n\n********###### Udvozollek a konyvtarban! ######********\n");
        printf("\n1. Konyv Hozzaadasa\n");
        printf("\n2. Konyvek listazasa\n");
        printf("\n3. Egy iro munkassaganak lekerdezese\n");
        printf("\n4. Konyvek szamanak lekerdezese a konyvtarbol\n");
        printf("\n5. Kilepes\n");

        printf("\n\n Kerlek adj meg egyet a fentiek kozul! ");
        scanf("%d", &operator);

        switch (operator) {
            case 1:
                printf("Add meg a konyv nevet!: ");
                scanf("%s", lib.title);
                printf("Add meg a szerzo nevet!: ");
                scanf("%s", lib.author);
                printf("Add meg a konyv oldalainak a szamat!: ");
                scanf("%d", &lib.pages);
                printf("Add meg a konyv arat!: ");
                scanf("%f", &lib.price);

                char query[256];
                snprintf(query, sizeof(query), "INSERT INTO konyvek(title, author, pages, price) VALUES('%s', '%s', %d, %f)", lib.title, lib.author, lib.pages, lib.price);

                if (mysql_query(con, query)) {
                    finish_with_error(con);
                }
                break;

            case 2:
                if (mysql_query(con, "SELECT * FROM konyvek")) {
                    finish_with_error(con);
                }

                MYSQL_RES *result = mysql_store_result(con);

                if (result == NULL) {
                    finish_with_error(con);
                }

                int num_fields = mysql_num_fields(result);
                MYSQL_ROW row;

                printf("\nAz alabbi konyvek talalhatoak a konyvtarban: \n");
                while ((row = mysql_fetch_row(result))) {
                    for (int i = 0; i < num_fields; i++) {
                        printf("%s ", row[i] ? row[i] : "NULL");
                    }
                    printf("\n");
                }

                mysql_free_result(result);
                break;

            case 3:
                printf("Add meg a szerzo nevet!: ");
                scanf("%s", author_name);

                snprintf(query, sizeof(query), "SELECT * FROM konyvek WHERE author='%s'", author_name);

                if (mysql_query(con, query)) {
                    finish_with_error(con);
                }

                result = mysql_store_result(con);

                if (result == NULL) {
                    finish_with_error(con);
                }

                num_fields = mysql_num_fields(result);

                while ((row = mysql_fetch_row(result))) {
                    for (int i = 0; i < num_fields; i++) {
                        printf("%s ", row[i] ? row[i] : "NULL");
                    }
                    printf("\n");
                }

                mysql_free_result(result);
                break;

            case 4:
                if (mysql_query(con, "SELECT COUNT(*) FROM konyvek")) {
                    finish_with_error(con);
                }

                result = mysql_store_result(con);

                if (result == NULL) {
                    finish_with_error(con);
                }

                row = mysql_fetch_row(result);
                printf("\n Konyvek szama a konyvtarban: %s\n", row[0]);

                mysql_free_result(result);
                break;

            case 5:
                mysql_close(con);
                exit(0);
        }
    }

    mysql_close(con);
    return 0;
}
