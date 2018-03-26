// u4-fonctions.cpp
// Declarations externes - inclusion des fichiers d'entete
// Librairies standards
#include <iostream>     // cout, cin, ...
#include <stdlib.h>     // exit, rand
#include <time.h>       // time
#include <string.h>
#include <stdio.h>
#include <math.h>   // strcpy
// Librairie fmod pour le son
#include <api/inc/fmod.h>
#include <api/inc/fmod_errors.h>
// Programmes locaux
#include "u1-interface.h"
#include "u2-dessin.h"
#include "u3-callbacks.h"
#include "u4-fonctions.h"

// Declaration pour utiliser iostream
using namespace std;




int gCarte[LIGNE][COLONNE];// on déclare la carte comme une matrice de ligne et de colonne constante
int gincrement;
int score;
int bestscore;
int affiche_game_over;



// Definition des donnees fonctionnelles du projet - structure globale de variables
struct Donnees gDonnees;


// on lit le fichier texte de la carte et on met ses valeurs dans gCarte
void lire_fond(char* nom_fichier)
{

	FILE* fondjeu = fopen( nom_fichier, "rt" );
	if (fondjeu == NULL ){
 		printf ("unable to read the file \n");
		exit (1) ;
	}
	int i,j;
	for (i=0;i<LIGNE;i++)
	{
		for (j=0;j<COLONNE;j++)
		{
		fscanf ( fondjeu, "%d", &gCarte[j][i]);
				//printf ("%d " , gCarte[i][j]);
		}
	//printf("%d\n", i);
	}

fclose(fondjeu);

}



// Initialiser
void InitialiserDonnees()
{

    // On initialise le generateur de nombres aleatoires
    srand(time(NULL));
    // Initialisation de Rebond
    gDonnees.Rebond = 0 ;
    // On initialise Texte
    strcpy(gDonnees.Texte, "LOUDE RUNNER") ;
    // On initialise Valeur
    gDonnees.Valeur = 0 ;
    gDonnees.Temps = 25;
    gDonnees.Heure=time(NULL);
    // On initialise Parametre
    gDonnees.Parametre = 5 ;

    // On initialise la boule
    gDonnees.Boule.X = 52 ;
    gDonnees.Boule.Y = 630 ;
    gDonnees.Boule.VX = 0 ;
    gDonnees.Boule.VY = 0 ;
    //on initialise gincrement qui est le rapport entre le déplacement de l'avatar en pixel et la touche du clavier
    gincrement = 5;
    // on initialise la position de la pièce
    srand(time(NULL));
    gDonnees.Piece.X = rand()%660 ;
    gDonnees.Piece.Y = rand()%660 ;
    gDonnees.Piece.VX = 0 ;
    gDonnees.Piece.VY = 0 ;
    // on initialise le score
    score = 0;
    // on initialise bestscore qui est stocké dans un fichier texte
    FILE* tab_txt;
    tab_txt=fopen("bestscore.txt", "r");// on ne fait que lire dans ce fichier
    if (tab_txt != NULL) fscanf ( tab_txt, "%d", &bestscore);
    fclose(tab_txt);
    // on initialise cette variable qui est une variable auxiliaire
    affiche_game_over =0;




    char fichier[256] = "fond.txt";


    lire_fond(fichier);

}

// on stock le meilleur score dans le fichier texte
void meilleurScore()
{
    FILE* tab_txt;
    if (tab_txt != NULL){
    tab_txt=fopen("bestscore.txt", "w");// on ne fait que écrire
    if (bestscore<score)
         {

            bestscore = score;
            fprintf(tab_txt,"%d\n",bestscore);
         }
    else fprintf(tab_txt,"%d\n",bestscore);





    fclose(tab_txt);

}
}
// Ces deux fonctions ne sont plus utiles carle joueur ne peut pas aller sur les bords.
// Nous les avons gardés pour éviter de trop modifiés le code de base
void DeplacerBouleSansRebond()
{
    // Nouvelle position de la boule ...
    gDonnees.Boule.X = gDonnees.Boule.X + gDonnees.Boule.VX  ;
    gDonnees.Boule.Y = gDonnees.Boule.Y + gDonnees.Boule.VY;

    // ... ramenee sur la sphere
    if ( gDonnees.Boule.X > L_ZONE )
        gDonnees.Boule.X = gDonnees.Boule.X - L_ZONE;

    if ( gDonnees.Boule.X < 0 )
        gDonnees.Boule.X = L_ZONE + gDonnees.Boule.X ;

    if ( gDonnees.Boule.Y > H_ZONE )
        gDonnees.Boule.Y = gDonnees.Boule.Y - gDonnees.Boule.Y;

    if ( gDonnees.Boule.Y < 0 )
        gDonnees.Boule.Y = H_ZONE + gDonnees.Boule.Y ;

    if (gCarte[gDonnees.Boule.X/10][gDonnees.Boule.Y/10+1]==0)
    {
        gDonnees.Boule.VY=2*gincrement;
    }
    else if (gCarte[gDonnees.Boule.X/10][gDonnees.Boule.Y/10+1]!=0)
    {
        gDonnees.Boule.VY=0;
    }
}


