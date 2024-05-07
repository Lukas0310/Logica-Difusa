#include "Regla.h"

Regla::Regla(std::vector <std::tuple <std::string, std::string> > p, std::string c, float v) {
    premisas = p;
    consecuencia = c;
    valorInferencia = v;
}

void Regla::setPremisas(std::vector <std::tuple <std::string, std::string> > p) {
    premisas = p;
}

void Regla::setConsecuencia(std::string c) {
    consecuencia = c;
}

void Regla::setValorInferencia(float v) {
    valorInferencia = v;
}

std::vector <std::tuple <std::string, std::string> > Regla::getPremisas() {
    return premisas;
}

std::string Regla::getConsecuencia() {
    return consecuencia;
}

float Regla::getValorInferencia() {
    return valorInferencia;
}

void Regla::agregarPremisa(std::tuple <std::string, std::string> p) {
    premisas.push_back(p);
}