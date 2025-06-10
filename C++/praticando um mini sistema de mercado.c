#include <stdio.h>
#include <stdlib.h>

void aloca(float **p, int tam);
float calculaTotal(float *p, int tam);

int main() {
    char continuar;

    do {
        float *precos = NULL;
        int qtdProdutos = 0;
        float preco;

        printf("Lojas Dos Manos\n\n");

        while (1) {
            printf("Produto %d: R$ ", qtdProdutos + 1);

            scanf("%f", &preco);

            if (preco < 0) {
                printf("\nPreco nao pode ser negativo! Tente novamente.\n");
                continue;
            }

            aloca(&precos, qtdProdutos + 1);
            precos[qtdProdutos] = preco;//cria array para armazenar valores
            qtdProdutos++;

            // Pergunta ao usuário se deseja continuar
            printf("Deseja adicionar mais um produto? (S/N): ");
            while (1) {
                scanf(" %c", &continuar);
                if (continuar == 'S' || continuar == 's' || continuar == 'N' || continuar == 'n') {
                    break;
                } else {
                    printf("Opcao invalida! Digite S para sim ou N para nao: ");
                }
            }

            if (continuar == 'N' || continuar == 'n') {
                break; // Encerra o loop de produtos
            }
        }

        if (qtdProdutos == 0) {
            printf("\nNenhum produto foi registrado.\n");
            continue;
        }

        // Exibe o total
        float total = calculaTotal(precos, qtdProdutos);
        printf("\nTotal: R$ %.2f\n", total);

        // Recebe o valor em dinheiro e calcula o troco
        float dinheiro;
        while (1) {
            printf("Dinheiro: R$ ");
            scanf("%f", &dinheiro);
            if (dinheiro < total) {
                printf("\nValor invalido ou insuficiente. Tente novamente.\n");
                while (getchar() != '\n'); // Limpa o buffer
                continue;
            }
            break;
        }

        float troco = dinheiro - total;
        printf("Troco: R$ %.2f\n", troco);

        // Libera a memória alocada dinamicamente
        free(precos);

        // Pergunta se o usuário deseja iniciar uma nova compra
        printf("\nDeseja iniciar uma nova compra? (S/N): ");
        while (1) {
            scanf(" %c", &continuar);
            if (continuar == 'S' || continuar == 's' || continuar == 'N' || continuar == 'n') {
                break;
            } else {
                printf("Opção invalida! Digite S para sim ou N para nao: ");
            }
        }

    } while (continuar == 'S' || continuar == 's');

    printf("\nObrigado por usar o sistema!,at\x82 a proxima na cara dos manos\n");

    return 0;
}

// =================== FUNÇÕES ===================

// Aloca ou realoca memória para armazenar os preços
void aloca(float **p, int tam) {
    *p = (float *)realloc(*p, tam * sizeof(float));
    if (*p == NULL) {
        printf("\nErro na alocacaoo de memoria!\n");
        exit(1);
    }
}

// Calcula o valor total dos produtos
float calculaTotal(float *p, int tam) {
    float total = 0;
    for (int i = 0; i < tam; i++) {
        total = total + p[i];
    }
    return total;
}
