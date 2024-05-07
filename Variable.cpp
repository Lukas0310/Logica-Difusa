#include "Variable.h"
using namespace std;

Variable::Variable(std::string n, std::vector<Termino*> t, float minval, float maxval){
    nombre=n;
    terminos=t;
    minimo=minval;
    maximo=maxval;
};
//constructor basico
//deberia implementar un destructor que elimine todos los termino* del vector

//setters y getters
void Variable::setNombre(std::string n){
    nombre=n;
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
    for (int i=0;i<terminos.size();i++){
        if(terminos[i]->getNombre()==nombreTermino) {
            return true;
        }
    }
    return false;
};

//fuzzificar es importante porque debe poder calcular el valor de pertenencia del input recibido para CADA término que haya
void Variable::fuzificar(float input){
    cout<<"--- Fuzificando variable: "<<nombre<<endl;
    for (int i=0;i<terminos.size();i++) {
        std::cout<<"--- Termino: "<<terminos[i]->getNombre()<<std::endl;
        float pert = terminos[i]->calcularPertenencia(input);
        std::cout<<"--- Pertenencia:  "<<pert<<std::endl;
        terminos[i]->setPertenencia(pert);
    }
};