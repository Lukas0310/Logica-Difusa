/* 
Clase que realiza la inferencia difusa.
las reglas estan compuestas de dos entradas y una salida
la representacion de las reglas es en una matriz.
*/

#ifndef MOTORINFERENCIA_H
#define MOTORINFERENCIA_H

#include <tuple>
#include <vector>
#include <string>
#include "Variable.h"
#include "Regla.h"

class MotorInferencia {

    private:
        std::vector<Regla*> reglas;
        std::vector<Variable*> variables;
        //representa la variable que contiene las acciones a realizar despues de la inferencia
        Variable* salida;
        //puntos en el plano qeu representan la grafica/conjunto a defuzzificar
        std::vector<std::tuple<float, float>> puntos;

    public:
        //constructor
        MotorInferencia(std::vector<Regla*> r, std::vector<Variable*> v);
        
        //metodo para establecer los valores de inferencia de las reglas: ej: (velocidad alta -> frenar) -> (0.8 -> frenar)
        void setValoresInferencia();

        //metdo para realizar la inferencia. retorna una lista de puntos en el plano que componen la salida
        void inferir();

        //defuzzificacion
        float defuzzificar();


};


#endif
