#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main(){

        char dificuldade;
        int tentativas,x;
        int numero;
        int resposta;


        srand(time(NULL));

        resposta=rand()%100 + 1;

        printf("********************************");
        printf("\n    jogo da adivinhacao       ");
        printf("\n******************************");
        printf("\n\n");
        printf("Escolha seu nivel de dificuldade:");
        printf("\nFacil (F)  medio(M)  Dificil(D)\n");


        scanf(" %c", &dificuldade);




        if(dificuldade=='f' || tentativas=='F'){
                tentativas=15;
                printf("\nVoce escolheu o modo facil, Chute o numero que estou pensando: \n");
        }

        else if(dificuldade=='m' || tentativas=='M'){;
                tentativas=10;
                printf("\nVoce escolheu o modo medio, Chute o numero que estou pensando: \n");
        }

        else if(dificuldade=='d' || tentativas=='D'){
                tentativas=5;
                printf("\nVoce escolheu o modo dificil, Chute o numero que estou pensando: \n");
        }

        else{

                printf("\nDificuldade invalida.");
                return 1;
        }



        scanf("%i", &numero);




        for(x=tentativas;x>0;x--){

        if(numero<resposta)
        {

                printf("\nNumero menor doq a resposta, tente novamente: \n");
                scanf("%i", &numero);
        }


        if(numero>resposta){

                printf("\nNumero maior doq a resposta, tente novamente: \n");
                scanf("%i", &numero);
        }

        if(x<=1){
                printf("\nAcabaram suas tentativas, o numero era %i", resposta);

        }

        if(numero==resposta){
                printf("\nParabens voce acertou, o numero era %i", resposta);
                return 0;
        }
}

}
