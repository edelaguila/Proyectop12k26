//creado por Moises De Leon 9959-25-18795
#include "Bancos.h"
#include <iostream>
#include <random>
#include <string>
#include <fstream>
#include <iomanip>

Bancos::Bancos()
{
    //ctor
}
bool Bancos::crearCuenta(std::string nombreCliente, double monto, std::string nombreBanco)
{
    this ->idCuenta = generadorTarjetasCuentas();
    this ->nombreCliente = nombreCliente;
    this ->saldo = monto;
    this ->movimiento = monto;
    this ->nombreBanco = nombreBanco;
    this ->numeroTarjeta = 0;
    if(nombreBanco=="BAC"){
        numeroTarjeta=5547961400000000LL+generadorTarjetasCuentas();
    } else if(nombreBanco=="G&T"){
        numeroTarjeta=7511451800000000LL+generadorTarjetasCuentas();
    } else if(nombreBanco=="Banco Industrial"){
        numeroTarjeta=9655147700000000LL+generadorTarjetasCuentas();
    }else{
        numeroTarjeta=7414220100000000LL+generadorTarjetasCuentas();
    }
    if (guardarCuenta(idCuenta, nombreCliente, saldo, movimiento, numeroTarjeta, nombreBanco))
    {
        return true;
    }else
    {
        return false;
    }
}

bool Bancos::guardarCuenta(int idCuenta, std::string nombreCliente, double saldo, double movimiento, long long numeroTarjeta, std::string nombreBanco)
{
std::fstream file;
    file.open("CuentasBancarias.txt", std::ios::app | std::ios::out);
    if (file.is_open())
    {
        file << std::left << std::setw(15) << idCuenta
             << std::left << std::setw(20) << nombreCliente
             << std::left << std::setw(15) << saldo
             << std::left << std::setw(15) << movimiento
             << std::left << std::setw(20) << numeroTarjeta
             << std::left << std::setw(10) << nombreBanco<< "\n";

        file.close();
        return true;
    }
    else
    {
        return false;
    }
}

int Bancos::generadorTarjetasCuentas()
{
    static std::random_device numero;
    static std::mt19937 gen(numero());
    std::uniform_int_distribution<int> dis(10000000, 99999999);
    return dis(gen);
}
Bancos::~Bancos()
{
    //dtor
}
