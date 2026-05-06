//creado por Moises De Leon 9959-25-18795
#ifndef BANCOS_H
#define BANCOS_H
#include <string>


class Bancos
{
    public:
        Bancos();
        virtual ~Bancos();
        bool InfoTransferencia(std::string nombreBanco, std::string nombreCliente, long long numeroTarjeta);
        bool InfoPagoPlanilla(std::string nombreBanco, std::string nombreCliente, int idCuenta);
        bool procesoTransferencia(long long numeroTarjeta, double monto, double saldoCuenta);
        bool procesoPagoPlanilla(int idCuenta, double monto, double saldoCuenta);
        bool crearCuenta(std::string nombreCliente, double monto, std::string nombreBanco);
    protected:

    private:
        std::string nombreBanco;
        std::string nombreCliente;
        double saldo;
        double movimiento;
        int idCuenta;
        long long numeroTarjeta;
        int generadorTarjetasCuentas();
        bool guardarCuenta(int idCuenta, std::string nombreCliente, double saldo, double movimiento, long long numeroTarjeta, std::string nombreBanco);

};

#endif // BANCOS_H
