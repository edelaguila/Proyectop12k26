#include "maestros.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
using namespace std;

Maestros::Maestros()
{
    nombre = "";
    apellido = "";
    correo = "";
    codigo = 0;
    sede = "";
    diasSemana = 3;
    horasClase = 2;

}

void Maestros::ingresarDatosPersonales()
{
    cout << "--- Ingreso de datos personales ---" << endl;
    cout << "Ingrese su nombre: ";
    cin >> nombre;
    cout << "Ingrese su apellido: ";
    cin >> apellido;

    generarCorreo();
    generarCodigo();
}
void Maestros::generarCorreo(){
    correo = nombre + apellido + "@miumg.edu.gt";
    cout << "Correo generado : " <<  correo << endl;
}

void Maestros::generarCodigo(){
    srand(time(0));
    codigo = 1000 + rand() % 9000;
    cout << "Codigo de seguridad: " << codigo << endl;
}

void Maestros::asignarHorario(){
    cout <<"--- Asignación de Horario ---" << endl;
    cout << "Seleccione la sede" << endl;
    cout << "1- Sede Zona Portales" << endl;
    cout << "2- Central" << endl;
    cout << "3- Sede Antigua" << endl;
    cout << "4- Sede San Jose Pinula" << endl;
    cout << "Opcion: ";
    int opcionSede;
    cin >> opcionSede;

    diasSemana = 3;
    cout << "Dias a la semana asignados por el sistema: "<< diasSemana << "días" << endl;

    horasClase = 2;
    cout << "Horas por clase asignadas: " << horasClase << "horas" << endl;

    switch (opcionSede){
    case 1: sede = "Sede Zona Portales";break;
    case 2: sede = "Central";break;
    case 3: sede = "Sede Antigua";break;
    case 4: sede = "Sede San Jose Pinula";break;
    default: sede = "No especificada"; break;
    }

    cout << "Sede asignada: " << sede << endl;

}

void Maestros::mostrarCarreras(){
    cout << "Carreras disponibles" << endl;
    vector<carrera> carreras = carrera().datoscarreras();

    for(int i = 0; i < carreras.size(); i++){
        if(carreras[i].getestadocarrera()){
            cout << i+1<< "." << carreras[i].getnombrecarrera()
            << "Codigo: " << carreras[i].getcodigocarrera() << endl;
        }
    }
}

void Maestros::mostrarCursosPorCarrera(string codigoCarrera){
    cout << "Cursos disponibles para esta carrera" << endl;

    if(codigoCarrera == "9959"){

        vector<Cursos> cursos = curso.catalagoCursosIngSistemas();
        int contador = 1;

        for(int i = 0; cursos.size(); i++){
            if(cursos[i].getestadoCurso()){
                cout << contador << ". " << cursos[i].getnombreCurso() << "Codigo: " << cursos[i].getcodigoCurso() << " " << endl;
                cout << "Pre-requisito: " << cursos[i].getpreRequisitoDeCurso() << endl;
                contador++;
            }
        }
    }
    else{
        cout << "No hay cursos registrados para esta carrera" << endl;
    }
}


void Maestros::asignarCurso(){
    cout << "Asignación Curso" << endl;

    int codigoIngresado;
    cout << "Ingrese su codigo: ";
    cin >> codigoIngresado;

    if(!verificarCodigo(codigoIngresado)){
        cout << "Codigo incorrecto" <<  endl;
        return;
    }

    mostrarCarreras();

    int opcionCarrera;
    cout << "Seleccione la carrera: ";
    cin >> opcionCarrera;


    vector<carrera> carreras = carrera().datoscarreras();

    if(opcionCarrera >= 1 && opcionCarrera <= carreras.size()){
        carreraSeleccionada = carreras[opcionCarrera - 1];
        cout << "Carrera seleccinada: " << carreraSeleccionada.getnombrecarrera() <<endl;

        mostrarCursosPorCarrera(carreraSeleccionada.getcodigocarrera());

        if(carreraSeleccionada.getcodigocarrera() == "9959"){
            Cursos cursoTemp;
            vector<Cursos> cursos = cursoTemp.catalagoCursosIngSistemas();

            int opcionCurso;

        if(opcionCurso >= 1 && opcionCurso <= cursos.size()){
            curso = cursos[opcionCurso - 1];
            cout << "Asignacion completada" << endl;
            cout << "Curso seleccionado: " << curso.getnombreCurso() << endl;
            cout << "Codigo del curso: " << curso.getnombreCurso() << endl;
            cout << "Pre-requisito: " << curso.getpreRequisitoDeCurso() << endl;

            asignarHorario();
            cout << "Salario: Q" << calcularSalario() << endl;

        }
        else{
            cout << "Opcion no valida" << endl;
        }
    }
    }
    else {
        cout << "Opcion no valida" << endl;
    }
}

double Maestros::calcularSalario(){
    double salarioBase = (diasSemana * horasClase * 4 * 150);
    double bonoSede = 0;

    if(sede == "Central")
        bonoSede = 500;
    else if (sede == "Sede Antigua")
        bonoSede = 300;
    else if (sede == "Sede Zona Portales")
        bonoSede = 400;
    else if(sede == "Sede San Jose Pinula")
        bonoSede = 200;

    return salarioBase + bonoSede;
}


bool Maestros::verificarCodigo(int codigoIngresado){
    return codigoIngresado == codigo;

}

void Maestros::mostrarResultados(){
    cout << "Nombre: " << nombre << " " << apellido << endl;
    cout << "Correro: " << correo<< endl;
    cout << "Codigo: " << codigo << endl;
    cout << "Curso asignado: " << curso.getnombreCurso() << endl;
    cout << "Sede: " << sede << endl;
    cout << "Dias por semana: " << diasSemana << endl;
    cout << "Horas por clase: " << horasClase << endl;
    cout << "Salario final Q: " << calcularSalario ()<< endl;

}

int Maestros::getCodigo(){
    return codigo;
}

string Maestros::getNombreCurso(){
    return curso.getnombreCurso();
}
string Maestros::getNombre(){
    return nombre;
}
string Maestros:: getApellido(){
    return apellido;
}
