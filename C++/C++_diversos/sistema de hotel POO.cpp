#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Quarto {
private:
    int numero;
    char categoria;
    bool ocupado;

public:
    Quarto(int num, char cat) {
        numero = num;
        categoria = cat;
        ocupado = false;
    }

    bool estaLivre() {
        return !ocupado;
    }

    char getCategoria() {
        return categoria;
    }

    int getNumero() {
        return numero;
    }

    void ocupar() {
        ocupado = true;
    }

    void liberar() {
        ocupado = false;
    }
};

class Hospede {
private:
    string nome;
    int acompanhantes;
    int dias;
    int numeroQuarto;

public:
    Hospede(string n, int a, int d, int q) {
        nome = n;
        acompanhantes = a;
        dias = d;
        numeroQuarto = q;
    }

    int calcularValor() {
        if (acompanhantes == 0)
            return dias * 85;
        else
            return dias * (acompanhantes + 1) * 65;
    }
};
