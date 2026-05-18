#include "Bancos.h"
#include "GeneradorConstancias.h"
#include <iostream>
#include <random>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>

const int ID_CUENTA_UMG = 28419906;
using namespace std;

Bancos::Bancos()
{
    // constructor
}

void Bancos::desplegarMenu()
{
    int opcion = 0;
    string nombre;
    string banco;
    double monto = 0.0;
    long long tarjeta = 0;
    int id = 0;
    int codigo = 0;

    while (opcion != 6)
    {
        system("cls");
        cout << "=== MENU BANCARIO UMG ===" << endl;
        cout << "1. Crear Cuenta" << endl;
        cout << "2. Realizar Pago (Transferencia Alumno)" << endl;
        cout << "3. Realizar Pago a Maestros (Planilla)" << endl;
        cout << "4. Desplegar Cuentas" << endl;
        cout << "5. Borrar Cuenta" << endl;
        cout << "6. Salir" << endl;
        cout << "=========================" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion)
        {
            case 1:
                system("cls");
                cout << "--- CREAR CUENTA ---" << endl;
                cout << "Nombre del cliente: ";
                getline(cin, nombre);
                cout << "Monto inicial: Q";
                cin >> monto;
                cout << "Nombre del banco (BAC, G&T, Banco Industrial): ";
                cin.ignore();
                getline(cin, banco);
                crearCuenta(nombre, monto, banco);
                system("pause");
                break;

            case 2:
                system("cls");
                cout << "--- REALIZAR PAGO (TRANSFERENCIA) ---" << endl;
                cout << "Nombre del alumno: ";
                getline(cin, nombre);
                cout << "Numero de tarjeta: ";
                cin >> tarjeta;
                cout << "Carnet: ";
                cin >> id;
                InfoTransferencia(nombre, tarjeta, id);
                system("pause");
                break;

            case 3:
                system("cls");
                cout << "--- PAGO A MAESTROS (PLANILLA) ---" << endl;
                cout << "Nombre del maestro: ";
                getline(cin, nombre);
                cout << "ID de cuenta del maestro: ";
                cin >> id;
                cout << "Codigo de catedratico: ";
                cin >> codigo;
                InfoPagoPlanilla(nombre, id, codigo);
                system("pause");
                break;

            case 4:
                desplegarCuentas();
                system("pause");
                break;

            case 5:
                system("cls");
                cout << "--- BORRAR CUENTA ---" << endl;
                cout << "Ingrese ID de cuenta a borrar: ";
                cin >> id;
                borrarCuenta(id);
                system("pause");
                break;

            case 6:
                cout << "\nGracias por utilizar el sistema bancario." << endl;
                break;

            default:
                cout << "\nOpcion no valida. Intente de nuevo." << endl;
                system("pause");
                break;
        }
    }
}

bool Bancos::InfoTransferencia(string nombreCliente, long long numeroTarjeta, int numeroCarnet)
{
    fstream file;
    int idArch;
    string clienteArch;
    double saldoArch;
    long long tarjetaArch;
    string bancoArch;
    bool encontrado = false;

    file.open("CuentasBancarias.txt", ios::in);

    if(file.is_open())
    {
        file.clear();

        while (file >> idArch >> clienteArch >> saldoArch >> tarjetaArch >> bancoArch)
        {
            if(tarjetaArch == numeroTarjeta && clienteArch == nombreCliente)
            {
                this->idCuenta = idArch;
                this->saldo = saldoArch;
                this->nombreBanco = bancoArch;
                encontrado = true;
                break;
            }
        }
        file.close();
    }
    else
    {
        cout << "Error: No se pudo abrir CuentasBancarias.txt" << endl;
    }

    this->movimiento = montoCobro(nombreCliente);

    if(encontrado)
    {
        cout << "Cuenta encontrada con exito." << endl;
        cout << "Cliente: " << nombreCliente << endl;
        cout << "Cuenta No. " << this->idCuenta << endl;

        if (procesoTransferencia(numeroTarjeta, this->movimiento))
        {
            cout << "Transaccion exitosa." << endl;
            return true;
        }
        else
        {
            cout << "Error con la transferencia." << endl;
            return false;
        }
    }
    else
    {
        cout << "Error: La cuenta no se ha encontrado." << endl;
        return false;
    }
}

