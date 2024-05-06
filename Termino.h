#ifndef TERMINO_H
#define TERMINO_H

#include <string>
#include <vector>

class Termino {
    private:
        std::string nombreT;
        float pertenencia;
        char tipo; //triangulo T o trapezoide Z
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
        virtual void setConjuntoFuzzy(std::vector<std::string> p ) = 0;
        virtual std::string getCoordenadas() = 0;
        virtual float calcularPertenencia(float input) = 0 ;
        virtual bool estaDentroDelIntervalo(float input) = 0;
};        

#endif
