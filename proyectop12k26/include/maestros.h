#ifndef MAESTROS_H
#define MAESTROS_H

#include <string>
<<<<<<< HEAD
#include "cursos.h"
#include "carrera.h"
=======
>>>>>>> 31ae166e5dc124f296f0215c68ec3b843393d089
using namespace std;

class Maestros {
private:
    string nombre;
    string apellido;
    string correo;
    int codigo;
    string sede;
    int diasSemana;
    int horasClase;
<<<<<<< HEAD
    Curso curso;
    carrera carreraSeleccionada;
=======

>>>>>>> 31ae166e5dc124f296f0215c68ec3b843393d089

public:
    Maestros();

    void ingresarDatosPersonales();
    void generarCorreo();
    void generarCodigo();
    void asignarCurso();
    void asignarHorario();
    double calcularSalario();
    bool verificarCodigo(int codigoIngresado);
    void mostrarResultados();
    void mostrarCarreras();
    void mostrarCursosPorCarrera(string codigoCarrera);

    int getCodigo();
    string getNombreCurso();
    string getNombre();
    string getApellido();
};

#endif
