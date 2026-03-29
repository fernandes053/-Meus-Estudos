#include <stdio.h>
#include <locale.h>

// Protótipos
void imprimirnum(double x);
double f(double x); // Usaremos apenas uma função para o intervalo
double pontomedio(double x, double y);
void verificaraiz(double fa, double fb);

int main() {
    setlocale(LC_ALL, "portuguese");
    double a, b, fa, fb, m, fm;

    printf("--- Estudo do Intervalo ---\n");
    printf("Função: f(x) = x^2 - 4\n\n");

    printf("Digite o valor de a (início): ");
    scanf("%lf", &a);
    printf("Digite o valor de b (fim): ");
    scanf("%lf", &b);

    fa = f(a);
    fb = f(b);

    printf("\nf(a) = %.2lf", fa);
    printf("\nf(b) = %.2lf\n", fb);

    // Passo 1: Verificar se existe raiz entre a e b
    verificaraiz(fa, fb);

    // Passo 2: Calcular ponto médio
    m = pontomedio(a, b);
    fm = f(m); // Calculando a função no ponto médio
    printf("\nPonto médio (m): %.2lf", m);
    printf("\nf(m): %.2lf\n", fm);

    // Passo 3: Onde a raiz está agora?
    printf("\nNova análise:");
    if (fa * fm < 0) {
        printf("\nA raiz está entre [a, m] -> [%.2lf, %.2lf]\n", a, m);
    } else {
        printf("\nA raiz está entre [m, b] -> [%.2lf, %.2lf]\n", m, b);
    }

    return 0;
}

void imprimirnum(double x) {
    if (x == (int)x) printf("%d", (int)x);
    else printf("%.2lf", x);
}

double f(double x) {
    return (x * x) - 4;
}

double pontomedio(double x, double y) {
    return (x + y) / 2;
}

void verificaraiz(double fa, double fb) {
    if ((fa * fb) < 0) {
        printf("Resultado: Existe raiz no intervalo!\n");
    } else {
        printf("Resultado: Não há garantia de raiz (sinais iguais).\n");
    }
}
