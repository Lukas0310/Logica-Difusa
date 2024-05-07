// Proyecto 3 - Grupo 1
// Juan Camacho
// Lukas Rodriguez
// Angie Cristancho

#include "Triangulo.h"
#include "Trapecio.h"
#include "MotorInferencia.h"

#include <fstream>
#include <sstream>

using namespace std;

//Funcion para leer los terminos linguisticos y las variables desde el archivo "fuzzyvars.txt"
vector <vector <Triangulo*> > readvars()
{
    int vars, atributos, minVar, maxVar;
    string varname, line, atributeName;
    ifstream ifile;
    vector <string> ValuesAtribute;
    vector <string> minMax;
    vector <Variable*> filevars;
    vector <Triangulo*> tempTerms;
    vector <vector <Triangulo*> > fileterms;

    ifile.open("fuzzyvars.txt");

    if (!ifile) // se verifica si existe el archivo
    {
        cout << "no se encontro el archivo fuzzyvars.txt" << endl;
    }
    else
    {
        ifile >> vars; // se leen cuantas variables estan guardadas en el archivo
        ifile.ignore(); // estos ignore son para que el getline no se confunda con los '\n'
        for (int q = 0; q < vars; q++)
        {
            // se crea un vector con los valores minimos y maximos de la variable correspondiente
            minMax.clear();
            getline(ifile, varname);
            ifile >> minVar;
            minMax.emplace_back(to_string(minVar));
            ifile >> maxVar;
            minMax.emplace_back(to_string(maxVar));
            minMax.emplace_back("0");

            //se esconden los datos de la variable en el primer puesto del vector de terminos, para devolver una sola cosa
            Triangulo* tempvar = new Triangulo(varname, minMax);
            tempTerms.emplace_back(tempvar);

            //se leen cuantos atributos tiene la variable, para saber cuantas lineas leer y separar por comas
            ifile >> atributos;
            ifile.ignore();

            for (int w = 0; w < atributos; w++)
            {
                getline(ifile, line);
                stringstream linestream(line);
                
                getline(linestream, atributeName, ',');
                while (linestream.eof() == false)
                {
                    getline(linestream, ValuesAtribute.emplace_back(), ',');
                }
                Triangulo* ptrTerm = new Triangulo(atributeName, ValuesAtribute);
                tempTerms.emplace_back(ptrTerm); // se llena el vector de terminos
                ValuesAtribute.clear();
            }
            // se llena la matriz de terminos con los vectores de terminos
            fileterms.emplace_back(tempTerms);
            tempTerms.clear();
        }
    }

    return fileterms;
}

