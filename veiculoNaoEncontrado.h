#ifndef VEICULO_NAO_ENCONTRADO_H
#define VEICULO_NAO_ENCONTRADO_H

#include <exception>
#include <string>

using namespace std;

class VeiculoNaoEncontrado : public exception {
    public:
        
        virtual const char* what() const throw() {
            return "Erro: Veiculo nao encontrado no sistema.";
        }
};

#endif