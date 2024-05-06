#include <vector>
#include <string>
#include "Variable.h"
#include "Regla.h"
#include "MotorInferencia.h"

MotorInferencia::MotorInferencia(std::vector<Regla*> r, std::vector<Variable*> v) {
    reglas = r;
    variables = v;
}

//metodo para establecer los valores de inferencia de las reglas: ej: (velocidad alta -> frenar) -> (0.8 -> frenar)
void MotorInferencia::setValoresInferencia() {
    for (int i = 0; i < reglas.size(); i++) {
        float minimo = 999999;
        for (int j = 0; j < reglas[i]->getPremisas().size(); j++) {
            std::string nombreVariable = std::get<0>(reglas[i]->getPremisas()[j]);
            std::string nombreTermino = std::get<1>(reglas[i]->getPremisas()[j]);
            for (int k = 0; k < variables.size(); k++) {
                if (variables[k]->getNombre() == nombreVariable) {
                    for (int l = 0; l < variables[k]->getTerminos().size(); l++) {
                        if (variables[k]->getTerminos()[l]->getNombre() == nombreTermino) {
                            float pertenencia = variables[k]->getTerminos()[l]->getPertenencia();
                            if (pertenencia < minimo) {
                                minimo = pertenencia;
                            }
                        }
                    }
                }
            }
        }
        reglas[i]->setValorInferencia(minimo);
    }
}

/*
Metdo para realizar la inferencia.
Establece el punto de corte en  el vector de acciones.
Si en las acciones ya se establecio el punto de corte y se encuentra un nuevo valor 
para esa accion, se elige el valor mas alto.
*/
void MotorInferencia::inferir() {
    setValoresInferencia();
    for (int i = 0; i < reglas.size(); i++) {
        float valorInferencia = reglas[i]->getValorInferencia();
        std::string nombreConsecuente = reglas[i]->getConsecuencia();
        for (int j = 0; j < salida->getTerminos().size(); j++) {
            if (salida->getTerminos()[j]->getNombre() == nombreConsecuente) {
                if (salida->getTerminos()[j]->getAltura() < valorInferencia) {
                    salida->getTerminos()[j]->setAltura(valorInferencia);
                }
            }
        }
    }
    //aca debe ir el for para iterar en Variable* salida para ir construyendo los puntos
    
}

/*
metodo para realizar la defuzzificacion.
Utiliza el metodo del centroide para obtener el valor de salida.
*/
