#ifndef CARRO_H
#define CARRO_H

#include "Veiculo.h"

class Carro : public Veiculo {
    public:
        Carro(const string& , const string&, double, double, int);

        double calculaCustoManutencao() const override;
        string getTipo() const override;

    protected:
        int numPortas;

        void imprime(ostream& os) const override;
};

#endif