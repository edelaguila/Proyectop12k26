#include "carrera.h"
#include <iostream>     //Creado por David Alegria
#include <vector>
using namespace std;

 carrera::carrera()
{
    //ctor
}

carrera::carrera(string codigocarrera, string nombrecarrera, bool estadocarrera)
{
    this -> codigocarrera = codigocarrera;
    this -> nombrecarrera = nombrecarrera;
    this -> estadocarrera = estadocarrera;

}


vector<carrera> carrera::datoscarreras()
{
    vector<carrera> infocarreras;
    infocarreras.push_back(carrera("9959", "Ingeniera en Sistemas", true));
    infocarreras.push_back(carrera("9975", "Ingeniera Industrial", true));
    infocarreras.push_back(carrera("9973", "Ingeniera Civil", true));
    return infocarreras;
}

string carrera::getnombrecarrera()
{
    return this -> nombrecarrera;
}
string carrera::getcodigocarrera()
{
    return this -> codigocarrera;
}
bool carrera::getestadocarrera()
{
    return this -> estadocarrera;
}
void carrera::setnombrecarrera(string nombrecarrera)
{
    this -> nombrecarrera = nombrecarrera;
}
void carrera::setcodigocarrera(string codigocarrera)
{
    this -> codigocarrera = codigocarrera;
}
void carrera::setestadocarrera(bool estadocarrera)
{
    this -> estadocarrera = estadocarrera;
}