bool Bancos::InfoPagoPlanilla(string nombreCliente, int idCuenta, int codigoCatedratico)
{
    fstream file;
    int idArch;
    string clienteArch, bancoArch;
    double saldoArch;
    long long tarjetaArch;
    bool encontrado = false;

    file.open("CuentasBancarias.txt", ios::in);

    if (file.is_open())
    {
        while (file >> idArch >> clienteArch >> saldoArch >> tarjetaArch >> bancoArch)
        {
            if (idArch == idCuenta && clienteArch == nombreCliente)
            {
                this->nombreCliente = clienteArch;
                encontrado = true;
                break;
            }
        }
        file.close();
    }
    this->movimiento = montoPago(codigoCatedratico);
    if (encontrado)
    {
        cout << "Cuenta encontrada: " << this->nombreCliente << endl;
        if (procesoPagoPlanilla(idCuenta, this->movimiento))
        {
            cout<<"pago realizado con exito"<<endl;
            return true;
        }
        else{
            cout<<"Error. El pago no pudo realizarse con exito"<<endl;
            return false;
        }
    }
    else
    {
        cout << "Error: No se encontro el ID de cuenta." << endl;
        return false;
    }
}

bool Bancos::procesoTransferencia(long long numeroTarjetaOrigen, double monto)
{
    fstream file, tempFile;
    int idArch;
    long long tarjetaArch;
    string clienteArch, bancoArch;
    double saldoArch;

    bool origenProcesado = false;
    bool destinoProcesado = false;

    file.open("CuentasBancarias.txt", ios::in);
    tempFile.open("Temp.txt", ios::out);

    if (file.is_open() && tempFile.is_open())
    {
        while (file >> idArch >> clienteArch >> saldoArch >> tarjetaArch >> bancoArch)
        {
            if (tarjetaArch == numeroTarjetaOrigen)
            {
                if (saldoArch >= monto)
                {
                    saldoArch -= monto;
                    origenProcesado = true;
                }
                else
                {
                    cout << "Error: Saldo insuficiente en la cuenta de origen." << endl;
                }
            }

            if (clienteArch == "UMG")
            {
                saldoArch += monto;
                destinoProcesado = true;
            }

            tempFile << left << setw(15) << idArch
                     << left << setw(20) << clienteArch
                     << left << setw(15) << saldoArch
                     << left << setw(20) << tarjetaArch
                     << left << setw(20) << bancoArch << "\n";
        }

        file.close();
        tempFile.close();

        if (origenProcesado && destinoProcesado)
        {
            remove("CuentasBancarias.txt");
            rename("Temp.txt", "CuentasBancarias.txt");
            return true;
        }
        else
        {
            remove("Temp.txt");

            if (!origenProcesado) {
                cout << "Error: No se pudo procesar la cuenta de origen." << endl;
            }
            if (!destinoProcesado) {
                cout << "Error critico: La cuenta de la UMG no fue encontrada en el archivo." << endl;
            }
            return false;
        }
    }
    return false;
}

bool Bancos::procesoPagoPlanilla(int idCuenta, double monto)
{
    fstream file, tempFile;
    int idArch;
    long long tarjetaArch;
    string clienteArch, bancoArch;
    double saldoArch;

    bool origenProcesado = false;
    bool destinoProcesado = false;

    file.open("CuentasBancarias.txt", ios::in);
    tempFile.open("Temp.txt", ios::out);

    if (file.is_open() && tempFile.is_open())
    {
        while (file >> idArch >> clienteArch >> saldoArch >> tarjetaArch >> bancoArch)
        {
            if (idArch == ID_CUENTA_UMG)
            {
                if (saldoArch >= monto)
                {
                    saldoArch -= monto;
                    origenProcesado = true;
                }
                else
                {
                    cout << "Error: Saldo insuficiente en la cuenta de UMG." << endl;
                }
            }
            else if (idArch == idCuenta)
            {
                saldoArch += monto;
                destinoProcesado = true;
            }

            tempFile << left << setw(15) << idArch
                     << left << setw(20) << clienteArch
                     << left << setw(15) << saldoArch
                     << left << setw(20) << tarjetaArch
                     << left << setw(20) << bancoArch << "\n";
        }

        file.close();
        tempFile.close();

        if (origenProcesado && destinoProcesado)
        {
            remove("CuentasBancarias.txt");
            rename("Temp.txt", "CuentasBancarias.txt");
            return true;
        }
        else
        {
            remove("Temp.txt");

            if (!destinoProcesado && origenProcesado) {
                cout << "Error critico: Transaccion cancelada. La cuenta destino no existe." << endl;
            }
            return false;
        }
    }

    cout << "Error: No se pudo acceder a la base de datos." << endl;
    return false;
}