int main() 
{
    //Se leen desde el archivo los terminos linguisticos, 
    //y en la matriz de retorno tambien estan los datos de las variables
    vector <vector <Triangulo*> > terminos = readvars();

    //se extrae la informacion de las variables, que tenian datos guardados en el primer "termino"
    // y se llena el vector de variables
    vector <Variable*> variables;

    for (int q = 0; q < terminos.size(); q++)
    {
        string tempname = terminos[q][0]->getNombre();
        float tempmin = terminos[q][0]->getX1();
        float tempmax = terminos[q][0]->getX2();
        terminos[q].erase(terminos[q].begin());

        Variable* ptrVar = new Variable(tempname, terminos[q], tempmin, tempmax);
        variables.emplace_back(ptrVar);
    }

   //declaracion de reglas
    vector <Regla*> reglas;

    vector <tuple <string, string> > premisas1;
    premisas1.push_back(make_tuple("Sabor", "Muy feo"));
    premisas1.push_back(make_tuple("Espera", "Muy largo"));
    Regla* ptrRegla1 = new Regla(premisas1, "baja", 0.0);

    vector <tuple <string, string> > premisas2;
    premisas2.push_back(make_tuple("Sabor", "Muy feo"));
    premisas2.push_back(make_tuple("Espera", "Corto"));
    Regla* ptrRegla2 = new Regla(premisas2, "normal", 0.0);

    vector <tuple <string, string> > premisas3;
    premisas3.push_back(make_tuple("Sabor", "Muy feo"));
    premisas3.push_back(make_tuple("Espera", "Muy corto"));
    Regla* ptrRegla3 = new Regla(premisas3, "normal", 0.0);

    vector <tuple <string, string> > premisas4;
    premisas4.push_back(make_tuple("Sabor", "Muy feo"));
    premisas4.push_back(make_tuple("Espera", "Medio"));
    Regla* ptrRegla4 = new Regla(premisas4, "baja", 0.0);

    vector <tuple <string, string> > premisas5;
    premisas5.push_back(make_tuple("Sabor", "Muy feo"));
    premisas5.push_back(make_tuple("Espera", "Largo"));
    Regla* ptrRegla5 = new Regla(premisas5, "baja", 0.0);

    vector <tuple <string, string> > premisas6;
    premisas6.push_back(make_tuple("Sabor", "Feo"));
    premisas6.push_back(make_tuple("Espera", "Muy corto"));
    Regla* ptrRegla6 = new Regla(premisas6, "normal", 0.0);

    vector <tuple <string, string> > premisas7;
    premisas7.push_back(make_tuple("Sabor", "Feo"));
    premisas7.push_back(make_tuple("Espera", "Corto"));
    Regla* ptrRegla7 = new Regla(premisas7, "normal", 0.0);

    vector <tuple <string, string> > premisas8;
    premisas8.push_back(make_tuple("Sabor", "Feo"));
    premisas8.push_back(make_tuple("Espera", "Medio"));
    Regla* ptrRegla8 = new Regla(premisas8, "baja", 0.0);

    vector <tuple <string, string> > premisas9;
    premisas9.push_back(make_tuple("Sabor", "Feo"));
    premisas9.push_back(make_tuple("Espera", "Largo"));
    Regla* ptrRegla9 = new Regla(premisas9, "baja", 0.0);

    vector <tuple <string, string> > premisas10;
    premisas10.push_back(make_tuple("Sabor", "Feo"));
    premisas10.push_back(make_tuple("Espera", "Muy largo"));
    Regla* ptrRegla10 = new Regla(premisas10, "baja", 0.0);

    vector <tuple <string, string> > premisas11;
    premisas11.push_back(make_tuple("Sabor", "Normal"));
    premisas11.push_back(make_tuple("Espera", "Muy corto"));
    Regla* ptrRegla11 = new Regla(premisas11, "alta", 0.0);

    vector <tuple <string, string> > premisas12;
    premisas12.push_back(make_tuple("Sabor", "Normal"));
    premisas12.push_back(make_tuple("Espera", "Corto"));
    Regla* ptrRegla12 = new Regla(premisas12, "normal", 0.0);

    vector <tuple <string, string> > premisas13;
    premisas13.push_back(make_tuple("Sabor", "Normal"));
    premisas13.push_back(make_tuple("Espera", "Medio"));
    Regla* ptrRegla13 = new Regla(premisas13, "normal", 0.0);

    vector <tuple <string, string> > premisas14;
    premisas14.push_back(make_tuple("Sabor", "Normal"));
    premisas14.push_back(make_tuple("Espera", "Alta"));
    Regla* ptrRegla14 = new Regla(premisas14, "normal", 0.0);

    vector <tuple <string, string> > premisas15;
    premisas15.push_back(make_tuple("Sabor", "Normal"));
    premisas15.push_back(make_tuple("Espera", "Muy alto"));
    Regla* ptrRegla15 = new Regla(premisas15, "baja", 0.0);

    vector <tuple <string, string> > premisas16;
    premisas16.push_back(make_tuple("Sabor", "Rico"));
    premisas16.push_back(make_tuple("Espera", "Muy corto"));
    Regla* ptrRegla16 = new Regla(premisas16, "alta", 0.0);

    vector <tuple <string, string> > premisas17;
    premisas17.push_back(make_tuple("Sabor", "Rico"));
    premisas17.push_back(make_tuple("Espera", "Corto"));
    Regla* ptrRegla17 = new Regla(premisas17, "alta", 0.0);

    vector <tuple <string, string> > premisas18;
    premisas18.push_back(make_tuple("Sabor", "Rico"));
    premisas18.push_back(make_tuple("Espera", "Medio"));
    Regla* ptrRegla18 = new Regla(premisas18, "alta", 0.0);

    vector <tuple <string, string> > premisas19;
    premisas19.push_back(make_tuple("Sabor", "Rico"));
    premisas19.push_back(make_tuple("Espera", "Alta"));
    Regla* ptrRegla19 = new Regla(premisas19, "normal", 0.0);

    vector <tuple <string, string> > premisas20;
    premisas20.push_back(make_tuple("Sabor", "Rico"));
    premisas20.push_back(make_tuple("Espera", "Muy alta"));
    Regla* ptrRegla20 = new Regla(premisas20, "baja", 0.0);

    vector <tuple <string, string> > premisas21;
    premisas21.push_back(make_tuple("Sabor", "Muy rico"));
    premisas21.push_back(make_tuple("Espera", "Muy corto"));
    Regla* ptrRegla21 = new Regla(premisas21, "alta", 0.0);

    vector <tuple <string, string> > premisas22;
    premisas22.push_back(make_tuple("Sabor", "Muy rico"));
    premisas22.push_back(make_tuple("Espera", "Corto"));
    Regla* ptrRegla22 = new Regla(premisas22, "alta", 0.0);

    vector <tuple <string, string> > premisas23;
    premisas23.push_back(make_tuple("Sabor", "Muy rico"));
    premisas23.push_back(make_tuple("Espera", "Medio"));
    Regla* ptrRegla23 = new Regla(premisas23, "alta", 0.0);

    vector <tuple <string, string> > premisas24;
    premisas24.push_back(make_tuple("Sabor", "Muy rico"));
    premisas24.push_back(make_tuple("Espera", "Larga"));
    Regla* ptrRegla24 = new Regla(premisas24, "normal", 0.0);

    vector <tuple <string, string> > premisas25;
    premisas25.push_back(make_tuple("Sabor", "Muy rico"));
    premisas25.push_back(make_tuple("Espera", "Muy larga"));
    Regla* ptrRegla25 = new Regla(premisas25, "normal", 0.0);

    reglas.push_back(ptrRegla1);
    reglas.push_back(ptrRegla2);
    reglas.push_back(ptrRegla3);
    reglas.push_back(ptrRegla4);
    reglas.push_back(ptrRegla5);
    reglas.push_back(ptrRegla6);
    reglas.push_back(ptrRegla7);
    reglas.push_back(ptrRegla8);
    reglas.push_back(ptrRegla9);
    reglas.push_back(ptrRegla10);
    reglas.push_back(ptrRegla11);
    reglas.push_back(ptrRegla12);
    reglas.push_back(ptrRegla13);
    reglas.push_back(ptrRegla14);
    reglas.push_back(ptrRegla15);
    reglas.push_back(ptrRegla16);
    reglas.push_back(ptrRegla17);
    reglas.push_back(ptrRegla18);
    reglas.push_back(ptrRegla19);
    reglas.push_back(ptrRegla20);
    reglas.push_back(ptrRegla21);
    reglas.push_back(ptrRegla22);
    reglas.push_back(ptrRegla23);
    reglas.push_back(ptrRegla24);
    reglas.push_back(ptrRegla25);

    //declaracion de la variable de salida
    //en nuestro caso leimos los parametros de la variable de salida desde el archivo de variables,
    //y guardamos esta variable de salida como la ultima variable que se lee,
    //por lo tanto esta es la ultima variable del vector de variables
    Variable* ptrCalidad = variables.back();
    //y podemos eliminarla del vector de variables cuando la guardamos en la variable especifica de salida
    variables.pop_back();
    
    //entrada de valores
    float sabor = 75;
    float tiempoEspera = 8;

    //fusificacion para sabor
    for (int i = 0; i < variables.size(); i++) 
    {
        if (variables[i]->getNombre() == "Sabor") 
        {
            variables[i]->fuzificar(sabor);
        }
    }

    //fusificacion para tiempo de espera
    for (int i = 0; i < variables.size(); i++) 
    {
        if (variables[i]->getNombre() == "Tiempo de Espera") 
        {
            variables[i]->fuzificar(tiempoEspera);
        }
    }

    //declaracion del motor de inferencia
    MotorInferencia* motor = new MotorInferencia(reglas, variables, ptrCalidad);

    //inferencia
    motor->inferir();

    //defuzificacion
    float paso = 0.01;
    float calidad = motor->defuzzificar(paso);

    return 0;
}