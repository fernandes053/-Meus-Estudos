#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Protótipos
double calcular_funcao(double x);
double calcular_ponto_medio(double inf, double sup);
int ler_double(double *valor);
int ler_int(int *valor);

int main() {
    double limite_inferior, limite_superior, ponto_medio;
    double precisao_alvo = 0.0001;
    int continuar = 1;

    do {
        system("cls"); // (no Linux/Mac use "clear")

        printf("============================================\n");
        printf("--- METODOS NUMERICOS: DICOTOMIA ---\n");
        printf("Equacao: f(x) = x^2 - 4\n");
        printf("Use PONTO para decimais (ex: 0.5)\n");
        printf("============================================\n\n");

        // Entrada validada para 'a'
        printf("Digite o inicio do intervalo (a): ");
        while (!ler_double(&limite_inferior)) {
            printf("Digite o inicio do intervalo (a): ");
        }

        // Entrada validada para 'b'
        printf("Digite o fim do intervalo (b): ");
        while (!ler_double(&limite_superior)) {
            printf("Digite o fim do intervalo (b): ");
        }

        // Verificação de existência de raiz
        if (calcular_funcao(limite_inferior) * calcular_funcao(limite_superior) >= 0) {
            printf("\nERRO: Sinais iguais em f(a) e f(b)!\n");
            printf("Nao ha garantia de raiz neste intervalo.\n");
            printf("\nPressione ENTER para tentar novos valores...");
            while (getchar() != '\n');
            getchar();
            continue;
        }

        int iteracao = 0;

        printf("\n%3s | %10s | %10s | %10s | %10s\n", "IT", "INF (a)", "SUP (b)", "MEDIO", "F(M)");
        printf("------------------------------------------------------------\n");

        while (fabs(limite_superior - limite_inferior) > precisao_alvo) {
            iteracao++;

            ponto_medio = calcular_ponto_medio(limite_inferior, limite_superior);

            double f_inferior = calcular_funcao(limite_inferior);
            double f_medio = calcular_funcao(ponto_medio);

            printf("%03d | %10.4lf | %10.4lf | %10.4lf | %10.4lf\n",
                   iteracao, limite_inferior, limite_superior, ponto_medio, f_medio);

            if (f_inferior * f_medio < 0) {
                limite_superior = ponto_medio;
            } else {
                limite_inferior = ponto_medio;
            }
        }

        printf("------------------------------------------------------------\n");
        printf("\nRESULTADO: Raiz aproximada: %.6lf\n", ponto_medio);
        printf("Total de iteracoes: %d\n", iteracao);

        // Entrada validada para continuar
        printf("\nDeseja testar outro intervalo? (1-Sim / 0-Sair): ");
        while (!ler_int(&continuar)) {
            printf("Digite 1 para continuar ou 0 para sair: ");
        }

    } while (continuar == 1);

    printf("\nPrograma encerrado. Bons estudos!\n");
    return 0;
}

// Função matemática
double calcular_funcao(double x) {
    return (x * x) - 4;
}

// Cálculo do ponto médio
double calcular_ponto_medio(double inf, double sup) {
    return (inf + sup) / 2.0;
}

// Leitura segura de double
int ler_double(double *valor) {
    int resultado = scanf("%lf", valor);

    if (resultado != 1) {
        printf("\nEntrada invalida! Digite apenas numeros.\n");

        // limpa buffer
        while (getchar() != '\n');

        return 0;
    }

    return 1;
}

// Leitura segura de inteiro
int ler_int(int *valor) {
    int resultado = scanf("%d", valor);

    if (resultado != 1) {
        printf("\nEntrada invalida! Digite apenas 1 ou 0.\n");

        // limpa buffer
        while (getchar() != '\n');

        return 0;
    }

    return 1;
}