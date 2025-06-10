#include <stdio.h>
#include <stdlib.h>

void aloca(int **p,int tam);
void leitura(int *p,int q);
void imprime_contrario(int *p,int q);





int main()
{

int *ptr=NULL;
int qtd=0;

printf("Digite a quantidade de elementos: ");
scanf("%i", &qtd);
aloca(&ptr,qtd);
leitura(ptr,qtd);
printf("\nMostra os valores ao contrario: \n\n");
imprime_contrario(ptr,qtd);



}


void aloca(int **p,int tam){

    if((*p=(int*)realloc(*p,tam*sizeof(int)))==NULL){
        printf("\nErro na alocacao");
        exit(1);
    }

}


void leitura(int *p,int q){

int i;

    for(i=0;i<q;i++){
        printf("\nDigite o %i Valor: ", i+1);
        scanf("%i", p+i);
    }

}


void imprime_contrario(int *p,int q){

int i;

for(i=q-1;i>=0;i--){
    printf("\nEndereco %u - Valor %i", p+i,*(p+i));
}




}

