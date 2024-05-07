// Proyecto 3 - Grupo 1
// Juan Camacho
// Lukas Rodriguez
// Angie Cristancho

#include "Triangulo.h"
#include "Trapecio.h"
#include "MotorInferencia.h"

#include <fstream>
#include <sstream>
#include <tuple>

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
    ifile.close();

    return fileterms;
}
//Esta es la funcion para leer las reglas de la base de conocimientos,
//Aca se leen 3 lineas a la vez del archivo "fuzzyreglas.txt",
//Las primeras dos lineas representan una variable y su valor linguistico
//Y la tercera line tiene las consecuencias sobre la variable de salida de las anteriores 2 lineas
vector <Regla*> readrules()
{
    ifstream ifile;
    vector <Regla*> filereglas;

    ifile.open("fuzzyreglas.txt");

    if (!ifile) //se verifica que el archivo exista
    {
        cout << "no se encontro el archivo fuzzyreglas.txt" << endl;
    }
    else
    {
        while (ifile.eof() == false)
        {
            //se crean variables temporales para almacenar los datos de cada linea
            float consecuenciafloat;
            string consecuenciastring, line, s1, s2;
            vector <tuple <string, string> > premisas;

            //se lee la primera linea, se separa, y se guarda en el vector de tuplas de premisas
            getline(ifile, line);
            stringstream linestream(line);
            getline(linestream, s1, ',');
            linestream.ignore();
            getline(linestream, s2);
            premisas.emplace_back(make_tuple(s1, s2));

            //se lee la segunda linea, se separa, y se guarda en el vector de tuplas de premisas
            getline(ifile, line);
            stringstream linestream2(line);
            getline(linestream2, s1, ',');
            linestream2.ignore();
            getline(linestream2, s2);
            premisas.emplace_back(make_tuple(s1, s2));

            //La tercera linea se guarda su variable en string y su consecuencia en float
            getline(ifile, line);
            stringstream linestream3(line);
            getline(linestream3, consecuenciastring, ',');
            linestream3 >> consecuenciafloat;

            // y con esto se crea una regla que va a ser almacenada en el vector de reglas
            Regla* ptrRegla = new Regla(premisas, consecuenciastring, consecuenciafloat);

            filereglas.emplace_back(ptrRegla);
        }
    }
    ifile.close();

    //se retorna el vector de reglas
    return filereglas;
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

    //lectura de reglas desde el archivo
    vector <Regla*> reglas = readrules();

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