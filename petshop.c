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
