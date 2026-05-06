//Creado por Fernando Castillo - 9959-25-288
//El 30/04/2006
#include "Cursos.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

//Constructor
Cursos::Cursos()
{
    this -> nombreCurso = "";
    this -> codigoCurso = "";
    this -> preRequisitoDeCurso = "";
    this -> estadoCurso = true;
}

//Constructor Sobrecargado
Cursos::Cursos(string nombreCurso, string codigoCurso, string preRequisitoDeCurso, bool estadoCurso)
{
    this -> nombreCurso = nombreCurso;
    this -> codigoCurso = codigoCurso;
    this -> preRequisitoDeCurso = preRequisitoDeCurso;
    this -> estadoCurso = estadoCurso;
}

//Crear vector
vector<Cursos> Cursos::catalagoCursosIngSistemas()
{
    //Se lleno el vector con todos los cursos de ingeniera en sistemas
    vector<Cursos> datosCursos;
    //Primer Ciclo
    datosCursos.push_back(Cursos("Desarrollo Humano y Profesional", "001", "Ninguno", true));
    datosCursos.push_back(Cursos("Metodologia de la Investigacion", "002", "Ninguno", true));
    datosCursos.push_back(Cursos("Contabilidad I", "003", "Ninguno", true));
    datosCursos.push_back(Cursos("Introduccion a los sistemas de computo", "004", "Ninguno", true));
    datosCursos.push_back(Cursos("Logica de Sistemas", "005", "Ninguno", true));
    //Segundo Ciclo
    datosCursos.push_back(Cursos("Precalculo", "006", "Ninguno", true));
    datosCursos.push_back(Cursos("Algebra Lineal", "007", "Ninguno", true));
    datosCursos.push_back(Cursos("Algoritmos", "008", "Ninguno", true));
    datosCursos.push_back(Cursos("Contabilidad II", "009","Ninguno", true));
    datosCursos.push_back(Cursos("Matematica Discreta", "010", "Ninguno", true));
    //Tercer Ciclo
    datosCursos.push_back(Cursos("Fisica I", "011", "006", true));
    datosCursos.push_back(Cursos("Programacion I", "012", "008", true));
    datosCursos.push_back(Cursos("Calculo I", "013", "006", true));
    datosCursos.push_back(Cursos("Proceso Administrativo", "014", "Ninguno", true));
    datosCursos.push_back(Cursos("Derecho Informatico", "015","Ninguno", true));
    //Cuarto Ciclo
    datosCursos.push_back(Cursos("Microeconomia", "016", "Ninguno", true));
    datosCursos.push_back(Cursos("Programacion II", "017", "012", true));
    datosCursos.push_back(Cursos("Calculo II", "018", "013", true));
    datosCursos.push_back(Cursos("Estadistica I", "019", "Ninguno", true));
    datosCursos.push_back(Cursos("Fisica II", "020","011", true));
    //Quinto Ciclo
    datosCursos.push_back(Cursos("Metodos Numericos", "021", "70 Crs.", true));
    datosCursos.push_back(Cursos("Programacion III", "022", "017", true));
    datosCursos.push_back(Cursos("Emprendedores de Negocios", "023", "Ninguno", true));
    datosCursos.push_back(Cursos("Electronica Analogia", "024", "020", true));
    datosCursos.push_back(Cursos("Estadistica II", "025","019", true));
    //Sexto Ciclo
    datosCursos.push_back(Cursos("Investigacion de Operaciones", "026", "80 Crs.", true));
    datosCursos.push_back(Cursos("Base de Datos I", "027", "022", true));
    datosCursos.push_back(Cursos("Automatas y Lenguaje Formales", "028", "80 Crs.", true));
    datosCursos.push_back(Cursos("Sistemas Operativos I", "029", "80 Crs.", true));
    datosCursos.push_back(Cursos("Electronica Digital", "030","024", true));
    //Septimo Ciclo
    datosCursos.push_back(Cursos("Base de Datos II", "031", "027", true));
    datosCursos.push_back(Cursos("Analisis de Sistemas I", "032", "100 Crs.", true));
    datosCursos.push_back(Cursos("Sistemas Operativos II", "033", "029", true));
    datosCursos.push_back(Cursos("Arquitectura de Computadoras I", "034", "100 Crs", true));
    datosCursos.push_back(Cursos("Compiladores", "035", "028", true));
    //Octavo Ciclo
    datosCursos.push_back(Cursos("Desarrollo Web", "036", "031", true));
    datosCursos.push_back(Cursos("Analisis de Sistemas II", "037", "032", true));
    datosCursos.push_back(Cursos("Redes de Computadora I", "038", "125 Crs.", true));
    datosCursos.push_back(Cursos("Etica Profesional", "039", "100 Crs.", true));
    datosCursos.push_back(Cursos("Arquitectura de Computadoras II", "040","034", true));
    //Noveno Ciclo
    datosCursos.push_back(Cursos("Administracion de Tecnologias de Informacion", "041", "150 Crs.", true));
    datosCursos.push_back(Cursos("Ingenieria de Software", "042", "150 Crs.", true));
    datosCursos.push_back(Cursos("Proyecto de Graduacion I", "043", "150 Crs.", true));
    datosCursos.push_back(Cursos("Redes de Computadoras II", "044", "038", true));
    datosCursos.push_back(Cursos("Inteligencia Artificial", "045","150 Crs.", true));
    //Decimo Ciclo
    datosCursos.push_back(Cursos("Telecomunicaciones", "046", "175 Crs.", true));
    datosCursos.push_back(Cursos("Seminario de Tecnoligias de Informacion", "047", "175 Crs.", true));
    datosCursos.push_back(Cursos("Aseguramiento de la Calidad de Software", "048", "175 Crs.", true));
    datosCursos.push_back(Cursos("Proyecto de Graduacion II", "049", "043", true));
    datosCursos.push_back(Cursos("Seguridad y Auditoria de Sistemas", "050","175 Crs.", true));
    return datosCursos;
}

