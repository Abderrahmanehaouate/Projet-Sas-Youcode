#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define Max 100

/******----declaration--**/
static int nb,i,j,n=0;
static int choix ;
static int trouve=0;
int chiffre ;
int quant ;
   /******----Debut des structures --**/

typedef struct{
	char nom[30];
	float prix;
	int quantite;
	int code;
}Produit;
Produit temp;
Produit prd[10];

typedef struct{
	int year;
	int mon;
	int day;
}Date;

typedef struct{
	float prixTTC;
	Date temps ;
}buyProduct;

buyProduct BP ;

typedef struct{
	buyProduct prdBP[10];
}boughtProduct;
boughtProduct BYPR;

static int compteBP=0;

      /******----Final des structures --**/

      /***********************************/

      /******----Debut des fonctions  --**/

    //fonction qui ajouter un seul produit

void Ajouter_produit(){

	for(i=n;i<n+1;i++){

	printf("\tEntrer le nom du produit %d       :",i+1);
	scanf("%s",prd[i].nom);
    printf("\t-------------------------------------------\n");
	printf("\tEntrer le code du produit %d      :",i+1);
	scanf("%d",&prd[i].code);
	printf("\t-------------------------------------------\n");
	printf("\tEntrer le prix du produit %d      :",i+1);
	scanf("%f",&prd[i].prix);
	printf("\t-------------------------------------------\n");
	printf("\tEntrer le quantite du produit %d  :",i+1);
	scanf("%d",&prd[i].quantite);
	printf("\t-------------------------------------------\n");
	}
	n=n+1;
}

    //fonction qui ajouter plusieur produit

 void Ajouter_produits(){

    printf("\tCombien de compte tu veux faire : ");
    scanf("%d",&nb);
	for(i=n;i<n+nb;i++){
    printf("\n\n");
	printf("\tEntrer le nom du produit %d       :",i+1);
	scanf("%s",prd[i].nom);
	printf("\t-------------------------------------------\n");
	printf("\tEntrer le code du produit %d      :",i+1);
	scanf("%d",&prd[i].code);
	printf("\t-------------------------------------------\n");
	printf("\tEntrer le prix du produit %d      :",i+1);
	scanf("%f",&prd[i].prix);
	printf("\t-------------------------------------------\n");
	printf("\tEntrer le quantite du produit %d  :",i+1);
	scanf("%d",&prd[i].quantite);
	printf("\t-------------------------------------------\n");
	printf("\n\n");
	}
	printf("\tSucces d'ajoute , Tapper entrer pour revenir au Menu : ");
	n=n+nb;
}

    //fonction qui afficher le Nom et Prix et PriTTC

void afficher_produit(){
            float prixTTC;
            for(i = 0; i < n; i++){

            prixTTC=prd[i].prix +(prd[i].prix*0.15);

            printf("\tle nom du produit       : %s\n", prd[i].nom);
            printf("\t-------------------------------------------\n");
            printf("\tle prix du produit      : %.2f\n", prd[i].prix);
            printf("\t-------------------------------------------\n");
            printf("\tLe prix TTC du produit  : %.2f\n", prixTTC);
            printf("\t-------------------------------------------\n");
            printf("\n\n");
        }
}

    //sorting alphabetique

void sort_nom(){
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(strcmp(prd[i].nom,prd[j].nom)>0){

				temp=prd[i];
				prd[i]=prd[j];
				prd[j]=temp;
			}
		}
	}
}

    //sorting prix

void sort_prix(){
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(prd[i].prix<prd[j].prix){
				temp=prd[i];
				prd[i]=prd[j];
				prd[j]=temp;
			}
		}
	}

}

   //fonction qui afficher les produits dont la quantité est inférieure à 3.

void Etat_stock(){

        for( i=0 ; i<n ; i++ ){

            if(prd[i].quantite<3){

            printf("\tle nom du produit       : %s\n", prd[i].nom);
            printf("\t-------------------------------------------\n");
            printf("\tle code du produit      : %d\n", prd[i].code);
            printf("\t-------------------------------------------\n");
            printf("\tle prix  du produit     : %.2f\n",prd[i].prix);
            printf("\t-------------------------------------------\n");
            printf("\tle quantite  du produit : %d\n", prd[i].quantite);
            printf("\t-------------------------------------------\n");
        }
    }
}

   //fonction qui rechercher par code

