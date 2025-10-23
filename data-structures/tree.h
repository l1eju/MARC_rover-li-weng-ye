//
// Created by wengj on 22/10/2024.
//

#ifndef UNTITLED1_TREE_H
#define UNTITLED1_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "../environment/map.h"
#include "../environment/moves.h"

#define NB_possibilities 9
#define NB_choices 5
#define MAX 18730

//Structure représentant un noeud dans l'arbre
typedef struct s_node
{
    int value; //coût de la val associé à ce noeud
    int depth; //profondeur de l'abre
    t_move mouvement; // mouvement menant au noeud actuel
    t_soil soil_type; // type de sol
    struct s_node *parent; //pointeur vers parents
    struct s_node **sons; //pointeur tableau des fils
    int nbSons; // Taille physique du tableau
} t_node;

typedef struct s_node t_node, *p_node;//Définition du noeud et du pointeur vers un noeud

typedef struct s_tree //Structure représentant un arbre complet
{
    p_node root; //racine de l'arbre
} t_tree;



t_move* remove_move(t_move*, int, int); //Supprime un mouvement du tableau des possibilités

p_node createNode(int nb_sons, int depth, t_move mouvement, t_localisation loc, t_map map, p_node node);//Création d'un nouveau nœud dans l'arbre.

p_node create_all_Node(int nb_poss, int depth, t_move mouvement, t_move* possibilities, t_localisation robot, t_map map, p_node parent_node);//Création de tous les nœuds récursivement.

t_tree create_tree(t_move* possibilities, t_localisation robot, t_map map); //Création de l'arbre complet à partir des possibilités de base.

int search_min(t_tree);// Cherche la valeur minimale dans l'arbre.

int search_min_node(p_node node); //Cherche la valeur minimale à partir d'un noeud.

int nb_min(t_node *node, int min); //Fonction bonus qui compte le nombre de nœuds ayant une valeur minimale

#endif //UNTITLED1_TREE_H
