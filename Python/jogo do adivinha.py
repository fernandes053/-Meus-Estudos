import random


num_secreto = random.randint(2, 101)
pontos=100

print("**********************")
print("   Jogo do Adivinha   ")
print("**********************")


print("Escolha sua dificuldade:")
print("1 - Fácil (10 tentativas)")
print("2 - Médio (6 tentativas)")
print("3 - Difícil (3 tentativas)")

dificuldade = int(input("Digite o número da dificuldade: "))


while dificuldade < 1 or dificuldade > 3:
    print("Dificuldade inválida, tente novamente.")
    dificuldade = int(input("Digite o número da dificuldade: "))


if dificuldade == 1:
    tentativas = 10
elif dificuldade == 2:
    tentativas = 6
else:
    tentativas = 3


for tentativa in range(1, tentativas + 1):
    print(f"\nTentativa {tentativa} de {tentativas}")
    palpite = int(input("Digite seu palpite (1 a 100): "))

    if palpite < 1 or palpite > 100:
        print("Palpite fora do intervalo! Tente entre 1 e 100.")
        continue

    if palpite == num_secreto:
        print(f"Parabéns! Você acertou o número {num_secreto}! / Pontuacao: ", pontos)
        break
    elif palpite > num_secreto:
        print("\nO número secreto é **maior**.")
        pontos_perdidos=abs(num_secreto-palpite)
        pontos=abs(pontos-pontos_perdidos)

    else:
        print("\nO número secreto é **menor**.")
    pontos_perdidos=abs(num_secreto-palpite)
    pontos=abs(pontos-pontos_perdidos)

else:
    print(f"\nSuas tentativas acabaram! O número era {num_secreto}. Boa sorte na próxima!")

