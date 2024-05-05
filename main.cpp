#include <iostream>
#include <string>
#include <vector>

#include "Variable.h"
#include "Triangulo.h"
#include "Trapecio.h"

//using namespace std;

int main() {


    std::cout << "Hello world!" << std::endl;
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