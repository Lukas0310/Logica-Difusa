#include <iostream>
#include <string>
#include <vector>

#include "Variable.h"
#include "Triangulo.h"
#include "Trapecio.h"
std::vector<Variable*> variables;
//using namespace std;

int main() {
    std::string nVar1 = "Temperatura";
    //std::string dVar1 = "Descripcion de la variable (eliminar de atributos de clase)";
    float minValVar1 = 110;
    float maxValVar1 = 330;
    std::string nFrio = "Frio";
    std::vector<std::string> cFrio = {"110", "110", "140", "180"};
    std::string nFresco = "Fresco";
    std::vector<std::string> cFresco = {"135", "180", "220"};
    std::string nFrio = "Normal";
    std::vector<std::string> cNormal = {"180", "220", "260"};
    std::string nFrio = "Tibio";
    std::vector<std::string> cTibio = {"225", "255", "280"};
    std::string nFrio = "Caliente";
    std::vector<std::string> cCaliente = {"260", "280", "330", "330"};
    
    
    Variable* ejemploVar1 = new Variable();
    std::vector<std::string> c1 ={"0", "20","43"};
    std::string n1 = "Lluvia";
    Triangulo* ptrTr1 = new Triangulo(n1, c1);

    std::vector<std::string> c2 ={"10", "30","50", "70"};
    std::string n2 = "Niebla";
    Trapecio* ptrTr2 = new Trapecio(n2, c2);

    std::vector<std::string> c3 ={"25", "50","80"};
    std::string n3 = "Sol";
    Triangulo* ptrTr3 = new Triangulo(n3, c3);


    /*

    std::cout<<ptrTr1->calcularPertenencia(15.0)<<std::endl;
    std::cout<<ptrTr2->calcularPertenencia(30.0)<<std::endl;
    std::cout<<ptrTr3->calcularPertenencia(15.0)<<std::endl;

    */

    std::vector<Termino*> terminos;
    terminos.push_back(ptrTr1);
    terminos.push_back(ptrTr2);
    terminos.push_back(ptrTr3);

    std::string varNombre = "Clima";
    std::string varDescripcion = "El valor del clima de hoy";
    float climaMin = 0.0;
    float climaMax = 80.0;
    //los valores de prueba son aleatorios

    Variable varPrueba(varNombre, varDescripcion, terminos, climaMin, climaMax);
    varPrueba.fuzificar(44.0);
    return 0;
}
