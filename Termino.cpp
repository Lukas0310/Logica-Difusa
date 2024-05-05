#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include "Trapecio.h"
#include "Termino.h"

Trapecio::Trapecio(float h, std::string nombre, std::vector<std::string> coor) {
    setNombre(nombre);
    setAltura(h);
    char tipo ='T';
    setTipo(tipo);
    setConjuntoFuzzy(coor);
}

void Trapecio::setX1(float x1) {
    this->x1=x1;
}

void Trapecio::setX2(float x2) {
    this->x2=x2;
}

void Trapecio::setX3(float x3) {
    this->x3=x3;
}

void Trapecio::setX4(float x4) {
    this->x4=x4;
}

void Trapecio::setConjuntoFuzzy(std::vector<std::string> coor) {
    setX1(atof(coor.at(0).c_str()));
    setX2(atof(coor.at(1).c_str()));
    setX3(atof(coor.at(2).c_str()));
}

float Trapecio::pertenenciaCF(float input){
    float pert = 0;
    if (input <= x1) {
        pert = 0;
    } else if (input >= x1 && input <= x2) {
        pert = (input-x1)/(x2-x1);
    } else if (input >= x2 && input <=x3 ){
        pert = 1.0;
    } else if (input >= x3 && input <=x4){
        pert = (x4-input)/(x4-x3);
    } else {
        pert = 0;
    }
    return pert;
};

std::string Trapecio::getCoordenadas() {
    return std::to_string(x1) + ", " + std::to_string(x2) + ", " + std::to_string(x3);
};



