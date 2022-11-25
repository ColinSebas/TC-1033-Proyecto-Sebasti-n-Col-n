/*
* Proyeco de Consultorio de Nutrición 
* Sebastián Colín 
* A01710148
*/


#ifndef DES_COM_CEN_H_
#define DES_COM_CEN_H_

// Bibliotecas
#include<iostream> 
#include<sstream>

using namespace std;

/*
* Clase Menu que es la clase padre de 
* Desayuno, Comida y Cena. 
* Contiene atributos y métodos compartidos
* con todos los hij@s. 
*/

class Menu {

    private:

        // Atributos genéricos
        std::string proteina, fruta_verd, grasas, carbohidrato;
        int cal_1, cal_2, cal_3, cal_4;
        int cal_tot;
        // Macros
        int carbs, prot, gras;

    public:

        // Constructor por default
        Menu(): proteina(""), fruta_verd(""), grasas(""), carbohidrato(""), 
        cal_1(0), cal_2(0), cal_3(0), cal_4(0){};
        // Constructor que recibe atributos para los menu's
        Menu(std::string protei, std::string frut_v, std::string gras,
        std::string carb, int ca1, int ca2, int ca3, int  ca4): proteina(protei), fruta_verd(frut_v),
        grasas(gras), carbohidrato(carb), cal_1(ca1), cal_2(ca2), cal_3(ca3), cal_4(ca4){};

        // Getter's & Setter's
        std::string get_prote(); std::string get_fruit_veg(); std::string get_gras(); std::string get_carbohi();
        int get_cal1(); int get_cal2();int get_cal3();int get_cal4(); int get_caltot(); int get_mcarbs();
        int get_mprot();int get_mgras();

        void set_prote(std::string); void set_fruit_veg(std::string); void set_grasa(std::string); 
        void set_carbohi(std::string); void set_cal1(int); void set_cal2(int);
        void set_cal3(int); void set_cal4(int); 

        // Funciones Extra 
        void calorias_totales();
        int macros_tot(); 
        void captura_datos();
        void imprime_menu(); 

};

std::string Menu::get_prote(){
    return proteina; 
}
std::string Menu::get_fruit_veg(){
    return fruta_verd;
}
std::string Menu::get_gras(){
    return grasas;
}
std::string Menu::get_carbohi(){
    return carbohidrato;
}
int Menu::get_cal1(){
    return cal_1;
}
int Menu::get_cal2(){
    return cal_2;
}
int Menu::get_cal3(){
    return cal_3;
}
int Menu::get_cal4(){
    return cal_4;
}
int Menu::get_caltot(){
    return cal_tot;
}
int Menu::get_mcarbs(){
    return carbs;
}
int Menu::get_mprot(){
    return prot;
}
int Menu::get_mgras(){
    return gras;
}
void Menu::set_prote(std::string pr){
    proteina = pr;
}
void Menu::set_fruit_veg(std::string fr){
    fruta_verd = fr;
}
void Menu::set_grasa(std::string gr){
    grasas = gr;
}
void Menu::set_carbohi(std::string cr){
    carbohidrato = cr;
}
void Menu::set_cal1(int c1){
    cal_1 = c1;
}
void Menu::set_cal2(int c2){
    cal_2 = c2;
}
void Menu::set_cal3(int c3){
    cal_3 = c3;
}
void Menu::set_cal4(int c4){
    cal_4 = c4;
}

/**
 * Calcula calorias totales del menu
 * 
 * @param 
 * @return método cal_tot [calorias totales]
*/
void Menu::calorias_totales(){
    cal_tot = cal_1 + cal_2 + cal_3 + cal_4; 
}

/**
 * Calcula macros del menu basado en 
 * las calorias.
 * 
 * @param 
 * @return int sum: suma de los macros
*/

int Menu::macros_tot(){

    int sum;
    carbs = cal_4 / 4;
    prot = cal_1 / 4;
    gras = cal_3 / 9;
    sum = carbs + prot + gras;

    return sum;

}

/**
 * Pide datos para crear un menu
 * personalizado
 * 
 * @param 
 * @return metodos que conforman al menu
*/
void Menu::captura_datos(){

    cout << "Captura proteina y calorias:" << "\n";
    cin >> proteina; cin >> cal_1; cout  << "\n";
    cout << "Captura fruta o verdura y calorias:" << "\n";
    cin >> fruta_verd; cin >> cal_2; cout << "\n";
    cout << "Captura grasa y calorias:" << "\n";
    cin >> grasas; cin >> cal_3; cout  << "\n";
    cout << "Captura carbohidrato y calorias:" << "\n";
    cin >> carbohidrato; cin >> cal_4; cout << "\n";


}

/**
 * Imprime metodos almacenados
 * 
 * @param
 * @return metodos que conforman menu
*/

void Menu::imprime_menu(){

    cout << "Proteina: " << proteina << "\n";
    cout << "Fruta o verdura: " << fruta_verd << "\n";
    cout << "Grasa: " << grasas << "\n";
    cout << "Carbohidrato: " << carbohidrato << "\n";

}

// Clase desayuno que hereda de Menu
class Desayuno: public Menu {

    private:

        std::string suplemento_des;
        bool ayuno;

    public:

        // Constructor por default que llama al constructor del padre
        Desayuno(): Menu(){}
        // Constructor que recibe metodos del constructor padre además de los propios
        Desayuno(std::string sup, std::string protei, std::string frut_v, std::string gras,
        std::string carb, int ca1, int ca2, int ca3, int  ca4): suplemento_des(sup), Menu(protei, 
        frut_v, gras, carb, ca1, ca2, ca3, ca4){}

        // Getter's y Setter's
        void set_ayuno(bool); std::string get_suplemento(); bool get_ayuno();
        void set_sumplemento(std::string);
};

