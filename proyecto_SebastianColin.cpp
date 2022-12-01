/*
* Proyeco de Consultorio de Nutrición 
* Sebastián Colín 
* A01710148
*/

/**
 * Descripción:
 * Programa para clase de Programación
 * Orientada a Objetos. Crea menus para 
 * pacientes de un consultorio de nutrición.
 * También calcula cuentas mensuales y lleva
 * registro de pacientes. 
*/


// Biblioteccas
#include<iostream>
#include<string>

// Archivos con clases
#include "des_com_cen.h"
#include"dieta.h"

using namespace std;

// Menú para interacción de usuario
void menu(){

    // Imprime opciones de menú
    cout << "Elige una opcion: \n"; 
    cout << "1. Muestra datos de paciente demo demo: \n"; 
    cout << "2. Muestra menu de desayuno de paciente demo y calorias \n"; 
    cout << "3. Muestra menu de comida de paciente demo y calorias \n";
    cout << "4. Agrega menu tipo cena \n";
    cout << "5. Muestra cuentas del consultorio \n"; 
    cout << "6. Salir \n";

}

// Función Main
int main() {

    int opcion = 0;

    // Inicializo objeto Nutrición que almacena otros objetos 
    Nutricion dietas;

    Paciente austreberto("Austreberto", 47, 78, 1.78);

    // Primer Menú
    Desayuno des_1("Vitamina C", "Pollo", "Calabacin", "Aguacate", "Quinoa",
    200, 50, 85, 300);

    // Segundo Menú
    Comida yakimeshi("Cheesecake", "Atun", "Brocoli", "Almendras", "Arroz",
    180, 75, 80, 200);

    des_1.calorias_totales();
    des_1.set_ayuno(false);
    Cena alitas;

    while(opcion < 6 && opcion > -1 ){

        // Selección
        menu();

        // Introduce opción
        cin >> opcion;

        // Cambia de opción
        switch(opcion){

            case 1:
                // Cálculo de datos e impresión
                austreberto.calcula_imc(); austreberto.rango_peso(); 
                austreberto.imprime_datos(); 
                break;

            case 2:
                // Datos desayuno 1 paciente
                cout << "Desayuno #1" << "\n";
                des_1.imprime_menu();
                cout << "Los macros del desayuno son:" << "\n" << des_1.macros_tot() << "\n";
                cout << "Las calorias totales del desayuno son: " << des_1.get_caltot() << "\n";
                dietas.agrega_menu(des_1); austreberto.agrega_desayuno(des_1);
                break;

            case 3:
                // Datos desayuno 2 paciente 
                cout << "Comida #1" << "\n";
                yakimeshi.imprime_menu();
                yakimeshi.calorias_totales(); yakimeshi.set_cheat_sweet(true); 

                if (yakimeshi.get_cheat_sweet() == true){
                    cout << "El menu de comida contienen cheat meal." << "\n"
                    << yakimeshi.get_cheat_sweet();
                } else {
                    cout << "El menu de comida no tiene cheat meal." << "\n";
                }
                cout << "Los macros de la primera comida son: " << "\n" << yakimeshi.macros_tot() << "\n";
                cout << "Las calorias de la comida son: " << yakimeshi.get_caltot() << "\n";
                dietas.agrega_menu(yakimeshi); austreberto.agrega_comida(yakimeshi); 
                break;

            case 4:
                // Crea objeto tipo cena y pide datos al usuario
                alitas.set_vitacena("Vitaminas B12");
                alitas.captura_datos();
                alitas.calorias_totales();
                cout << "Las calorias totales de tu cena personalizada son: " << "\n" << alitas.get_caltot() << "\n";
                dietas.agrega_menu(alitas); austreberto.agrega_cena(alitas); 
                break;

            case 5:
                // Sección de cuentas del consultorio
                dietas.agrega_cuenta(35000.89, 12500.00); 
                dietas.agrega_cuenta(43987.69, 13000.00);
                dietas.agrega_cuenta(50982.4, 13000.00);
                dietas.agrega_cuenta(29802.6, 13000.00);
                dietas.agrega_cuenta(31878.46, 13000.00);
                dietas.imprime_cuentas();
                break;

            case 6: 
                break;
            
        }
    }
    
    return 0;

}