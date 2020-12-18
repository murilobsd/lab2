#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "petshop.h"

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
