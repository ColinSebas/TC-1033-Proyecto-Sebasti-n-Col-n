/*
* Proyeco de Consultorio de Nutrición 
* Sebastián Colín 
* A01710148
*/

#ifndef DIETA_H_
#define DIETA_H_

// Bibliotecas
#include<string>
#include<iostream>

#include "des_com_cen.h"

using namespace std;

/*
* Clase Cuenta que con composición
* almacena cuentas de ingresos, gastos
* y utilidades mensuales
*/

class Cuenta {

    private: 

        double ingresos, gastos, utilidades; 
        
    public:

        // Constructor por default
        Cuenta(): ingresos(0.0), gastos(0.0){}
        // Constructor que recibe metodos de ingresos y gastos
        Cuenta(double ing, double gast): ingresos(ing), gastos(gast){}

        // Getter's & Setter's
        double get_ingresos(); double get_gastos(); double get_utilidades();

        void set_ingresos(double); void set_gastos(double);

        // Funciones adicionales
        void calc_utilidades();

};

double Cuenta::get_ingresos(){
    return ingresos;
}
double Cuenta::get_gastos(){
    return gastos;
}
double Cuenta::get_utilidades(){
    return utilidades;
}

void Cuenta::set_ingresos(double ing){
    ingresos = ing;
}
void Cuenta::set_gastos(double gas){
    gastos = gas;
}

/**
 * Calcula utilidad neta al mes
 * 
 * @param
 * @return metodo utilidades
*/

void Cuenta::calc_utilidades(){
    utilidades = ingresos - gastos;
}

/*
* Clase Nutricion que sirve como master
* para almacenar pacientes, menus y cuentas
*/

class Nutricion {
    
    private:

        std::string consultorio;
        int imenu, ipaciente, icuenta;
        Menu arg_menu[5];
        Paciente arg_paciente[5];
        Cuenta arg_cuenta[5];

    public:

        Nutricion(): imenu(0), ipaciente(0), icuenta(0){};
        void agrega_menu(Menu); void agrega_paciente(Paciente); 
        void agrega_cuenta(double, double);void set_nom_c(string);

};

void Nutricion::agrega_cuenta(double in, double ut){

    arg_cuenta[icuenta] = Cuenta(in, ut);
    icuenta += 1;

}
void Nutricion::agrega_menu(Menu m){

    arg_menu[imenu] = m;
    imenu += 1;

}
void Nutricion::set_nom_c(string nm){
    consultorio = nm;
}
void Nutricion::agrega_paciente(Paciente pac){

    arg_paciente[ipaciente] = pac;
    ipaciente += 1;

}

#endif