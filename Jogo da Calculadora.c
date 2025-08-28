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
void sinal();


// Declaração das variáveis globais
int i, j, V[5][5]; // Variável V é uma matriz 5x5
int lin1, lin2, col1, col2;
int soma = 0, sub = 0, divisao = 0, mult = 0;  // Variáveis para contagem
char r; // Variável para armazenar a escolha do usuário no menu

// Função principal do programa
int main(){
do {
    Menu(); // Chama a função Menu para exibir o menu principal

    r = getchar(); // Captura a escolha do usuário

    // Utiliza um switch para tratar as diferentes opções do menu
    switch (r) {
        case 'a': {
            printf("Jogar\n");
            jogar(); // Chama a função jogar
            break;
        }
        case 'b': {
            printf("Regras\n");
            regras(); // Chama a função regras
             pausarPrograma(&r); 
            system("clear || cls"); // Limpa a tela
            break;
        }
        case 'e':
            printf("Saindo do programa...\n");
            break;
    }

    if (r == 'a') {
        // Pausa o programa se o usuário não escolheu 'e'
        getchar(); // Captura o Enter após a escolha no menu
        system("clear || cls"); // Limpa a tela
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

// Função que inicia e executa o jogo
void jogar() {
    int Operando1, Operando2, Operacao, resposta, tentativa = 0, pares = 0;
    char oper;
    int erro = 0;
    char r; // Variável para armazenar a escolha do usuário no menu

    // preencher a matriz com os numeros aleatoriamente:
    PreencherMatriz();

    do {
        erro = 0; // toda vez que uma partida começar ele vai ser zerado.
        matriz(); // exibe a matriz do jogo

        numeros(&Operando1, &Operando2); // Função para a escolha dos operadores e verificação deles
        sinal(&Operacao, &oper); // Função para a escolha de qual operação fazer e a verificação

        // número escolhido em colorido:
        SelMatriz();
        
        // laço que confere se o jogador acertou e conta quantidade de erros:
        do {
            // Exibir mensagem de confirmação da operação escolhida
            printf("Digite o resultado de %i %c %i: ", Operando1, oper, Operando2);
            scanf("%i", &resposta); // Lê a resposta fornecida pelo usuário

            //verifica se a resposta esta correta:
            if (resposta == Operacao) {
             printf("\nParabens, voce acertou!\n"); // Mensagem de acerto
             tentativa++;
             printf("Tentativas restantes: %i\n", 24 - tentativa);
             pares += 2;
             printf("Pares acertados ate agora: %i\n", pares);
             break; // Sai do loop interno se a resposta estiver correta


            // contador de erros:
            } else {
              printf("\nResposta errada. Tente novamente.\n"); // Mensagem de erro
              erro++; // Incrementa o contador de erros
              tentativa++;
              printf("Tentativas restantes: %i\n", 24 - tentativa);

            //caso ele ja tenha tentado 24 vezes o jogo finaliza:
            if (tentativa == 24) {
             printf("Suas tentativas acabaram, voce perdeu!\n");
             break;
             }
            }
            
            // quando o usuario errar tres vezes, vai ter a opçao de pedir a resposta e encerrar essa partida
            if (erro == 3) {
            printf("\nDeseja a resposta da questao? (s/n): ");
            scanf(" %c", &r); // Pergunta ao usuário se ele deseja ver a resposta correta
            }
           
           // Mostra a resposta correta e sai do loop de esperar o usuario digitar a respota correta
           if (r == 's') {
           printf("\nA resposta seria: %d\n", Operacao);
           break; 
           }
          
          // rodada acaba caso ele tenha errado 5 vezes
          if (erro == 5) {
          printf("\nSuas chances acabaram, o resultado era %d. Tente outros números!\n", Operacao);
          break;
          }


        } while (r != 's'); // Continua o loop externo até o usuário pedir a resposta correta

        // apagando os números já usados com 0(forma que eu encontrei para assim garantir que os numeros sejam apagados)
        apagarMatriz();
        
        // da a chance do usuario encerrar o jogo ou continuar:
        pausarPrograma(&r); 
        
        //verificaçao novamente para garantir que a partida acabe caso as condiçoes sejam compridas:
        if (tentativa == 24) {
            printf("Suas tentativas acabaram, voce perdeu!\n");
             system("clear || cls"); // Limpa a tela
            break;
           
        } else if (pares == 18) {
            printf("Você acertou todos os numeros, parabens!!!\n");
             system("clear || cls"); // Limpa a tela
            break;

        } else if(r == 'e' || r == 'E'){
             system("clear || cls"); // Limpa a tela
            break;
        }
        
         system("clear || cls"); // Limpa a tela
        
    } while (r != 'e');
}

// Função que exibe as regras do jogo
void regras() {
    printf("O jogo funcionara da seguinte forma:\n\n");
    printf("1. Escolha de Numeros e Operacoes:\n");
    printf("   - O jogador devera escolher um par de numeros da matriz e uma operação aritmetica, e indicar o resultado da operacao.\n\n");
    printf("2. Acerto de Operacoes:\n");
    printf("   - Cada vez que o jogador acerta o valor da operacao, as posicoes escolhidas nao estarao mais disponiveis e nao devem mostrar numeros.\n\n");
    printf("3. Diversidade de Operacoes:\n");
    printf("   - O jogador nao pode escolher sempre a mesma operacao matematica. Para garantir que as quatro operacoes sejam contempladas ele podera usar:\n");
    printf("  Adicao 5 vezes\n");
    printf("  Subtracao 4 vezes\n");
    printf("  Multiplicacao 4 vezes\n");
    printf("  Divisao 4 vezes\n\n");
    printf("4. Solicitacao de Resposta:\n");
    printf("   - Depois de tres tentativas erradas, o jogador pode pedir a resposta.\n\n");
    printf("5. Condicoes de Termino do Jogo:\n");
    printf("   - O jogo termina se:\n");
    printf("    - O jogador acerta todos os resultados das operacoes de todos os pares em um máximo de 24 tentativas (sao 18 pares de numeros).\n");
    printf("     - O jogador ultrapassa as 24 tentativas.\n");
    printf("     - O jogador deseja terminar o jogo.\n");
}

// Função para pausar o programa, esperando o usuário pressionar Enter
void pausarPrograma(char *r){
    char input;
    while (1) {
        printf("Pressione Enter para continuar ou 'e' para sair...\n");

        // Limpa o buffer de entrada
        fflush(stdin);

        input = getchar();

        if (input == 'e' || input == 'E') {
            printf("Programa encerrado.\n");
            *r = input; // Atribui o valor de input à variável apontada por r
            break;
        } else if (input == '\n') {
            printf("Continuando o programa...\n\n");
            break;
        }
    }
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

// Função que preenche a matriz com os números entre 1 a 9:
void PreencherMatriz() {
    srand(time(NULL));

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            V[i][j] = (rand() % 9) + 1; // Gera um número aleatório entre 1 e 9
        }
    }
}

// Função que apaga os números escolhidos da matriz, marcando-os com 0:
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

// Função que exibe a matriz do jogo com os números escolhidos destacados:
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
    do{
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
        } else if(lin2 == lin1 && col2== col1){
            printf("Essa posicao voce acabou de escolher, tente outra.\n");

        }
    } while (col2 < 0 || col2 > 4 || V[lin2][col2] == 0);

    } while(lin2 == lin1 && col2== col1);

    *Operando2 = V[lin2][col2];
}

