#include "procedimento.h"

/*
 * Estrutura Animal
 */
typedef struct animal_t {
        char             apelido[20];
        char             cor[10];
        char             nome_dono[40];
        char             raca[10];
        int              idade;
        int              num_reg;
        Procedimento    *procedimento;
} Animal;

void animal_novo(Animal *);
