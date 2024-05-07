#include "Triangulo.h"

Triangulo::Triangulo(std::string nombre, std::vector <std::string> coor) {
    setNombre(nombre);
    char tipo ='T';
    setTipo(tipo);
    setConjuntoFuzzy(coor);
    setAltura(0);
} //en el constructor automaticamente se pone que es tipo T de triangulo

void Triangulo::setX1(float x1) {
    this->xy1 = x1;
}
float Triangulo::getX1()
{
    return this->xy1;
}
void Triangulo::setX2(float x2) {
    this->xy2 = x2;
}
float Triangulo::getX2()
{
    return this->xy2;
}
void Triangulo::setX3(float x3) {
    this->xy3 = x3;
}
float Triangulo::getX3()
{
    return this->xy3;
}
void Triangulo::setConjuntoFuzzy(std::vector<std::string> coor) {
    setX1(atof(coor.at(0).c_str()));
    setX2(atof(coor.at(1).c_str()));
    setX3(atof(coor.at(2).c_str()));
} //convierte en un float lo que venga en las strings

float Triangulo::calcularPertenencia(float input){
    float pert = 0;
    if (input <= xy1) {
        //si es menor que el limite inferior pues no pertenece al triangulo
        pert = 0;
    } else if (input < xy2) {
        pert = (input-xy1)/(xy2-xy1);
    } else if (input == xy2 ){
        pert = 1.0;
    } else if (input<xy3){
        pert = (xy3-input)/(xy3-xy2);
    } else {
        pert = 0;
    }
    return pert;
}; //la pertenencia la calculamos de acuerdo a las diapositivas de clase

std::string Triangulo::getCoordenadas() {
    return std::to_string(xy1) + ", " + std::to_string(xy2) + ", " + std::to_string(xy3);
};

bool Triangulo::estaDentroDelIntervalo(float input) {
    if (input >= xy1 && input <= xy3) {
        return true;
    } else {
        return false;
    }
}

