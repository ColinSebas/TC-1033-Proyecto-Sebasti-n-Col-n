#include<string>
#include<iostream>

class Nutricion {
    
    private:

        std::string consultorio;
        int arg_menus[100];
        int arg_pacientes[100];

    public:

        void almacena_menu(); void almacena_pacientes();

};


class Menu {

    private:

        std::string proteina, fruta_verd, grasas, carbohidrato;
        int cal_1, cal_2, cal_3, cal_4;
        int cal_tot;
        // Macros
        int carbs, prot, gras;

    public:

        Menu(): proteina(""), fruta_verd(""), grasas(""), carbohidrato(""), 
        cal_1(0), cal_2(0), cal_3(0), cal_4(0){};
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
        int macros_tot(int); 

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

void Menu::calorias_totales(){
    cal_tot = cal_1 + cal_2 + cal_3 + cal_4; 
}

int Menu::macros_tot(int sum){

    carbs = cal_4 / 4;
    prot = cal_1 / 4;
    gras = cal_3 / 9;
    sum = carbs + prot + gras;

    return sum;

}

class Paciente {

    private:

        std::string name, rango;
        int edad, peso; 
        float altura, imc;
        

    public:

        Paciente(): name("J. Doe"), edad(0), peso(0), altura(0.0) {}
        Paciente(std::string nom, int ed, int pes, float al): name(nom), edad(ed),
        peso(pes), altura(al){}

        // Getters & Setters 
        std::string get_name(); int get_edad(); int get_peso(); float get_imc();
        float get_altura(); std::string get_rango();

        void set_name(std::string); void set_edad(int); void set_peso(int);
        void set_altura(float); 

        // Funciones adicionales
        void calcula_imc(); void rango_peso();

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
void Paciente::calcula_imc(){
    imc = peso / (altura * altura);
}
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

class Cuentas {

    private: 

        double ingresos, gastos, utilidades; 
        
    public:

        Cuentas(): ingresos(0.0), gastos(0.0){}
        Cuentas(double ing, double gast): ingresos(ing), gastos(gast){}

        // Getter's & Setter's
        double get_ingresos(); double get_gastos(); double get_utilidades();

        void set_ingresos(double); void set_gastos(double);

        // Funciones adicionales
        void calc_utilidades();

};

double Cuentas::get_ingresos(){
    return ingresos;
}
double Cuentas::get_gastos(){
    return gastos;
}
double Cuentas::get_utilidades(){
    return utilidades;
}

void Cuentas::set_ingresos(double ing){
    ingresos = ing;
}
void Cuentas::set_gastos(double gas){
    gastos = gas;
}

void Cuentas::calc_utilidades(){
    utilidades = ingresos - gastos;
}

class Desayuno {

    private:

        std::string suplemento_des;
        bool ayuno;

    public:

        Desayuno();
        Desayuno(std::string sup): suplemento_des(sup){}
        void set_ayuno(bool); std::string get_suplemento(); bool get_ayuno();
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

class Comida {

    private:

        bool cheat_sweet;
        std::string cheat_name;

    public:

        Comida();
        Comida(std::string ch): cheat_name(ch){}
        void set_cheat_sweet(bool); bool get_cheat_sweet(); std::string get_name();

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

class Cena {

    private:    

        std::string vitaminas_cena;
        int mg_vitaminas;

};