#ifndef HORARIOS_H
#define HORARIOS_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream> // 👈 recomendable agregarlo aquí
#include "Cursos.h"

using namespace std;

class Horarios
{
private:
    string nombreCurso;
    string horaInicio;
    string horaFin;

public:
    Horarios();
    Horarios(string nombreCurso, string horaInicio, string horaFin);

    static vector<Horarios> generar(vector<Cursos> cursos, string jornada, bool pagoRealizado);
    static void mostrar(vector<Horarios> lista);

    // archivo
    static void guardarEnArchivo(vector<Horarios> lista);
};

#endif
