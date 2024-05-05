#ifndef TRIANGULO_H
#define TRIANGULO_H

#include <string>
#include <vector>
#include "Termino.h"

class Triangulo: public Termino {
    private:
        float xy1, xy2, xy3;

    public:
        Triangulo(float h, std::string nombre, std::vector<std::string> coor);
        void setX1(float x1);
        void setX2(float x2);
        void setX3(float x3);
        void setConjuntoFuzzy(std::vector<std::string> c) override;
        float pertenenciaCF(float i) override;
        std::string getCoordenadas() override;
};

#endif
