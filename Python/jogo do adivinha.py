import random

def main():
    print("********************************")
    print("    Jogo da Adivinhacao       ")
    print("******************************")
    print("\n")
    print("Escolha seu nivel de dificuldade:")
    print("Facil (F)  Medio (M)  Dificil (D)")

    dificuldade = input("\n").upper()
    resposta = random.randint(1, 100)
    tentativas = 0

    if dificuldade == 'F':
        tentativas = 15
        print("\nVoce escolheu o modo facil, Chute o numero que estou pensando (1-100):")
    elif dificuldade == 'M':
        tentativas = 10
        print("\nVoce escolheu o modo medio, Chute o numero que estou pensando (1-100):")
    elif dificuldade == 'D':
        tentativas = 5
        print("\nVoce escolheu o modo dificil, Chute o numero que estou pensando (1-100):")
    else:
        print("\nDificuldade invalida.")
        return

    for x in range(tentativas, 0, -1):
        try:
            numero = int(input())
        except ValueError:
            print("Por favor, digite um número válido.")
            continue

        if numero < resposta:
            print("\nNumero menor do que a resposta, tente novamente:")
        elif numero > resposta:
            print("\nNumero maior do que a resposta, tente novamente:")
        else:
            print(f"\nParabens voce acertou, o numero era {resposta}")
            return

        if x == 1:
            print(f"\nAcabaram suas tentativas, o numero era {resposta}")

if __name__ == "__main__":
    main()