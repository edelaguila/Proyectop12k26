#ifndef CARRERA_H
#define CARRERA_H
#include <string>
#include <vector>

class carrera
{
    public:
        //Constructor
        carrera();
        carrera(std::string codigoCarrera, std::string nombreCarrera, bool estadoCarrera);
        //Get
        std::string getcodigoCarrera();
        std::string getnombreCarrera();
        bool getestadoCarrera();
        //Set
        void setcodigoCarrera(std::string codigoCarera);
        void setnombreCarrera(std::string nombreCarerra);
        void setestadoCarrera(bool estadoCarrera);
        //Metodos
        std::vector<carrera> datosCarreras();


    protected:

    private:
        std::string codigoCarrera;
        std::string nombreCarrera;
        bool estadoCarrera;
};

#endif // CARRERA_H
