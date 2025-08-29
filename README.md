# Jogo Matemático Infantil

## Descrição

Este é um **jogo infantil em C** desenvolvido na disciplina de Algoritmos (2024.1), onde o jogador interage com uma tabela de números e realiza operações matemáticas básicas (adição, subtração, multiplicação e divisão). O objetivo é **adivinhar o resultado das operações corretamente** e acumular pontos.

O projeto foi criado com o propósito de **praticar lógica de programação em C**, manipulação de matrizes, estruturas de repetição, controle de fluxo e funções.

---

## Regras do Jogo

1. **Escolha de Números e Operações**

   * O jogador escolhe um par de números da matriz e uma operação aritmética.
   * Em seguida, deve indicar o resultado da operação.

2. **Acerto de Operações**

   * Cada acerto remove os números escolhidos da tabela, tornando essas posições indisponíveis.

3. **Diversidade de Operações**

   * O jogador não pode usar sempre a mesma operação.
   * Limite de uso de cada operação:

     * Adição: 5 vezes
     * Subtração: 4 vezes
     * Multiplicação: 4 vezes
     * Divisão: 4 vezes

4. **Solicitação de Resposta**

   * Após **três tentativas erradas**, o jogador pode pedir a resposta.

5. **Condições de Término**

   * O jogo termina quando:

     * O jogador acerta todos os pares de números (máximo de 24 tentativas, 18 pares de números)
     * O jogador ultrapassa as 24 tentativas
     * O jogador decide encerrar o jogo

---

## Funcionalidades

* Tabela interativa com números
* Escolha de pares de números pelo jogador
* Operações matemáticas: adição, subtração, multiplicação e divisão
* Contagem de pontos baseada nos acertos
* Limite de tentativas e operações para tornar o jogo mais desafiador
* Opção de pedir a resposta após três erros

---

## Tecnologias utilizadas

* Linguagem: **C**
* Ferramentas: **Compilador GCC / qualquer IDE de C**
---
