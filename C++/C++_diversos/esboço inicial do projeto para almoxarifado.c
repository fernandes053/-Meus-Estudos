#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PECAS 1000
#define TAM_NOME 50

struct Peca {
    char nome[TAM_NOME];
    char corredor[10];
    char prateleira[10];
};

struct Peca almoxarifado[MAX_PECAS] = {
    // Filtros
    {"Filtro de oleo", "B", "B46"},
    {"Filtro de ar", "B", "B50"},
    {"Filtro de combustivel", "B", "B67"},
    {"Filtro do ar-condicionado", "B", "B68"},
    {"Filtro separador de agua", "B", "B69"},
    {"Filtro hidraulico", "B", "B70"},
    {"Filtro da caixa de marcha", "B", "B71"},
    {"Filtro de cabine", "B", "B72"},
    {"Filtro de ventilacao", "B", "B73"},
    {"Filtro de direcao hidraulica", "B", "B74"},

    // Outras peças
    {"Pastilha de freio dianteira", "C", "C12"},
    {"Pastilha de freio traseira", "C", "C13"},
    {"Disco de freio", "C", "C20"},
    {"Amortecedor dianteiro", "A", "A10"},
    {"Amortecedor traseiro", "A", "A11"},
    {"Braco da suspensao", "D", "D05"},
    {"Terminal de direcao", "D", "D08"},
    {"Correia do alternador", "E", "E02"},
    {"Radiador", "E", "E10"},
    {"Mangueira do radiador", "E", "E11"},
    {"Motor de partida", "F", "F03"},
    {"Alternador", "F", "F05"},
    {"Bateria", "F", "F10"},
    {"Lampada farol dianteiro", "G", "G01"},
    {"Lampada lanterna traseira", "G", "G02"},
    {"Rolamento da roda", "H", "H07"},
    {"Cubo de roda", "H", "H08"}
};

int total_pecas = 27;

// Função para converter string para minúsculo
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Função principal
void localizarPeca(struct Peca almoxarifado[], int quantidade);

int main() {
    int opcao;

    do {
        printf("\n--- CONSULTA DE PECAS - ALMOXARIFADO ---\n");
        printf("1. Localizar peca\n");
        printf("2. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // limpa o enter

        switch (opcao) {
            case 1:
                localizarPeca(almoxarifado, total_pecas);
                break;
            case 2:
                printf("Encerrando sistema.\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }

    } while (opcao != 2);

    return 0;
}

void localizarPeca(struct Peca almoxarifado[], int quantidade) {
    char busca[TAM_NOME];
    char busca_lower[TAM_NOME];
    int encontrados = 0;

    printf("Digite o nome (ou parte do nome) da peca: ");
    fgets(busca, TAM_NOME, stdin);
    busca[strcspn(busca, "\n")] = 0;
    strcpy(busca_lower, busca);
    toLowerCase(busca_lower);

    printf("\nResultados encontrados:\n\n");

    for (int i = 0; i < quantidade; i++) {
        char nome_lower[TAM_NOME];
        strcpy(nome_lower, almoxarifado[i].nome);
        toLowerCase(nome_lower);

        if (strstr(nome_lower, busca_lower) != NULL) {
            printf("%s - Corredor %s - Prateleira %s\n\n",
                almoxarifado[i].nome,
                almoxarifado[i].corredor,
                almoxarifado[i].prateleira);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("Nenhuma peca encontrada contendo \"%s\".\n", busca);
    }
}
