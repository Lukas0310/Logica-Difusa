#ifndef FL_VARIABLE_H
#define FL_VARIABLE_H

#include <string>
#include <vector>
#include "Termino.h"

class Variable {
    private:
        std::string nombre;
        std::string descripcion;
        std::vector<Termino*> terminos;
        float valor;
        float minimo, maximo;

    public:
        Variable(std::string n, std::string d, std::vector<Termino*> t, float minval, float maxval);
        void setNombre(std::string n);
        void setDescripcion(std::string d);
        void setTerminos(const std::vector<Termino*>& ts);
        void setMinimo(float m);
        void setMaximo(float m);
        void setValor(float v);
        std::string getNombre();
        std::string getDescripcion();
        std::vector<Termino*> getTerminos();
        float getMinimo();
        float getMaximo();
        float getValor();
        void nuevoTermino(Termino* t);
        bool getTermino(std::string nombreTermino);
        void fuzificar(float input);
};

#endif
