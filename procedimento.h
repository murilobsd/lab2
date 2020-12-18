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