void DeplacerBouleAvecRebonds()
{
    // Nouvelle position de la boule ...
    gDonnees.Boule.X = gDonnees.Boule.X + gDonnees.Boule.VX ;
    gDonnees.Boule.Y = gDonnees.Boule.Y + gDonnees.Boule.VY ;

    // Gestion des rebonds sur les bords du rectangle

    if ( gDonnees.Boule.X >= L_ZONE )
    {
        gDonnees.Boule.X = L_ZONE ;
        gDonnees.Boule.VX = -1 * gDonnees.Boule.VX ;
    }

    if ( gDonnees.Boule.Y >= H_ZONE )
    {
        gDonnees.Boule.Y = H_ZONE ;
        gDonnees.Boule.VY = -1 * gDonnees.Boule.VY ;
    }

    if ( gDonnees.Boule.X <= 0 )
    {
        gDonnees.Boule.X = 0 ;
        gDonnees.Boule.VX = -1 * gDonnees.Boule.VX ;
    }

    if ( gDonnees.Boule.Y <= 0 )
    {
        gDonnees.Boule.Y = 0 ;
        gDonnees.Boule.VY = -1 * gDonnees.Boule.VY ;
    }
}
//On fait bouger la pièce
void DeplacerPiece()
{
    gDonnees.Piece.X = gDonnees.Piece.X + gDonnees.Piece.VX  ;
    gDonnees.Piece.Y = gDonnees.Piece.Y + gDonnees.Piece.VY;
    // si le joueur est sur la pièce
    if (gDonnees.Piece.X/10<=gDonnees.Boule.X/10 + 1 && gDonnees.Piece.X/10 >=gDonnees.Boule.X/10 -1 && gDonnees.Piece.Y/10<= gDonnees.Boule.Y/10+1 && gDonnees.Piece.Y/10>= gDonnees.Boule.Y/10-1 )
    {   // alors on en fait apparaitre une autre et le score augmente de 1
        gDonnees.Piece.X=rand()%660;
        gDonnees.Piece.Y=rand()%660;
        gDonnees.Valeur = gDonnees.Valeur + 1 ;
        score +=1;
    }
    // on replace la pièce si celle-çi se situe dans une plateforme ou sur un bord
    while(gCarte[gDonnees.Piece.Y/10][gDonnees.Piece.X/10]==1 || gCarte[gDonnees.Piece.Y/10][gDonnees.Piece.X/10]==3)
    {
        gDonnees.Piece.X=rand()%660;
        gDonnees.Piece.Y=rand()%660;
    }
    // on fait chuter la pièce si elle n'est pas sur une plateforme
    if (gCarte[gDonnees.Piece.X/10][gDonnees.Piece.Y/10+1]==0)
    {
        gDonnees.Piece.VY=2*gincrement;
    }
    else if (gCarte[gDonnees.Piece.X/10][gDonnees.Piece.Y/10+1]!=0)
    {
        gDonnees.Piece.VY=0;
    }

}
// Utilitaires

// Joue le fichier son passe en parametre, mp3, etc...
void JouerSon(char * FichierSon)
{
    // Musique de fond
    FMOD_SYSTEM      *system;
    FMOD_SOUND       *sound;
    FMOD_CHANNEL     *channel = 0;
    FMOD_RESULT       result;
    int               key;
    unsigned int      version;
    /*
        Create a System object and initialize.
    */
    result = FMOD_System_Create(&system);
    result = FMOD_System_GetVersion(system, &version);
    result = FMOD_System_Init(system, 32, FMOD_INIT_NORMAL, NULL);
    result = FMOD_System_CreateSound(system, FichierSon, FMOD_SOFTWARE, 0, &sound);
    result = FMOD_Sound_SetMode(sound, FMOD_LOOP_OFF);
    result = FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, sound, 0, &channel);
}

// Cette procedure permet une attente de x secondes, x peut etre en secondes mais aussi en flottant par exemple : 0.1 s
void Attente ( double Seconds )
{
    clock_t Endwait;
    Endwait = (int) (clock () + Seconds * CLOCKS_PER_SEC);
    while (clock() < Endwait);
}
