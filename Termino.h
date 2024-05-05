#ifndef TERMINO_H
#define TERMINO_H

#include <string>
#include <vector>

class Termino {
    private:
        std::string nombreT;
        float pertenencia;
        char tipo; //triangulo T o trapezoide Z

    public:
        void setNombre(std::string n);
        void setPertenencia(float h);
        void setTipo(char t);
        std::string getNombre();
        float getPertenencia();
        char getTipo();
        virtual void setConjuntoFuzzy(std::vector<std::string> p ) = 0;
        virtual std::string getCoordenadas() = 0;
        //este metodo esta implementado de manera diferente en cada uno de los tipos de conjunto
        virtual float calcularPertenencia(float input) = 0 ;
        //este metodo hace el defuzzificacion y fuzzificacion porque recibe el input, lo revisa como pertenencia al termino y retorna qué tanto pertenece al término
        //ej. input es 4 retorna pertenencia 80%
};

#endif
