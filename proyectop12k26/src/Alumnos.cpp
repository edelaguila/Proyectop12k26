//Creado por Fernando Castillo - 9959-25-288
//El 30/04/2026
#include "Alumnos.h"
#include "carrera.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <vector>
using namespace std;

//Constructor
Alumnos::Alumnos()
{
    //inicializar varibles
    this -> nombreAlumno = "";
    this -> apellidoAlumno = "";
    this -> diaNacimiento = 0;
    this -> mesNacimiento = 0;
    this -> anioNacimiento = 0;
    this -> numeroDpi = "";
    this -> correoPersonal = "";
    this -> fechaNacimientoAlumno = "";
    this -> carnetPersonal = "";
    this -> sexoAlumno = "";
}


//Constructor sobrecargado
Alumnos::Alumnos(string nombreCompletoAlumno, string sexoAlumno, string numeroDpi, string correoPersonal, string carnetPersonal, string carreraAsignada)
{
    this -> nombreCompletoAlumno = nombreCompletoAlumno;
    this -> sexoAlumno = sexoAlumno;
    this -> numeroDpi = numeroDpi;
    this -> correoPersonal = correoPersonal;
    this -> carnetPersonal = carnetPersonal;
    this -> carreraAsignada = carreraAsignada;
}

//Creando Alumnos Prueba
vector<Alumnos> Alumnos::alumnosPrueba()
{
    //Almacena en un vector datos de unos alumnos de prueba
    //Los datos se almacenara en el constructor sobrecargado
    vector<Alumnos> alumnos;
    alumnos.push_back(Alumnos("Carlos Roberto Méndez Ruiz", "Maculino", "2584910230101", "cmendez001@miumg.edu.gt", "9959-26-001", "Ingenieria en Sistemas"));
    alumnos.push_back(Alumnos("Ana Lucia Villagran Sosa", "Femenino", "3015427891702", "avillagran002@miumg.edu.gt", "9975-26-002", "Ingenieria Industrial"));
    alumnos.push_back(Alumnos("Sergio Alejandro Torres Paz", "Maculino", "1992553010401", "storres003@miumg.edu.gt", "9973-26-003", "Ingenieria Civil"));
    alumnos.push_back(Alumnos("Maria Fernanda Lopez Herrera", "Femenino", "2240189650101", "mlopez004@miumg.edu.gt", "9959-26-004", "Ingenieria en Sistemas"));
    alumnos.push_back(Alumnos("Gustavo Adolfo Xitumul Calel", "Masculino", "2833041121501", "gxitumul005@miumg.edu.gt", "9975-26-005", "Ingenieria Industrial"));
    return alumnos;
}

//Menu registro alumno
void Alumnos::menuRegistro()
{
    //Variables
    int opcionCarrera = 0;//Para obtener la opcion del alumno
    int indice = 0;//Para recorrer el vector
    //Instancia de clase carrera y obtener los datos del vector
    carrera configCarrera;
    vector<carrera> obtenerCarrera = configCarrera.datosCarreras();

    //Inicio del do-while
    do{
        //Carreras Disponibles
        system("cls");
        cout << "--- Seleccione la Carrera ---" << endl;
        cout << "1. Ingenieria en Sistemas" << endl;
        cout << "2. Ingenieria Industrial" << endl;
        cout << "3. Ingenieria Civil" << endl;
        cout << "¿Que carrera desea escoger?:" << endl;
        cin >> opcionCarrera;//Obtener el digito
        cin.ignore(1000, '\n');//Ingonra los espaciones del usuario
        //Validacion del menu
        if (opcionCarrera < 1 || opcionCarrera > 3){
            //Capturamos el error del usuario y le mostramos el error
            cout << "Error. escoga una carrera (1-3)" << endl;
            this_thread::sleep_for(chrono::seconds(2));
        }else {
            //Sino se cumple la condicion recorre el vector
            indice = opcionCarrera - 1;//Como empieza el vector en 0 le restamos 1 la opcionCarrera
        }
    }while (!(opcionCarrera >= 1 && opcionCarrera <= 3));//Fin del do while

    //Llamada de los metodos
    registroDatos();
    creaCorreoPersonal();//La funcion crear un correo
    crearCarnetPersonal(obtenerCarrera[indice].getcodigoCarrera());//En la clase carrera buscara el codigo de la carrera
    this -> carreraAsignada = obtenerCarrera[indice].getnombreCarrera();//En la clase carrera buscara el nombre de la carrera y lo aguardamos en esta variable
    registroExitoso();//Muestra que el registro fue exitoso y genera su carnet y correo de uso personal
}

