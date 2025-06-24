def escolhe_jogo():
    print("**********************")
    print("   Escolha seu jogo   ")
    print("**********************")

    print("(1) Jogo da forca | (2) Jogo do adivinha")
    jogo = int(input(""))

    if jogo == 1:
        import forca
        forca.jogo_da_forca()
    elif jogo == 2:
        import adivinha
        adivinha.jogo_do_adivinha()
    else:
        print("Opção inválida!")
        escolhe_jogo()