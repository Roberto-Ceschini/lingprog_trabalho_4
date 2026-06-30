#include <exception>

class VeiculoNaoEncontrado : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Erro: veículo não encontrado no sistema.";
        }
};