//Obtner los datos ingresados por el usuario
void Alumnos::registroDatos()
{
    //Variables
    bool validarInformacion;//Para validar los digitos del dpi
    char confirmarDatos;//Confirmacion de los datos del usuario
    //Inicio del do-while
    do{
        //Inicio del do-while
        do{
            system("cls");//Borra informacion del compilador y no llenarla de tanta informacion
            cout << "Ingrese sus nombres: " << endl;//Pedir los nombres
            getline(cin, this -> nombreAlumno);//S
            //Validar los datos ingresados por el alumno
            if (this -> nombreAlumno == ""){
                cout << "Error, el nombre no puede ir vacio" << endl;
                this_thread::sleep_for(chrono::seconds(2));//Comando para que el compilador espere 2 segundo asi el usuario puede leer el error
            }else{
                if (this -> nombreAlumno == " "){
                    cout << "Error, solo coloco un espacio ingrese sus nombres" << endl;
                    this_thread::sleep_for(chrono::seconds(2));//Comando para que el compilador espere 2 segundo asi el usuario puede leer el error
                }
            }
        }while (this -> nombreAlumno == "" || this -> nombreAlumno == " ");//Fin del do-while

        //Inicio del do-while
        do{
            system("cls");//Borra informacion del compilador y no llenarla de tanta informacion
            cout << "Ingrese sus apellidos: " << endl;//Pedir los apellidos
            getline(cin, this -> apellidoAlumno);
            //Validar los datos ingresados por el alumno
            if (this -> apellidoAlumno == ""){
                cout << "Error, el apellido no puede ir vacio" << endl;
                this_thread::sleep_for(chrono::seconds(2));//Comando para que el compilador espere 2 segundo asi el usuario puede leer el error
            }else{
                if (this -> apellidoAlumno == " "){
                    cout << "Error, el apellido no puede ir vacio" << endl;
                    this_thread::sleep_for(chrono::seconds(2));//Comando para que el compilador espere 2 segundo asi el usuario puede leer el error
                }
            }
        }while (this -> apellidoAlumno == "" || this -> apellidoAlumno == " ");//Fin del do-while

        //Inicio del do-while
        do{
            system("cls");//Borra informacion del compilador y no llenarla de tanta informacion
            cout << "Ingrese su sexo (Masculino/Femenino): " << endl;//Pedir su genero
            getline(cin, this -> sexoAlumno);
            //Validar los datos ingresados por el alumno
            if (this -> sexoAlumno == ""){
                cout << "Error, el sexo no puede ir vacio" << endl;
                this_thread::sleep_for(chrono::seconds(2));//Comando para que el compilador espere 2 segundo asi el usuario puede leer el error
            }else {
                if (this -> sexoAlumno == "M" || this -> sexoAlumno == "m"){
                    cout << "Error, dato no valido" << endl;
                    this_thread::sleep_for(chrono::seconds(2));//Comando para que el compilador espere 2 segundo asi el usuario puede leer el error
                }else{
                    if (this -> sexoAlumno == " "){
                        cout << "Error, solo coloco un espacio ingrese su sexo" << endl;
                        this_thread::sleep_for(chrono::seconds(2));
                    }
                }
            }
        }while (this -> sexoAlumno == "" || this -> sexoAlumno == "M" || this -> sexoAlumno == "m" || this -> sexoAlumno == " ");//Fin del do-while

        //Inicio del do-while
        do{
            system("cls");//Borra informacion del compilador y no llenarla de tanta informacion
            cout << "Ingrese su numero de DPI: " << endl;//Pedir su numero de dpi
            getline(cin, this -> numeroDpi);
            //Valida digitos del dpi
            if (this -> numeroDpi.size() != 13){
                cout << "Error, su numero de DPI tiene que tener 13 digitos" << endl;
                validarInformacion = false;
            }else{
                validarInformacion = true;
            }

            if (!validarInformacion){
                this_thread::sleep_for(chrono::seconds(2));//Comando para que el compilador espere 2 segundo asi el usuario puede leer el error
            }
        }while (validarInformacion != true || this -> numeroDpi == "" || this -> numeroDpi == " ");//Fin del do-while

        //Inicio del do-while
         do{
            system("cls");//Borra informacion del compilador y no llenarla de tanta informacion
            cout << "Ingrese su dia de nacimiento (1-31): " << endl;//Pedir dia nacimiento
            cin >> this -> diaNacimiento;
            //Validar los datos ingresados por el alumno
            if (this -> diaNacimiento < 1 || this -> diaNacimiento > 31){
                cout << "Error, dia no valido" << endl;
                this_thread::sleep_for(chrono::seconds(2));//Comando para que el compilador espere 2 segundo asi el usuario puede leer el error
            }
        }while (!(this -> diaNacimiento >= 1 && this -> diaNacimiento <= 31));//Fin del do-while

        //Inicio del do-while
        do{
            system("cls");//Borra informacion del compilador y no llenarla de tanta informacion
            cout << "Ingrese su mes de nacimiento (1-12): " << endl;//Pedir mes de nacimiento
            cin >> this -> mesNacimiento;
            //Validar los datos ingresados por el alumno
            if (this -> mesNacimiento < 1 || this -> mesNacimiento > 12){
                cout << "Error, mes no valido" << endl;
                this_thread::sleep_for(chrono::seconds(2));//Comando para que el compilador espere 2 segundo asi el usuario puede leer el error
            }
        }while (!(this -> mesNacimiento >= 1 && this -> mesNacimiento <= 12));//Fin del do-while

        //Inicio del do-while
        do{
            system("cls");//Borra informacion del compilador y no llenarla de tanta informacion
            cout << "Ingrese su año de nacimiento (1940-2009): " << endl;//Pedir año de nacimiento
            cin >> this -> anioNacimiento;
            //Validar los datos ingresados por el alumno
            if (this -> anioNacimiento < 1940 || this -> anioNacimiento > 2009){
                cout << "Error, mes no valido" << endl;
                this_thread::sleep_for(chrono::seconds(2));//Comando para que el compilador espere 2 segundo asi el usuario puede leer el error
            }
        }while (!(this -> anioNacimiento >= 1940 && this -> anioNacimiento <= 2009));//Fin del do-while

        //Se llaman estas dos funciones para que pueda almacenar los datos ingresados
        obtenerFechaNacimiento();
        obtenerNombreCompleto();

        system("cls");//Borra informacion del compilador y no llenarla de tanta informacion
        //Se muestra los datos del usuario y le preguntamos si son correctos
        //Si dice que no lo regresamos otra vez para que ingrese sus datos
        cout << "--- Datos Personales ---" << endl;
        cout << "Nombres: " << this -> getnombreCompletoAlumno() << endl;//Muestra sus nombres que ingreso
        cout << "Apellidos: " << this -> getapellidoAlumno() << endl;//Muestra sus apellidos que ingreso
        cout << "Sexo: " << this -> getsexoAlumno() << endl;//Muestra su genero que ingreso
        cout << "DPI: " << this -> getnumeroDpi() << endl;//Muestra su dpi
        cout << "Fecha nacimiento: " << this -> getfechaNacimientoAlumno() << endl;//Muestra su fecha de nacimiento
        cout << "¿Los datos son correctos (S/N)?: " << endl;//Preguntamos si son correctos
        cin >> confirmarDatos;
        cin.ignore(1000, '\n');

    }while (confirmarDatos == 'n' || confirmarDatos == 'N');//Fin del do-while

    //Aqui genera un pequeño texto interactivo para el usuario
    cout << "Verificando datos... por favor espere." << endl;
	this_thread::sleep_for(chrono::seconds(2));//Comando para que el compilador espere 2 segundo y pasa al siguiente dato
	cout << "Generando carnet..." << endl;
	this_thread::sleep_for(chrono::seconds(2));//Comando para que el compilador espere 2 segundo y pasa al siguiente dato
	cout << "Generando correo..." << endl;
	this_thread::sleep_for(chrono::seconds(2));//Comando para que el compilador espere 2 segundo y pasa al siguiente dato
}

