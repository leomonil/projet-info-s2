# Rapport programmeur à programmeur
## I Présentation du jeu.
Notre jeu est un jeu à plateforme fixe type load runner. C’est-à-dire que lors du lancement du jeu, une carte constitué d'échelle et de plateforme flottante apparaît.
 Le joueur incarne un avatar en forme de mario qui peut se déplacer uniquement sur les plateforme et peut monter uniquement à travers les échelles.

 Lorsque le personnage n’est pas sur une plateforme ou une échelle, il tombe jusqu’à être sur une plateforme ou une échelle. Le joueur peut appuyer sur “e” pour sauter et aller à droite en même temps, “a” pour faire de même mais à gauche et “z” pour sauter droit. Pour se déplacer en haut, en bas, à droite, à gauche, le joueur peut utiliser les touches directionnels.
Des pièces apparaissent aléatoirement sur la carte (au dessus des plateformes ou sur le sol) et le but est que notre avatar en ramasse le plus possible.

 Pour ramasser des pièces, il suffit d’être dessus. Dans l’interface du jeu, le nombre de pièces récupérés depuis le début de la partie est affiché. Le meilleur score réalisé sur ce PC est aussi affiché en dessous. Un minuteur est affiché dans l’interface et lorsque celui est nul, le jeu s'arrête. Il y a donc un écran noir où il est affiché une image “game over”. 
On peut rejouer une partie en cliquant sur la case rejoué en bas à gauche de l’interface. 
Une musique peut-être activé en cliquant sur la case radio 1 dans l’interface. Il y a alors une musique de fond et un son lors des sauts.

## II Présentation du code
### 1. Présentation général du code
Le code de base permet de créer une fenêtre graphique avec une interface, le tout s’actualisant régulièrement (15 ms). Le main permet de lancer la boucle dans lequel le programme va s'effectuer. Le fichier u1 permet de créer l’interface et de lancer le programme qui permet de l’actualiser. Le fichier u2-dessin permet de dessiner tous les cycles la carte actualiser.

Chaque fonction est écrite dans son fichier.cpp correspondant et est externalisé à l’aide des fichiers .h. De la même façon toutes les variables créées sont externalisées dans le fichier u4-fonctions.h. Les variables externes sont toutes initialisées dans la fonction void InitialiserDonnees.

### 2. Lecture de la carte
Créer la carte se fait en excel, qui est ensuite converti en fichier texte. La carte est une matrice de 66 par 66 contenant 0 pour le vide, 1 pour les plateformes, 2 pour les échelles et 3 pour les bords du jeu. Le fichier .txt contenant la carte doit être insérer dans le fichier global (ne pas le mettre dans media par exemple) et doit être appelé fond. Il faudra sinon renommer le fichier à ouvrir dans la fonction void lire_fond(char* nom_fichier) qui permet d’ouvrir le fichier .txt et de créer une matrice 2x2 de la taille de la carte nommé gCarte[ ][ ]. 
gCarte est déclaré en int et de LIGNE ligne et de COLONNE  colonne. LIGNE et COLONNE sont définis dans u4.h.  La fonction lire_fond permet de rentrer toute les valeurs du fichier .txt dans la matrice gCarte. Une fois cette matrice compléter, elle est externaliser et il suit donc la conception graphique de la map.

### 3. Graphisme de la carte et du joueur
L’intégralité de la conception graphique de la map et du personnage est réalisé dans le fichier u2-dessin.cpp. 

Concernant la partie création de la map la fonction est  void ZoneDessinDessinerCB( Fl_Widget* widget, void* data ). On ouvre tout d’abord une image de fond pour le jeu en l'occurrence une image jpeg convertit au préalable en fichier .bmp et dont les dimensions sont la taille de la matrice x 10. Pour exemple si la matrice gCarte fait 66*66 l’image devra faire 660*660. Chaque case du tableau correspondant à 10 pixels à l’affichage. Pour chaque case du tableau lu par incrémentation en fonction de la valeur une image bmp et placé sur l’emplacement correspondant (échelle, sol, bord du jeu …). Les images placé sont mises dans le fichier media et sont de taille 20*20 dans le but de moins alourdir le chargement de la map (une image couvre 4 cases du tableau gCarte).

Cette fonction contient également un code pour modéliser graphiquement une pièce jaune représentant la pièce dont les coordonnées sont créer de façons aléatoire (voir partie 7).

Pour le graphisme du personnage une image bmp de 30*20 en l'occurrence représentant mario est affiché à l’endroit du pointeur sur le tableau (gDonnées.Boule .X et .Y).

Améliorations envisageable :
 Une des améliorations réalisables et que lorsqu’on appuie sur une touche (gauche, droite, haut, bas …) l’image de mario soit actualisé simplement en remplaçant l’image originale par une autre correspondant au mouvement.
Une autre amélioration à réaliser serait de réaliser la création de la partie map en dehors de la boucle qui actualise en permanence le jeu afin de pouvoir réaliser des maps plus complexes et donc plus lourdes à faire tourner.

### 4. Déplacement de l’avatar
Les déplacements de l’avatar sont basés sur différentes touches du clavier.

Flèche vers le haut: Permet de monter une échelle. Cette dernière ne fonctionne que si l’avatar est positionné sous une échelle. Pour cela on détermine la position de l’avatar dans la matrice grâce à gDonnees.Boule.X et Y puis on regarde si un “1” est placé sur la case supérieur dans la matrice, si c’est le cas l’avatar peut monter d’un cran ( c’est à dire de gincrément).