//CRUD
void Cursos::menuInsertarCursos()
{
    int escogerOpcion = 0;
    char validacionAgregar;
    do{
        system("cls");
        cout << "\t\t\t\t\t---------------------------------" << endl;
        cout << "\t\t\t\t\t |   SISTEMA GESTION CURSOS    | " << endl;
        cout << "\t\t\t\t\t---------------------------------" << endl;
        cout << "\t\t\t\t\t 1. Ingresar Curso" << endl;
        cout << "\t\t\t\t\t 2. Desplegar Curso" << endl;
        cout << "\t\t\t\t\t 3. Modificar Curso" << endl;
        cout << "\t\t\t\t\t 4. Buscar Curso" << endl;
        cout << "\t\t\t\t\t 5. Borrar Curso" << endl;
        cout << "\t\t\t\t\t 6. Exit" << endl;

        cout << "\t\t\t\t\t---------------------------------" << endl;
        cout << "\t\t\t\t\t Opciones a Escoger: [1/2/3/4/5/6]" << endl;
        cout << "\t\t\t\t\t---------------------------------" << endl;
        cout << "¿Que opcion desea escoger?: "; cin >> escogerOpcion;

        switch(escogerOpcion)
        {
            case 1:
                do
                {
                    insertarCurso();
                    cout << "\n\t\t\t\t Agregar otro curso (S/N): "; cin >> validacionAgregar;
                }while (validacionAgregar == 's' || validacionAgregar == 'S');
                break;
            case 2:
                desplegarCurso();
                break;
            case 3:
                modificarCurso();
                break;
            case 4:
                buscarCurso();
                break;
            case 5:
                borrarCurso();
                break;
            case 6:
                exit(0);
            default:
                cout << "\n\t\t\t\t Opcion invalida... Por favor pruebe otra vez" << endl;
        }
        getch();
    }while (escogerOpcion != 6);

}

//Crear
void Cursos::insertarCurso()
{
        cin.ignore();
        system("cls");
        fstream file;
        cout << "\n------------------------------------------------------------------------------------------------------------";
        cout << "\n----------------------------------------Agregar Detalles del Curso-----------------------------------------" << endl;
        cout << "\t\t\t Ingrese id unico del curso: "; cin >> idUnicoCurso;
        cin.ignore();
        cout << "\t\t\t Ingrese nombre del curso: "; getline(cin, nombreCurso);
        cout << "\t\t\t Ingrese codigo del curso: "; getline(cin, codigoCurso);
        cout << "\t\t\t Ingrese pre-requiso del curso: "; getline(cin, preRequisitoDeCurso);
        file.open("Cursos.txt", ios::app | ios::out);
        file << std::left << std::setw(15) << idUnicoCurso << std::left << std::setw(30) << nombreCurso <<
        std::left << std::setw(15) << codigoCurso <<
        std::left << std::setw(15) << preRequisitoDeCurso << "\n";
        file.close();
}

//Desplegar
void Cursos::desplegarCurso()
{
    cin.ignore();
    system("cls");
    fstream file;
    int total = 0;
    cout << "\n----------------------------------------Tabla de Detalles de Personas-----------------------------------------" << endl;
    file.open("Cursos.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\t\t No hay información...";
        file.close();
    }
    else
    {
        file >> idUnicoCurso >> nombreCurso >> codigoCurso >> preRequisitoDeCurso;
        while(!file.eof())
        {
            total++;
            cout << "\n\n\t\t\t Id del curso: " << idUnicoCurso << endl;
            cout << "\t\t\t Nombre del curso: " << nombreCurso << endl;
            cout << "\t\t\t Codigo del curso: " << codigoCurso << endl;
            cout << "\t\t\t Pre-requisito del curso: " << preRequisitoDeCurso << endl;
            file >> idUnicoCurso >> nombreCurso >> codigoCurso >> preRequisitoDeCurso;
        }
        if (total == 0)
        {
            cout << "\t\t\t No hay información...";
        }
    }
    file.close();
}

