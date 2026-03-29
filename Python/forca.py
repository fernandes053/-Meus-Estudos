import random


def jogo_da_forca():

    palavras = ["coelho", "computador", "navio", "mochila", "chocolate", "amor", "python", "jogo", "programacao", "algoritmo"]
    palavra_sorteada = random.choice(palavras)
    letras_descobertas = ["_" for letra in palavra_sorteada]
    letras_usadas = []


    print("**********************")
    print("     Jogo da forca    ")
    print("**********************")

    print("Escolha sua dificuldade:")
    print("1 - Fácil (10 tentativas)")
    print("2 - Médio (6 tentativas)")
    print("3 - Difícil (3 tentativas)")


    dificuldade = int(input("\nDigite o número da dificuldade: "))

    while dificuldade < 1 or dificuldade > 3:
        print("\nDificuldade inválida, tente novamente")
        dificuldade = int(input("\nDigite o número da dificuldade: "))

    if dificuldade == 1:
        tentativas = 10
    elif dificuldade == 2:
        tentativas = 6
    else:
        tentativas = 3


    while tentativas > 0 and "_" in letras_descobertas:
        print("\nPalavra: ", " ".join(letras_descobertas))
        print(f"Tentativas restantes: {tentativas}")
        print(f"Letras já usadas: {', '.join(letras_usadas)}")

        chute = input("Digite uma letra: ").lower()

        if len(chute) != 1 or not chute.isalpha():
            print("Digite apenas UMA letra válida.")
            continue

        if chute in letras_usadas:
            print("Você já tentou essa letra. Tente outra.")
            continue

        letras_usadas.append(chute)

        if chute in palavra_sorteada:
            print(f"Boa! A letra '{chute}' está na palavra.")
            for i in range(len(palavra_sorteada)):
                if palavra_sorteada[i] == chute:
                    letras_descobertas[i] = chute
        else:
            print(f"A letra '{chute}' não está na palavra.")
            tentativas -= 1


    if "_" not in letras_descobertas:
        print("\nParabéns! Você descobriu a palavra:", palavra_sorteada)
    else:
        print("\nFim de jogo! A palavra era:", palavra_sorteada)

    print("Deseja jogar de novo?")
    escolha = int(input("(1) SIM | (2) NÃO "))

    while escolha < 1 or escolha > 2:
        print("Opção inválida, digite novamente")
        escolha = int(input("(1) SIM | (2) NÃO "))

    if escolha == 1:
        import jogos
        jogos.escolhe_jogo()
    else:
        print("Obrigado por jogar!")
    

    

    
