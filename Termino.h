#pragma once

#include <iostream>
#include <string>
#include <vector>

class Termino {
/* la clase termino es una clase padre, basicamente se refiere a cada conjunto fuzzy o
    termino linguistico que tenga una variable. En el ejemplo estos son los valores de
    "muy frio", "muy feo", "normal" donde el conjunto puede ser un triangulo o 
    un trapecio
*/
    private:
        /* tiene como atributos el nombre, el valor de pertenencia que se calcula ocn un metodo que 
        se puede heredar de forma diferente para triangulo o para trapecio
        */
        std::string nombreT;
        float pertenencia;
        char tipo; //triangulo T o trapezoide Z aunque no lo usamos
        float altura; //se usa para la parte de inferencia y defuzzificacion

    public:
        void setNombre(std::string n);
        void setPertenencia(float h);
        void setTipo(char t);
        void setAltura(float a);
        std::string getNombre();
        float getPertenencia();
        char getTipo();
        float getAltura();
        //estos son los metodos que se pueden heredar a los tipos de termino
        //si es triangulo es diferente a si es trapecio y por eso lo de calcularPertenencias cambia
        virtual void setConjuntoFuzzy(std::vector<std::string> p ) = 0;
        virtual std::string getCoordenadas() = 0;
        virtual float calcularPertenencia(float input) = 0 ;
        virtual bool estaDentroDelIntervalo(float input) = 0;
};