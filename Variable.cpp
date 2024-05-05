#include <string>
#include <vector>
#include "Termino.h"
#include "Variable.h"
#include <iostream>

Variable::Variable(std::string n, std::string d, std::vector<Termino*> t, float minval, float maxval){
    nombre=n;
    descripcion=d;
    terminos=t;
    minimo=minval;
    maximo=maxval;
};

void Variable::setNombre(std::string n){
    nombre=n;
};

void Variable::setDescripcion(std::string d){
    descripcion=d;
};

void Variable::setTerminos(const std::vector<Termino*>& ts){
    terminos=ts;
};

void Variable::setMinimo(float m){
    minimo=m;
};

void Variable::setMaximo(float m){
    maximo=m;
};

void Variable::setValor(float v){
    valor=v;
};

std::string Variable::getNombre(){
    return nombre;
};

std::string Variable::getDescripcion(){
    return descripcion;
};

std::vector<Termino*> Variable::getTerminos(){
    return terminos;
};

float Variable::getMinimo(){
    return minimo;
};

float Variable::getMaximo(){
    return maximo;
};

float Variable::getValor(){
    return valor;
};

void Variable::nuevoTermino(Termino* t){
    terminos.push_back(t);
};

bool Variable::getTermino(std::string nombreTermino){
    //std::vector<Termino*>::iterator itT;
    for (int i=0;i<terminos.size();i++){
        if(terminos[i]->getNombre()==nombreTermino) {
            return true;
        }
    }
    return false;
};

void Variable::fuzificar(float input){
    /*
    fuzificar es importante
    los pasos son
    crear un float de referencia
    hacer un for que recorre cada termino
    en cada termino va a revisar que el input cuanto pertenece
    if pert = 0, pues nada continue
    if pert no es ninguna de los anteriores, lo compara con el floatRef y si es mayor lo cambia por ese valor
    tambien guarda el termino como un apuntador al termino temporal
    recuerda, debes redirigir el apuntador al termino que sea mayor
    por ultimo retorna el termino que haya tenido mayor pertenencia
    */

    float fRef = 0.0;
    //Termino* ttemp = nullptr;
    for (int i=0;i<terminos.size();i++) {
        std::cout<<"Termino: "<<terminos[i]->getNombre();
        float pert = terminos[i]->pertenenciaCF(input);
        std::cout<<"   Pertenencia:  "<<pert<<std::endl;
        terminos[i]->setAltura(pert);
    }
};


