#include <stdio.h>
#include "environment/map.h"
#include "environment/path.h"
#include "environment/moves.h"

int main() {

    t_map map;
    int val = 0, r;
    printf("You are going to choose a map : \n");

    printf("Choose between 1 2 3 or press any other number to exit (0 to test)\n");
    scanf("%d",&val);

    if (val == 0 || val == 1) map = createMapFromFile("..\\maps\\example1.map");
    else if (val == 2) map = createMapFromFile("..\\maps\\example2.map");
    else if (val == 3) map = createMapFromFile("..\\maps\\example3.map");
    else return 0;

    printf("Map created with dimensions %d x %d\n", map.y_max, map.x_max);
    for (int i = 0; i < map.y_max; i++) {
        for (int j = 0; j < map.x_max; j++) {
            printf("%d ", map.soils[i][j]);
        }
        printf("\n");
    }

    // printf the costs, aligned left 5 digits
    for (int i = 0; i < map.y_max; i++) {
        for (int j = 0; j < map.x_max; j++) {
            printf("%-5d ", map.costs[i][j]);
        }
        printf("\n");
    }

    displayMap(map);

    int x, y;
    t_orientation ori;

    if (!val) {
        x = 4;
        y = 6;
        ori = NORTH;
    }
    else {
        printf("Please enter MARC inital position \n");

        do {
            do {
                printf("MARC x position (between 0 and %d)\n", map.x_max - 1);
                r = scanf("%d", &x);

                if (r != 1) {
                    while (getchar() != '\n'); // Pour éviter un cycle infini si l'entrée est invalide
                }
            } while (x < 0 || x > map.x_max - 1 || r != 1);
            do {
                printf("MARC y position (between 0 and %d)\n", map.y_max - 1);
                r = scanf("%d", &y);

                if (r != 1) {
                    while (getchar() != '\n'); // Pour éviter un cycle infini si l'entrée est invalide
                }
            } while (y < 0 || y > map.y_max - 1 || r != 1);

            if (map.costs[y][x] >= 10000) printf("The position is invalid, MARC is on a CREVASSE\n");
        } while (map.costs[y][x] >= 10000); //Si on est sur une crevasse on recommence

        int choice;

        do {
            printf("Enter MARC orientation number\n");
            printf("[NORTH : 1] [EAST : 2] [SOUTH : 3] [WEST : 4] \n");
            r = scanf("%d", &choice);
            if (r != 1) {
                while (getchar() != '\n'); // Pour éviter un cycle infini si l'entrée est invalide
            }
        } while (choice < 1 || choice > 4 || r != 1);

        if (choice == 1) ori = NORTH;
        else if (choice == 2) ori = EAST;
        else if (choice == 3) ori = SOUTH;
        else ori = WEST;
    }

    t_position base = getBaseStationPosition(map);
    t_localisation MARC = loc_init(x, y, ori);

    if (MARC.pos.x == base.x && MARC.pos.y == base.y) printf("MARS is already at home!");
    else{
        t_move *moves;
        int loop = 0, total_moves = 0, nb_move;

        do{
            loop++;
            moves = getRandomMoves(NB_possibilities);
            if (moves == NULL){
                printf("MARC ran out of movements and can't get home...\n");
                exit(EXIT_FAILURE);
            }
            t_tree tree = create_tree(moves, MARC, map);

            printf("Here are the possible for the %d loop(s) movements : \n[ ", loop);
            for (int j = 0; j < NB_possibilities; j++) {
                printf("%s ", getMoveAsString(moves[j]));
                if (j < NB_possibilities - 1) {
                    printf("; ");
                }
            }
            printf("]\n");

            t_move *path = best_path(tree, &nb_move);

            printf("The movement(s) required to arrive at the nearest point to the base : [");
            for (int j = 0; j < nb_move; j++) {
                printf("%s ", getMoveAsString(path[j]));
                updateLocalisation(&MARC, path[j]);
                if (j < nb_move) {
                    printf("; ");
                }
            }
            printf("]\n\n");

            total_moves += nb_move;
        } while (MARC.pos.x != base.x || MARC.pos.y != base.y);

        printf("MARS needed %d move(s) and %d loop(s) to arrive.\n", total_moves, loop);
        printf("Welcome Home MARC!\n");
    }

    return 0;
}