double Bancos::montoCobro(string nombreAlumno)
{
    fstream file;
    long long tarjetaArch;
    string nombreArch;
    string mesArch;
    double montoArch;

    double montoEncontrado = 0.0;

    file.open("tarjetadebito.txt", ios::in);

    if (file.is_open())
    {
        while (file >> tarjetaArch >> nombreArch >> mesArch >> montoArch)
        {
            if (nombreArch == nombreAlumno)
            {
                montoEncontrado = montoArch;
                break;
            }
        }
        file.close();
    }
    else
    {
        cout << "Error: No se pudo abrir el archivo tarjetdebito.txt" << endl;
    }

    return montoEncontrado;
}

double Bancos::montoPago(int codigo)
{
    fstream file;
    string linea;
    double montoEncontrado = 0.0;

    file.open("Salarios_Maestros.txt", ios::in);

    if (file.is_open())
    {
        while (getline(file, linea))
        {
            stringstream ss(linea);
            string campo;
            int codigoArch = 0;

            while (getline(ss, campo, '|'))
            {
                if (campo.find("ID:") != string::npos)
                {
                    size_t posId = campo.find("ID:") + 3;
                    while (posId < campo.length() && isspace(campo[posId])) posId++;

                    string strId = "";
                    while (posId < campo.length() && isdigit(campo[posId]))
                    {
                        strId += campo[posId];
                        posId++;
                    }
                    if (!strId.empty())
                    {
                        codigoArch = stoi(strId);
                    }
                }
            }

            if (codigoArch == codigo)
            {
                size_t posSalario = linea.rfind("Salario:");
                if (posSalario != string::npos)
                {
                    size_t posQ = linea.find('Q', posSalario);
                    if (posQ != string::npos)
                    {
                        string strMonto = linea.substr(posQ + 1);
                        montoEncontrado = stod(strMonto);
                        break;
                    }
                }
            }
        }
        file.close();
    }
    else
    {
        cout << "Error: No se pudo abrir el archivo Salarios_Maestros.txt" << endl;
    }

    return montoEncontrado;
}

bool Bancos::crearCuenta(string nombreCliente, double monto, string nombreBanco)
{
    this->idCuenta = generadorTarjetasCuentas();
    this->nombreCliente = nombreCliente;
    this->saldo = monto;
    this->nombreBanco = nombreBanco;
    this->numeroTarjeta = 0;

    if (nombreBanco == "BAC") {
        numeroTarjeta = 5547961400000000LL + generadorTarjetasCuentas();
    }
    else if (nombreBanco == "G&T") {
        numeroTarjeta = 7511451800000000LL + generadorTarjetasCuentas();
    }
    else if (nombreBanco == "Banco Industrial") {
        numeroTarjeta = 9655147700000000LL + generadorTarjetasCuentas();
    }
    else {
        numeroTarjeta = 7414220100000000LL + generadorTarjetasCuentas();
    }

//Parte de constancias
    string carnetIngresado;
    cout << "\n>>> PROCESO DE CONSTANCIA <<<" << endl;
    cout << "Ingrese el carnet para el comprobante: ";
    cin >> carnetIngresado;

    GeneradorConstancias miConstancia;
    miConstancia.recibirDatos(nombreCliente, carnetIngresado, monto, 1);

    miConstancia.disenoConstancia();
    cout << endl;
    system("pause");

    cout << ">>> FIN DE CONSTANCIA <<<\n" << endl;
    return guardarCuenta(idCuenta, nombreCliente, saldo, numeroTarjeta, nombreBanco);
}