void Recherche_code(){
    do{
		printf("Entrer le code du produit : ");
		scanf("%d",&chiffre);

	}while(chiffre<0);
	for( i=0 ; i<n ; i++){

        if(prd[i].code==chiffre){

            printf("\tle nom du produit       : %s\n", prd[i].nom);
            printf("\t-------------------------------------------\n");
            printf("\tle code du produit      : %d\n", prd[i].code);
            printf("\t-------------------------------------------\n");
            printf("\tle prix  du produit     : %.2f\n",prd[i].prix);
            printf("\t-------------------------------------------\n");
            printf("\tle quantite  du produit : %d\n", prd[i].quantite);
            printf("\t-------------------------------------------\n");
            trouve=1 ;
        }

    }
    if(trouve==0){
		printf("\nLe code n'exist pas !!. \n");
	}
}

   //fonction qui rechercher par quantite

void Recherche_quantite(){

    do{
		printf("Entrer la quantite du produit : ");
		scanf("%d",&quant);

	}while(quant<0);
	for( i=0 ; i<n ; i++){

        if(prd[i].quantite==quant){

            printf("\tle nom du produit       : %s\n", prd[i].nom);
            printf("\t-------------------------------------------\n");
            printf("\tle code du produit      : %d\n", prd[i].code);
            printf("\t-------------------------------------------\n");
            printf("\tle prix  du produit     : %.2f\n",prd[i].prix);
            printf("\t-------------------------------------------\n");
            printf("\tle quantite  du produit : %d\n", prd[i].quantite);
            printf("\t-------------------------------------------\n");
            trouve=1 ;
        }

    }
    if(trouve==0){

		printf("\nCette quantite n'exist pas !!. \n");
	}
}

   //fonction qui supprimer les produit

void DaleteProduit(){
	int code ;
	printf("\n Entrer le code du produit qui tu veux supprimer : ");
	scanf("%d",&code);
	int trouve = 0;
	for(i=0;i<n;i++){
			if(prd[i].code==code){
				for( j=i ; j<n-1 ; j++){
					prd[j]=prd[j+1];
				}
				n--;
				printf("\nSuppression effectuer ! \n");
				trouve = 1;
			    break;
			}
	}
	if (trouve == 0)
		 printf("Impossible de supprimer le produit de code %d \n",code);
}

  //fonction qui acheter des produits avec engistrer le temps de acheter

void buyingproducts(){
    time_t my_time;
    struct tm  timeinfo;
	int code , quant ;
	float prixTTC;
	int trouve =0 ;
	int pos ;
    do{
		printf("Donner le code du produit : ");
		scanf("%d",&code);
	}while(code<0);
	for(i=0;i<n;i++){
		if(prd[i].code==code){
                trouve= 1 ;
    printf("Donner la quantite du produit  que tu veux : ");
	scanf("%d",&quant);

		if(prd[i].quantite>=quant){
			int pos=i;// pour stocker la position de produit qui acheter ghadi n7tajo fi l'affichage
			prd[i].quantite -= quant;

			BP.prixTTC = (prd[i].prix * quant)+(prd[i].prix * quant*0.15) ;
            my_time = time(NULL);
			timeinfo = *localtime (&my_time);

			BP.temps.year = timeinfo.tm_year+1900;
			BP.temps.mon=timeinfo.tm_mon+1;
			BP.temps.day=timeinfo.tm_mday;
			BYPR.prdBP[compteBP] = BP;

			compteBP++;//calculer les produits deja acheter
			for(i = 0; i < compteBP; i++)
	{

		printf("prixTTC = %f\n",BYPR.prdBP[i].prixTTC);
		printf("La date d'achat:\n");
		printf("Annee est : %d\n",BYPR.prdBP[i].temps.year);
		printf("mois  est : %d\n",BYPR.prdBP[i].temps.mon);
		printf("jour est : %d\n",BYPR.prdBP[i].temps.day);

	}

		}
}
}
    if(trouve==0){
  	printf("Votre code incorrect!!!\n");
  }
}

   //fonction qui ajout les produit dans  le stock

