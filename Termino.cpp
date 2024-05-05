#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include "Termino.h"

void Termino::setNombre(std::string n) {
    nombreT=n;
};

void Termino::setAltura(float h){
    altura=h;
};

void Termino::setTipo(char t){
    tipo = t;
};

std::string Termino::getNombre() {
    return nombreT;
};

float Termino::getAltura() {
    return altura;
};

char Termino::getTipo() {
    return tipo;
};
