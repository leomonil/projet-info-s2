# Rapport programmeur � programmeur
## I Pr�sentation du jeu.
Notre jeu est un jeu � plateforme fixe type load runner. C�est-�-dire que lors du lancement du jeu, une carte constitu� d'�chelle et de plateforme flottante appara�t. Le joueur incarne un avatar en forme de mario qui peut se d�placer uniquement sur les plateforme et peut monter uniquement � travers les �chelles. Lorsque le personnage n�est pas sur une plateforme ou une �chelle, il tombe jusqu�� �tre sur une plateforme ou une �chelle. Le joueur peut appuyer sur �e� pour sauter et aller � droite en m�me temps, �a� pour faire de m�me mais � gauche et �z� pour sauter droit. Pour se d�placer en haut, en bas, � droite, � gauche, le joueur peut utiliser les touches directionnels.
Des pi�ces apparaissent al�atoirement sur la carte (au dessus des plateformes ou sur le sol) et le but est que notre avatar en ramasse le plus possible. Pour ramasser des pi�ces, il suffit d��tre dessus. Dans l�interface du jeu, le nombre de pi�ces r�cup�r�s depuis le d�but de la partie est affich�. Le meilleur score r�alis� sur ce PC est aussi affich� en dessous. Un minuteur est affich� dans l�interface et lorsque celui est nul, le jeu s'arr�te. Il y a donc un �cran noir o� il est affich� une image �game over�. 
On peut rejouer une partie en cliquant sur la case rejou� en bas � gauche de l�interface. 
Une musique peut-�tre activ� en cliquant sur la case radio 1 dans l�interface. Il y a alors une musique de fond et un son lors des sauts.

## II Pr�sentation du code
### 1. Pr�sentation g�n�ral du code
Le code de base permet de cr�er une fen�tre graphique avec une interface, le tout s�actualisant r�guli�rement (15 ms). Le main permet de lancer la boucle dans lequel le programme va s'effectuer. Le fichier u1 permet de cr�er l�interface et de lancer le programme qui permet de l�actualiser. Le fichier u2-dessin permet de dessiner tous les cycles la carte actualiser.

Chaque fonction est �crite dans son fichier.cpp correspondant et est externalis� � l�aide des fichiers .h. De la m�me fa�on toutes les variables cr��es sont externalis�es dans le fichier u4-fonctions.h. Les variables externes sont toutes initialis�es dans la fonction void InitialiserDonnees.

### 2. Lecture de la carte
Cr�er la carte se fait en excel, qui est ensuite converti en fichier texte. La carte est une matrice de 66*66 contenant 0 pour le vide, 1 pour les plateformes, 2 pour les �chelles et 3 pour les bords du jeu. Le fichier .txt contenant la carte doit �tre ins�rer dans le fichier global (ne pas le mettre dans media par exemple) et doit �tre appel� fond. Il faudra sinon renommer le fichier � ouvrir dans la fonction void lire_fond(char* nom_fichier) qui permet d�ouvrir le fichier .txt et de cr�er une matrice 2x2 de la taille de la carte nomm� gCarte[ ][ ]. 
gCarte est d�clar� en int et de LIGNE ligne et de COLONNE  colonne. LIGNE et COLONNE sont d�finis dans u4.h.  La fonction lire_fond permet de rentrer toute les valeurs du fichier .txt dans la matrice gCarte. Une fois cette matrice compl�ter, elle est externaliser et il suit donc la conception graphique de la map.

### 3. Graphisme de la carte et du joueur
L�int�gralit� de la conception graphique de la map et du personnage est r�alis� dans le fichier u2-dessin.cpp. 

Concernant la partie cr�ation de la map la fonction est  void ZoneDessinDessinerCB( Fl_Widget* widget, void* data ). On ouvre tout d�abord une image de fond pour le jeu en l'occurrence une image jpeg convertit au pr�alable en fichier .bmp et dont les dimensions sont la taille de la matrice x 10. Pour exemple si la matrice gCarte fait 66*66 l�image devra faire 660*660. Chaque case du tableau correspondant � 10 pixels � l�affichage. Pour chaque case du tableau lu par incr�mentation en fonction de la valeur une image bmp et plac� sur l�emplacement correspondant (�chelle, sol, bord du jeu �). Les images plac� sont mises dans le fichier media et sont de taille 20*20 dans le but de moins alourdir le chargement de la map (une image couvre 4 cases du tableau gCarte).

Cette fonction contient �galement un code pour mod�liser graphiquement une pi�ce jaune repr�sentant la pi�ce dont les coordonn�es sont cr�er de fa�ons al�atoire (voir partie 7).

Pour le graphisme du personnage une image bmp de 30*20 en l'occurrence repr�sentant mario est affich� � l�endroit du pointeur sur le tableau (gDonn�es.Boule .X et .Y).

Am�liorations envisageable :
 Une des am�liorations r�alisables et que lorsqu�on appuie sur une touche (gauche, droite, haut, bas �) l�image de mario soit actualis� simplement en rempla�ant l�image originale par une autre correspondant au mouvement.
Une autre am�lioration � r�aliser serait de r�aliser la cr�ation de la partie map en dehors de la boucle qui actualise en permanence le jeu afin de pouvoir r�aliser des maps plus complexes et donc plus lourdes � faire tourner.