void AlimenterStock(){
	int code , quant ;
	float prixTTC;
	int trouve =0 ;
    do{
		printf("Donner le code du produit : ");
		scanf("%d",&code);
	}while(code<0);
	for(i=0;i<n;i++){
		if(prd[i].code==code){
                trouve= 1 ;
    printf("Donner la quantite du produit  que tu veux : ");
	scanf("%d",&quant);
		int pos=i;
			prd[i].quantite += quant;
			printf("Votre commande succes\n");
      }
	}
    if(trouve==0)
		printf("Votre commande ne se trouve pas!!");
}

//fonction qui calculer le prix totale

void PrixTotal(){
    time_t my_time;
    struct tm  timeinfo;
	 float TotalPrixTTC = 0;

	 for(i=0;i<compteBP;i++){
	 	if(
		 	(BYPR.prdBP[i].temps.year == timeinfo.tm_year+1900) && (BYPR.prdBP[i].temps.mon=timeinfo.tm_mon+1) &&  (BYPR.prdBP[i].temps.day=timeinfo.tm_mday)


		 ){
	 		TotalPrixTTC=TotalPrixTTC+BYPR.prdBP[i].prixTTC;
		 }
	 }

	 printf("Le prix Total est : %f\n",TotalPrixTTC);
}

// fonction qui afficher  le prix minimum

void PrixMin(){
	 float min = BYPR.prdBP[0].prixTTC ;
	 for(i=1 ; i<compteBP ; i++){

	 	if(BYPR.prdBP[i].prixTTC < min){
	 		min =BYPR.prdBP[i].prixTTC;
		 }
	 }

	 printf("Le min prix est : %f\n",min);

}

//fonction qui afficher le prix maximum

void PrixMax(){
    float max = BYPR.prdBP[0].prixTTC;

	 for(i=1;i<compteBP;i++){

	 	if(BYPR.prdBP[i].prixTTC > max){
	 		max =BYPR.prdBP[i].prixTTC;
		 }
	 }

	 printf("Le Max prix est : %f\n",max);


}

//fonction qui afficher le moyenne

void PrixMoyenne(){
	 float TotalPrixTTC = 0;
	 float moyen;
     int sommeProduit = 0;
    time_t my_time;
    struct tm  timeinfo;

	 for(i=0;i<compteBP;i++){
	 	if(
		 	(BYPR.prdBP[i].temps.year == timeinfo.tm_year+1900) && (BYPR.prdBP[i].temps.mon=timeinfo.tm_mon+1) &&  (BYPR.prdBP[i].temps.day=timeinfo.tm_mday)
		 ){
	 		TotalPrixTTC+=BYPR.prdBP[i].prixTTC;
	 		sommeProduit++;

		 }
	 }
	 if(sommeProduit!=0){
	 	moyen=TotalPrixTTC / sommeProduit;
	 }
	 else{
	 	moyen=0;
	 }
	 printf("Le moyen prix est : %f\n",moyen);
}



       /******----Fin des foncrions   --***/

       /***********************************/

       /******----Debut Programme Principale --**/
