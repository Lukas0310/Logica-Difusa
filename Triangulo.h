#ifndef TRIANGULO_H
#define TRIANGULO_H

#include <string>
#include <vector>
#include "Termino.h"

class Triangulo: public Termino {
    /* La clase triangulo hereda a Termino porque es un tipo de conjunto Fuzzy o de
        término linguistico que tiene tres coordenadas, en este caso pusimos xy
        pero se asume que la segunda coordenada esta en el punto mas alto es decir 1
    */
    private:
        float xy1, xy2, xy3;
        //solo tiene como atributos propios las coordenadas

    public:
        Triangulo(std::string nombre, std::vector<std::string> coor);
        void setX1(float x1);
        void setX2(float x2);
        void setX3(float x3);
        //estos son los metodos que se adaptan a cada tipo de conjunto
        void setConjuntoFuzzy(std::vector<std::string> c) override;
        //guarda las coordenadas leyendo un vector de strings que tienen las x
        float calcularPertenencia(float i) override;
        //calcula la pertenencia de un input i al triangulo teniendo en cuenta las coordenadas
        std::string getCoordenadas() override;
        bool estaDentroDelIntervalo(float i) override;
};

#endif
