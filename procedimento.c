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

#include "procedimento.h"
/*
char                     data[10];
char                     descricao[40];
float                    valor;
int                      codigo;
int                      qtd_procedimento;
Procedimento            *proximo;
*/

static void procedimento_set_data(Procedimento *, char *);
static void procedimento_set_desc(Procedimento *, char *);

Procedimento *
procedimento_novo(void)
{
        char             value[1024];
        Procedimento    *p = NULL;

        if ((p = malloc(sizeof(Procedimento))) == NULL)
                return NULL;

        printf("Digite a data: ");
        if (fgets(value, sizeof(value), stdin) != NULL)
                value[strcspn(value, "\n")] = '\0';

        procedimento_set_data(p, value);

        printf("Digite a descricao: ");
        if (fgets(value, sizeof(value), stdin) != NULL)
                value[strcspn(value, "\n")] = '\0';

        procedimento_set_desc(p, value);

        printf("Digite valor: ");
        scanf("%f", &p->valor);

        printf("Digite codigo: ");
        scanf("%d", &p->codigo);

        p->proximo = NULL;
}

void
procedimento_set_desc(Procedimento *p, char *val)
{
        if (p == NULL || strlen(val) <= 0)
                return;

        strncpy(p->descricao, val, sizeof(p->descricao) - 1);
        p->descricao[sizeof(p->descricao) - 1] = '\0';
}

void
procedimento_set_data(Procedimento *p, char *val)
{
        if (p == NULL || strlen(val) <= 0)
                return;

        strncpy(p->data, val, sizeof(p->data) - 1);
        p->data[sizeof(p->data) - 1] = '\0';
}
