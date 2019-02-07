/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||||||||||||||||||||||||||||||||||||||||||||||||||||||||TP N.01 SFSD||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "functions.h"
/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||||||||||||||||||||||||||||||||||||||||||||||||||||EXERCICE 01 : SERIE1||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
/*MODULE QUI AFFICHE LE CONTENU D'UN FICHIER TEXT*/
void affichfich(char nomfich[100])
{
    char chaine[100]="";
    FILE* fichier=NULL;
    fichier=fopen(nomfich,"r");
    rewind(fichier);
    if(fichier!=NULL)
    {
        while(fgets(chaine,100,fichier)!=NULL)
        {
            printf("%s",chaine);
        }
        fclose(fichier);

    }
   else
    {
        printf("ECHEC D'OUVERTURE DE FICHIER");
    }
rewind(fichier);
}
/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||||||||||||||||||||||||||||||||||||||||||||||||||||EXERCICE 02 : SERIE1||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
/*MODULE QUI CONCATENE LE CONTENU DE DEUX FICHIER TEXT*/
void concatene(char fich1[100],char fich2[100],char fichout[100])
/*il fait la concatenation dans fichout*/
{
    char chaine1[100]="";
    char chaine2[100]="";
    FILE* fichier1=NULL;
    FILE* fichier2=NULL;
    FILE* fichierout=NULL;
    fichier1=fopen(fich1,"r");
    fichier2=fopen(fich2,"r");
    fichierout=fopen(fichout,"w");
    if((fichier1!=NULL)&&(fichier2!=NULL)&(fichierout!=NULL))
    {
        rewind(fichier1); rewind(fichier2); rewind(fichierout);
        while(fgets(chaine1,100,fichier1)!=NULL)
        {
            fprintf(fichierout,"%s",chaine1);
        }
        fprintf(fichierout,"\n---------------\n");
        while(fgets(chaine2,100,fichier2)!=NULL)
        {
            fprintf(fichierout,"%s",chaine2);
        }
        rewind(fichier1); rewind(fichier2); rewind(fichierout);
        fclose(fichier1);
        fclose(fichier2);
        fclose(fichierout);
    }
    else
    {
        printf("ECHEC D'OUVERTURE DE FICHIER");
    }
}
/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||||||||||||||||||||||||||||||||||||||||||||||||||||EXERCICE 03 : SERIE1||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
/*MODULE QUI CALCUL LE NOMBRE D'OCCURENCE D'UN MOT DONNEE DANS UN FICHIER*/
int nbroccfich(char nomfich[100],char mot[100])
{
    char chaine[1000];
    char* token;
    char* ver=NULL;
    int cmp=0;
    int i;
    FILE* fichier=NULL;
    fichier=fopen(nomfich,"r");
    if(fichier!=NULL)
    {
        rewind(fichier);
        ver=fgets(chaine,1000,fichier);
        while(ver!=NULL)
        {
            token=strtok(chaine," .\n");
            while(token!=NULL)
            {
                if(strcmp(mot,token)==0)
                {
                    printf("%s\n",token);
                    cmp++;
                }
                token=strtok(NULL," .\n");
            }
            ver=fgets(chaine,1000,fichier);
        }
        rewind(fichier);
        fclose(fichier);
        return cmp;
    }
    else
    {
        printf("\nECHEC D'OUVERTURE DU FICHIER\n");
    }
}
/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||||||||||||||||||||||||||||||||||||||||||||||||||||EXERCICE 04 : SERIE1||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
int nbrlignefich(char nomfich[100])
/*CALCUL LE NOMBRE DE LIGNE DANS UN FICHEIR*/
{
    char chaine[300]="";
    int cmp=0;
    FILE* fichier=NULL;
    fichier=fopen(nomfich,"r");
    if(fichier!=NULL)
    {
        rewind(fichier);
    while(fgets(chaine,260,fichier)!=NULL)
        {
            cmp++;
        }
        rewind(fichier);
        fclose(fichier);
    }
    return cmp;
}
/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||||||||||||||||||||||||||||||||||||||||||||||||||||EXERCICE 05 : SERIE1||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
void cryptage(char chaine[100],char nomfich1[100],char nomfich2[100])
/*MODULE QUI CRYPTE UN FICHIER AVEC UNE CLE*/
{
    char cara=0;
    int i,j=0;
    FILE* fichierin=NULL;
    FILE* fichierout=NULL;
    fichierin=fopen(nomfich1,"r");
    fichierout=fopen(nomfich2,"w");
    if(fichierin!=NULL&&fichierout!=NULL)
    {
    rewind(fichierin);
    j=strlen(chaine);
    cara=fgetc(fichierin);
    while(cara!=EOF)
    {
        for(i=0;i<j;i++)
        {
            if(cara!=EOF)
            {
            cara=cara - chaine[i] ;
            fprintf(fichierout,"%c",cara);
            cara=fgetc(fichierin);
        }
        }
        i=0;
    }
    printf("YOUR FILE HAS BEEN CRYPTED...");
    }
    else
    {
        printf("ECHEC D'OUVERTURE DU FICHIER...");
    }
    rewind(fichierin);
    rewind(fichierout);
    fclose(fichierin);
    fclose(fichierout);
}
void Decryptage(char chaine[100],char nomfich1[100],char nomfich2[100])
/*MODULE QUI DECRYPTE UN FICHIER SELON UNE CLE*/
{
    char cara=0;
    int i,j=0;
    FILE* fichierin=NULL;
    FILE* fichierout=NULL;
    fichierin=fopen(nomfich1,"r");
    fichierout=fopen(nomfich2,"w");
    if(fichierin!=NULL&&fichierout!=NULL)
    {
    rewind(fichierin);
    rewind(fichierout);
    j=strlen(chaine);
    cara=fgetc(fichierin);
    while(cara!=EOF)
    {
        for(i=0;i<j;i++)
        {
            if(cara!=EOF)
            {
                cara=cara + chaine[i] ;
                fprintf(fichierout,"%c",cara);
                cara=fgetc(fichierin);
            }
        }
    }
    printf("\nYOUR FILE HAS BEEN DECRYPTED...\n");
    }
    else
    {
        printf("ECHEC D'OUVERTURE DU FICHIER...");
    }
    rewind(fichierin);
    rewind(fichierout);
    fclose(fichierin);
    fclose(fichierout);
}
/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||||||||||||||||||||||||||||||||||||||||||||||||||||EXERCICE 06 : SERIE1||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
/*MODULE QUI CALCUL MAXIMUM DE TEMPERATURE D'UNE VILLE DONNER*/
int MaxTemp(char ville1[100],int *trouv)
{
    FILE* fichier=NULL;
    fichier=fopen("temperature.bin","rb+");
    if(fichier!=NULL)
    {
    Tville p;
    int maximum=0;
    int cpt=0;
while(fread(&p,sizeof(Tville),1,fichier)!=NULL)
{
    if(strcmp(ville1,p.ville)==0)
    {

        if(cpt==0)
        {
            maximum=p.temp;
        }
        if(p.temp>maximum)
        {
            maximum=p.temp;
        }
        cpt=1;

    }
}
*trouv=cpt;
return maximum;
    }
    else
    {
        printf("ECHEC DE L'OUVERTURE DU FICHIER...");
    }
    rewind(fichier);
    fclose(fichier);
}
/*MODULE QUI REMPLIT LE FICHIER PAR LES VILLES ET LEUR TEMPERATURE*/
void RemplirFile(int elements,char nomfich[100])
{
    int i;
    FILE* fichier=NULL;
    Tville v;
    fichier=fopen(nomfich,"wb");
    if (fichier!=NULL)
    {
    for(i=1;i<=elements;i++)
    {
        printf("\nDonner La Ville %d:  ",i);
        scanf("%s",v.ville);
        printf("\nDonner sa date (jj/mm/aaaa): ");
        scanf("%s",v.date);
        printf("\nDonner sa temperature: ");
        scanf("%d",&v.temp);
        fwrite(&v,sizeof(Tville),1,fichier);
    }
    }
    else
    {
        printf("ECHEC D'OUVERTURE DE FICHIER");
    }
    fclose(fichier);
}
/*MODULE QUI CALCUL LA TEMPERATURE MINIMAL D'UNE VILLE DONNER*/
int MinTemp(char ville1[100],int *trouv)
{
    FILE* fichier=NULL;
    fichier=fopen("temperature.bin","rb+");
if(fichier!=NULL)
    {
        rewind(fichier);
    Tville p;
    int minimum=0;
    int cpt=0;
while(fread(&p,sizeof(Tville),1,fichier)!=NULL)
{
    if(strcmp(ville1,p.ville)==0)
    {

        if(cpt==0)
        {
            minimum=p.temp;
        }
            if(p.temp<minimum)
            {
                minimum=p.temp;
            }
        cpt++;

}
}
*trouv=cpt;
return minimum;
    }
    else
    {
       printf("ECHEC DU L'OUVERTURE DE FICHIER");
    }
    rewind(fichier);
    fclose(fichier);
}
/*MODULE QUI CALCUL LA TEMPERATURE MOYENNE D'UNE VILLE DONNEE*/
float MoyTemp(char ville1[100],int *trouv)
{
    FILE* fichier=NULL;
    fichier=fopen("temperature.bin","rb+");
    Tville p;
    int moyenne=0;
    int cpt=0;
    if(fichier!=NULL)
    {
        rewind(fichier);
while(fread(&p,sizeof(Tville),1,fichier)!=NULL)
{
    if(strcmp(ville1,p.ville)==0)
    {

        moyenne=moyenne+p.temp;
        cpt++;
    }
}
*trouv=cpt;
return (float)moyenne/cpt ;
}
else
{
    printf("\nECHEC DE L'OUVERTURE DE FICHIER\n");
}
rewind(fichier);
fclose(fichier);
}
void modiffich(char ville[100],char date[100],int temp,char nomfich[100])
{
    /*MODULE QUI MODIFIE UNE TEMPERATURE D'UNE VILLE A UNE DATE DONNEE */
    FILE* fichier=NULL;
    fichier=fopen(nomfich,"rb+");
    if(fichier!=NULL)
    {
    rewind(fichier);
    char ville1[100];
    char date1[100];
    int i;
    Tville p;
    int trouv=0;
    int moy=0;
    int cpt=0;
    while(trouv==0&&fread(&p,sizeof(Tville),1,fichier)!=NULL)
    {

        if(strcmp(p.ville,ville)==0&&strcmp(p.date,date)==0)
        {
            trouv=1;
        }

    }
    if(trouv==1)
    {
        fseek(fichier,-sizeof(Tville),SEEK_CUR);
        p.temp=temp;
        fwrite(&p,sizeof(Tville),1,fichier);
    }
    else
    {
        printf("\nLA VILLE N'EXISTE PAS\n");
    }
}
else
{
    printf("ECHEC DE L'OUVERTURE DU FICHIER");
}
rewind(fichier);
fclose(fichier);
}
void ajoutenreg(char ville[100],char date[100],int temp,char nomfich[100])
{
    /*MODULE QUI AJOUTE UN ENREGISTREMENT EN FIN D'UN FICHIER BINAIRE*/
    FILE* fichier=NULL;
    fichier=fopen(nomfich,"ab");
    if(fichier!=NULL)
    {
        fclose(fichier);
        if(existe(ville,date,nomfich)==0)
        {
        fichier=fopen(nomfich,"ab");
        Tville v;
        strcpy(v.ville,ville);
        strcpy(v.date,date);
        v.temp=temp;
        fwrite(&v,sizeof(Tville),1,fichier);
        }
        else
        {
            printf("\nLA VILLE ET LA DATE EXISTE DEJA DANS LE FICHIER...\n");
        }
    }
    else
    {
        printf("ECHEC D'OUVERTURE DU FICHIER...");
    }
    rewind(fichier);
    fclose(fichier);

}