//Modificar
void Cursos::modificarCurso()
{
    cin.ignore();
    system("cls");
    fstream file,file1;
    string participanteId = "";
    int found = 0;
    cout << "\n----------------------------------------Modificar Detalles Alumno-----------------------------------------" << endl;
    file.open("Cursos.txt", ios::in);
    if(!file)
    {
        cout << "\t\t\t No hay información...";
        file.close();
    }
    else
    {
        cout << "\n Ingrese el id del curso que quiere modificar: "; cin >> participanteId;
        file1.open("Record.txt", ios::app | ios::out);
        file >> idUnicoCurso >> nombreCurso >> codigoCurso >> preRequisitoDeCurso;
        while(!file.eof())
        {
            cout << "\t\t\t Ingrese id unico del curso: "; cin >> idUnicoCurso;
            cin.ignore();
            cout << "\t\t\t Ingrese nombre del curso: "; getline(cin, nombreCurso);
            cout << "\t\t\t Ingrese codigo del curso: "; getline(cin, codigoCurso);
            cout << "\t\t\t Ingrese pre-requisito del curso: "; getline(cin, preRequisitoDeCurso);
            file1 << std::left << std::setw(15) << idUnicoCurso << std::left << std::setw(30) << nombreCurso <<
            std::left << std::setw(15) << codigoCurso <<
            std::left << std::setw(15) << preRequisitoDeCurso << "\n";
            found++;
        }
        file >> idUnicoCurso >> nombreCurso >> codigoCurso >> preRequisitoDeCurso;
    }
    file1.close();
    file.close();
    remove("Cursos.txt");
    rename("Record.txt", "Cursos.txt");
}

//Buscar
void Cursos::buscarCurso()
{
    cin.ignore();
    system("cls");
    fstream file;
    int found = 0;
    file.open("Cursos.txt", ios::in);
    if(!file)
    {
        cout << "\n----------------------------------------Datos del Alumno Buscado-----------------------------------------" << endl;
        cout << "\t\t\t No hay información...";
    }
    else
    {
        string participanteId = "";
        cout << "\n----------------------------------------Datos del Alumno Buscado-----------------------------------------" << endl;
        cout << "\n Ingrese el id del curso que quiere buscar: "; cin >> participanteId;
        file >> idUnicoCurso >> nombreCurso >> codigoCurso >> preRequisitoDeCurso;
        while(!file.eof())
        {
            if (participanteId == idUnicoCurso)
            {
                cout << "\n\n\t\t\t Id del curso: " << idUnicoCurso << endl;
                cout << "\t\t\t Nombre del curso: " << nombreCurso << endl;
                cout << "\t\t\t Codigo del curso: " << codigoCurso << endl;
                cout << "\t\t\t Prerequisito del curso: " << preRequisitoDeCurso << endl;
                found++;
            }
            file >> idUnicoCurso >> nombreCurso >> codigoCurso >> preRequisitoDeCurso;
        }
        if (found == 0)
        {
            cout << "\t\t\t Curso encontrado...";
        }
        file.close();

    }
}

//Borrar
void Cursos::borrarCurso()
{
    cin.ignore();
    system("cls");
    fstream file,file1;
    string participanteId = "";
    int found = 0;
    cout << "\n----------------------------------------Detalles del Alumno a Borrar-----------------------------------------" << endl;
    file.open("Cursos.txt", ios::in);
    if(!file){
        cout << "\n\t\t\t\t No hay información..." << endl;
        file.close();
    }else{
        cout << "\n Ingrese el id del curso que quiere borrar: "; cin >> participanteId;
        file1.open("Record.txt", ios::app | ios::out);
        file >> idUnicoCurso >> nombreCurso >> codigoCurso >> preRequisitoDeCurso;
        while(!file.eof()){
            if (participanteId != idUnicoCurso){
                file1 << std::left << std::setw(15) << idUnicoCurso << std::left << std::setw(30) << nombreCurso <<
                        std::left << std::setw(15) << codigoCurso <<
                        std::left << std::setw(15) << preRequisitoDeCurso << "\n";
            }else{
                found++;
                cout << "\n\t\t\t\t Borrado de informacion exitoso";
            }
            file >> idUnicoCurso >> nombreCurso >> codigoCurso >> preRequisitoDeCurso;
        }
        if (found == 0){
            cout << "\n\t\t\t\t Id alumno no econtrado...";
        }
        file1.close();
        file.close();
        remove("Cursos.txt");
        rename("Record.txt", "Cursos.txt");
    }
}

//Getters
string Cursos::getnombreCurso()
{
    return this -> nombreCurso;
}
string Cursos::getpreRequisitoDeCurso()
{
    return this -> preRequisitoDeCurso;
}
string Cursos::getcodigoCurso()
{
    return this -> codigoCurso;
}
bool Cursos::getestadoCurso()
{
    return this -> estadoCurso;
}

//Setters
void Cursos::setnombreCurso(string nombreCurso)
{
    this -> nombreCurso = nombreCurso;
}
void Cursos::setpreRequisitoDeCurso(string preRequisitoDeCurso)
{
    this -> preRequisitoDeCurso = preRequisitoDeCurso;
}
void Cursos::setcodigoCurso(string codigoCurso)
{
    this -> codigoCurso = codigoCurso;
}
void Cursos::setestadoCurso(bool estadoCurso)
{
    this -> estadoCurso = estadoCurso;
}
