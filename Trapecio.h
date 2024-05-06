#ifndef TRAPECIO_H
#define TRAPECIO_H

#include <string>
#include <vector>
#include "Termino.h"

class Trapecio: public Termino {
    private:
        float x1, x2, x3, x4;

    public:
        Trapecio(std::string nombre, std::vector<std::string> coor);
        void setX1(float x1);
        void setX2(float x2);
        void setX3(float x3);
        void setX4(float x4);
        void setConjuntoFuzzy(std::vector<std::string> c) override;
        float calcularPertenencia(float i) override;
        std::string getCoordenadas() override;
        bool estaDentroDelIntervalo(float i) override;
};

#endif

