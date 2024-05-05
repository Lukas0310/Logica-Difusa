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
    float h=1.0;
    Triangulo* ptrTr1 = new Triangulo(h, n1, c1);
    std::vector<std::string> c2 ={"10", "30","50", "70"};
    std::string n2 = "Niebla";
    float h2=1.0;
    Trapecio* ptrTr2 = new Trapecio(h2, n2, c2);
    std::vector<std::string> c3 ={"25", "50","80"};
    std::string n3 = "Sol";
    float h3=1.0;
    Triangulo* ptrTr3 = new Triangulo(h3, n3, c3);


    /*

    std::cout<<ptrTr1->pertenenciaCF(15.0)<<std::endl;
    std::cout<<ptrTr2->pertenenciaCF(30.0)<<std::endl;
    std::cout<<ptrTr3->pertenenciaCF(15.0)<<std::endl;

    */

    std::vector<Termino*> terminos;
    terminos.push_back(ptrTr1);
    terminos.push_back(ptrTr2);
    terminos.push_back(ptrTr3);

    std::string varNombre = "Clima";
    std::string varDescripcion = "El valor del clima de hoy";
    float alturaMax = 1.0;
    float climaMin = 0.0;
    float climaMax = 80.0;
    //los valores de prueba son aleatorios

    Variable varPrueba(varNombre, varDescripcion, terminos, climaMin, climaMax);
    varPrueba.fuzificar(44.0);
    return 0;
}