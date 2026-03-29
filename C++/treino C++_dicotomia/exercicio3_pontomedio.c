#include<stdio.h>
#include<locale.h>

double funcaoa(double x);
double funcaob(double y);
void imprimirnum(double x);
void verificaraiz(double x, double y);
double pontomedio(double x, double y);

int main(){

double x, y, resultadoa, resultadob, raiz, pmedio;
setlocale(LC_ALL, "portuguese");

    printf("Primeira função: \n");
    printf("f(x)=x^2-4\n");
    printf("Digite um valor de x: ");
    scanf("%lf", &x);

    resultadoa=funcaoa(x);

    printf("\nf(");
    imprimirnum(x);
    printf(")=");
    imprimirnum(x);
    printf("^2-4 = %.2lf\n\n", resultadoa);

    printf("Segunda função: \n");
    printf("f(y)=y^3-4\n");
    printf("Digite um valor de y: ");
    scanf("%lf", &y);

    resultadob=funcaob(y);

    printf("\nf(");
    imprimirnum(y);
    printf(")=");
    imprimirnum(y);
    printf("^3-4 = %.2lf\n\n", resultadob);

    verificaraiz(resultadoa,resultadob);
    pmedio=pontomedio(x,y);
    printf("Ponto médio dos valores: %.2lf", pmedio);
}

double funcaoa(double x){
    return x*x-4;

}

double funcaob(double y){
    return (y*y*y)-4;

}

void imprimirnum(double num){

    if(num == (int)num){
        printf("%d", (int)num);
    }else{
        printf("%.2lf", num);
    }

}

void verificaraiz(double x, double y){

if(x*y<0){
    printf("Existe raiz no intervalo\n");
}else{
    printf("Não há raiz no intervalo\n");
}


}

double pontomedio(double x, double y){
    return (x*y)/2;
}
