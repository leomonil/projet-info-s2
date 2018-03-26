// u2-dessin.cpp
// Declarations externes - inclusion des fichiers d'entete
// Librairies standards
#include <iostream>         // cin, cout, ...
// Librairies fltk
#include <FL/Fl.H>
#include <FL/fl_draw.H>     // fonctions de dessin
// Programmes locaux
#include "u1-interface.h"
#include "u2-dessin.h"
#include "u4-fonctions.h"
#include <stdio.h>
#include <FL/Fl_BMP_Image.H>

// Declaration pour utiliser iostream
using namespace std;

// DessinerZone
void ZoneDessinDessinerCB( Fl_Widget* widget, void* data )
{
    // On efface toute la zone ( en dessinant dessus un rectangle plein, noir )

   int i,j;
  Fl_BMP_Image fond("media/fond.bmp") ;// on dessine le fond grâce à une image importée

fond.draw(X_ZONE , Y_ZONE);
    for(i=0;i<LIGNE;i++)// on dessine case par case de la carte l'image du dessin en fonction de la valeur de la carte
    {
        for(j=0;j<COLONNE;j++)
        {
            if( gCarte[i][j] == 0)// si il n'y a rien içi
            {

            }
           else if(gCarte[i][j] == 1 && gCarte[i][j-1] != 1 && i%2==0)
            {
            Fl_BMP_Image plateforme("media/plateforme.bmp") ;
            plateforme.draw(X_ZONE+10*i,Y_ZONE+10*j);
               /*fl_color(FL_BLACK);
               fl_rectf(X_ZONE+10*i, Y_ZONE+10*j, 10, 10);*/
            }
            else if(gCarte[i][j] == 2 && gCarte[i-1][j] != 2 && j%2==0 )
            {
           Fl_BMP_Image echelle("media/echelle.bmp") ;
            echelle.draw(X_ZONE+10*i,Y_ZONE+10*j);
               /*fl_color(FL_GREEN);
               fl_rectf(X_ZONE+10*i, Y_ZONE+10*j, 10, 10);*/
            }

            else if(gCarte[i][j] == 3)
            {
                fl_color(FL_RED) ;
                fl_rectf(X_ZONE+10*i, Y_ZONE+10*j, 10, 10);

            }
        }

    }
    // on dessine la pièce
 fl_color(FL_YELLOW);
    fl_pie( X_ZONE + gDonnees.Piece.X - RAYON_BOULE, Y_ZONE -10 + gDonnees.Piece.Y - RAYON_BOULE,  2*RAYON_BOULE,  2*RAYON_BOULE,0,360 );


  Fl_BMP_Image joueur("media/mario1.bmp") ;

    joueur.draw(X_ZONE + gDonnees.Boule.X -10 , Y_ZONE + gDonnees.Boule.Y -20 );

}

void DessinApresCoup(Fl_Widget* widget, void* data)
    // on dessine l'image quand le temps à atteint 0
{

    fl_color(FL_BLACK);
    fl_rectf(X_ZONE,Y_ZONE,660,660);
    Fl_BMP_Image gameover("media/gameover.bmp") ;
            gameover.draw(X_ZONE+100,Y_ZONE+100);



}
