#include <stdio.h>
#include <string.h>

// Definição da estrutura da carta
typedef struct {
    char nome[30];
    int populacao;
    float area;
    float densidade;
    int pib;
} Carta;

// Função para exibir os atributos disponíveis
void mostrarAtributosDisponiveis(int escolhido) {
    printf("Escolha um atributo:\n");
    if (escolhido != 1) printf("1. População\n");
    if (escolhido != 2) printf("2. Área\n");
    if (escolhido != 3) printf("3. Densidade Demográfica\n");
    if (escolhido != 4) printf("4. PIB\n");
}

// Função para obter um atributo válido do usuário
int escolherAtributo(int jaEscolhido) {
    int opcao;
    do {
        mostrarAtributosDisponiveis(jaEscolhido);
        printf("Digite o número do atributo: ");
        scanf("%d", &opcao);
        if (opcao < 1 || opcao > 4 || opcao == jaEscolhido) {
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao < 1 || opcao > 4 || opcao == jaEscolhido);
    return opcao;
}

// Função para retornar o valor de um atributo
float obterValorAtributo(Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.densidade;
        case 4: return c.pib;
        default: return 0;
    }
}

// Função para nome do atributo
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "Densidade Demográfica";
        case 4: return "PIB";
        default: return "Desconhecido";
    }
}

// Função de comparação
void compararCartas(Carta c1, Carta c2, int at1, int at2) {
    float v1a1 = obterValorAtributo(c1, at1);
    float v2a1 = obterValorAtributo(c2, at1);
    float v1a2 = obterValorAtributo(c1, at2);
    float v2a2 = obterValorAtributo(c2, at2);

    int resultadoA1 = (at1 == 3) ? (v1a1 < v2a1 ? 1 : v1a1 > v2a1 ? 2 : 0)
                                : (v1a1 > v2a1 ? 1 : v1a1 < v2a1 ? 2 : 0);
    int resultadoA2 = (at2 == 3) ? (v1a2 < v2a2 ? 1 : v1a2 > v2a2 ? 2 : 0)
                                : (v1a2 > v2a2 ? 1 : v1a2 < v2a2 ? 2 : 0);

    float soma1 = v1a1 + v1a2;
    float soma2 = v2a1 + v2a2;

    printf("\nResultado da Comparação:\n");
    printf("--------------------------------------------------\n");
    printf("País 1: %s\n", c1.nome);
    printf("%s: %.2f\n", nomeAtributo(at1), v1a1);
    printf("%s: %.2f\n", nomeAtributo(at2), v1a2);
    printf("Soma dos atributos: %.2f\n", soma1);

    printf("\nPaís 2: %s\n", c2.nome);
    printf("%s: %.2f\n", nomeAtributo(at1), v2a1);
    printf("%s: %.2f\n", nomeAtributo(at2), v2a2);
    printf("Soma dos atributos: %.2f\n", soma2);
    printf("--------------------------------------------------\n");

    if (soma1 > soma2)
        printf("Vencedor: %s\n", c1.nome);
    else if (soma2 > soma1)
        printf("Vencedor: %s\n", c2.nome);
    else
        printf("Empate!\n");
}

int main() {
    // Cartas pré-cadastradas
    Carta pais1 = {"Brasil", 213000000, 8515767, 25.0, 1847020};
    Carta pais2 = {"Japão", 125800000, 377975, 333.0, 5064873};

    printf("Bem-vindo ao Super Trunfo dos Países!\n\n");

    printf("Comparando os países:\n1. %s\n2. %s\n\n", pais1.nome, pais2.nome);

    int atributo1 = escolherAtributo(0);
    int atributo2 = escolherAtributo(atributo1);

    compararCartas(pais1, pais2, atributo1, atributo2);

    return 0;
}