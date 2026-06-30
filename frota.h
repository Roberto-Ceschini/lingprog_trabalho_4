#ifndef FROTA_H
#define FROTA_H

#include <iostream>
#include <string>
#include "veiculo.h"
#include "arvore.h" 

using namespace std;

class Frota {
    public:

        // insere novo veiculo delegando para o operator+ da arvore
        Frota& insere(Veiculo*); 

        // metodo de busca por placa
        Veiculo* operator () (const string&); 

        // atualizacao da quilometragem
        Veiculo* operator () (const string&, double); 

        // delega para o operator<< da arvore
        void imprime() const;
        
        void calculaCustoManutencao() const;

    
    private:
        // instanciacao correta do template
        Arvore<Veiculo*> arvoreVeiculos;

        void acumulaCustos(
                typename Arvore<Veiculo*>::no*, 
                double&, int&,
                double&, int&,
                double&, 
                int&) const;
};

#endif