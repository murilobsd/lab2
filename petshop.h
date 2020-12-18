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
