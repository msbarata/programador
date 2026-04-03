//6-PPT
void ppt() {
    cls();
    pontosJogador = 0;
    pontosComputador = 0;
    char *opcoes[] = {"Pedra", "Papel", "Tesoura"};
    srand(time(NULL));

    while (pontosJogador < 2 && pontosComputador < 2) {
        printf("\nEscolhe a tua jogada:\n");
        printf("1) Pedra\n2) Papel\n3) Tesoura\nA tua opção: "); scanf("%d", &escolha);

        if (escolha < 1 || escolha > 3) {
            printf("Jogada inválida. Tenta novamente.\n"); continue;
        }

        computador = rand() % 3 + 1;

        printf("Escolheste: %s\n", opcoes[escolha - 1]);
        printf("Computador escolheu: %s\n", opcoes[computador - 1]);

        if (escolha == computador) {
            printf("Empate!\n");
        } else if ((escolha == 1 && computador == 3) || (escolha == 2 && computador == 1) || (escolha == 3 && computador == 2)) {
            printf("Ganhaste esta ronda!\n");
            pontosJogador++;
        } else {
            printf("Computador ganhou esta ronda!\n");
            pontosComputador++;
        }

        printf("Pontuação: Você %d - %d Computador\n", pontosJogador, pontosComputador);
    }

    if (pontosJogador == 2)
        printf("\nParabéns! Ganhaste!\n");
    else
        printf("\nO computador venceu. Tenta novamente!\n");
}