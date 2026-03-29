def main():
    print("Lojas Dos Manos\n")
    
    while True:
        precos = []
        
        while True:
            try:
                preco = float(input(f"Produto {len(precos)+1}: R$ "))
                if preco < 0:
                    print("\nPreço não pode ser negativo! Tente novamente.")
                    continue
                
                precos.append(preco)
                
                continuar = input("Deseja adicionar mais um produto? (S/N): ").upper()
                while continuar not in ('S', 'N'):
                    print("Opção inválida! Digite S para sim ou N para não: ", end="")
                    continuar = input().upper()
                
                if continuar == 'N':
                    break
            
            except ValueError:
                print("Valor inválido! Digite um número válido.")
                continue
        
        if not precos:
            print("\nNenhum produto foi registrado.")
            continue
        
        total = sum(precos)
        print(f"\nTotal: R$ {total:.2f}")
        
        while True:
            try:
                dinheiro = float(input("Dinheiro: R$ "))
                if dinheiro < total:
                    print("\nValor insuficiente. Tente novamente.")
                    continue
                break
            except ValueError:
                print("Valor inválido! Digite um número válido.")
        
        troco = dinheiro - total
        print(f"Troco: R$ {troco:.2f}")
        
        continuar = input("\nDeseja iniciar uma nova compra? (S/N): ").upper()
        while continuar not in ('S', 'N'):
            print("Opção inválida! Digite S para sim ou N para não: ", end="")
            continuar = input().upper()
        
        if continuar == 'N':
            break
    
    print("\nObrigado por usar o sistema! Até a próxima na cara dos manos")

if __name__ == "__main__":
    main()