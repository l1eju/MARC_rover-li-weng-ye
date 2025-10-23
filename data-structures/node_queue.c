//
// Created by wengj on 21/11/2024.
//

#include "node_queue.h"

//Fonction de queue pour p_node
/** @brief Crée une file vide
*/
t_queue_tab createEmptyQueue() //Initialise une file vide (FIFO) et return une file vide de type t_queue_tab
{
    t_queue_tab q;
    q.first = q.last = 0; //Initialise la file à vide, first & last valent 0
    return q;
}

/** @brief Ajoute un noeud dans la file
 * @param pq Pointeur vers la file où le noeud doit être ajouté
 * @param val Noeud à insérer
*/
void enqueue_node(t_queue_tab *pq, p_node val) //Ajoute val, le noeud de type p_node à la fin de la file
{
    int pos;
    pos = pq->last % MAX;   //Calcule pour trouver l'indice du tableau où ajouter le noeud
    pq->values[pos] = val; //Insère le noeud à cette position
    pq->last = pq->last + 1; //Incrémente last après l'ajout
}

/** @brief Retire et retourne un noeud de la file
 * @param pq Pointeur vers la file où le noeud doit être retiré
 * @return Noeud retiré de la file
*/
p_node dequeue_node(t_queue_tab *pq)
{
    p_node res;
    int pos = pq->first % MAX; //Calcule pour trouver l'indice du tableau où retirer le noeud
    res = pq->values[pos]; //Retire le noeud à cette position
    pq->first = pq->first + 1; //Incrémente first après l'ajout
    return res;
}