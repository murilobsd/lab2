#include <stdio.h>
#include <string.h>

#include "animal.h"

/*
 * Gera um novo animal
 */
void
animal_novo(Animal *a)
{

        printf("Digite o apelido: ");
        if (fgets(a->apelido, sizeof(a->apelido), stdin) != NULL)
                a->apelido[strcspn(a->apelido, "\n")] = '\0';

        printf("Digite o nome do dono: ");
        if (fgets(a->nome_dono, sizeof(a->nome_dono), stdin) != NULL)
                a->nome_dono[strcspn(a->nome_dono, "\n")] = '\0';

        printf("Digite a raca: ");
        if (fgets(a->raca, sizeof(a->raca), stdin) != NULL)
                a->raca[strcspn(a->raca, "\n")] = '\0';

        printf("Digite a cor: ");
        if (fgets(a->cor, sizeof(a->cor), stdin) != NULL)
                a->cor[strcspn(a->cor, "\n")] = '\0';

        printf("Digite a idade: ");
        scanf("%d", &a->idade);

        printf("Digite o numero de registro: ");
        scanf("%d", &a->num_reg);
}
