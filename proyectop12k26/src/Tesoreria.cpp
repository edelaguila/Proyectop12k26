#include "Tesoreria.h"
#include "Bancos.h"
#include "Recepcion.h"
#include "GeneradorConstancias.h"

#include <iostream>
#include <string>

using namespace std;

// Constructor
Tesoreria::Tesoreria()
{
}

// Menu principal de Tesoreria
void Tesoreria::menu()
{
    int opcion;

    Bancos banco;
    Recepcion recepcion;
    GeneradorConstancias constancia;

    do
    {
        system("cls");

        cout << "==========================================" << endl;
        cout << "              MODULO TESORERIA            " << endl;
        cout << "==========================================" << endl;
        cout << "1. Gestiones Bancarias" << endl;
        cout << "2. Recepcion de Pagos" << endl;
        cout << "3. Generar Constancia" << endl;
        cout << "4. Regresar al Menu Principal" << endl;
        cout << "==========================================" << endl;
        cout << "Seleccione una opcion: ";

        cin >> opcion;
        cin.ignore();

        switch(opcion)
        {
            case 1:
            {
                system("cls");
                banco.desplegarMenu();
                break;
            }

            case 2:
            {
                system("cls");

                cout << "===== RECEPCION DE PAGOS =====" << endl;
                cout << "Validando datos del alumno previamente registrado..." << endl;

                // Aqui Recepcion solo valida datos ya registrados
                // El alumno debe venir desde Registro general del sistema
                cout << "\nNOTA: Integrar con modulo Registro para datos reales." << endl;

                recepcion.menu();

                system("pause");
                break;
            }

     case 3:
{
    constancia.menu();
    // No necesita system("pause") aqui porque tu menu() ya los tiene adentro
    break;
}
            case 4:
                cout << "\nRegresando al menu principal..." << endl;
                break;

            default:
                cout << "\nOpcion invalida. Intente nuevamente." << endl;
                system("pause");
                break;
        }

    } while(opcion != 4);
}
