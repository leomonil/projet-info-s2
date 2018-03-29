# Rapport programmeur � programmeur
## I Pr�sentation du jeu.
Notre jeu est un jeu � plateforme fixe type load runner. C�est-�-dire que lors du lancement du jeu, une carte constitu� d'�chelle et de plateforme flottante appara�t.
 Le joueur incarne un avatar en forme de mario qui peut se d�placer uniquement sur les plateforme et peut monter uniquement � travers les �chelles.

 Lorsque le personnage n�est pas sur une plateforme ou une �chelle, il tombe jusqu�� �tre sur une plateforme ou une �chelle. Le joueur peut appuyer sur �e� pour sauter et aller � droite en m�me temps, �a� pour faire de m�me mais � gauche et �z� pour sauter droit. Pour se d�placer en haut, en bas, � droite, � gauche, le joueur peut utiliser les touches directionnels.
Des pi�ces apparaissent al�atoirement sur la carte (au dessus des plateformes ou sur le sol) et le but est que notre avatar en ramasse le plus possible.

 Pour ramasser des pi�ces, il suffit d��tre dessus. Dans l�interface du jeu, le nombre de pi�ces r�cup�r�s depuis le d�but de la partie est affich�. Le meilleur score r�alis� sur ce PC est aussi affich� en dessous. Un minuteur est affich� dans l�interface et lorsque celui est nul, le jeu s'arr�te. Il y a donc un �cran noir o� il est affich� une image �game over�. 
On peut rejouer une partie en cliquant sur la case rejou� en bas � gauche de l�interface. 
Une musique peut-�tre activ� en cliquant sur la case radio 1 dans l�interface. Il y a alors une musique de fond et un son lors des sauts.

## II Pr�sentation du code
### 1. Pr�sentation g�n�ral du code
Le code de base permet de cr�er une fen�tre graphique avec une interface, le tout s�actualisant r�guli�rement (15 ms). Le main permet de lancer la boucle dans lequel le programme va s'effectuer. Le fichier u1 permet de cr�er l�interface et de lancer le programme qui permet de l�actualiser. Le fichier u2-dessin permet de dessiner tous les cycles la carte actualiser.

Chaque fonction est �crite dans son fichier.cpp correspondant et est externalis� � l�aide des fichiers .h. De la m�me fa�on toutes les variables cr��es sont externalis�es dans le fichier u4-fonctions.h. Les variables externes sont toutes initialis�es dans la fonction void InitialiserDonnees.

### 2. Lecture de la carte
Cr�er la carte se fait en excel, qui est ensuite converti en fichier texte. La carte est une matrice de 66 par 66 contenant 0 pour le vide, 1 pour les plateformes, 2 pour les �chelles et 3 pour les bords du jeu. Le fichier .txt contenant la carte doit �tre ins�rer dans le fichier global (ne pas le mettre dans media par exemple) et doit �tre appel� fond. Il faudra sinon renommer le fichier � ouvrir dans la fonction void lire_fond(char* nom_fichier) qui permet d�ouvrir le fichier .txt et de cr�er une matrice 2x2 de la taille de la carte nomm� gCarte[ ][ ]. 
gCarte est d�clar� en int et de LIGNE ligne et de COLONNE  colonne. LIGNE et COLONNE sont d�finis dans u4.h.  La fonction lire_fond permet de rentrer toute les valeurs du fichier .txt dans la matrice gCarte. Une fois cette matrice compl�ter, elle est externaliser et il suit donc la conception graphique de la map.

### 3. Graphisme de la carte et du joueur
L�int�gralit� de la conception graphique de la map et du personnage est r�alis� dans le fichier u2-dessin.cpp. 

Concernant la partie cr�ation de la map la fonction est  void ZoneDessinDessinerCB( Fl_Widget* widget, void* data ). On ouvre tout d�abord une image de fond pour le jeu en l'occurrence une image jpeg convertit au pr�alable en fichier .bmp et dont les dimensions sont la taille de la matrice x 10. Pour exemple si la matrice gCarte fait 66*66 l�image devra faire 660*660. Chaque case du tableau correspondant � 10 pixels � l�affichage. Pour chaque case du tableau lu par incr�mentation en fonction de la valeur une image bmp et plac� sur l�emplacement correspondant (�chelle, sol, bord du jeu �). Les images plac� sont mises dans le fichier media et sont de taille 20*20 dans le but de moins alourdir le chargement de la map (une image couvre 4 cases du tableau gCarte).

Cette fonction contient �galement un code pour mod�liser graphiquement une pi�ce jaune repr�sentant la pi�ce dont les coordonn�es sont cr�er de fa�ons al�atoire (voir partie 7).

Pour le graphisme du personnage une image bmp de 30*20 en l'occurrence repr�sentant mario est affich� � l�endroit du pointeur sur le tableau (gDonn�es.Boule .X et .Y).

Am�liorations envisageable :
 Une des am�liorations r�alisables et que lorsqu�on appuie sur une touche (gauche, droite, haut, bas �) l�image de mario soit actualis� simplement en rempla�ant l�image originale par une autre correspondant au mouvement.
Une autre am�lioration � r�aliser serait de r�aliser la cr�ation de la partie map en dehors de la boucle qui actualise en permanence le jeu afin de pouvoir r�aliser des maps plus complexes et donc plus lourdes � faire tourner.

### 4. D�placement de l�avatar
Les d�placements de l�avatar sont bas�s sur diff�rentes touches du clavier.

Fl�che vers le haut: Permet de monter une �chelle. Cette derni�re ne fonctionne que si l�avatar est positionn� sous une �chelle. Pour cela on d�termine la position de l�avatar dans la matrice gr�ce � gDonnees.Boule.X et Y puis on regarde si un �1� est plac� sur la case sup�rieur dans la matrice, si c�est le cas l�avatar peut monter d�un cran ( c�est � dire de gincr�ment).