//Obtiene la fecha completa del alumno
void Alumnos::obtenerFechaNacimiento()
{
    this -> fechaNacimientoAlumno = to_string(this -> diaNacimiento) + "/" + to_string(this -> mesNacimiento) + "/" + to_string(this -> anioNacimiento);
}

//Genera correo personal
void Alumnos::creaCorreoPersonal()
{
    size_t i = 0;
    string nombreInicial = "";
    int numAleatorioCorreo = numeroAleatorio(100, 2000);//Genera numeros aleatorios para su correo
    string primerApellido = "";
    nombreInicial = this -> nombreAlumno.substr(0, 1);//Obtener la primera inicial de su nombre
    //Un while para obtener el apellido del alumno y poder generar su correo
    while ( i < this -> apellidoAlumno.size() && this -> apellidoAlumno[i] != ' '){
        primerApellido += this -> apellidoAlumno[i];
        i++;
    }
    this -> correoPersonal = nombreInicial + primerApellido + to_string(numAleatorioCorreo) + "@miumg.edu.gt";//se crea su correo perosnal

    //Un ciclo for para crear el correo en minusculas
    for (size_t j = 0 ; j < this -> correoPersonal.length(); j++){
        this -> correoPersonal[j] = tolower(this -> correoPersonal[j]);
    }
}

