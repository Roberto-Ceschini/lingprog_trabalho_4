#ifndef VEICULO_H
#define VEICULO_H

#include <iostream>
#include <string>

using namespace std;

class Veiculo {
    public:

        Veiculo(const string&, const string&, double, double);

        // mtodos (Polimorfismo)
        virtual double calculaCustoManutencao() const = 0; 
        virtual string getTipo() const = 0; //agrupamento final da frota

        void atualizaQuilometragem(double);

        // Operadores de comparação (objeto vs objeto)
        bool operator>(const Veiculo& outro) const;
        bool operator==(const Veiculo& outro) const;

        // Operadores de busca (objeto vs String da Placa)
        bool operator==(const string&) const;
        bool operator<(const string&) const;

        friend ostream& operator<<(ostream& os, const Veiculo& veiculo);

    protected:
        string placa;
        string marca;
        double quilometragem;
        double custoManutencao;

        // Método virtual auxiliar para permitir que as classes filhas estendam a impressão
        virtual void imprime(ostream& os) const;
};

#endif