int main()
{
    while(1){
        system("cls");
		printf("\t\t\t\t _______________________________________________\n");
		printf("\t\t\t\t| --------- Menu des choix du pharmacie --------| \n");
		printf("\t\t\t\t| 1  : Ajouter un seul medicament               | \n");
		printf("\t\t\t\t| 2  : Ajouter plusieurs des medicaments        | \n");
		printf("\t\t\t\t| 3  : Afficher les produits qui tu a ajouter   | \n");
		printf("\t\t\t\t| 4  : Afficher les produits dont quantite < 3  | \n");
		printf("\t\t\t\t| 5  : Rechercher des produits par code         | \n");
		printf("\t\t\t\t|      et quntite                               | \n");
		printf("\t\t\t\t| 6  : Acheter un produit                       | \n");
		printf("\t\t\t\t| 7  : Alimenter etat de  stock                 | \n");
		printf("\t\t\t\t| 8  : Supprimer des produits                   | \n");
		printf("\t\t\t\t| 9  : statique de vante T-M-X                  | \n");
		printf("\t\t\t\t| 0  : Quitter la base de donnes                | \n");
		printf("\t\t\t\t|_______________________________________________| \n");
		printf("\n");
	do{
		printf("\t*Donner votre choix : ");
		scanf("%d",&choix);
		printf("\n");
		if(choix<0 || choix >10)
            printf("Le choix n'est pas exist , Veuillez saisir un nombre entre 0 et 10 , ");
	}while(choix<0 || choix >10);

	switch(choix){
			case 1:{//ajout produit
			        Ajouter_produit();
			        getch();
                    }break;
			case 2:{//ajout plusieur produits
                    Ajouter_produits();
                    getch();
                    break;
			}
			case 3:{//afficher par order alphabetique et par order de prix
                printf("\t\t\t\t _______________________________________________\n");
                printf("\t\t\t\t| 1  : Afficher par order alphabethique         | \n");
                printf("\t\t\t\t| 2  : Afficher par order decroissant de prix   | \n");
        		printf("\t\t\t\t|_______________________________________________|\n");
                do{
                printf("\t*Donner votre choix : ");
                scanf("%d",&choix);
                printf("\n");
                if(choix<0 || choix >2)
                printf("Le choix n'est pas exist , Veuillez saisir un nombre entre 1 et 2 , ");
                }while(choix<0 || choix >2);

                switch(choix){
                case 1 :{
                    sort_nom();
                    afficher_produit();
                    getch();
                    break ;
                }
                case 2 :{
                    sort_prix();
                    afficher_produit();
                    getch();
                    break ;
                }
               default : break ;
                }
			}
			case 4: {//afficher etat de stock
			     Etat_stock();
                getch();
			}   break;
			case 5:{//rechercher par code et par quantite
			    printf("\t\t\t\t _______________________________________________\n");
                printf("\t\t\t\t| 1  : Rechercher par code                      | \n");
                printf("\t\t\t\t| 2  : Rechercher par quantite                  | \n");
        		printf("\t\t\t\t|_______________________________________________|\n");
                do{
                printf("\t*Donner votre choix : ");
                scanf("%d",&choix);
                printf("\n");
                if(choix<0 || choix >2)
                printf("Le choix n'est pas exist , Veuillez saisir un nombre entre 1 et 2 , ");
                }while(choix<0 || choix >2);
                switch(choix){
                case 1 :{
                    Recherche_code();
                    getch();
                    break ;
                }
                case 2 :{
                    Recherche_quantite();
                    getch();
                    break ;
        }
    }
               default : break ;
                }
			case 6:{//Acheter des produit
			    buyingproducts();
			    getch();
			    break;
			    }
			case 7:{//Alimenter de stock
			    AlimenterStock();
			    getch();
			    break;
			}
			case 8:{//supprimer les produits
			    DaleteProduit();
			    getch();
				break;
			}
			case 9:{//afficher les prix total et max min moyenne
			     do{
						printf("\t\t\t\t_________________________________________\n");
						printf("\t\t\t\t| 1  : Afficher Le Total des Prix        | \n");
						printf("\t\t\t\t| 2  : Afficher Le Moyen des Prix        | \n");
					    printf("\t\t\t\t| 3  : Afficher Le Max des Prix          | \n");
					    printf("\t\t\t\t| 4  : Afficher Le Min des Prix          | \n");
						printf("\t\t\t\t|________________________________________| \n");
					    printf("\n");
						printf("Donner votre choix:");
						scanf("%d",&choix);
					}while(choix<1 || choix>4);
					switch(choix){
							 	case 1:{
								PrixTotal();
								getch();
								break;
							 	}
						    	case 2:// PrixMoyenne();
						    	break;
						    	case 3:{
								PrixMax();
								getch();
								break;
						    	}
						    	case 4:{
								PrixMin();
								getch();
								break;
						    	}
								default:break;
					}
			}
			case 0:{//quitter le programme
                printf("\n\n----- Au Revoir -----\n\n");
                exit(0);
			}
	}
	}
    return 0;
    }
