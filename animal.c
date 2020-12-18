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
#include <string.h>

#include "animal.h"

void animal_set_apelido(Animal *, char *);

/*
 * Gera um novo animal
 */
void
animal_novo(Animal *a)
{

        /* setamos o apelido do animal */
        animal_set_apelido(a, NULL);

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
animal_set_apelido(Animal *a, char *val)
{
        if (a == NULL)
                return;

        printf("Digite o apelido: ");
        if (fgets(a->apelido, sizeof(a->apelido), stdin) != NULL)
                a->apelido[strcspn(a->apelido, "\n")] = '\0';
}
