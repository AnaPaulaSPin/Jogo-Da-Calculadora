#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declaração das funções que serão utilizadas no programa
void Menu();
void regras();
void jogar();
void PreencherMatriz();
void matriz();
void SelMatriz();
void pausarPrograma();
void apagarMatriz();
void numeros();

// Declaração das variáveis globais
int i, j, V[5][5]; // Variável V é uma matriz 5x5
char r; // Variável para armazenar a escolha do usuário no menu
int lin1,lin2,col1,col2;

// Função principal do programa
int main() {
    do {
        Menu(); // Chama a função Menu para exibir o menu principal

        r = getchar(); // Captura a escolha do usuário

        // Utiliza um switch para tratar as diferentes opções do menu
        switch (r) {
            case 'a': { 
                printf("Jogar\n");
                jogar(); // Chama a função jogar
                pausarPrograma(); // Pausa o programa
                break;
            }
            case 'b': { 
                printf("Regras");
                regras(); // Chama a função regras
                pausarPrograma(); // Pausa o programa
                break;
            }
            case 'e': 
                printf("Saindo do programa...\n");
                pausarPrograma(); // Pausa o programa
                break;
        }
    } while (r != 'e'); // Continua exibindo o menu até que a opção 'e' seja escolhida

    return 0; // Encerra o programa
}

// Função que exibe o menu principal do jogo
void Menu() {
    printf("  Inicio do jogo \n");
    printf("A- Jogar\n");
    printf("B- Regras\n");
    printf("E- Sair\n");
}

// Função que exibe as regras do jogo
void regras() {
    printf("O jogo funcionara da seguinte forma:\n\n");
    printf("1. Escolha de Numeros e Operacoes:\n");
    printf("   - O jogador devera escolher um par de numeros da matriz e uma operação aritmetica, e indicar o resultado da operacao.\n\n");
    printf("2. Acerto de Operacoes:\n");
    printf("   - Cada vez que o jogador acerta o valor da operacao, as posicoes escolhidas nao estarao mais disponiveis e nao devem mostrar numeros.\n\n");
    printf("3. Diversidade de Operacoes:\n");
    printf("   - O jogador nao pode escolher sempre a mesma operacao matematica. Para garantir que as quatro operacoes (adicao, subtracao, multiplicacao e divisao) sejam contempladas, implemente uma regra para controlar essa situacao individualmente.\n\n");
    printf("4. Solicitacao de Resposta:\n");
    printf("   - Depois de tres tentativas erradas, o jogador pode pedir a resposta.\n\n");
    printf("5. Condicoes de Termino do Jogo:\n");
    printf("   - O jogo termina se:\n");
    printf("     - O jogador acerta todos os resultados das operacoes de todos os pares em um máximo de 24 tentativas (sao 18 pares de numeros).\n");
    printf("     - O jogador ultrapassa as 24 tentativas.\n");
    printf("     - O jogador deseja terminar o jogo.\n");
}

// Função para pausar o programa, esperando o usuário pressionar Enter
void pausarPrograma() {
    printf("\nPressione Enter para continuar ou 'e' para sair...\n");

    // Limpar o buffer de entrada
    char buffer[256]; // Buffer para armazenar a entrada
    fgets(buffer, sizeof(buffer), stdin); // Lê a linha do stdin

    // Remover o caractere de nova linha, se houver
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove a nova linha, se presente

    // Verificar se o usuário digitou 'e'
    if (strcmp(buffer, "e") == 0) {
        printf("Saindo do programa...\n");
        exit(0); // Saída do programa
    }
}


// Função que inicia e executa o jogo
void jogar() {

  int Operando1, Operando2, Operacao, resposta;
  char oper,r;
  int erro;
  erro =0;

    // preencher a matriz com os numeros aleatoriamente:
    PreencherMatriz();

do{
    matriz();

    numeros(&Operando1, &Operando2); // Passagem de endereço para modificar Operando1 e Operando2

    do {
    // Usuário escolhe a operação
    printf("Escolha uma operacao (+ - / *): ");
    scanf(" %c", &oper);

    // Verifica se o operador é válido
    if (oper != '+' && oper != '-' && oper != '*' && oper != '/') {
        printf("\nOperador invalido. Por favor, escolha um dos seguintes: +, -, *, /\n");
    }

    } while (oper != '+' && oper != '-' && oper != '*' && oper != '/'); // Continua o loop enquanto o operador não for válido

    // reconhecendo o operador:
        if (oper == '+') {
            Operacao = Operando1 + Operando2;
        } else if (oper == '-') {
            Operacao = Operando1 - Operando2;
        } else if (oper == '*') {
            Operacao = Operando1 * Operando2;
        } else if (oper == '/') {
            oper = Operando1 / Operando2;
        } 

    //numero escolhido em colorido:
    SelMatriz(); 

do {
    do {
        // Usuário digita o resultado da operação
        printf("Digite o resultado de %i %c %i: ", Operando1, oper, Operando2);
        scanf("%i", &resposta);  // Lê a resposta fornecida pelo usuário

        if (resposta == Operacao) {
            printf("\nParabens, voce acertou!\n");  // Mensagem de acerto
            break;  // Sai do loop interno se a resposta estiver correta
        } else {
            printf("\nResposta errada. Tente novamente.\n");  // Mensagem de erro
            erro++;  // Incrementa o contador de erros
        }

        if (erro == 3) {
            printf("\nDeseja a resposta da questao?(s/n): ");
            scanf(" %c", &r);  // Pergunta ao usuário se ele deseja ver a resposta correta
        }

    } while (erro != 5);  // Continua pedindo resposta enquanto o número de erros for diferente de 5

    if (r == 's') {
        printf("\nA resposta sera: %d", Operacao); 
        break;  // Sai do loop externo
    }

    if (erro == 5) {
        printf("\nsuas chances acabaram, o resultado e %d, tente outro numero!\n", Operacao);
        break;  // Sai do loop externo se o usuário tiver errado 5 vezes
    }

    if (resposta == Operacao) {
            break;  // Sai do loop externo tbm se a resposta estiver correta
        }

} while (r != 's');  // Continua o loop externo até o usuário pedir a resposta correta

    //apagando o numeros ja usados com 0:
      apagarMatriz();

    printf("\nPressione Enter para continuar ou e para sair...\n");
    r = getchar(); // Aguarda até que o usuário pressione Enter

   } while(r !='e');
}

