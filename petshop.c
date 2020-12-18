#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* numero maximo de animais */
#define MAX_ANIMAL 100

/*
 * Estrutura Procedimento
 */
typedef struct procedimento_t {
        char                     data[10];
        char                     descricao[40];
        float                    valor;
        int                      codigo;
        int                      qtd_procedimento;
        struct procedimento_t   *proximo;
} Procedimento;

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

/*
 * Estrutura Petshop
 */
typedef struct petshop_t {
        Animal  animais[MAX_ANIMAL];
        int     qtd_animais;
} Petshop;

void petshop_inserir_animal(Petshop *, Animal);
void animal_novo(Animal *);

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
