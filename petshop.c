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

#include "petshop.h"

/* numero maximo de animais */
#define MAX_ANIMAL 100

static void bubble_sort(Petshop *, int);
static void swap(int *, int *);

void
petshop_inserir_animal(Petshop *p, Animal a)
{
        /* checamos se nao esta cheio */
        if (p->qtd_animais < MAX_ANIMAL) {
                p->animais[p->qtd_animais] = a;
                p->qtd_animais++;
                bubble_sort(p, p->qtd_animais);
        }
}

void
petshop_listar_animal(Petshop *p)
{
        int count = 0;

        /* checamos se nao esta cheio */
        if (p->qtd_animais > 0 && count <= p->qtd_animais) {
                Animal a = p->animais[count];
                printf("Reg: [%d] Apelido: %s\n", a.num_reg, a.apelido);
                count++;
        }
}

static void
swap(int *xp, int *yp)
{
    int temp = *xp;

    *xp = *yp;
    *yp = temp;
}

static void
bubble_sort(Petshop *p, int n)
{
        int i;
        int j;

        for (i = 0; i < n-1; i++)
                for (j = 0; j < n-i-1; j++)
                        if (p->animais[j].num_reg > p->animais[j+1].num_reg)
                                swap(&p->animais[j].num_reg,
                                    &p->animais[j+1].num_reg);
}
