#include <iostream>
#include <vector>
#include <string>
#include "Variable.h"
#include "Regla.h"
#include "MotorInferencia.h"
#include "Termino.h"

using namespace std;

MotorInferencia::MotorInferencia(std::vector<Regla*> r, std::vector<Variable*> v, Variable* s) {
    reglas = r;
    variables = v;
    salida = s;
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
        cout<<"--- Estableciendo valor de inferencia: (";
        for (int j = 0; j < reglas[i]->getPremisas().size(); j++) {
            cout<<std::get<1>(reglas[i]->getPremisas()[j])<<" ";
            if(j < reglas[i]->getPremisas().size()-1){
                cout<<"& ";
            }
        }
        cout<<"-> "<<reglas[i]->getConsecuencia()<<") <--> ("<<reglas[i]->getValorInferencia()<<" -> "<<reglas[i]->getConsecuencia()<<")"<<endl;
    }
}

/*
Metdo para realizar la inferencia.
Establece el punto de corte en  el vector de acciones.
Si en las acciones ya se establecio el punto de corte y se encuentra un nuevo valor 
para esa accion, se elige el valor mas alto.
*/
void MotorInferencia::inferir() {
    cout<<"\n\n---------- Iniciando Inferencia: ----------\n"<<endl;
    setValoresInferencia();
    for (int i = 0; i < reglas.size(); i++) {
        float valorInferencia = reglas[i]->getValorInferencia();
        std::string nombreConsecuente = reglas[i]->getConsecuencia();
        for (int j = 0; j < salida->getTerminos().size(); j++) {
            if (salida->getTerminos()[j]->getNombre() == nombreConsecuente) {
                if (salida->getTerminos()[j]->getAltura() < valorInferencia) {
                    cout<<"--- Estableciendo altura en termino de salida: "<<salida->getTerminos()[j]->getNombre()<<" = "<<valorInferencia<<endl;
                    salida->getTerminos()[j]->setAltura(valorInferencia);
                }
            }
        }
    }
}

//Funcion que recibe un x y retorna el u mas alto de los terminos de salida
float MotorInferencia::getMayorU(float x) {
    float mayor = 0;
    for (int i = 0; i < salida->getTerminos().size(); i++) {
        if (salida->getTerminos()[i]->estaDentroDelIntervalo(x) && salida->getTerminos()[i]->getAltura() > 0) {
            float pertenencia = salida->getTerminos()[i]->calcularPertenencia(x);
            if (pertenencia <= salida->getTerminos()[i]->getAltura() && pertenencia > mayor) {
                mayor = pertenencia;
            }
        }
    }
    return mayor;
}
                
/*
metodo para realizar la defuzzificacion.
Utiliza el metodo del centroide para obtener el valor de salida.
*/
float MotorInferencia::defuzzificar(float paso) {
    cout<<"\n\n---------- Iniciando Defuzzificacion: ----------\n"<<endl;
    float numerador = 0;
    float denominador = 0;
    for (float i = salida->getMinimo(); i <= salida->getMaximo(); i += paso) {
        numerador += i * getMayorU(i);
        denominador += getMayorU(i);
    }
    cout<<"--- Metodo del centroide: "<<endl;
    cout<<"--- Valor de salida: "<<numerador / denominador<<endl;
    return numerador / denominador;
}        