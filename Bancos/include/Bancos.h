#ifndef BANCOS_H
#define BANCOS_H
#include <string>


class Bancos
{
    public:
        Bancos();
        virtual ~Bancos();
        bool procesoTransferencia(std::string nombreCliente, int numeroCuenta, double monto);
        bool procesoPagoPlanilla(std::string nombreCliente, int numeroCuenta, double monto);

    protected:

    private:
        std::string titularCuenta;
        double saldo;
        int idCuenta;


};

#endif // BANCOS_H