void Desayuno::set_ayuno(bool ay){
    ayuno = ay;
}
bool Desayuno::get_ayuno(){
    return ayuno;
}
std::string Desayuno::get_suplemento(){
    return suplemento_des;
}
void Desayuno::set_sumplemento(std::string su){
    suplemento_des = su;
}

// Clase comida que hereda de Menu
class Comida: public Menu {

    private:

        bool cheat_sweet;
        std::string cheat_name;

    public:

        // Constructor por default que llama al constructor del padre
        Comida(): Menu(){}
        // Constructor que recibe metodos del constructor padre además de los propios
        Comida(std::string ch, std::string protei, std::string frut_v, std::string gras,
        std::string carb, int ca1, int ca2, int ca3, int  ca4): cheat_name(ch), Menu(protei, 
        frut_v, gras, carb, ca1, ca2, ca3, ca4){}
        // Getter's y Setter's
        void set_cheat_sweet(bool); bool get_cheat_sweet(); std::string get_name();
        void set_name(std::string);

};

void Comida::set_cheat_sweet(bool sw){
    cheat_sweet = sw;
}
bool Comida::get_cheat_sweet(){
    return cheat_sweet;
}
std::string Comida::get_name(){
    return cheat_name;
}
void Comida::set_name(std::string na){
    cheat_name = na;
}

// Clase comida que hereda de Menu
class Cena: public Menu {

    private:    

        std::string vitaminas_cena;
        int mg_vitaminas;

    public: 

        // Constructor por default que llama al constructor del padre
        Cena(): Menu(){};
        // Constructor que recibe metodos del constructor padre además de los propios
        Cena(std::string vit, std::string protei, std::string frut_v, std::string gras,
        std::string carb, int ca1, int ca2, int ca3, int  ca4): vitaminas_cena(vit), Menu(protei, 
        frut_v, gras, carb, ca1, ca2, ca3, ca4){}
        // Getter's y Setter's
        void set_vitacena(std::string); void set_mg(int); std::string get_vitacena();
        int get_mg();

};

void Cena::set_vitacena(std::string vit){
    vitaminas_cena = vit;
}
void Cena::set_mg(int m){
    mg_vitaminas = m;
}
std::string Cena::get_vitacena(){
    return vitaminas_cena;
}
int Cena::get_mg(){
    return mg_vitaminas;
}

/*
* Clase Paciente que almacena desayunos, comidas y cenas
* ademas de tener información de los pacientes que 
* atienden al consultorio.
*/

class Paciente {

    private:

        std::string name, rango;
        int edad, peso; 
        float altura, imc;
        int ides = 0; int icoms = 0; int icens = 0;
        Desayuno des[100];
        Comida coms[100];
        Cena cens[100]; 
        

    public:

        // Constructor por default
        Paciente(): name("J. Doe"), edad(0), peso(0), altura(0.0) {}
        // Constructor que recibe valores de metodos para Paciente
        Paciente(std::string nom, int ed, int pes, float al): name(nom), edad(ed),
        peso(pes), altura(al){}

        // Getters & Setters 
        std::string get_name(); int get_edad(); int get_peso(); float get_imc();
        float get_altura(); std::string get_rango();

        void set_name(std::string); void set_edad(int); void set_peso(int);
        void set_altura(float); 

        // Funciones adicionales
        void calcula_imc(); void rango_peso(); void agrega_desayuno(Desayuno); 
        void agrega_comida(Comida); void agrega_cena(Cena); void imprime_datos(); 

};

std::string Paciente::get_name(){
    return name; 
}
int Paciente::get_edad(){
    return edad; 
}
int Paciente::get_peso(){
    return peso;
}
float Paciente::get_imc(){
    return imc;
}
float Paciente::get_altura(){
    return altura;
}
std::string Paciente::get_rango(){
    return rango;
}
void Paciente::set_name(std::string n){
    name = n;
}
void Paciente::set_edad(int e){
    edad = e;
}
void Paciente::set_peso(int p){
    peso = p;
}
void Paciente::set_altura(float a){
    altura = a;
}

/**
 * Calcula el Indice de Masa
 * Corporal del Paciente
 * 
 * @param
 * @return metodo imc
*/
void Paciente::calcula_imc(){
    imc = peso / (altura * altura);
}

/**
 * Calcula el rango de peso en el
 * que se encuentra el Paciente 
 * basado en su IMC
 * 
 * @param
 * @return metodo rango que dice
 * rango de peso
*/
void Paciente::rango_peso(){

    if (imc < 18.5){
        rango = "Bajo Peso";
    } else if (imc > 18.5 && imc < 24.9){
        rango = "Peso Normal";
    } else if (imc > 25 && imc < 29.9){
        rango = "Sobrepeso";
    } else if (imc > 30.0){
        rango = "Obesidad";
    }

}

/*
* Funciones para agregar desayuno, comida o cena
* a arreglos dentro de paciente
*/

void Paciente::agrega_desayuno(Desayuno d){

    if (ides == 0){
        des[ides] = d;
        ides += 1;
    } else {
        ides += 1;
        des[ides] = d;
    }

}
void Paciente::agrega_comida(Comida c){

    if (icoms == 0){
        coms[icoms] = c;
        icoms += 1;
    } else {
        icoms += 1;
        coms[icoms] = c;
    }

}
void Paciente::agrega_cena(Cena ce){

    if (icens == 0){
        cens[icens] = ce;
        icens += 1;
    } else {
        icens += 1;
        cens[icens] = ce;
    }

}

/**
 * Imprime datos de paciente
*/
void Paciente::imprime_datos(){

    cout << "El paciente " << name << " tiene un IMC de: " 
    << imc << " y se encuentra en un rango de peso:  " << rango << "\n";

}

#endif