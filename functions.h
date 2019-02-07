/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||||||||||||||||||||||||||||||||||||||||||||||||||||||||TP N.01 SFSD||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
/*------------------------------------------------------------------------------------------------------------------------------*/
/*|||||||||||||||||||||||||||||||||||||||||||||||DEFINITION DE LA STRUCTURE|||||||||||||||||||||||||||||||||||||||||||||||||||||*/
typedef struct Tville Tville;
struct Tville
{
    char ville[100];
    char date[100];
    int temp;
};
void affichfich(char nomfich[100]);//affiche un fichier text
void concatene(char fich1[100],char fich2[100],char fichout[100]);//concatene 2fichier texte
int nbroccfich(char nomfich[100],char mot[100]);//nombre d'occurence d'un mot dans fichier texte
int nbrlignefich(char nomfich[100]);//nombre de lignes  d'un mot dans un fichier texte
void cryptage(char chaine[100],char nomfich1[100],char nomfich2[100]);//crypter un fichier texte
void Decryptage(char chaine[100],char nomfich1[100],char nomfich2[100]);//decrypte un fichier texte
int MaxTemp(char ville1[100],int *trouv);//maximum de temperature
void RemplirFile(int elements,char nomfich[100]);//remplir les enreg dans fichier binaire
float MoyTemp(char ville1[100],int *trouv);//moyenne des temperatures
void modiffich(char ville[100],char date[100],int temp,char nomfich[100]);//modifie une temperature d'une ville
void ajoutenreg(char ville[100],char date[100],int temp,char nomfich[100]);//ajout d'un enreg en fin du fichier
void suppression(char ville[100]);//supprime un enreg (suppression phisique)
int identique(char nomfich1[100],char nomfich2[100]);//verifie si 2 fichier texte sont identique
/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||||||||||||||||||||||||||||||||||||||||||||||||||||||MODULES DE PLUS:||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
int existe(char ville[100],char date[100],char nomfich[100]);//verifie si l'enreg existe
int verfich(char nomfich[100]);//verifie si le fichier existe dans le repertoire
void affichage(char nomfich[100]);//affiche le fichier binaire
void color(int couleurDuTexte,int couleurDeFond); // fonction d'affichage de couleurs
