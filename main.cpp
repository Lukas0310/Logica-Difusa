#include <iostream>
#include <string>
#include <vector>

#include "Variable.h"
#include "Triangulo.h"
#include "Trapecio.h"
std::vector<Variable*> variables;
//using namespace std;

int main() {

    //declaracion de variables del ejemplo de las diapositivas
    std::string nVar1 = "Temperatura";
    std::string dVar1 = "Descripcion de la variable (eliminar de atributos de clase)";
    float minValVar1 = 110;
    float maxValVar1 = 330;
    std::string nFrio = "Frio";
    std::vector<std::string> cFrio = {"110", "110", "140", "180"};
    std::string nFresco = "Fresco";
    std::vector<std::string> cFresco = {"135", "180", "220"};
    std::string nNormal = "Normal";
    std::vector<std::string> cNormal = {"180", "220", "260"};
    std::string nTibio = "Tibio";
    std::vector<std::string> cTibio = {"225", "255", "280"};
    std::string nCaliente = "Caliente";
    std::vector<std::string> cCaliente = {"260", "280", "330", "330"};
    Trapecio* ptrFrio =  new Trapecio(nFrio, cFrio);
    Trapecio* ptrCaliente = new Trapecio(nCaliente, cCaliente);
    Triangulo* ptrFresco = new Triangulo(nFresco, cFresco);
    Triangulo* ptrNormal = new Triangulo(nNormal, cNormal);
    Triangulo* ptrTibio = new Triangulo(nTibio, cTibio);
    std::vector<Termino*> terminosLing;
    terminosLing.push_back(ptrFrio);
    terminosLing.push_back(ptrCaliente);
    terminosLing.push_back(ptrNormal);
    terminosLing.push_back(ptrTibio);
    terminosLing.push_back(ptrFresco);
    Variable* ptrTemperatura = new Variable(nVar1, dVar1, terminosLing, minValVar1, maxValVar1);

    std::string nVar2 = "Presion";
    std::string dVar2 = "Descripcion de la variable (eliminar de atributos de clase)";
    float minValVar2 = 10;
    float maxValVar2 = 230;
    std::string nDebil = "Debil";
    std::vector<std::string> cDebil = {"10", "10", "30", "70"};
    std::string nBaja = "Baja";
    std::vector<std::string> cBaja = {"28", "70", "120"};
    std::string nNormal2 = "Normal";
    std::vector<std::string> cNormal2 = {"70", "120", "165"};
    std::string nFuerte = "Fuerte";
    std::vector<std::string> cFuerte = {"125", "165", "200"};
    std::string nAlta = "Alta";
    std::vector<std::string> cAlta = {"165", "200", "230", "230"};
    Trapecio* ptrDebil =  new Trapecio(nDebil, cDebil);
    Trapecio* ptrAlta = new Trapecio(nAlta, cAlta);
    Triangulo* ptrBaja = new Triangulo(nBaja, cBaja);
    Triangulo* ptrNormal2 = new Triangulo(nNormal2, cNormal2);
    Triangulo* ptrFuerte = new Triangulo(nFuerte, cFuerte);
    std::vector<Termino*> terminosLing2;
    terminosLing2.push_back(ptrDebil);
    terminosLing2.push_back(ptrAlta);
    terminosLing2.push_back(ptrBaja);
    terminosLing2.push_back(ptrNormal2);
    terminosLing2.push_back(ptrFuerte);
    Variable* ptrPresion = new Variable(nVar2, dVar2, terminosLing2, minValVar2, maxValVar2);

    variables.push_back(ptrTemperatura);
    variables.push_back(ptrPresion);
    
    //declaracion de reglas del ejemplo de las diapositivas
    
    

    return 0;
}
