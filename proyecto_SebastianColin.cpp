#include<iostream>
#include<string>
#include"dieta.h"


using namespace std;

// Given a set of coordinates, calculate the minimum travel distance
// touching all coordinates, starting from the origin. 


int main() {

    Menu menu_1("Pollo", "Brocoli", "Aguacate", "Arroz", 250, 125, 160, 200);
    menu_1.calorias_totales();
    int cals = menu_1.get_caltot();
    int macros = menu_1.macros_tot(cals);
    cout << "Las calorias de tu menu 1 son" << cals << "\n";
    cout << "Estos son tus macros:" << macros << "\n";

    Paciente paciente_1("Carlos", 22, 60, 1.69);
    paciente_1.calcula_imc();
    float indice_masa = paciente_1.get_imc();
    paciente_1.rango_peso();
    cout << "El paciente" << paciente_1.get_name() << "tiene un IMC de" <<
    indice_masa << " y esta en un rango" << paciente_1.get_rango();

    Cuentas dia_1(4765.98, 2567.5);
    dia_1.calc_utilidades();
    cout << "Las utilidades del dia fueron" << dia_1.get_utilidades();

    return 0;
}