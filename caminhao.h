#ifndef CAMINHAO_H
#define CAMINHAO_H

#include "Veiculo.h"

class Caminhao : public Veiculo {
    public:
        
        Caminhao(const string&, const string&, double, double, double);

        // Funcoes da classe veiculo
        double calculaCustoManutencao() const override;
        string getTipo() const override;

    protected:
        double capacidadeCarga;

        void imprime(ostream& os) const override;
};

#endif