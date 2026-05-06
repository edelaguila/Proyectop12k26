#include "carrera.h"
#include <iostream>
#include <vector>
using namespace std;

carrera::carrera()
{
    //ctor
}

carrera::carrera(string codigoCarrera, string nombreCarrera, bool estadoCarrera)
{
    this -> codigoCarrera = codigoCarrera;
    this -> nombreCarrera = nombreCarrera;
    this -> estadoCarrera = estadoCarrera;

}

vector<carrera> carrera::datosCarreras()
{
    vector<carrera> infocarreras;
    infocarreras.push_back(carrera("9959", "Ingeniera en Sistemas", true));
    infocarreras.push_back(carrera("9975", "Ingeniera Industrial", true));
    infocarreras.push_back(carrera("9973", "Ingeniera Civil", true));
    return infocarreras;
}

string carrera::getnombreCarrera()
{
    return this -> nombreCarrera;
}
string carrera::getcodigoCarrera()
{
    return this -> codigoCarrera;
}
bool carrera::getestadoCarrera()
{
    return this -> estadoCarrera;
}
void carrera::setnombreCarrera(string nombreCarrera)
{
    this -> nombreCarrera = nombreCarrera;
}
void carrera::setcodigoCarrera(string codigoCarrera)
{
    this -> codigoCarrera = codigoCarrera;
}
void carrera::setestadoCarrera(bool estadoCarrera)
{
    this -> estadoCarrera = estadoCarrera;
}
