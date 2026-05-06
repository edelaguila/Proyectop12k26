#ifndef MAESTROS_H
#define MAESTROS_H

#include <string>
#include "cursos.h"
#include "carrera.h"

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
    Cursos curso;
    carrera carreraSeleccionada;

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
