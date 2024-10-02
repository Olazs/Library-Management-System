#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct library{
    char title[32];
    char author[32];
    int pages;
    float price;
};

int main(){
    struct library lib[254]; //254 konyv tarolasara kepes konyvtar letrehozasa
    char author_name[32], title_of_book[32];
    int operator = 0; //Ez a "gomb" amit a felhasznalo megnyom 
// A menu letrehozasahoz majd az "operator" valtozot fogjuk alkalmazni
    while (operator != 5){

        printf("\n\n********######Udvozollek a konyvtarban!######********\n");
        printf("\n1. Konyv Hozzaadasa\n");
        printf("\n2. Konyv Lekerdezese\n");
        printf("\n3. Egy iro munkassaganak lekerdezese\n");
        printf("\n4. Konyvek szamanak lekerdezese a konyvtarbol\n");
        printf("\n5. Kilepes\n");

    }
    printf("\n\n Kerlek adj meg egyet a fentiek kozul!");
    scanf("%d", &operator);
    

    return 0;
}