void suppression(char ville[100])
/*SUPPRESION PHISIQUE D'UNE VILLE*/
{
    FILE* fichier=NULL;
    fichier=fopen("temperature.bin","rb");
    FILE* nfichier=NULL;
    nfichier=fopen("n","wb");
    rewind(fichier);
    Tville v;
 while(fread(&v,sizeof(v),1,fichier)!=NULL)
 {
     if(strcmp(v.ville,ville)!=0)
     {
          fwrite(&v,sizeof(v),1,nfichier);
     }
 }
 fclose(fichier);
 fclose(nfichier);
 remove("temperature.bin");
 rename("n","temperature.bin");
}
/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||||||||||||||||||||||||||||||||||||||||||||||||||||EXERCICE 07 : SERIE1||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
int identique(char nomfich1[100],char nomfich2[100])
/*VERIFIE SI DEUX FICHIERS SONT IDENTIQUE*/
{
    FILE* fichier1=NULL;
    int idem=1;
    FILE* fichier2=NULL;
    fichier1=fopen(nomfich1,"r");
    fichier2=fopen(nomfich2,"r");
    rewind(fichier1);
    rewind(fichier2);
    if(fichier1!=NULL&&fichier2!=NULL)
    {
        char cara1;
        char cara2;
        cara1=fgetc(fichier1);
        cara2=fgetc(fichier2);
        while(cara1!=EOF&&cara2!=EOF&&idem==1)
        {
            if(cara1!=cara2)
            {
                idem=0;
            }
            cara1=fgetc(fichier1);
            cara2=fgetc(fichier2);
        }
        if(idem==1)
        {
            if(cara1!=EOF||cara2!=EOF)//cas de deux fichier identique dans les parties commmun mais un superieur a l'autre ou le contraire
            {
                idem=0;
            }
        }
    }
    else
    {
        printf("ECHEC D'OUVERTURE DU FICHIER");
    }
    rewind(fichier1);
    rewind(fichier2);
    fclose(fichier1);
    fclose(fichier2);
    return idem;
}
/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||||||||||||||||||||||||||||||||||||||||||||||||||||||MODULES DE PLUS:||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
int existe(char ville[100],char date[100],char nomfich[100])
/*VERIFIE SI UNE VILLE A UNE DATE EXISTE DANS LE FICHIER*/
{
    int boolean=0;
    FILE* fichier=NULL;
    fichier=fopen(nomfich,"rb");
    if(fichier!=NULL)
    {
        Tville v;
        rewind(fichier);
        while(fread(&v,sizeof(Tville),1,fichier)!=NULL)
        {
            if(strcmp(v.ville,ville)==0&&strcmp(v.date,date)==0)
            {
                boolean=1;
            }
        }
    }
    else
    {
        printf("ECHEC D'OUVERTURE DU FICHIER");
    }
    rewind(fichier);
    fclose(fichier);
    return boolean;
}
int verfich(char nomfich[100])
/*MODULE QUI VERIFIE SI UN FICHIER EXISTE*/
{
    int booleen;
    if(strcmp(nomfich,"text.txt")==0||strcmp(nomfich,"text1.txt")==0||strcmp(nomfich,"text2.txt")==0||strcmp(nomfich,"textout.txt")==0)
        {
            booleen=1;
        }
        else
        {
            booleen=0;
        }
        return booleen;
}
void affichage(char nomfich[100])
/*MODULE QUI AFFICHE LE CONTENU DU FICHIER BINAIRE DE L'EXO6*/
{
    FILE* fichier=NULL;
    Tville v;
    fichier=fopen(nomfich,"rb+");
    rewind(fichier);
    if(fichier!=NULL)
    {
    while(fread(&v,sizeof(Tville),1,fichier)!=NULL)
    {

        printf("%s\n",v.ville);
        printf("%s\n",v.date);
        printf("%d\n",v.temp);

    }
}
else
{
    printf("ECHEC D'OUVERTURE DE FICHIER");
}
rewind(fichier);
fclose(fichier);
}
void color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

