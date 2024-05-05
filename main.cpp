#include <iostream>
#include <string>
#include <vector>
#include "Variable.h"
#include "Triangulo.h"

//using namespace std;

int main() {

    std::cout << "Hello world!" << std::endl;
    std::vector<std::string> c1 ={"0", "20","43"};
    std::string n1 = "Lluvia";
    float h=1.0;
    Triangulo* ptrTr1 = new Triangulo(h, n1, c1);
    std::vector<std::string> c2 ={"10", "30","50"};
    std::string n2 = "Niebla";
    float h2=1.0;
    Triangulo* ptrTr2 = new Triangulo(h2, n2, c2);
    std::vector<std::string> c3 ={"25", "50","80"};
    std::string n3 = "Sol";
    float h3=1.0;
    Triangulo* ptrTr3 = new Triangulo(h3, n3, c3);


    std::cout<<ptrTr1->pertenenciaCF(15.0)<<std::endl;
    std::cout<<ptrTr2->pertenenciaCF(15.0)<<std::endl;
    std::cout<<ptrTr3->pertenenciaCF(15.0)<<std::endl;
    std::vector<Termino*> terminos;
    terminos.push_back(ptrTr1);
    terminos.push_back(ptrTr2);
    terminos.push_back(ptrTr3);

    std::string varNombre = "Clima";
    std::string varDescripcion = "El valor del clima de hoy";
    float alturaMax = 1.0;
    float climaMin = 0.0;
    float climaMax = 80.0;
    //los valores son random, no tienen mayor sentido

    Variable varPrueba(varNombre, varDescripcion, terminos, climaMin, climaMax);
    varPrueba.fuzificar(44.0);
    //std::cout<<"CONCLUSION DE VARIABLE: "<< ttemp->getNombre()<<std::endl;
    //delete ttemp;

    return 0;


    /*debo tener un montón de variables con terminos diferentes
    despues de pensar un rato, solo tendré max 2 variables
    pero estas sí pueden tener muchos términos

    Puedo crear un vector de variables
    std::vector<Variable> variables;
    para cada variable que haya en el archivo creo un vector de sus terminos
    std::vector<Termino*> terminos;
    recuerda, como estás creando términos*, cada vez que se añada se tiene que borrar el espacio de memoria
    Tengo que llenar terminos usando la lectura del archivo
    Entonces
    stringstream ss
    while (!eof)
        lee la primera linea como variable
        entonces
        ss>nombreVar>>descripcion>>minval>>maxval>>alturamax
        guardar la info de la variable para poder crearla cuando lea todos los terminos
        aca empieza a leer el termino 1 i.e. la segunda linea del archivo
        ss>nombreT>alturaT
        ss>coordenadasSinConfigurar
        std::vector<Termino*> terminosT;
        crearTermino(nombreT, alturaT, coordenadasSinConfigurar)
        con ese metodo ya determino si es triangulo o trapecio y lo añade a un vector de terminos*
        cuando no halla mas terminos en esta linea se crea la variable y se para por parametro terminosT
        Variable Var = new Var(n, d, t, minval, maxval, terminosT)
        Se hace push_back al vector de variables con var
        se hace terminosT.clear();

        lee la tercera linea como variable2, etc.
    luego debe leer las reglas desde otro archivo
    las reglas son bastante sencillas cada linea es una regla, tiene solamente dos variables y solo un resultado
    sin embargo, cada regla puede desarrollar a otras reglas, por lo que necesitamos un motor de inferencia  hacia adelante
    entonces

    cuando ya tengo el vector de variables en el main, necesitaré el input
    input para cada variable
    en orden, recibirá un input y lo fuzzificara
    crea un vector de termino* para cada input fuzzificado, en este caso solo seran dos
    cuando ya tiene esos dos valores, hace termino1->getNombre(), termino2->getNombre() y busca reglas con esas dos caracteristicas
    la conclusion es el output value
    */
}

/*

void crearTermino(std::string nombre, float altura, std::string cc, std::vector<Termino*>& terminosT const) {
    std::string delimiter = " ";
    std::vector<std::string> tokens;
    std::stringstream ss(cc);
    std::string token;

    while (std::getline(ss, token, ' ')) {
        size_t pos = token.find(",");
        if (pos != std::string::npos) {
            std::string value = token.substr(1, pos - 1);
            tokens.push_back(value);
        }
    } if (tokens.size() < 3) {
        throw std::runtime_error("Error: se requieren al menos 3 coordenadas para un conjunto");
    } else if (tokens.size()==3) {
        Triangulo t* = new Triangulo(altura, nombre, tokens);
        terminosT.push_back(t);
    } else if (tokens.size()==4) {
        Trapecio tr* = new Trapecio(altura, nombre, tokens);
        terminosT.push_back(tr);
    } else {
        throw std::runtime_error("Muchas coordenadas");
    }
}

*/
