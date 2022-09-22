#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char code[100];
    char nom[100];
    int quantite;
    float prix;
    float prixTTC;
    float produit_vendu;
    int jour;
    int mois;
    int annee;

}produit;


int main()
{
    //DASHBOARD:
    int opt;
    int n;
    int z = 0;
    produit *prd = malloc(z *sizeof(produit));

    printf("\n\n\t================ Gestion de Pharmacie =================");
    printf("\n\n1.Ajouter un nouveau produit");
    printf("\n2.Ajouter plusieurs nouveaux produits");
    printf("\n3.Lister tous les produits");
    printf("\n4.Acheter produit");
    printf("\n5.Rechercher les produits par le code");
    printf("\n6.Rechercher les produits par la quantite");
    printf("\n7.Etat du stock");
    printf("\n8.Alimenter le stock");
    printf("\n9.Supprimer les produits");
    printf("\n10.Statistique de vente");
    printf("\n11.Exit");

    printf("\n\nVeuillez selectionner votre option:\t");
    scanf("%d",&opt);




void print(){
    for(int i = 0;i<z;i++){
        printf("%s\n",prd[i].code);
        printf("%s\n",prd[i].nom);
        printf("%d\n",prd[i].quantite);
        printf("%.2f\n",prd[i].prix);
        printf("%.2f\n",prd[i].prixTTC);
    }

}




//1--> ADD_PRODUCT
void ajoutPrd(){

        printf("Entrer le code du produit : ");
        scanf("%s",&prd[z].code);
        printf("Entrer le nom du produit : ");
        scanf("%s",&prd[z].nom);
        printf("Entrer la quantite du produit  : ");
        scanf("%d",&prd[z].quantite);
        printf("Entrer le prix du produit : ");
        scanf("%f",&prd[z].prix);
        prd[z].prixTTC = prd[z].prix+(prd[z].prix*15/100);
        prd[z].produit_vendu = 0;
        z++;
}




//2--> ADD_PRODUCTS
void ajoutPrds(){


           printf("\n\n\t________Ajouter les produits________");
           printf("\n\nVeuillez entrer le numero des produits :");
           scanf("%d",&n);

       for(int i=z; i<z+n; i++){
        printf("\nEntrer le code du produit : ");
        scanf("%s",&prd[i].code);
        printf("Entrer le nom du produit : ");
        scanf("%s",&prd[i].nom);
        printf("Entrer la quantite du produit  : ");
        scanf("%d",&prd[i].quantite);
        printf("Entrer le prix du produit : ");
        scanf("%f",&prd[i].prix);
        prd[i].prixTTC = prd[i].prix+(prd[i].prix*15/100);
        prd[i].produit_vendu = 0;
        }
        z=z+n;

}




//3--> SORTING ITEMS:
void lister(){
        int ch;
         produit temp;
         printf("\n\t__________Lister les produits__________");
         printf("\n\n-->Le Tries des produits se fait par:\n");
         printf("\n1.Prix (decroissant)");
         printf("\n2.Nom (croissant)");
         printf("\n\nVeuillez entrer votre choix: ");
         scanf("%d",&ch);

//BY PRICE:
        if(ch==1){
        for(int i=0; i<z;i++){
            for(int j=+i; j<z; j++){
              if(prd[i].prix<prd[j].prix){

                temp = prd[i];
                prd[i]=prd[j];
                prd[j]=temp;
              }}}
           for(int i=0; i<z; i++){
                  printf("Code du produit: %s \nNom du produit: %s \nQuantite du produit: %d \nPrix du produit: %.2fDH \nPrix TTC du produit: %.2fTTC\n\n",prd[i].code,prd[i].nom,prd[i].quantite,prd[i].prix,prd[i].prixTTC);
                  }}


//BY NAME ::: (BY BUBLLE)
         if(ch==2){
         int j=0;
         produit temps;

        do{
            for(int i=z-1; i>j; i--){
                if(strcmp(prd[i].nom,prd[i-1].nom) < 0){
                        temps= prd[i];
                          prd[i]= prd[i-1];
                          prd[i-1]=temps;
                }
            }
            j++;
        }while(j<z);
          for(int i=0; i<z; i++){
                  printf("Code du produit: %s \nNom du produit: %s \nQuantite du produit: %d \nPrix du produit: %.2fDH \nPrix TTC du produit: %.2fTTC\n\n",prd[i].code,prd[i].nom,prd[i].quantite,prd[i].prix,prd[i].prixTTC);
                  }

}}




//4--> BUY A PRODUCTS:
void acheter(){
            char code[60];
            int qM=0;

            printf("\n\t___________Acheter produit___________");
            printf("\n\nVeuillez entrer le Code du produit: ");
            scanf("%s",&code);

            for(int i=0; i<z; i++){
               if(!strcmp(prd[i].code,code)) {
                printf("La quantite que vous voulez acheter: ");
                scanf("%d",&qM);
 //(2)- LA DATE D'ACHAT :
                printf("\nLa date d'achat : ");
                scanf("%d %d %d",&prd[i].jour,&prd[i].mois,&prd[i].annee);
//moin quantite:
                prd[i].quantite=prd[i].quantite-qM;
 // (1)- ENREGISTRER LE PRIX TTC:
                prd[i].produit_vendu = prd[i].produit_vendu + prd[i].prixTTC * qM;

                //RECU:
                printf("\n\n\t::Recu::\n");
                printf("\nCode du produit : %s\n",prd[i].code);
                printf("Nom du produit : %s\n",prd[i].nom);
                printf("Quantite du produit: %d\n",qM);
                printf("Total : %.2f\n",prd[i].prixTTC *qM);
                printf("Date : %d/%d/%d",prd[i].jour,prd[i].mois,prd[i].annee);
                }}
}




//5--> SEARCH_PRODUCTS:
//BY CODE :
void rechercheCode(){
            char code[20];
            printf("\n\t_________Rechercher un produit_________");

            printf("\n\nVeuillez entrer le Code de produit: ");
            scanf("%s",&code);
            for(int i=0; i<z; i++){
                if(!strcmp(prd[i].code,code)){
                 printf("Code du produit: %s \nNom du produit: %s \nQuantite du produit: %d \nPrix du produit: %.2fDH\n",prd[i].code,prd[i].nom,prd[i].quantite,prd[i].prix);
                }
                }}



//6--> SEARCH_PRODUCTS:
//BY  QUANTITY:
void rechercheQuantite(){

            int quantite;
            printf("\n\t_________Rechercher un produit_________");

            printf("\n\nVeuillez entrer la quantite de produit: ");
            scanf("%d",&quantite);
            for(int i=0; i<z; i++){
                if(quantite==prd[i].quantite){
                  printf("Code du produit: %s \nNom du produit: %s \nQuantite du produit: %d \nPrix du produit: %.2f\n",prd[i].code,prd[i].nom,prd[i].quantite,prd[i].prix);
                  }}}




//7--> STOCK STATUS:
void etatStock(){
           int z;
           printf("\n\n\t___________Etat du stock__________");
           for(int i=0; i<z; i++){
            if(prd[i].quantite<3){
            printf("\nLe produit dont la quantite inferieure a \"3\":\n %s \nAvoir la quantite: %d",prd[i].nom,prd[i].quantite);}
           }
}




//8--> SUPPLY THE STOCK:
void  alimenterStock(){
        printf("\nenter the product code : ");
        char code[50];
        int quantity;
        scanf("%s",&code);
        for(int i = 0;i<z;i++){
            if(!strcmp(prd[i].code,code)){
                printf("\nEntrer le Code du produit : ");
                scanf("%d",&quantity);
                prd[i].quantite =  prd[i].quantite  + quantity;

            }
        }

}




//9--> SUPPRESSION:
void suppression(){
            char Scode[300];
            int temp;
            printf("\n\t___________La Suppression___________");
            printf("\n\n-->La Suppression des produits se fait par Code\n");

            printf("\nVeuillez entrer le Code du produit: ");
            scanf("%s",&Scode);

            for(int i=0; i<z; i++){
                if(!strcmp(prd[i].code, Scode)){
                  temp=i;
                    for (int i=temp; i<z; i++){
                        prd[i]=prd[i+1];
                    }
                    z--;
                    }
                }
}



//STATISTIQUE DU VENTE:
void statiqueVente(){



    int option;
    printf("\n1 - Le produit maximum a une date precise ");
    printf("\n2 - Le produit minimum a une date precise ");
    printf("\n2 - Le Total a une date precise ");
    printf("\nVotre choix : ");
    scanf("%d",&option);

    //MAX::
    int jour, mois, annee;
    float Max=0;

    if(option==1){
            printf("\nVeulliez entrer la date: ");
            scanf("%d %d %d",&jour,&mois,&annee);
        for(int i=0; i<z; i++){
            if(prd[i].jour==jour && prd[i].mois==mois && prd[i].annee==annee)
                {
                    if(Max<prd[i].produit_vendu)
                        {
                        Max=prd[i].produit_vendu;
                        }
                    }
}
printf("Produit maximum a cette date %d/%d/%d : %.2f",jour,mois,annee,Max);
}


//TOTALE:
if(option==3){
float total=0;

            int jour, mois, annee;
            printf("\nVeulliez entrer la date: ");
            scanf("%d %d %d",&jour,&mois,&annee);
        for(int i=0; i<z; i++){
            if(prd[i].jour==jour && prd[i].mois==mois && prd[i].annee==annee){
                total+=prd[i].produit_vendu;
            }
}
printf("Total: %.2f", total);
}
}






while(opt!=11){

        if(opt==1){
            ajoutPrd();
        }


        if(opt==2){
            ajoutPrds();
        }


        if(opt==3){
            lister();
        }


        if(opt==4){
                acheter();

        }


        if(opt==5){
            rechercheCode();
        }


        if(opt==6){
            rechercheQuantite();
        }


        if(opt==7){
                etatStock();
        }


        if(opt==8){
                alimenterStock();
        }


        if(opt==9){
           suppression();
        }



        if(opt==10){
                statiqueVente();
        }




        if(opt == 12){
            print();
        }







        printf("\n\n\t_______________MENU_______________");
        printf("\n\n1.Ajouter un nouveau produit");
        printf("\n2.Ajouter plusieurs nouveaux produits");
        printf("\n3.Lister tous les produits");
        printf("\n4.Acheter produit");
        printf("\n5.Rechercher les produits par le code");
        printf("\n6.Rechercher les produits par la quantite");
        printf("\n7.Etat du stock");
        printf("\n8.Alimenter le stock");
        printf("\n9.Supprimer les produits");
        printf("\n10.Statistique de vente");
        printf("\n11.Exit");

//        printf("\n12.print data");

        printf("\n\nVeuillez selectionner votre option:\t");
        scanf("%d",&opt);

        printf("\n\n");
    }

    return 0;
    }
