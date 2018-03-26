// u1-interface.h
// Sentinelle d'inclusion
#ifndef _u1_interface_h
#define _u1_interface_h

// Declarations externes - inclusion des fichiers d'entete
#include "main.h"
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Value_Output.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Value_Slider.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Value_Input.H>

// Definition des constantes
#define X_ZONE  10      // X de la zone
#define Y_ZONE  20      // Y de la zone
#define L_ZONE  670     // Largeur de la zone
#define H_ZONE  670     // Hauteur de la zone

// Declaration des objets de l'interface
struct Interface
{
    Fl_Double_Window*   Fenetre ;
    DrawingArea*        ZoneDessin ;
    Fl_Button*          BoutonQuitter ;
    Fl_Button*          BoutonReplay;



    Fl_Output*          ChampTxt ;
    Fl_Value_Output*    ChampNum ; // declaration de l'objet associé au score
    Fl_Value_Output*    ChampS ;// déclaration de l'objet associé au meilleur score
    Fl_Value_Output*    Temps ;
    Fl_Input*           ChampSaisieTxt ;

    Fl_Group*           GroupeBoutonsRadio ;
    Fl_Round_Button*    BoutonRadio1 ;
    Fl_Round_Button*    BoutonRadio2 ;
    Fl_Round_Button*    BoutonRadio3 ;

} ;

// Declaration des objets de l'interface generale - ne pas supprimer
extern struct Interface gInterface ;


// Declaration des sous-programmes
void CreerInterface();
void ActualiserInterface();

#endif // _u1_interface_h
