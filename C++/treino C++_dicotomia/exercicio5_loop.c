#include <stdio.h>
#include <stdlib.h> // Para system("cls")
#include <math.h>

// Prototipos
double calcular_funcao(double x);
double calcular_ponto_medio(double inf, double sup);

int main() {
    // IMPORTANTE: Removido o setlocale para aceitar PONTO (.) como decimal

    double limite_inferior, limite_superior, ponto_medio;
    double precisao_alvo = 0.0001;
    int continuar = 1;

    do {
        system("cls");

        printf("============================================\n");
        printf("--- METODOS NUMERICOS: DICOTOMIA ---\n");
        printf("Equacao: f(x) = x^2 - 4\n");
        printf("Use PONTO para decimais (ex: 0.5)\n");
        printf("============================================\n\n");

        printf("Digite o inicio do intervalo (a): ");
        if (scanf("%lf", &limite_inferior) != 1) break; // Seguranca caso digitem letras

        printf("Digite o fim do intervalo (b): ");
        if (scanf("%lf", &limite_superior) != 1) break;

        // Verificacao de Bolzano
        if (calcular_funcao(limite_inferior) * calcular_funcao(limite_superior) >= 0) {
            printf("\nERRO: Sinais iguais em f(a) e f(b)!\n");
            printf("Nao ha garantia de raiz neste intervalo.\n");
            printf("\nPressione ENTER para tentar novos valores...");

            fflush(stdin);
            getchar();
            continue;
        }

        int iteracao = 0;
        printf("\n%3s | %10s | %10s | %10s | %10s\n", "IT", "INF (a)", "SUP (b)", "MEDIO", "F(M)");
        printf("------------------------------------------------------------\n");

        // Loop de Dicotomia
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

        printf("\nDeseja testar outro intervalo? (1-Sim / 0-Sair): ");
        scanf("%d", &continuar);

    } while (continuar == 1);

    printf("\nPrograma encerrado. Bons estudos!\n");
    return 0;
}

double calcular_funcao(double x) {
    return (x * x) - 4;
}

double calcular_ponto_medio(double inf, double sup) {
    return (inf + sup) / 2.0;
}