//
void sinal(int *Operacao, char *oper) {
    int Operando1, Operando2;
    
    // Loop do-while para garantir que o usuário escolha uma operação válida e dentro dos limites
    do {
        do {
            // Usuário escolhe a operação
            printf("Escolha uma operacao (+ - / *): ");
            scanf(" %c", oper);

            // Verifica se o operador é válido
            if (*oper != '+' && *oper != '-' && *oper != '*' && *oper != '/') {
                printf("\nOperador invalido. Por favor, escolha um dos seguintes: +, -, *, /\n");
            }

        } while (*oper != '+' && *oper != '-' && *oper != '*' && *oper != '/');

        // Verifica se a operação escolhida já atingiu o limite de uso permitido
        if (*oper == '+' && soma == 5) {
            printf("Voce ja escolheu a operacao de soma 5 vezes. Escolha outra operacao!\n\n");
        } else if (*oper == '-' && sub == 4) {
            printf("Voce ja escolheu a operacao de subtracao 4 vezes. Escolha outra operacao!\n\n");
        } else if (*oper == '*' && mult == 4) {
            printf("Voce ja escolheu a operacao de multiplicacao 4 vezes. Escolha outra operacao!\n\n");
        } else if (*oper == '/' && divisao == 4) {
            printf("Voce ja escolheu a operacao de divisao 4 vezes. Escolha outra operacao!\n");
        }

    } while ((*oper == '+' && soma == 5) || (*oper == '-' && sub == 4) || (*oper == '*' && mult == 4) || (*oper == '/' && divisao == 4));


  // Incrementa o contador da operação escolhida
       if (*oper == '+') {
        soma++;
        printf("Voce escolheu a operacao de soma %d vezes.\n", soma);
       } else if (*oper == '-') {
        sub++;
        printf("Voce escolheu a operacao de subtracao %d vezes.\n", sub);
       } else if (*oper == '*') {
        mult++;
        printf("Voce escolheu a operacao de multiplicacao %d vezes.\n", mult);
       } else if (*oper == '/') {
        divisao++;
        printf("Voce escolheu a operacao de divisao %i vezes.\n", divisao);
       }

    // Ler os operandos já escolhidos pelo jogador
    Operando1 = V[lin1][col1];
    Operando2 = V[lin2][col2];

    // Determina o resultado da operação escolhida
    *Operacao = 0; // Inicializa a operação como zero
    if (*oper == '+') {
        *Operacao = Operando1 + Operando2;
    } else if (*oper == '-') {
        *Operacao = Operando1 - Operando2;
    } else if (*oper == '*') {
        *Operacao = Operando1 * Operando2;
    } else if (*oper == '/') {
        *Operacao = Operando1 / Operando2;
    }

}

