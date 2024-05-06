#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include "Trapecio.h"
#include "Termino.h"


void Termino::setNombre(std::string n) {
    this->nombreT=n;
}

void Termino::setPertenencia(float h) {
    this->pertenencia=h;
}

void Termino::setTipo(char t) {
    this->tipo=t;
}

void Termino::setAltura(float a) {
    this->altura=a;
}

std::string Termino::getNombre() {
    return nombreT;
}

float Termino::getPertenencia() {
    return pertenencia;
}

char Termino::getTipo() {
    return tipo;
}

float Termino::getAltura() {
    return altura;
}
