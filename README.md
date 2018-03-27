# Rapport programmeur à programmeur
## I Présentation du jeu.
Notre jeu est un jeu à plateforme fixe type load runner. C’est-à-dire que lors du lancement du jeu, une carte constitué d'échelle et de plateforme flottante apparaît. Le joueur incarne un avatar en forme de mario qui peut se déplacer uniquement sur les plateforme et peut monter uniquement à travers les échelles. Lorsque le personnage n’est pas sur une plateforme ou une échelle, il tombe jusqu’à être sur une plateforme ou une échelle. Le joueur peut appuyer sur “e” pour sauter et aller à droite en même temps, “a” pour faire de même mais à gauche et “z” pour sauter droit. Pour se déplacer en haut, en bas, à droite, à gauche, le joueur peut utiliser les touches directionnels.
Des pièces apparaissent aléatoirement sur la carte (au dessus des plateformes ou sur le sol) et le but est que notre avatar en ramasse le plus possible. Pour ramasser des pièces, il suffit d’être dessus. Dans l’interface du jeu, le nombre de pièces récupérés depuis le début de la partie est affiché. Le meilleur score réalisé sur ce PC est aussi affiché en dessous. Un minuteur est affiché dans l’interface et lorsque celui est nul, le jeu s'arrête. Il y a donc un écran noir où il est affiché une image “game over”. 
On peut rejouer une partie en cliquant sur la case rejoué en bas à gauche de l’interface. 
Une musique peut-être activé en cliquant sur la case radio 1 dans l’interface. Il y a alors une musique de fond et un son lors des sauts.

## II Présentation du code
### 1. Présentation général du code
Le code de base permet de créer une fenêtre graphique avec une interface, le tout s’actualisant régulièrement (15 ms). Le main permet de lancer la boucle dans lequel le programme va s'effectuer. Le fichier u1 permet de créer l’interface et de lancer le programme qui permet de l’actualiser. Le fichier u2-dessin permet de dessiner tous les cycles la carte actualiser.

Chaque fonction est écrite dans son fichier.cpp correspondant et est externalisé à l’aide des fichiers .h. De la même façon toutes les variables créées sont externalisées dans le fichier u4-fonctions.h. Les variables externes sont toutes initialisées dans la fonction void InitialiserDonnees.

### 2. Lecture de la carte
Créer la carte se fait en excel, qui est ensuite converti en fichier texte. La carte est une matrice de 66*66 contenant 0 pour le vide, 1 pour les plateformes, 2 pour les échelles et 3 pour les bords du jeu. Le fichier .txt contenant la carte doit être insérer dans le fichier global (ne pas le mettre dans media par exemple) et doit être appelé fond. Il faudra sinon renommer le fichier à ouvrir dans la fonction void lire_fond(char* nom_fichier) qui permet d’ouvrir le fichier .txt et de créer une matrice 2x2 de la taille de la carte nommé gCarte[ ][ ]. 
gCarte est déclaré en int et de LIGNE ligne et de COLONNE  colonne. LIGNE et COLONNE sont définis dans u4.h.  La fonction lire_fond permet de rentrer toute les valeurs du fichier .txt dans la matrice gCarte. Une fois cette matrice compléter, elle est externaliser et il suit donc la conception graphique de la map.

### 3. Graphisme de la carte et du joueur
L’intégralité de la conception graphique de la map et du personnage est réalisé dans le fichier u2-dessin.cpp. 

Concernant la partie création de la map la fonction est  void ZoneDessinDessinerCB( Fl_Widget* widget, void* data ). On ouvre tout d’abord une image de fond pour le jeu en l'occurrence une image jpeg convertit au préalable en fichier .bmp et dont les dimensions sont la taille de la matrice x 10. Pour exemple si la matrice gCarte fait 66*66 l’image devra faire 660*660. Chaque case du tableau correspondant à 10 pixels à l’affichage. Pour chaque case du tableau lu par incrémentation en fonction de la valeur une image bmp et placé sur l’emplacement correspondant (échelle, sol, bord du jeu …). Les images placé sont mises dans le fichier media et sont de taille 20*20 dans le but de moins alourdir le chargement de la map (une image couvre 4 cases du tableau gCarte).

Cette fonction contient également un code pour modéliser graphiquement une pièce jaune représentant la pièce dont les coordonnées sont créer de façons aléatoire (voir partie 7).

Pour le graphisme du personnage une image bmp de 30*20 en l'occurrence représentant mario est affiché à l’endroit du pointeur sur le tableau (gDonnées.Boule .X et .Y).

Améliorations envisageable :
 Une des améliorations réalisables et que lorsqu’on appuie sur une touche (gauche, droite, haut, bas …) l’image de mario soit actualisé simplement en remplaçant l’image originale par une autre correspondant au mouvement.
Une autre amélioration à réaliser serait de réaliser la création de la partie map en dehors de la boucle qui actualise en permanence le jeu afin de pouvoir réaliser des maps plus complexes et donc plus lourdes à faire tourner.
