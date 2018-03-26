// u4-fonctions.h
// Sentinelle d'inclusion
#ifndef _u4_fonctions_h
#define _u4_fonctions_h

// Definition des constantesvoid DeplacerPiece() ;
#define DUREE_CYCLE 0.015    // 0.500 secondes, depend du materiel utilise
#define RAYON_BOULE  15

// Declaration des donnees du projet

#define LIGNE 66
#define COLONNE 66
// Structure de definition de la boule
struct Boule
{
    int X;
    int Y;
    int VX;
    int VY;
} ;

struct Piece
{
    int X;
    int Y;
    int VX;
    int VY;

};
// Structure globale pour les variables fonctionnelles
struct Donnees
{
    struct Boule    Boule ;
    struct Piece    Piece;
    int             Rebond ;
    char            Texte[80] ;
    unsigned int    Valeur ;
    unsigned int    Temps ;
    unsigned int    Heure ;
    int             Parametre ;
    int             Option1 ;
    int             Option2 ;
    int             Option3 ;
};

extern struct Donnees gDonnees;
extern int gincrement;
extern int gCarte [LIGNE][COLONNE];
extern int score;
extern int bestscore;
extern int affiche_game_over;


struct position
{
    int I;
    int J;
};
extern struct position gPosition;

void meilleurScore();

// Déclaration des sous-programmes
void InitialiserDonnees() ;
void DeplacerBouleSansRebond() ;
void DeplacerPiece() ;
void DeplacerBouleAvecRebonds() ;

void JouerSon(char *) ;         // Jouer un son
void Attente(double Seconds);
unsigned char** alloue_fond_char();
unsigned char** lire_fond();  // Procedure d'attente

#endif // _u4_fonctions_h
