#include "Caminhao.h"

// O construtor usa a lista de inicialização para enviar os dados para a classe base Veiculo
Caminhao::Caminhao(const string& placa, const string& marca, double quilometragem, double custoManutencao, double capacidadeCarga)
    : Veiculo(placa, marca, quilometragem, custoManutencao), capacidadeCarga(capacidadeCarga) {}

// Regra de negócio própria para o caminhão (ex: custo base multiplicado pela carga)
double Caminhao::calculaCustoManutencao() const {
    return custoManutencao + (capacidadeCarga * 50.0);
}

string Caminhao::getTipo() const {
    return "Caminhao";
}

// Estende a impressão usando os atributos protegidos da base graças ao "protected"
void Caminhao::imprime(ostream& os) const {
    Veiculo::imprime(os); // Chama a impressão padrão de Veiculo primeiro
    os << " | Capacidade Carga: " << capacidadeCarga << " toneladas";
}