Flèche du bas: Permet de descendre une échelle. Fonctionne de la même manière que la flèche du haut mais en regardant si l’avatar possède un “1” dans la case en dessous de sa position dans la matrice.

Flèche de droite: Permet de se déplacer de gincrément vers la droite. Cette action ne peut se faire que s’il n’y a pas de “3” dans la case à la droite de la position de l’avatar dans la matrice. Ceci permet à l’avatar de ne pas sortir de la map.

Flèche de gauche: Permet de se déplacer de gincrément vers la gauche. Cette action ne peut se faire que s’il n’y a pas de “3” dans la case à la gauche de la position de l’avatar dans la matrice. Ceci permet à l’avatar de ne pas sortir de la map.

Touche “z”: Permet de faire un saut de 2xgincrément de haut.

Touche “a”: Permet de faire un saut latéral avec une trajectoire parabolique vers la gauche.

Touche “e”: Permet de faire un saut latéral avec une trajectoire parabolique vers la droite.

Si l’avatar est positionné sur une case au dessus d’un “0” dans la matrice alors la vitesse vertical de ce dernier devient non nul, lui permettant de chuter jusqu’à atteindre le sol ou une plateforme.

### 5. Minuteur
En utilisant la fonction time() nous pouvons déterminer combien de temps il s’est écoulé depuis une date précise.
Il suffit donc d’initialiser une variable timer puis de créer une variable de transition temps valant time() et finalement faire l’opération suivante à chaque itérations : timer-(time()-temps) pour obtenir un minuteur partant de la valeur initiale et décroissant jusqu’à zéro.

### 6. Ecran de fin
Concernant l’écran de fin de jeu la fonction void DessinApresCoup() est écrite dans le fichier u2-dessins.cpp. 
Elle permet simplement d'afficher une image noir de la taille de la map puis d’afficher par dessus une image bmp affichant game over.
Cette fonction est appelée dans la fonction void TraiterCycleCB() elle même appelé par le main. Elle est déclenchée quand gDonnees.Temps prend la valeur de 0, soit quand le timer arrive à la fin.
Améliorations envisageable :
Il serait également possible d’enregistrer le nom du joueur dans le même fichier et de pouvoir l’afficher sur l’interface graphique quand le jeu est lancer.

### 7. Création pièce
On donne à la pièce la même structure que la structure de boule initiale avec donc une vitesse en abscisse, une position en abscisse etc…
La position de la première pièce est donnée dans initialisé donné. Elle est créée de manière aléatoire. Le déplacement et la création de la pièce se passe dans la fonction DeplacerPiece. Elle est similaire à la fonction déplacer boule tant que le joueur n’est pas sur la pièce. 

Lorsque le joueur est sur la pièce, une nouvelle pièce apparaît. Sa position est créée de manière aléatoire. Une boucle interdit que la position de la pièce soit à l'intérieur d’une plateforme ou sur un bord et donne une autre position à la pièce tant que c’est la cas. 
Si la pièce est dans le vide ie s’il y a un zéro en dessous d’elle, la pièce tombe avec une vitesse de 2 fois gIncrement. Cela permet que le joueur puisse toujours récupérer la pièce. 

### 8. Musique
La musique est téléchargé en format mp3 puis importé dans le fichier média. 
Il suffit ensuite d’appliquer la fonction jouerson lorsque ceci est demandé (lors d’un saut, d’un gain de point, ou de l’activation d’un des boutons radio).

### 9. Incrémentation et conservation du meilleur score
Le score augmente lorsque le joueur est sur la même position que la pièce avec une marge de 20 pixels. Cela se passe dans la fonction  DeplacerPiece dans le fichier u4. Il y a 2  variables qui représente le score: score et gDonnes.Valeur. 
La variable bestscore prend la valeur du meilleur score précédent.

 Pour cela, la valeur du meilleur score précédent est stocké dans une fichier .txt nommé bestscore.txt. Lors de l’initialisation de donné, on lit le fichier et la variable bestscore prend la valeur du fichier. On peut ensuite l’afficher dans l’interface.
La fonction permettant d’enregistrer le meilleur score réalisé sur le jeu et dans le fichier u4-fonction.cpp et se nomme void meilleurScore().

Elle est déclenché quand la variable gDonnes.Temps prend la valeur 0 et que affiche_game_over =0 dans la fonction traiter_cycle. La variable affiche_game_over est une variable utilitaire qui permet de n'appeler qu’une seul fois par parti la fonction meilleurScore. En effet, sinon elle était appelé plusieurs fois. 
La fonction meilleurScore consiste en l’écriture du meilleur score dans un fichier texte si le score affiché est plus haut que le best score enregistré.

### 10. Bouton rejouer
La fonction qui est associé au bouton rejouer est la fonction void BoutonReplayCB(Fl_Widget* w, void* data) écrite dans le fichier u3. Elle réinitialise les donnés, recrée l’interface( pour notamment avoir le nouveau meilleur score) et redessine la fenêtre graphique de jeu.
 Cette fonction est appelé dans la fonction creerInterface. La case bouton rejouer est créé dans la fonction creerInterface. Un temps de latence est observé après avoir appuyer sur le bouton rejouer. Elle dure quelques secondes. 








