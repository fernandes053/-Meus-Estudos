#include <stdio.h>
#include <stdlib.h>

typedef struct dados{
int reg;
char produto[20];
int qtd;
float preco;
}dados;

void aloca(dados **p,int tam);
int verifica();
void cadastro(dados *p);
void grava(dados *p);
void mostra(dados *p);

int main(){

dados *pdados=NULL;
char op;

aloca(&pdados,1);

do{

cadastro(pdados);
printf("\nDeseja continuar <S/N>: ");
scanf("%c", &op);
fflush(stdin);


}while(op!='n'&&op!='N');

mostra(pdados);




}

void cadastro(dados *p){

int nreg;
nreg=verifica();
p->reg=nreg+1;
printf("\nRegistro: %i", (p->reg)+1);
printf("\nDigite o nome do seu produto: ");
gets(p->produto);
fflush(stdin);
printf("\nQuantidade : ");
scanf("%i", &(p->qtd));
fflush(stdin);
printf("\nPreco: ");
scanf("%f", &(p->preco));
fflush(stdin);
grava(p);

}

void grava(dados *p)
{

FILE *fptr=fopen("estoque.bin", "ab");

if(fptr==NULL){

printf("\nERRO\n");

}

else{

fwrite(p,sizeof(dados),1,fptr);
fclose(fptr);

}


}

int verifica(){

FILE *pfile=NULL;
int cont=0;

pfile=fopen("execercicioaf.bin","ab");

if(pfile==NULL){

printf("\nERRO\n");

}

else{

fseek(pfile,0,SEEK_END);
cont=ftell(pfile)/sizeof(dados);
fclose(pfile);
return cont;
}

}


void aloca(dados **p,int tam){

if((*p=(dados*)realloc(*p,tam*sizeof(dados)))==NULL){

printf("\nErro ao alocar memoria\n");
exit(1);

}

}



void mostra(dados *p)
{
FILE *fptr=NULL;
int i,qreg;

qreg=verifica();
system("cls");

if((fptr=fopen("estoque.bin","rb"))==NULL)

    printf("\nErro ao abrir o arquivo");

else
{
for(i=0;i<qreg;i++)
{
fseek(fptr,i*sizeof(dados),0);
fread(p,sizeof(dados),1,fptr);
printf("\nRegistro: %i\nProduto: %s\nQtde: %i\nPreco: %.2f\n\n",p->reg,p->produto,p->qtd,p->preco);
}
fclose(fptr);
}
system("pause");
}