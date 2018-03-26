// u1-interface.cpp
// Declarations externes - inclusion des fichiers d'entete
// Librairies standards
#include <iostream>         // cin, cout, ...
// Programmes locaux
#include "u1-interface.h"
#include "u2-dessin.h"
#include "u3-callbacks.h"
#include "u4-fonctions.h"
#include <stdio.h>



// Declaration pour utiliser iostream
using namespace std;

// Definition des donnees de l'interface - structure globale de variables
struct Interface gInterface ;

// CreerInterface
void CreerInterface()
{
    // Creation de la fenetre principale
    gInterface.Fenetre = new Fl_Double_Window(1000,800);
    gInterface.Fenetre->label("Projet Type") ;
    gInterface.Fenetre->begin() ;

    // Creation de la zone de dessin
    gInterface.ZoneDessin = new DrawingArea(X_ZONE,Y_ZONE,L_ZONE,H_ZONE);
    gInterface.ZoneDessin->draw_callback( ZoneDessinDessinerCB, NULL ) ;
    //gInterface.ZoneDessin->mouse_callback( ZoneDessinSourisCB, NULL ) ;
    gInterface.ZoneDessin->keyboard_callback( ZoneDessinClavierCB, NULL ) ;
    // Creation du bouton Quitter
    gInterface.BoutonQuitter = new Fl_Button(20, 720, 100, 20, "Quitter") ;
    gInterface.BoutonQuitter->callback( BoutonQuitterCB, NULL ) ;

    gInterface.BoutonReplay = new Fl_Button(140, 720, 100, 20, "Replay") ;
    gInterface.BoutonReplay->callback( BoutonReplayCB, NULL ) ;


    // Creation du champ texte
    gInterface.ChampTxt = new Fl_Output(770, 80, 200, 20, "Bienvenue sur ") ;

    // Creation du champ numerique
    gInterface.ChampNum = new Fl_Value_Output(770, 110, 100, 20, "Score : ") ;// création de la case score
    gInterface.ChampS = new Fl_Value_Output(770, 210, 100, 20, "Best Score : ") ;// création de la case où est affiché le meilleur score
    gInterface.Temps = new Fl_Value_Output(770, 170, 100, 20, "Temps : ") ;// création de la case ou est affché le temps

    // Creation du champ de saisie texte
    gInterface.ChampSaisieTxt = new Fl_Input(770, 140, 100, 20, "Pseudo : ") ;
	gInterface.ChampSaisieTxt->when( FL_WHEN_ENTER_KEY | FL_WHEN_RELEASE ) ;
	gInterface.ChampSaisieTxt->callback(ChampSaisieTxtCB, NULL ) ;

    // Creation du champ de saisie numerique


    // Creation du groupe de boutons radio
    // Aide : methode new Fl_Group( X, Y, L, H, Libelle ) :
    // Le groupe doit englober l'ensemble des boutons (largeur et hauteur).
    // Le libelle du groupe n'est pas considere comme faisant partie du bloc au niveau des interactions.
    // En pratique :
    // - Largeur L : on met pareil que les boutons.
    // - Hauteur H : on met la hauteur d'un bouton multipliee par [le nombre de boutons].
    // - Hauteur H : si probleme, multiplier la hauteur d'un bouton par [le nombre de boutons + 1] ou [le nombre de boutons + 2]

    gInterface.GroupeBoutonsRadio = new Fl_Group( 770, 260, 120, 60, "GroupeBoutonsRadio :" ) ;
    gInterface.GroupeBoutonsRadio->align( FL_ALIGN_LEFT ) ;
    gInterface.GroupeBoutonsRadio->begin() ;

    gInterface.BoutonRadio1 = new  Fl_Round_Button( 770, 260, 120, 20, "BoutonRadio1") ;
    gInterface.BoutonRadio1->type(FL_RADIO_BUTTON) ;
	gInterface.BoutonRadio1->callback(BoutonRadioCB, NULL ) ;

    gInterface.BoutonRadio2 = new  Fl_Round_Button( 770, 280, 120, 20, "BoutonRadio2") ;
    gInterface.BoutonRadio2->type(FL_RADIO_BUTTON) ;
	gInterface.BoutonRadio2->callback(BoutonRadioCB, NULL ) ;

    gInterface.BoutonRadio3 = new  Fl_Round_Button( 770, 300, 120, 20, "BoutonRadio3") ;
    gInterface.BoutonRadio3->type(FL_RADIO_BUTTON) ;
	gInterface.BoutonRadio3->callback(BoutonRadioCB, NULL ) ;

    gInterface.GroupeBoutonsRadio->end();


    // Affichage de la fenetre
    gInterface.Fenetre->end();
    gInterface.Fenetre->show();

}


void ActualiserInterface()
{


    // Actualisation Texte
    gInterface.ChampTxt->value( gDonnees.Texte );
    // Actualisation Valeur
    gInterface.ChampNum->value( gDonnees.Valeur ) ;
    gInterface.ChampS -> value(bestscore);
    gInterface.Temps->value( gDonnees.Temps ) ;

    gInterface.BoutonRadio3->value( gDonnees.Option2 );
    // Actualisation Option3
    //gInterface.MenuOptions->value( gDonnees.Option3 ) ;

}
