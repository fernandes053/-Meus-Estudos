#include<stdio.h>
#include<locale.h>

double funcao(double x);
void imprimirnum(double x);

int main(){

double x, resultado;
setlocale(LC_ALL, "portuguese");

    printf("Função: \n");
    printf("f(x)=x^2-4\n");
    printf("Digite um valor de x: ");
    scanf("%lf", &x);

    resultado=funcao(x);

    printf("\nf(");
    imprimirnum(x);
    printf(")=");
    imprimirnum(x);
    printf("^2-4 = %.2lf\n\n", resultado);

}

double funcao(double x){
    return x*x-4;

}


void imprimirnum(double num){

    if(num == (int)num){
        printf("%d", (int)num);
    }else{
        printf("%.2lf", num);
    }

}
