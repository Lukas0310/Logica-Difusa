#pragma once

#include "Termino.h"

class Trapecio: public Termino {
    /* la clase trapecio hereda termino porque es un tipo de conjunto fuzzy
    en este caso tenemos 4 atributos haciendo referencia a las coordenadas en x del trapecio
        solo las tomamos en x porque asumimos que x2 y x3 están en el punto más alto i.e. 1
    también hereda los métodos de calcularPertenencia y los adapta
    */
    private:
        float x1, x2, x3, x4;

    public:
        Trapecio(std::string nombre, std::vector<std::string> coor);
        void setX1(float x1);
        void setX2(float x2);
        void setX3(float x3);
        void setX4(float x4);
        //metodos heredados
        void setConjuntoFuzzy(std::vector<std::string> c) override;
        //en este caso configura cuatro coordenadas en vez de tres
        float calcularPertenencia(float i) override;
        std::string getCoordenadas() override;
        bool estaDentroDelIntervalo(float i) override;
};