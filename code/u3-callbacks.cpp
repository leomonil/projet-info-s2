// u3-callbacks.cpp
// Declarations externes - inclusion des fichiers d'entete
// Librairies standards
#include <iostream>     // cout, cin, ...
// Librairies fltk
#include <FL/Fl.H>
#include <FL/fl_ask.H>  // fl_message, fl_alert, fl_ask
#include <FL/Fl_File_Chooser.H> // fl_file_chooser
// Programmes locaux
#include "u1-interface.h"
#include "u3-callbacks.h"
#include "u4-fonctions.h"
#include "u2-dessin.h"

// Declaration pour utiliser iostream
using namespace std;

// TraiterCycle
void TraiterCycleCB()
{
    // Trace pour bien montrer que la fonction est appelee cycliquement
    // printf(""Appel de TraiterCycleCB");

    // On incremente Valeur de 1 ET on la reaffiche

    gInterface.ChampNum->value(gDonnees.Valeur) ;// on actualise le score
    gDonnees.Temps = gDonnees.Temps-(time(NULL)-gDonnees.Heure) ; // on actualise l'heure
    gDonnees.Heure = time(NULL);
    gInterface.Temps->value(gDonnees.Temps) ;
    DeplacerBouleSansRebond() ;
    DeplacerPiece();
    // on stock le meilleur score et on dessine le dessin de fin
    if(gDonnees.Temps==0)
    {
        if (affiche_game_over==0)
        {

            affiche_game_over=1;
            meilleurScore();
            gInterface.ZoneDessin->draw_callback( DessinApresCoup, NULL ) ;
        }

}

    else gInterface.ZoneDessin->redraw() ;
}




// ZoneDessinClavierCB
void ZoneDessinClavierCB( Fl_Widget* widget, void* data )
{
    // Definition des variables
    int Touche ;


    // Recuperation de la touche clavier activee
    Touche = Fl::event_key() ;

    // Traitement de la touche
    switch ( Touche )
    {
        // Touches speciales
        case FL_Left :
            // on déplace le personnage à gauche
            if (gCarte[gDonnees.Boule.X/10-1][gDonnees.Boule.Y/10]!=3 && gCarte[gDonnees.Boule.X/10-1][gDonnees.Boule.Y/10]!=1 )
            {gDonnees.Boule.X -= gincrement;}

            break;
        case FL_Right :

            // on déplace le personnage à droite si il ne cogne pas sur un bord ou sur une plateforme
            if (gCarte[gDonnees.Boule.X/10+1][gDonnees.Boule.Y/10]!=3 && gCarte[gDonnees.Boule.X/10+1][gDonnees.Boule.Y/10]!=1)
            {
            gDonnees.Boule.X += gincrement;

            }
            break;
        case FL_Down :
            //on déplace le personnage en bas si il est sur une échelle
            if (gCarte[gDonnees.Boule.X/10][gDonnees.Boule.Y/10+1]==2 )
            {
                gDonnees.Boule.Y += gincrement;
            }
            break ;
        case FL_Up :
            // on fait monter le personnage si il est sur une échelle
            if (gCarte[gDonnees.Boule.X/10][gDonnees.Boule.Y/10+1]==2 && gCarte[gDonnees.Boule.X/10][gDonnees.Boule.Y/10-1]!=3)
            {
                gDonnees.Boule.Y -= gincrement;
            }
        // Caracteres
        case ' ' :

            gDonnees.Boule.Y -=gincrement;
            break ;

        case 'a' :
            // on fait sauter le personnage en haut à gauche
            if(gCarte[gDonnees.Boule.X/10][gDonnees.Boule.Y/10 +1]!=0 && gDonnees.Boule.X>80)
            {
                gDonnees.Boule.Y-= 6*gincrement;
                gDonnees.Boule.X -= 12*gincrement;
                JouerSon("media/Saut.mp3");
            }
            break ;
        case 'e' :
            // on fait sauter le personnage en haut à droite
            if(gCarte[gDonnees.Boule.X/10][gDonnees.Boule.Y/10 +1]!=0 && gDonnees.Boule.X<580)
            {
                gDonnees.Boule.Y-= 6*gincrement;
                gDonnees.Boule.X += 12*gincrement;
                JouerSon("media/Saut.mp3");
            }
            break ;
        case 'z' :
            if(gCarte[gDonnees.Boule.X/10][gDonnees.Boule.Y/10 +1]!=0 )
            {
                gDonnees.Boule.Y-= 6*gincrement;
                JouerSon("media/Saut.mp3");

            }
            break ;
        case '2' :
            printf("Appui sur le chiffre 2\n");
            break ;
    }
}

void BoutonQuitterCB(Fl_Widget* w, void* data)
{
    // Fin du programme
    exit(0) ;
}
void BoutonReplayCB(Fl_Widget* w, void* data)
{
    // on recommence le programme et on redessine la zone de dessin
    InitialiserDonnees();
    ActualiserInterface();
    gInterface.ZoneDessin->draw_callback( ZoneDessinDessinerCB, NULL ) ;


}

void ChampSaisieTxtCB(Fl_Widget* w, void* data)
{
    char Saisie[80] ;
    strcpy( Saisie, gInterface.ChampSaisieTxt->value() ) ;
    printf("ChampSaisieTxtCB : %s\n", Saisie);
}



void CurseurCB(Fl_Widget* w, void* data)
{
    gDonnees.Parametre = (int)gInterface.Curseur->value() ;
    printf("CurseurCB : Parametre = %i\n", gDonnees.Parametre);
}

void CaseCocherCB(Fl_Widget* w, void* data)
{
    gDonnees.Option1 = gInterface.CaseCocher->value() ;
    printf("CaseCocherCB : Option1 = %i\n", gDonnees.Option1);
}*/

void BoutonRadioCB(Fl_Widget* w, void* data)
{
    // On regarde quel bouton est sélectionné
    if ( gInterface.BoutonRadio1->value() == 1 )
        {
            gDonnees.Option2 = 1 ;
            JouerSon("media/megaman.mp3");
        }
    else  if ( gInterface.BoutonRadio2->value() == 1 )
        gDonnees.Option2 = 2 ;
    else
        gDonnees.Option2 = 3 ;

    printf("BoutonRadioCB : Option2 = %i\n", gDonnees.Option2);
}