//Genera Carnet Personal
void Alumnos::crearCarnetPersonal(string codigoCarrera)
{
    int numAleatorio =  numeroAleatorio(100, 2000);//numeros aleatorios para su carnet
    this -> carnetPersonal = codigoCarrera + "-" + to_string(obtenerAnioCorto()) + "-" + to_string(numAleatorio);//se crea su carnet personal
}

//Genera numeros Aleatorios
int Alumnos::numeroAleatorio(int minimo, int maximo)
{
    return minimo + rand() % (maximo - minimo + 1);
}

//Obtener el año corto (ej.26) para el codigo del carnet
int Alumnos::obtenerAnioCorto()
{
    return this -> ANIO_ACTUAL % 100;
}

//Almacena el nombre y apellido dentro de una sola variable
void Alumnos::obtenerNombreCompleto()
{
    this -> nombreCompletoAlumno = this -> nombreAlumno + " " + this -> apellidoAlumno;
}

//Muestra que se registro se hizo correctamente
void Alumnos::registroExitoso()
{
    system("cls");//Borra informacion del compilador y no llenarla de tanta informacion
    cout << "--- Universidad UMG - Registro Exitoso ---" << endl;
    cout << "Alumno: " << this -> getnombreAlumno() << " " << this -> getapellidoAlumno() << endl;//Nombre del alumno
    cout << "Carnet: " << this -> getcarnetPersonal() << endl;//carnet personal
    cout << "Correo: " << this -> getcorreoPersonal() << endl;//correo personal
    cout << "Carrera: " << this -> getcarreraAsignada() << endl;//carrera que se asigno el alumno

}

//Getters
string Alumnos::getnombreCompletoAlumno()
{
    return this -> nombreCompletoAlumno;
}
string Alumnos::getnombreAlumno()
{
    return this -> nombreAlumno;
}
string Alumnos::getapellidoAlumno()
{
    return this -> apellidoAlumno;
}
string Alumnos::getsexoAlumno()
{
    return this -> sexoAlumno;
}
int Alumnos::getdiaNacimiento()
{
    return this -> diaNacimiento;
}
string Alumnos::getnumeroDpi()
{
    return this -> numeroDpi;
}
int Alumnos::getmesNacimiento()
{
    return this -> mesNacimiento;
}
int Alumnos::getanioNacimiento()
{
    return this -> anioNacimiento;
}
string Alumnos::getcorreoPersonal()
{
    return this -> correoPersonal;
}

string Alumnos::getfechaNacimientoAlumno()
{
    return this -> fechaNacimientoAlumno;
}
string Alumnos::getcarnetPersonal()
{
    return this -> carnetPersonal;
}
string Alumnos::getcarreraAsignada()
{
    return this -> carreraAsignada;
}
//Setters
void Alumnos::setnombreCompletoAlumno(string nombreCompletoAlumno)
{
    this -> nombreCompletoAlumno = nombreCompletoAlumno;
}
void Alumnos::setnombreAlumno(string nombreAlumno)
{
    this -> nombreAlumno = nombreAlumno;
}
void Alumnos::setapellidoAlumno(string apellidoAlumno)
{
    this -> apellidoAlumno = apellidoAlumno;
}
void Alumnos::setsexoAlumno(string sexoAlumno)
{
    this -> sexoAlumno = sexoAlumno;
}
void Alumnos::setdiaNacimiento(int diaNacimiento)
{
    this -> diaNacimiento = diaNacimiento;
}
void Alumnos::setmesNacimiento(int mesNacimiento)
{
    this -> mesNacimiento = mesNacimiento;
}
void Alumnos::setanioNacimiento(int anioNacimiento)
{
    this -> anioNacimiento = anioNacimiento;
}
void Alumnos::setnumeroDpi(string numeroDpi)
{
    this -> numeroDpi = numeroDpi;
}
void Alumnos::setcorreoPersonal(string correoPersonal)
{
    this -> correoPersonal = correoPersonal;
}
void Alumnos::setfechaNacimientoAlumno(string fechaNacimientoAlumno)
{
    this -> fechaNacimientoAlumno = fechaNacimientoAlumno;
}
void Alumnos::setcarnetPersonal(string carnetPersonal)
{
    this -> carnetPersonal = carnetPersonal;
}
void Alumnos::setcarreraAsignada(string carreraAsignada)
{
    this -> carreraAsignada = carreraAsignada;
}

