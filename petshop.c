#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "animal.h"

/* numero maximo de animais */
#define MAX_ANIMAL 100

/*
 * Estrutura Petshop
 */
typedef struct petshop_t {
        Animal  animais[MAX_ANIMAL];
        int     qtd_animais;
} Petshop;

void petshop_inserir_animal(Petshop *, Animal);

int
main(int argc, char *argv[])
{
        Petshop meupet;

        /* inicializamos nosso pet */
        meupet.qtd_animais = 0;

        /* inserindo um novo animal */
        Animal a;
        animal_novo(&a);

        /* inserir animal no petsthop */
        petshop_inserir_animal(&meupet, a);

        return (0);
}


void
petshop_inserir_animal(Petshop *p, Animal a)
{
        /* checamos se nao esta cheio */
        if (p->qtd_animais <= MAX_ANIMAL) {
                p->animais[p->qtd_animais] = a;
                p->qtd_animais++;

                printf("Animal: %s inserido com sucesso\n", a.apelido);
        }
}
