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
    int operator, i, count;
    operator=i=count=0;
// A menu letrehozasahoz majd az "operator" valtozot fogjuk alkalmazni
    while (operator != 5){

        printf("\n\n********######Udvozollek a konyvtarban!######********\n");
        printf("\n1. Konyv Hozzaadasa\n");
        printf("\n2. Konyvek listazasa\n");
        printf("\n3. Egy iro munkassaganak lekerdezese\n");
        printf("\n4. Konyvek szamanak lekerdezese a konyvtarbol\n");
        printf("\n5. Kilepes\n");

    
    printf("\n\n Kerlek adj meg egyet a fentiek kozul!");
    scanf("%d", &operator);
    
    switch (operator) //Menu kezelo
    {
    case 1:
    	printf("Add meg a konyv nevet!: ");
    	scanf("%s", lib[i].title);
    	printf("Add meg a szerzo nevet!: ");
    	scanf("%s", lib[i].author);
    	printf("Add meg a konyv oldalainak a szamat!: ");
    	scanf("%d", &lib[i].pages);
    	printf("Add meg a konyv arat!: ");
    	scanf("%2f", &lib[i].price);
    	i++;
    	count++;
    break;
        
    case 2:
    	printf("\nAz alabbi konyvek talalhatoak a konyvtarban: \n");
    	for(i=0; i<count; i++){ //SizeOf?/Count? 
    		printf("Konyvcim: %s", lib[i].title);
    		printf("\tSzerzo: %s", lib[i].author);
    		printf("\tOldalszam: %d", lib[i].pages);
    		printf("\tAr: %f", lib[i].price);
    		printf("\n");
		}
	break;
	
	case 3: 
		printf("Add meg a szerzo nevet!: ");
		scanf("%s", author_name);
		for(i=0; i<count; i++){ //SizeOf?/Count?
			if (strcmp(author_name, lib[i].author)==0){
				printf("%s %s %d %f", lib[i].title, lib[i].author, lib[i].pages, lib[i].price);
			}
		}
	break;
	
	case 4: 
		printf("\n Konyvek szama a konyvtarban: %d", count); //SizeOf?/Count? 
	break;
	
	case 5:
		exit(0);
    }
}

    return 0;
}