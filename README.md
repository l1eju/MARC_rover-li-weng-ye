PROJET C : MARC_rover
Étudiant 1: Hélène LI
Étudiant 2: Julie WENG
Étudiant 3: Emma YE

Lien dépôt GIT : https://github.com/l1eju/MARC_rover-li-weng-ye.git

Explication du projet :
 Le projet a pour but de permettre à MARC, un rover ayant été victime d'un dysfonctionnement sur la planète MARS, de rentrer à une station base pour pouvoir la réparer.
 Il possède encore son radar et son gyroscope pour lui permettent de se situer.
 Il se repère donc par sa position, et la direction à laquelle il fait face, parmi Nord, Sud, Est et Ouest (même sur Mars).
 N'ayant plus qu'un nombre limité de mouvement, 9 mouvements unitaire restants, MARC ne peut qu'en choisir 5 pour pouvoir rentrer chez lui.
 Il va donc falloir programmer le « meilleur choix possible » de déplacement.

Fonctionnalités principales :

Voici ci-dessous l'ensemble des fonctions/fonctionnalités faites :

TREE :
 Définition de la structure de l'arbre et des noeuds
 Création d'un noeud
 Construction d'un arbre n-aires
 Recherche de la valeur minimale de tout l'arbre
 Complexité phase de construction de l'arbre : O((n!)²)
 
NODE_QUEUE :
Fonction de file pour les noeuds
 Création d'une file vide
 Ajout d'un noeud dans la file
 Retirer un noeud de la file

PATH :
Recherche de la feuille de valeur minimale
 Parcours en largeur pour trouver tous les noeuds ayant la valeur minimale
 Calcul du coût total du chemin pour arriver à chaque noeud minimal
 Choix du noeud ayant le coût optimal
Définition du chemin optimal
 Définir les mouvements à effectuer pour avoir le parcours le plus optimal
 Complexité phase de recherche d'une feuille de valeur minimale parmi toutes les feuilles de l'arbre : O((n!)²)
 Complexité du calcul du chemin de la racine vers cette feuille : O(n)
Merci !

Hélène LI, Julie WENG et Emma YE
