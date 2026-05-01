#ifndef carrera_H
#define carrera_H     //Creado por David Alegria
#include <string>
#include <vector>

class carrera
{
    public:
        //Constructor
        carrera();
        carrera(std::string codigoCarrera, std::string nombreCarrera, bool estadoCarrea);
        //Get
        std::string getcodigocarrera();
        std::string getnombrecarrera();
        bool getestadocarrera();
        //Set
        void setcodigocarrera(std::string codigocarera);
        void setnombrecarrera(std::string nombrecarerra);
        void setestadocarrera(bool estadocarrera);
        //Metodos
        std::vector<carrera> datoscarreras();


    protected:

    private:
        std::string codigocarrera;
        std::string nombrecarrera;
        bool estadocarrera;
};

#endif // CARRERA_H
