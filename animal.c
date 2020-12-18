/*
 * Copyright (c) 2020 Murilo Ijanc' <mbsd@m0x.ru>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "animal.h"

static void animal_set_apelido(Animal *, char *);
static void animal_set_nome_dono(Animal *, char *);
static void animal_set_raca(Animal *, char *);
static void animal_set_cor(Animal *, char *);

/*
 * Gera um novo animal
 */
void
animal_novo(Animal *a)
{
        char value[1024];

        printf("Digite o apelido: ");
        if (fgets(value, sizeof(value), stdin) != NULL)
                value[strcspn(value, "\n")] = '\0';

        /* setamos o apelido do animal */
        animal_set_apelido(a, value);

        printf("Digite o nome do dono: ");
        if (fgets(value, sizeof(value), stdin) != NULL)
                value[strcspn(value, "\n")] = '\0';

        /* setamos o nome do dono do animal */
        animal_set_nome_dono(a, value);

        printf("Digite a raca: ");
        if (fgets(value, sizeof(value), stdin) != NULL)
                value[strcspn(value, "\n")] = '\0';

        /* setamos a raca do animal */
        animal_set_raca(a, value);

        printf("Digite a cor: ");
        if (fgets(value, sizeof(value), stdin) != NULL)
                value[strcspn(value, "\n")] = '\0';

        /* setamos a raca do animal */
        animal_set_cor(a, value);

        printf("Digite a idade: ");
        scanf("%d", &a->idade);

        printf("Digite o numero de registro: ");
        scanf("%d", &a->num_reg);
}

void
animal_set_cor(Animal *a, char *val)
{
        if (a == NULL || strlen(val) <= 0)
                return;

        strncpy(a->cor, val, sizeof(a->cor) - 1);
        a->cor[sizeof(a->cor) - 1] = '\0';
}

void
animal_set_raca(Animal *a, char *val)
{
        if (a == NULL || strlen(val) <= 0)
                return;

        strncpy(a->raca, val, sizeof(a->raca) - 1);
        a->raca[sizeof(a->raca) - 1] = '\0';
}

void
animal_set_apelido(Animal *a, char *val)
{
        if (a == NULL || strlen(val) <= 0)
                return;

        strncpy(a->apelido, val, sizeof(a->apelido) - 1);
        a->apelido[sizeof(a->apelido) - 1] = '\0';
}

void
animal_set_nome_dono(Animal *a, char *val)
{
        if (a == NULL || strlen(val) <= 0)
                return;

        strncpy(a->nome_dono, val, sizeof(a->nome_dono) - 1);
        a->nome_dono[sizeof(a->nome_dono) - 1] = '\0';
}
