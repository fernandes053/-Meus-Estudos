#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct	carreira{
	int		reg;			// registro da patente
	int		qmilitar;		// quantidade de militares daquela patente
	char	org[20];		// organização - exemplo: exército, aeronáutica, marinha
	char	patente[20];	// exemplo: soldado, cabo, sargento
	float	salario;		// valor do salário
}carreira;

typedef struct 	militar{
	char	CPF[13];		// CPF do militar
	char	nome[20];		// nome do militar
	int		numreg;		// número do registro da carreira
}militar;

void aloca_carreira(carreira **pc,int qc);
void aloca_militar(militar **pm,int qm);
void cadastro_carreira(carreira *pc,int qc);
void cadastro_militar(militar *pm,carreira *pc,int qc);
int  busca_patente(carreira *pc,int qc,char *aux_org,char *aux_pat);
void mostra_patente(carreira *pc,int qc);
void maiuscula(char *p);

main()
{
carreira *pc=NULL;
militar  *pm=NULL;
int op,cont=0;
aloca_carreira(&pc,5);
cadastro_carreira(pc,5);
system("cls");
do{
	system("cls");
	printf("\n[1]Cadastro Militar\n[2]Troca Patente\n[3]Mostra Patente\n[4]Fim\nOpcao: ");
	scanf("%i",&op);
	fflush(stdin);
	switch(op)
	  {
	  	case 1: aloca_militar(&pm,cont+1);
	  			cadastro_militar(pm+cont,pc,5);
	  			cont++;
	  			break;
	  	case 3: mostra_patente(pc,5);
		  		break; 	
	  }//switch
  }while(op!=4);
}//main

void aloca_carreira(carreira **pc,int qc)
{
if((*pc=(carreira*)realloc(*pc,qc*sizeof(carreira)))==NULL)
  exit(1);
}//aloca_carreira

void aloca_militar(militar **pm,int qm)
{
if((*pm=(militar*)realloc(*pm,qm*sizeof(militar)))==NULL)
  exit(1);	
}//aloca_militar

void cadastro_carreira(carreira *pc,int qc)
{
int i;
for(i=0;i<qc;i++,pc++)
  {
  	pc->reg=i+1;
  	pc->qmilitar=0;
  	printf("\nOrganizacao: Exercito / Aeronautica / Marinha\n");
  	gets(pc->org);
  	fflush(stdin);
  	maiuscula(pc->org);
  	printf("\nPatente: ");
  	gets(pc->patente);
  	fflush(stdin);
  	maiuscula(pc->patente);
  	printf("\nSalario: ");
  	scanf("%f",&pc->salario);
  	fflush(stdin);
  }//for
}//cadastro_carreira

void cadastro_militar(militar *pm,carreira *pc,int qc)
{
char aux_org[20],aux_pat[20];
printf("\nCPF: ");
gets(pm->CPF);
fflush(stdin);
printf("\nNome: ");
gets(pm->nome);
fflush(stdin);
printf("\nOrganizacao: Exercito / Aeronautica / Marinha:\n");
gets(aux_org);
fflush(stdin);
maiuscula(aux_org);
printf("\nPatente: ");
gets(aux_pat);
fflush(stdin);
maiuscula(aux_pat);
pm->numreg=busca_patente(pc,qc,aux_org,aux_pat);
if(pm->numreg==-1)
  printf("\nCarreira nao encontrada\n\n");
else
  printf("\nCadastrado com sucesso - salario: %.2f\n\n",(pc+(pm->numreg)-1)->salario);
system("pause");
}//cadastro_militar

int  busca_patente(carreira *pc,int qc,char *aux_org,char *aux_pat)
{
int i;
for(i=0;i<qc;i++,pc++)
  if(strcmp(pc->org,aux_org)==0 && strcmp(pc->patente,aux_pat)==0)
    {
    	pc->qmilitar++;
    	return(pc->reg);
	}//if	
return -1;   //nao achou
}//busca_patente

void mostra_patente(carreira *pc,int qc)
{
int i;
for(i=0;i<qc;i++,pc++)	
  printf("\nRegistro: %i\nQtde: %i\nOrganizacao: %s\nPatente: %s\nSalario: %.2f\n\n",pc->reg,pc->qmilitar,pc->org,pc->patente,pc->salario);
system("pause");
}//mostra_carreira

void maiuscula(char *p)
{
int i,tam;
tam=strlen(p);
for(i=0;i<tam;i++,p++)
  if(*p>='a' && *p<='z')
    *p=*p-32;   //*p-=32
}//maiuscula