Fl�che du bas: Permet de descendre une �chelle. Fonctionne de la m�me mani�re que la fl�che du haut mais en regardant si l�avatar poss�de un �1� dans la case en dessous de sa position dans la matrice.

Fl�che de droite: Permet de se d�placer de gincr�ment vers la droite. Cette action ne peut se faire que s�il n�y a pas de �3� dans la case � la droite de la position de l�avatar dans la matrice. Ceci permet � l�avatar de ne pas sortir de la map.

Fl�che de gauche: Permet de se d�placer de gincr�ment vers la gauche. Cette action ne peut se faire que s�il n�y a pas de �3� dans la case � la gauche de la position de l�avatar dans la matrice. Ceci permet � l�avatar de ne pas sortir de la map.

Touche �z�: Permet de faire un saut de 2xgincr�ment de haut.

Touche �a�: Permet de faire un saut lat�ral avec une trajectoire parabolique vers la gauche.

Touche �e�: Permet de faire un saut lat�ral avec une trajectoire parabolique vers la droite.

Si l�avatar est positionn� sur une case au dessus d�un �0� dans la matrice alors la vitesse vertical de ce dernier devient non nul, lui permettant de chuter jusqu�� atteindre le sol ou une plateforme.

### 5. Minuteur
En utilisant la fonction time() nous pouvons d�terminer combien de temps il s�est �coul� depuis une date pr�cise.
Il suffit donc d�initialiser une variable timer puis de cr�er une variable de transition temps valant time() et finalement faire l�op�ration suivante � chaque it�rations : timer-(time()-temps) pour obtenir un minuteur partant de la valeur initiale et d�croissant jusqu�� z�ro.

### 6. Ecran de fin
Concernant l��cran de fin de jeu la fonction void DessinApresCoup() est �crite dans le fichier u2-dessins.cpp. 
Elle permet simplement d'afficher une image noir de la taille de la map puis d�afficher par dessus une image bmp affichant game over.
Cette fonction est appel�e dans la fonction void TraiterCycleCB() elle m�me appel� par le main. Elle est d�clench�e quand gDonnees.Temps prend la valeur de 0, soit quand le timer arrive � la fin.
Am�liorations envisageable :
Il serait �galement possible d�enregistrer le nom du joueur dans le m�me fichier et de pouvoir l�afficher sur l�interface graphique quand le jeu est lancer.

### 7. Cr�ation pi�ce
On donne � la pi�ce la m�me structure que la structure de boule initiale avec donc une vitesse en abscisse, une position en abscisse etc�
La position de la premi�re pi�ce est donn�e dans initialis� donn�. Elle est cr��e de mani�re al�atoire. Le d�placement et la cr�ation de la pi�ce se passe dans la fonction DeplacerPiece. Elle est similaire � la fonction d�placer boule tant que le joueur n�est pas sur la pi�ce. 

Lorsque le joueur est sur la pi�ce, une nouvelle pi�ce appara�t. Sa position est cr��e de mani�re al�atoire. Une boucle interdit que la position de la pi�ce soit � l'int�rieur d�une plateforme ou sur un bord et donne une autre position � la pi�ce tant que c�est la cas. 
Si la pi�ce est dans le vide ie s�il y a un z�ro en dessous d�elle, la pi�ce tombe avec une vitesse de 2 fois gIncrement. Cela permet que le joueur puisse toujours r�cup�rer la pi�ce. 

### 8. Musique
La musique est t�l�charg� en format mp3 puis import� dans le fichier m�dia. 
Il suffit ensuite d�appliquer la fonction jouerson lorsque ceci est demand� (lors d�un saut, d�un gain de point, ou de l�activation d�un des boutons radio).

### 9. Incr�mentation et conservation du meilleur score
Le score augmente lorsque le joueur est sur la m�me position que la pi�ce avec une marge de 20 pixels. Cela se passe dans la fonction  DeplacerPiece dans le fichier u4. Il y a 2  variables qui repr�sente le score: score et gDonnes.Valeur. 
La variable bestscore prend la valeur du meilleur score pr�c�dent.

 Pour cela, la valeur du meilleur score pr�c�dent est stock� dans une fichier .txt nomm� bestscore.txt. Lors de l�initialisation de donn�, on lit le fichier et la variable bestscore prend la valeur du fichier. On peut ensuite l�afficher dans l�interface.
La fonction permettant d�enregistrer le meilleur score r�alis� sur le jeu et dans le fichier u4-fonction.cpp et se nomme void meilleurScore().

Elle est d�clench� quand la variable gDonnes.Temps prend la valeur 0 et que affiche_game_over =0 dans la fonction traiter_cycle. La variable affiche_game_over est une variable utilitaire qui permet de n'appeler qu�une seul fois par parti la fonction meilleurScore. En effet, sinon elle �tait appel� plusieurs fois. 
La fonction meilleurScore consiste en l��criture du meilleur score dans un fichier texte si le score affich� est plus haut que le best score enregistr�.

### 10. Bouton rejouer
La fonction qui est associ� au bouton rejouer est la fonction void BoutonReplayCB(Fl_Widget* w, void* data) �crite dans le fichier u3. Elle r�initialise les donn�s, recr�e l�interface( pour notamment avoir le nouveau meilleur score) et redessine la fen�tre graphique de jeu.
 Cette fonction est appel� dans la fonction creerInterface. La case bouton rejouer est cr�� dans la fonction creerInterface. Un temps de latence est observ� apr�s avoir appuyer sur le bouton rejouer. Elle dure quelques secondes. 








