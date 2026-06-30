#ifndef CAMINHAO_H
#define CAMINHAO_H

#include "Veiculo.h"

class Caminhao : public Veiculo {
    public:
        // Construtor repassa os dados base e inicializa a capacidade de carga
        Caminhao(const string& placa, const string& marca, double quilometragem, double custoManutencao, double capacidadeCarga);

        // Implementação das funções virtuais puras da classe base
        double calculaCustoManutencao() const override;
        string getTipo() const override;

    protected:
        double capacidadeCarga;

        // Sobrescrita do método de impressão para estender o comportamento da base
        void imprime(ostream& os) const override;
};

#endif