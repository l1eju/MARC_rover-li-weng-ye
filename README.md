# PROJET C : MARC_rover 🤖
**Étudiante 1:** Hélène LI  
**Étudiante 2:** Julie WENG  
**Étudiante 3:** Emma YE  

**Lien dépôt GIT :** https://github.com/l1eju/MARC_rover-li-weng-ye.git

---

## Explication du projet :
 Le projet a pour but de permettre à **MARC**, un rover ayant été victime d'un dysfonctionnement sur la planète MARS, de rentrer à une station Base pour pouvoir la réparer.  
 Il possède encore son radar et son gyroscope pour lui permettent de se situer.  
 Il se repère donc par sa position, et la direction à laquelle il fait face, parmi Nord, Sud, Est et Ouest (même sur Mars).  
 N'ayant plus qu'un nombre limité de mouvement, 9 mouvements unitaires restants par cycle, MARC ne peut qu'en utilisé 5 par cycle pour pouvoir rentrer chez lui.  
 Il va donc falloir programmer le « meilleur choix possible » de déplacement.

---

## Fonctionnalités principales :

Voici ci-dessous l'ensemble des fonctions/fonctionnalités faites :

### TREE :
- Définition de la structure de l'arbre et des nœuds  
- Création d'un nœud  
- Construction d'un arbre n-aire  
- Recherche de la valeur minimale de tout l'arbre  
- Complexité phase de construction de l'arbre : O((n!)²)
 
### NODE_QUEUE :
- Fonction de file pour les nœuds  
- Création d'une file vide  
- Ajout d'un nœud dans la file  
- Retirer un nœud de la file

### PATH :
- Recherche de la feuille de valeur minimale  
- Parcours en largeur pour trouver tous les nœuds ayant la valeur minimale  
- Calcul du coût total du chemin pour arriver à chaque noœud minimal  
- Choix du noœud ayant le coût optimal  
- Définition du chemin optimal  
- Définir les mouvements à effectuer pour avoir le parcours le plus optimal  
- Complexité phase de recherche d'une feuille de valeur minimale parmi toutes les feuilles de l'arbre : O((n!)²)  
- Complexité du calcul du chemin de la racine vers cette feuille : O(n)

---

### Nous tenons à remercier le département Informatique de l'Efrei ainsi que Monsieur *Nicolas FLASQUE* pour la conception du projet et la mise à disposition des fichiers initiaux (gestion de file, pile, etc.) indispensables au développement du projet.  
### Nous remercions particulièrement Monsieur *Safwan CHENDEB* pour son suivi et ses conseils lors de la conception du projet ainsi que son retour pédagogique lors de notre soutenance.

Merci ! 😁  
**Hélène LI** – **Julie WENG** – **Emma YE**
