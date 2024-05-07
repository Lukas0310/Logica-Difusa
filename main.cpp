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
    std::string nVar1 = "Sabor";
    std::string dVar1 = "Descripcion de la variable (eliminar de atributos de clase)";
    float minValVar1 = 0;
    float maxValVar1 = 100;
    std::string nMR = "Muy Rico";
    std::vector<std::string> cMR = {"80", "100", "100"};
    std::string nR = "Rico";
    std::vector<std::string> cR = {"60", "80", "100"};
    std::string nNormal = "Normal";
    std::vector<std::string> cNormal = {"40", "60", "80"};
    std::string nF = "Feo";
    std::vector<std::string> cF = {"20", "40", "60"};
    std::string nMF = "Muy Feo";
    std::vector<std::string> cMF = {"0", "20", "40"};
    Trapecio* ptrMR =  new Triangulo(nMR, cMR);
    Trapecio* ptrR = new Triangulo(nR, cR);
    Triangulo* ptrN = new Triangulo(nNormal, cNormal);
    Triangulo* ptrF = new Triangulo(nF, cF);
    Triangulo* ptrMF = new Triangulo(nMF, cMF);
    std::vector<Termino*> terminosLing;
    terminosLing.push_back(ptrMR);
    terminosLing.push_back(ptrR);
    terminosLing.push_back(ptrN);
    terminosLing.push_back(ptrF);
    terminosLing.push_back(ptrMF);
    Variable* ptrSabor = new Variable(nVar1, dVar1, terminosLing, minValVar1, maxValVar1);

    std::string nVar2 = "Tiempo de Espera";
    std::string dVar2 = "Descripcion de la variable (eliminar de atributos de clase)";
    float minValVar2 = 0;
    float maxValVar2 = 60;
    std::string nMC = "Muy Corto";
    std::vector<std::string> cMC = {"0", "0", "5"};
    std::string nC = "Corto";
    std::vector<std::string> cC = {"5", "10", "17"};
    std::string nM = "Mediano";
    std::vector<std::string> cM = {"15", "22", "27"};
    std::string nL = "largo";
    std::vector<std::string> cL = {"27", "30", "45"};
    std::string nML = "Muy Largo";
    std::vector<std::string> cML = {"35", "50", "60", "60"};
    Trapecio* ptrML =  new Trapecio(nML, cML);
    Trapecio* ptrL = new Triangulo(nL, cL);
    Triangulo* ptrM = new Triangulo(nM, cM);
    Triangulo* ptrC = new Triangulo(nC, cC);
    Triangulo* ptrMC = new Triangulo(nMC, cMC);
    std::vector<Termino*> terminosLing2;
    terminosLing2.push_back(ptrML);
    terminosLing2.push_back(ptrL);
    terminosLing2.push_back(ptrM);
    terminosLing2.push_back(ptrC);
    terminosLing2.push_back(ptrMC);
    Variable* ptrTiempoEspera = new Variable(nVar2, dVar2, terminosLing2, minValVar2, maxValVar2);

    variables.push_back(ptrSabor);
    variables.push_back(ptrTiempoEspera);
    
    //declaracion de reglas del ejemplo de las diapositivas
    //Regla(std::vector<std::tuple<std::string, std::string>> p, std::string c, float v);
    
    

    return 0;
}
