/*
Clase para representar una regla difusa.
las premisas se representan como un vector de tuplas de la forma (nombreVariable, nombreTermino, valor.
las consecuencias se representan un string.
*/

#pragma once

#include "Variable.h"

#include <map>
#include <tuple>

class Regla {
    private:
        std::vector <std::tuple <std::string, std::string> > premisas;
        float valorInferencia;
        std::string consecuencia;

    public:
        Regla(std::vector <std::tuple <std::string, std::string> > p, std::string c, float v);
        void setPremisas(std::vector <std::tuple <std::string, std::string> > p);
        void setConsecuencia(std::string c);
        void setValorInferencia(float v);
        std::vector <std::tuple <std::string, std::string> > getPremisas();
        std::string getConsecuencia();
        float getValorInferencia();
        void agregarPremisa(std::tuple <std::string, std::string> p);
};