bool Bancos::guardarCuenta(int idCuenta, string nombreCliente, double saldo, long long numeroTarjeta, string nombreBanco)
{
    fstream file;
    file.open("CuentasBancarias.txt", ios::app | ios::out);

    if (file.is_open())
    {
        file << left << setw(15) << idCuenta
             << left << setw(20) << nombreCliente
             << left << setw(15) << saldo
             << left << setw(20) << numeroTarjeta
             << left << setw(20) << nombreBanco
             << "\n";

        file.close();
        return true;
    }

    return false;
}

int Bancos::generadorTarjetasCuentas()
{
    static random_device numero;
    static mt19937 gen(numero());
    uniform_int_distribution<int> dis(10000000, 99999999);

    return dis(gen);
}

bool Bancos::borrarCuenta(int idCuentaBorrar)
{
    fstream file, tempFile;
    int idArch;
    long long tarjetaArch;
    string clienteArch, bancoArch;
    double saldoArch;
    bool eliminado = false;

    file.open("CuentasBancarias.txt", ios::in);
    tempFile.open("Temp.txt", ios::out);

    if (file.is_open() && tempFile.is_open())
    {
        while (file >> idArch >> clienteArch >> saldoArch >> tarjetaArch >> bancoArch)
        {
            if (idArch == idCuentaBorrar)
            {
                eliminado = true;
                continue;
            }

            tempFile << left << setw(15) << idArch
                     << left << setw(20) << clienteArch
                     << left << setw(15) << saldoArch
                     << left << setw(20) << tarjetaArch
                     << left << setw(20) << bancoArch << "\n";
        }

        file.close();
        tempFile.close();

        if (eliminado)
        {
            remove("CuentasBancarias.txt");
            rename("Temp.txt", "CuentasBancarias.txt");
            cout << "La cuenta con ID " << idCuentaBorrar << " fue eliminada exitosamente." << endl;
            return true;
        }
        else
        {
            remove("Temp.txt");
            cout << "Error: No se encontro ninguna cuenta con el ID " << idCuentaBorrar << "." << endl;
            return false;
        }
    }
    else
    {
        cout << "Error: No se pudo abrir el archivo de cuentas." << endl;
        return false;
    }
}

void Bancos::desplegarCuentas()
{
    fstream file;
    int idArch;
    long long tarjetaArch;
    string clienteArch, bancoArch;
    double saldoArch;
    bool tieneDatos = false;

    file.open("CuentasBancarias.txt", ios::in);

    if (file.is_open())
    {
        system("cls");
        cout << "=================================================================================" << endl;
        cout << "                           LISTADO DE CUENTAS BANCARIAS                          " << endl;
        cout << "=================================================================================" << endl;
        cout << left << setw(15) << "ID Cuenta"
             << left << setw(20) << "Cliente"
             << left << setw(15) << "Saldo"
             << left << setw(20) << "No. Tarjeta"
             << left << setw(20) << "Banco" << endl;
        cout << "---------------------------------------------------------------------------------" << endl;

        while (file >> idArch >> clienteArch >> saldoArch >> tarjetaArch >> bancoArch)
        {
            cout << left << setw(15) << idArch
                 << left << setw(20) << clienteArch
                 << left << "Q" << setw(14) << fixed << setprecision(2) << saldoArch
                 << left << setw(20) << tarjetaArch
                 << left << setw(20) << bancoArch << endl;
            tieneDatos = true;
        }

        if (!tieneDatos)
        {
            cout << "\n   No hay cuentas bancarias registradas en el sistema." << endl;
        }

        cout << "=================================================================================" << endl;
        file.close();
    }
    else
    {
        cout << "Error: No se pudo abrir el archivo CuentasBancarias.txt" << endl;
    }
}

Bancos::~Bancos()
{
    // dtor
}
