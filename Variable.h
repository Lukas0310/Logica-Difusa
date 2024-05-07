#ifndef FL_VARIABLE_H
#define FL_VARIABLE_H

#include <string>
#include <vector>
#include "Termino.h"

class Variable {
    //la clase variable aloja las variables que vayamos a usar para recibir input y calcular el output
    private:
        std::string nombre;
        std::vector<Termino*> terminos;
        float valor;
        float minimo, maximo;
        /* tiene un nombre, los terminos linguisticos de tipo Termino alojados en un vector y un rango de valores
        */

    public:
        //constructor y setters y getters
        Variable(std::string n, std::vector<Termino*> t, float minval, float maxval);
        void setNombre(std::string n);
        void setTerminos(const std::vector<Termino*>& ts);
        void setMinimo(float m);
        void setMaximo(float m);
        void setValor(float v);
        std::string getNombre();
        std::vector<Termino*> getTerminos();
        float getMinimo();
        float getMaximo();
        float getValor();
        void nuevoTermino(Termino* t);
        bool getTermino(std::string nombreTermino);
        /* fuzificar hace parte de la clase variable porque calcula el grado de pertenencia
            del valor input para cada término linguistico. Es decir si ingreso temp = 80 entonces
            calculo el grado de pertenencia de 80 para cada conjunto fuzzy (termino linguistico)
            dentro del vector de terminos de esta variable
        */
        void fuzificar(float input);
};

#endif
