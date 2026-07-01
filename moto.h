#ifndef MOTO_H
#define MOTO_H

#include "Veiculo.h"

class Moto : public Veiculo {
    public:
        Moto(const string&, const string&, double, double, int);

        double calculaCustoManutencao() const override;
        string getTipo() const override;

    protected:
        int cilindrada;

        void imprime(ostream& os) const override;
};

#endif