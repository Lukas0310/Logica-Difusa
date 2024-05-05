#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include "Triangulo.h"
#include "Termino.h"

Triangulo::Triangulo(std::string nombre, std::vector<std::string> coor) {
    setNombre(nombre);
    char tipo ='T';
    setTipo(tipo);
    setConjuntoFuzzy(coor);
}

void Triangulo::setX1(float x1) {
    this->xy1=x1;
}

void Triangulo::setX2(float x2) {
    this->xy2=x2;
}

void Triangulo::setX3(float x3) {
    this->xy3=x3;
}

void Triangulo::setConjuntoFuzzy(std::vector<std::string> coor) {
    setX1(atof(coor.at(0).c_str()));
    setX2(atof(coor.at(1).c_str()));
    setX3(atof(coor.at(2).c_str()));
}

float Triangulo::calcularPertenencia(float input){
    float pert = 0;
    if (input <= xy1) {
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
};

std::string Triangulo::getCoordenadas() {
    return std::to_string(xy1) + ", " + std::to_string(xy2) + ", " + std::to_string(xy3);
};


