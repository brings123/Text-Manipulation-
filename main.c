#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
//TP N.01 SFSD REALISE PAR AFRAOUCENE CHAKIB G4
int main()
{
  char nomfich[100];
    int i=1;
    char nomfich1[100];
    char nomfich2[100];
    char nomfichout[100];
    int choice=1;
    color(15,0);
menu:       printf("REALISE PAR: AFRAOUCENE CHAKIB GRP4");
    printf("\n\n\n******************************MENU DES FONCTIONS:*****************************\n\n\n");
    printf("*******************1.AFFICHAGE DE CONTENU D'UN FICHIER TEXTE******************\n\n");
    printf("*******************2.CONCATENER DEUX FICHIERS TEXTE         ******************\n\n");
    printf("*******************3.NOMBRE D'OCCURENCE D'UN MOT            ******************\n                     DANS UN FICHIER TEXT\n\n");
    printf("*******************4.NOMBRE DE LIGNES D'UN FICHIER TEXTE    ******************\n\n");
    printf("*******************5.CRYPTAGE/DECRYPTAGE D'UN FICHEIER TEXTE******************\n\n");
    printf("*******************6.EXERCICES 6 DES TEMPERATURES           ******************\n\n");
    printf("*******************7.VERIFIE DEUX FICHIERS SI SONT IDENTIQUE******************\n\n");
    printf("*******************0.QUITTER                                ******************\n\n");
    color(12,0);
    printf("NOTE IMPORTANTE: IL EXISTE 3 FICHIER TEXTE: text.txt / text1.txt / text2.txt / textout.txt\n\n");
    color(15,0);
    printf("DONNER VOTRE CHOIX:  ");
    int choice1;
    scanf("%d",&choice);
    system("cls");
    if (choice==1)//SI IL A CHOISIT 1
    {
        color(12,0);
        printf("NOTE IMPORTANTE: IL EXISTE 3 FICHIER TEXTE: text.txt / text1.txt / text2.txt / textout.txt\n\n");
        color(15,0);
        choice1=1;
        printf("DONNER LE NOM DU FICHIER QUE TU VEUT AFFICHER SONT CONTENU:");
        scanf("%s",nomfich);
        while(verfich(nomfich)==0&&choice1==1)//tanque le fichier n'existe pas et il veut ecrire un autre fichier
        {
            printf("\nLE FICHIER N'EXISTE PAS VOULEZ VOUS RESSAYER?(1=OUI/0=NON): \n");
            scanf("%d",&choice1);
            if(choice1==1)//si il veut donner un autre fichier
            {
                printf("\nDONNER UN AUTRE NOM AU FICHIER: ");
                scanf("%s",nomfich);
            }
        }
        if(choice1==1)//si il a voulu afficher le fichier
        {
            printf("\n\nLE CONTENU DU FICHIER EST:\n\n");
            affichfich(nomfich);
        }//sinon on sort du fichier
        printf("\nENTRER N'IMPORTE QU'ELLE NUMERO POUR RETOURNER AU MENU: ");
        int a;
        scanf("%d",&a);
        system("cls");
        goto menu;

    }
    else if(choice==2)
    {
        color(12,0);
        printf("NOTE IMPORTANTE: IL EXISTE 3 FICHIER TEXTE: text.txt / text1.txt / text2.txt / textout.txt\n\n");
        color(15,0);
        printf("DONNER LE NOM DU FICHIER1:");
        scanf("%s",nomfich1);
        printf("\nDONNER LE NOM DU FICHIER2:");
        scanf("%s",nomfich2);
        printf("\nDONNER LE NOM DU FICHIER OUT:");
        scanf("%s",nomfichout);
        if(verfich(nomfich1)==1&&verfich(nomfich2)==1&&verfich(nomfichout)==1)//si le fichier existe
        {
            concatene(nomfich1,nomfich2,nomfichout);
            printf("\nCONCATENATION AVEC SUCCEES!\n");
            printf("\nVEUT TU AFFICHER LE RESULTAT?(1=OUI/0=NON): \n");
            scanf("%d",&choice1);
            if(choice1==1)
            {
                printf("LE CONTENUE DU RESULTAT EST:\n");
                affichfich(nomfichout);
            }
        }
        else
        {
            printf("\nUN OU TOUS DE SES FICHIER N'EXISTE PAS\n\n");
        }
        printf("\nENTRER N'IMPORTE QU'ELLE NUMERO POUR RETOURNER AU MENU: ");
        int a;
        scanf("%d",&a);
        system("cls");
        goto menu;
    }
    else if(choice==3)
    {
        color(12,0);
        printf("NOTE IMPORTANTE: IL EXISTE 3 FICHIER TEXTE: text.txt / text1.txt / text2.txt / textout.txt\n\n");
        color(15,0);
        char mot[100];
        printf("DONNER LE NOM DU FICHIER: ");
        scanf("%s",nomfich);
    if(verfich(nomfich)==1)
    {
        printf("\n");
        printf("\nDONNER LE MOT: ");
        scanf("%s",mot);
        printf("\nLE NOMBRE D'OCCURENCE DU MOT '%s' DANS LE FICHIER '%s' EST: %d \n",mot,nomfich,nbroccfich(nomfich,mot));
    }
    else
    {
        printf("LE FICHIER N'EXISTE PAS");
    }
        printf("\nENTRER N'IMPORTE QU'ELLE NUMERO POUR RETOURNER AU MENU: ");
        int a;
        scanf("%d",&a);
        system("cls");
        goto menu;
    }
    else if(choice==4)
    {
        color(12,0);
        printf("NOTE IMPORTANTE: IL EXISTE 3 FICHIER TEXTE: text.txt / text1.txt / text2.txt / textout.txt\n\n");
        color(15,0);
        printf("DONNER LE NOM DU FICHIER: ");
        scanf("%s",nomfich);
        if(verfich(nomfich)==1)
        {
            printf("LE NOMBRE DE LIGNE DANS LE FICHIER EST: %d ",nbrlignefich(nomfich));
        }
        else
        {
            printf("FICHIER N'EXISTE PAS");
        }
        printf("\nENTRER N'IMPORTE QU'ELLE NUMERO POUR RETOURNER AU MENU: ");
        int a;
        scanf("%d",&a);
        system("cls");
        goto menu;
    }
    else if (choice==5)
    {
        color(15,0);
        printf("VEUILLER ECRIRE LE MESSAGE QUE TU VEUT CRYPTER DANS LE FICHIER 'a_crypter.txt'\n");
        int i;
        char cle[100];
        for(i=0;i<20;i++)
        {
            Sleep(600);
            printf(".");
        }
        printf("\nVEUILLEZ ENTRER LA CLE SECRETE...\n");
        scanf("%s",cle);
        cryptage(cle,"a_crypter.txt","crypted.txt");
        printf("\nLE MESSAGE CRYPTE\n\n");
        printf("---------------\n");
        affichfich("crypted.txt");
        printf("\n---------------\n");
        printf("\nVOUS TROUVEZ TON MESSAGE CRYPTE DANS LE FICHIER 'crypted.txt'... \n");
        printf("\nVOULEZ VOUS LE DECRYPTER?(1=oui/0=non)\n");
        scanf("%d",&i);
        if(i==1)
        {
            Decryptage(cle,"crypted.txt","fichierout.txt");
            printf("\nVOUS TROUVEZ TON MESSAGE DECRYPTE DANS LE FICHIER 'fichierout.txt'\n");
            printf("\nVOULEZ VOUS AFFICHER LE MESSAGE DECRYPTE?(1=oui/0=non)...\n");
            int answer;//reponse de la question precedente
            scanf("%d",&answer);
            if(answer==1)
            {
                printf("\nLE CONTENU DE TON MESSAGE DECRYPTE EST:\n");
                printf("---------------\n");
                affichfich("fichierout.txt");//afficher le message decrypté
                printf("\n---------------\n");
            }

        }
        printf("\nENTRER N'IMPORTE QU'ELLE NUMERO POUR RETOURNER AU MENU: ");
        int a;
        scanf("%d",&a);
        system("cls");
        goto menu;
    }
    else if(choice==6)
    {

        color(15,0);
        printf("\nVEUILLEZ REMPLIR LE FICHIER 'temperature.bin'\n");
        printf("DONNER LE NOMBRE D'ENREGISTREMENT QUE TU VEUT METTRE DANS LE FICHIER: ");
        int i;
        scanf("%d",&i);
        RemplirFile(i,"temperature.bin");
        printf("\n\n1-SUPPRIMME UNE VILLE DE FICHIER\n\n");
        printf("\nDONNER LA VILLE QUE TU VEUT SUPPRIMER: \n");
        char ville3[100];
        scanf("%s",ville3);
        suppression(ville3);
        printf("\nSUPPRESSION AVEC SUCCEE...");
        printf("\n-------------RESULTAT:-------------\n");
        affichage("temperature.bin");
        printf("DONNER LE NOM DE LA VILLE QUE TU VEUT CALCULER SA TEMPERATURE MAX: ");
        char ville[100];
        scanf("%s",ville);
        int trouv=0;
        MaxTemp(ville,&trouv);
        if(trouv==0)
        {
            printf("\n\nLA VILLE N'EXISTE PAS\n\n");
        }
        else
        {
            printf("\nLA TEMPERATURE MAXIMALE DE LA VILLE '%s' EST %d\n",ville,MaxTemp(ville,&trouv));
        }
            printf("\nDONNER LE NOM DE LA VILLE QUE TU VEUT CALCULER SA TEMPERATURE MIN\n ");
        scanf("%s",ville);
        MinTemp(ville,&trouv);
        if(trouv==0)
        {
            printf("\n\nLA VILLE N'EXISTE PAS\n\n");
        }
        else
        {
            printf("\n\nLA TEMPERATURE MINIMALE DE LA VILLE '%s' EST %d\n\n",ville,MinTemp(ville,&trouv));
        }
           printf("\n\nDONNER LE NOM DE LA VILLE QUE TU VEUT CALCULER SA TEMPERATURE MOYENNE: \n\n");
        scanf("%s",ville);
        MoyTemp(ville,&trouv);
        if(trouv==0)
        {
            printf("\n\nLA VILLE N'EXISTE PAS\n\n");
        }
        else
        {
            printf("\n\nLA TEMPERATURE MOYENNE DE LA VILLE '%s' EST %f\n\n",ville,MoyTemp(ville,&trouv));
        }
        printf("*****************************************************");
        printf("\n2-AJOUTER UN ENREGISTREMENT EN FIN DU FICHIER\n\n");
        printf("DONNER LE NOM DE LA VILLE QUE TU VEUT AJOUTER: ");
        scanf("%s",ville);
        char date[100];
        printf("\n\nDONNER LA TEMPERATURE DE CETTE VILLE: ");
        scanf("%d",&i);
        printf("\n\nDONNER LA DATE DE CETTER VILLE (jj/mm/dddd): ");
        scanf("%s",date);
        ajoutenreg(ville,date,i,"temperature.bin");
        printf("ENREGISTREMENT AJOUTEE AVEC SUCCEE...\n\n");
        printf("\n********************************\n");
        printf("3.MODIFIER UNE TEMPERATURE D'UNE VILLE..\n\n");
        printf("\nVOICI LE CONTENU DE FICHIER: \n");
        affichage("temperature.bin");
        printf("\nDONNER LE NOM DE LA VILLE QUE TU VEUT MODIFIER SA TEMPERATURE : \n");
        scanf("%s",ville);
        printf("\nDONNER LA DATE DE LA VILLE QUE TU VEUT MODIFIER SA TEMPERATURE\n\n");
        scanf("%s",date);
        printf("DONNER LA NOUVELLE TEMPERATURE: ");
        int temp;
        scanf("%d",&temp);
        modiffich(ville,date,temp,"temperature.bin");
        printf("\n-------------RESULTAT:-------------\n");
        affichage("temperature.bin");
        printf("\nENTRER N'IMPORTE QU'ELLE NUMERO POUR RETOURNER AU MENU: ");
        int a;
        scanf("%d",&a);
        system("cls");
        goto menu;

    }
    else if(choice==7)
    {
        color(12,0);
        printf("NOTE IMPORTANTE: IL EXISTE 3 FICHIER TEXTE: text.txt / text1.txt / text2.txt / textout.txt\n\n");
        color(15,0);
        printf("DONNER LE NOM DU FICHIER1:");
        scanf("%s",nomfich1);
        printf("\nDONNER LE NOM DU FICHIER2:");
        scanf("%s",nomfich2);
        if(verfich(nomfich1)==1&&verfich(nomfich2)==1)
        {
            if(identique(nomfich1,nomfich2))
            {
                printf("\nLES DEUX FICHIERS SONT IDENTIQUE ...\n");
            }
            else
            {
                printf("\nLES DEUX FICHIERS NE SONT PAS IDENTIQUE ...\n");
            }

        }
        else
        {
            printf("\nAU MOINS UN DES FICHIERS N'EXISTE PAS...\n");
        }
        printf("ENTRER N'IMPORTE QU'ELLE NUMERO POUR RETOURNER AU MENU: \n");
        int a;
        scanf("%d",&a);
        system("cls");
        goto menu;
    }
    else if(choice==0)
    {
        printf("\n\nMERCI D'AVOIR UTILISER NOTRE APPLICATION :) \n\nAPPUYEZ SUR N'IMPORTE QUELLE TOUCHE POUR QUITTER!\n\n");
    }
    else
    {
        printf("\nCE CHOIX N'EXISTE PAS DANS LE MENU...\n\n");
        printf("ENTRER N'IMPORTE QU'ELLE NUMERO POUR RETOURNER AU MENU: \n");
        int a;
        scanf("%d",&a);
        system("cls");
        goto menu;

    }

}

