/* 
Clase que realiza la inferencia difusa.
las reglas estan compuestas de dos entradas y una salida
*/

#pragma once

#include "Regla.h"

class MotorInferencia 
{
    private:
        std::vector<Regla*> reglas;
        std::vector<Variable*> variables;
        //representa la variable que contiene las acciones a realizar despues de la inferencia
        Variable* salida;

    public:
        //constructor
        MotorInferencia(std::vector<Regla*> r, std::vector<Variable*> v, Variable* s);
        
        //metodo para establecer los valores de inferencia de las reglas: ej: (velocidad alta -> frenar) -> (0.8 -> frenar)
        void setValoresInferencia();

        //metdo para realizar la inferencia. retorna una lista de puntos en el plano que componen la salida
        void inferir();

        //defuzzificacion
        float defuzzificar(float x);

        //obtiene el mayor u de un conjunto de terminos
        float getMayorU(float x);
};