// Função que exibe a matriz do jogo:
void matriz() {
    printf("\nJogo da Calculadora\n\n");
    printf("col   0  1  2  3  4\n");
    for (int i = 0; i < 5; i++) {
        printf("lin %d|", i);
        for (int j = 0; j < 5; j++) {
            if (V[i][j] == 0) {
                printf("   |"); // Imprime espaço vazio para as posições usadas
            } else {
                printf(" %d |", V[i][j]); // Exibe o valor normalmente
            }
        }
        printf("\n");
    }
}

// funçao que preenche a matriz com os numeros entre 1 a 9:
void PreencherMatriz(){

    srand(time(NULL));

     for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            V[i][j] = (rand() % 9) + 1;   // Gera um número aleatório entre 1 e 9
        }
    }
}

void apagarMatriz() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == lin1 && j == col1) {
                V[i][j] = 0; 
            } else if (i == lin2 && j == col2) {
                V[i][j] = 0; // Define a posição como 0
            }
        }
    }
}

void SelMatriz() {
    printf("\nJogo da Calculadora\n\n");
    printf("col   0  1  2  3  4\n");
    for (int i = 0; i < 5; i++) { // Itera sobre as linhas da matriz
        printf("lin %d|", i);
        for (int j = 0; j < 5; j++) { // Itera sobre as colunas da matriz
            if (i == lin1 && j == col1) {
                // Se a posição corresponder a lin1 e col1, imprime em vermelho
                printf("\033[31m %d \033[0m|", V[i][j]);
            } else if (i == lin2 && j == col2) {
                // Se a posição corresponder a lin2 e col2, imprime em vermelho
                printf("\033[31m %d \033[0m|", V[i][j]); 
            } else if (V[i][j] == 0) {
                printf("   |"); // Imprime espaço vazio para valores zero
            } else {
                printf(" %d |", V[i][j]); // Exibe o valor normalmente
            }
        }
        printf("\n");
    }
}

//verificando as entradas dos numeros e garantir que o jogador não escolha os mesmos numeros:
void numeros(int *Operando1, int *Operando2) {
    // Ler o primeiro operando
    printf("\nJogador escolha o primeiro numero:\n");
    do {
        printf("Linha (0 a 4): ");
        scanf("%i", &lin1);
        if (lin1 < 0 || lin1 > 4) {
            printf("Valor de linha invalido. Por favor, escolha um numero entre 0 e 4.\n");
        }
    } while (lin1 < 0 || lin1 > 4);

    do {
        printf("Coluna (0 a 4): ");
        scanf("%i", &col1);
        if (col1 < 0 || col1 > 4) {
            printf("Valor de coluna invalido. Por favor, escolha um numero entre 0 e 4.\n");
        } else if (V[lin1][col1] == 0) {
            printf("Numero ja foi escolhido, tente outro.\n");
        }
    } while (col1 < 0 || col1 > 4 || V[lin1][col1] == 0);

    *Operando1 = V[lin1][col1];

    // Ler o segundo operando
    printf("\nJogador escolha o segundo numero:\n");
    do {
        printf("Linha (0 a 4): ");
        scanf("%i", &lin2);
        if (lin2 < 0 || lin2 > 4) {
            printf("Valor de linha invalido. Por favor, escolha um numero entre 0 e 4.\n");
        }
    } while (lin2 < 0 || lin2 > 4);

    do {
        printf("Coluna (0 a 4): ");
        scanf("%i", &col2);
        if (col2 < 0 || col2 > 4) {
            printf("Valor de coluna invalido. Por favor, escolha um numero entre 0 e 4.\n");
        } else if (V[lin2][col2] == 0) {
            printf("Numero ja foi escolhido, tente outro.\n");
        }
    } while (col2 < 0 || col2 > 4 || V[lin2][col2] == 0);

    *Operando2 = V[lin2][col2];
}
