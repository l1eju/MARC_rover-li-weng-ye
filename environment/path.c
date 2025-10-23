//
// Created by wengj on 21/11/2024.
//

#include "path.h"
/**
 * @brief Trouve toutes les feuilles de val min dans l'arbre
 * @param node Nœud racine de l'arbre
 * @param len Pointeur pour stocker le nb de feuilles trouvées
 * @return Tableau de pointeurs des feuilles de valeur minimale
 */
p_node* tab_of_min(p_node node, int* len){

    int min_val = search_min_node(node); //Cherche la val min dans l'arbre
    p_node* min_leaf = (p_node*) malloc(MAX * sizeof(p_node));//Tableau où stocker les feuilles de val min

    t_queue_tab q;
    p_node cur;
    q = createEmptyQueue(); //File pour parcourir l'arbre en largeur
    enqueue_node(&q, node);// Ajoute le noeud racine dans la file

    while (q.first != q.last){ //Tant que file non vide
        cur = dequeue_node(&q); //Retirer un noeud de la file

        if(cur->value == min_val){ //Si le noeud est la val min
            int depth_of_min = cur->depth;//La profondeur du min est la profondeur actuel

            while (cur->depth == depth_of_min && q.first != q.last) {//Tant que l'on a pas fini de parcourir la file et que la profondeur du min est la profondeur actuel (quasiment impossible)

                if(cur->value == min_val){ //Si la val de cur est la val_min
                    min_leaf[(*len)++] = cur; //Ajoute cur dans le tableau de feuille de val min et incrémente
                }
                cur = dequeue_node(&q); //Passe au noeud suivant dans la file si elle existe
            }
            min_leaf[(*len)++] = cur;

            return min_leaf; //Retourne le tab de feuilles de val min trouvées
        }
        else if (cur->nbSons != 0){//Si le noeud a des fils, on ajoute chaque fils dans la file
            for (int i = 0; i < cur->nbSons; i++) {
                if (cur->sons[i] != NULL){
                    enqueue_node(&q,cur->sons[i]);
                }
            }
        }
    }
    return NULL;//Si aucune feuille trouvée, retourne NULL
}

p_node min_leaf(t_tree t) {
    return min_leaf_node(t.root);//Appelle de la fonction min_leaf_mode en partant de la racine
}

/**
 * @brief Trouve la feuille ayant le coût total le plus optimale du chemin pour arriver jusque lui depuis la position de MARC à partir d'un noeud
 * @param node Nœud racine de l'arbre
 * @return Retourne la feuille de valeur minimale et ayant le parcours le parcours le plus optimal
 */
p_node min_leaf_node(p_node node){
    int len = 0, cheaper = 10000, idx;//Stocke le nb de feuille de val min, le coût total du parcours de la feuille parcouru et le coût le moins élevé
    p_node* tab_min = tab_of_min(node, &len); //Prend toutes les feuilles de val min

    for (int i = 0; i < len; i++){  //Parcours toutes les feuilles pour calculer leur coût de parcours total
        int cost = 0; //Coût total pour le chemin de cette feuille
        p_node cur = tab_min[i];
        while (cur != NULL) {   //Tant que cur n'est pas NULL on parcours
            cost += cur->value; //Additionne la val du noeud au coût total de la feuille
            cur = cur->parent;  //Remonte au noeud parent
        }
        if (cost < cheaper){    //Si le coût de la feuille est inférieur au coût minimum trouvé
            cheaper = cost; //On remplace le coût minimum par le coût de la feuille
            idx = i;    //Stocke l'indice de la feuille avec le parcours le plus optimal (moins chère)
        }
    }
    return tab_min[idx]; //Retourne la feuille de valeur minimale et ayant le parcours le parcours le plus optimal
}

/**
 * @brief Donne le meilleur chemin (mouvements à effectuer) pour atteindre la feuille de coût min
 * @param t Arbre n-aires
 * @param len Pointeur pour stocker le nb de mouvement
 * @return Tableau de mouvement
 */
t_move* best_path(t_tree t, int *len){
    p_node leaf = min_leaf(t);  // On commence par trouver la feuille avec le coût total minimal dans l'arbre

    int depth = leaf->depth;    // On stocke la profondeur de la feuille de la val min
    *len = depth;   //Nombre de mouvement à effectuer (longueur du tab de mouvement retourné)
    t_move* path = (t_move*) malloc((depth) * sizeof(t_move));  //Stock les mouvements à effectuer pour le parcours le plus optimisé

    for (int i = depth - 1; i >= 0; i--){   //Parcourt le chemin de la feuille jusqu'à la racine
        path[i] = leaf->mouvement; //Stocke le mouvement associé au noeud de la fin du tableau au début (car on part de la base et remonte à MARC avec la feuille)
        leaf = leaf->parent;    //On continue de remonter en passant par le parent du noeud
    }
    return path;//Retourne tab des mouvements avec le meilleur chemin
}
