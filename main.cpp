#include <iostream>
#include <string>
#include <vector>

#include "Variable.h"
#include "Triangulo.h"
#include "Trapecio.h"
#include "Regla.h"
#include "MotorInferencia.h"
std::vector<Variable*> variables;
using namespace std;

int main() {

    //declaracion de variables del ejemplo de las diapositivas
    std::string nVar1 = "Sabor";
    float minValVar1 = 0;
    float maxValVar1 = 100;
    std::string nMR = "Muy rico";
    std::vector<std::string> cMR = {"80", "100", "100"};
    std::string nR = "Rico";
    std::vector<std::string> cR = {"60", "80", "100"};
    std::string nNormal = "Normal";
    std::vector<std::string> cNormal = {"40", "60", "80"};
    std::string nF = "Feo";
    std::vector<std::string> cF = {"20", "40", "60"};
    std::string nMF = "Muy feo";
    std::vector<std::string> cMF = {"0", "20", "40"};
    Termino* ptrMR =  new Triangulo(nMR, cMR);
    Termino* ptrR = new Triangulo(nR, cR);
    Termino* ptrN = new Triangulo(nNormal, cNormal);
    Termino* ptrF = new Triangulo(nF, cF);
    Termino* ptrMF = new Triangulo(nMF, cMF);
    std::vector<Termino*> terminosLing;
    terminosLing.push_back(ptrMR);
    terminosLing.push_back(ptrR);
    terminosLing.push_back(ptrN);
    terminosLing.push_back(ptrF);
    terminosLing.push_back(ptrMF);
    Variable* ptrSabor = new Variable(nVar1, terminosLing, minValVar1, maxValVar1);

    std::string nVar2 = "Tiempo de espera";
    float minValVar2 = 0;
    float maxValVar2 = 60;
    std::string nMC = "Muy corto";
    std::vector<std::string> cMC = {"0", "0", "5"};
    std::string nC = "Corto";
    std::vector<std::string> cC = {"5", "10", "17"};
    std::string nM = "Medio";
    std::vector<std::string> cM = {"15", "22", "27"};
    std::string nL = "Largo";
    std::vector<std::string> cL = {"27", "30", "45"};
    std::string nML = "Muy largo";
    std::vector<std::string> cML = {"35", "50", "60", "60"};
    Termino* ptrML =  new Trapecio(nML, cML);
    Termino* ptrL = new Triangulo(nL, cL);
    Termino* ptrM = new Triangulo(nM, cM);
    Termino* ptrC = new Triangulo(nC, cC);
    Termino* ptrMC = new Triangulo(nMC, cMC);
    std::vector<Termino*> terminosLing2;
    terminosLing2.push_back(ptrML);
    terminosLing2.push_back(ptrL);
    terminosLing2.push_back(ptrM);
    terminosLing2.push_back(ptrC);
    terminosLing2.push_back(ptrMC);
    Variable* ptrTiempoEspera = new Variable(nVar2, terminosLing2, minValVar2, maxValVar2);

    variables.push_back(ptrSabor);
    variables.push_back(ptrTiempoEspera);
    

   //declaracion de reglas
    std::vector<Regla*> reglas;

    std::vector<std::tuple<std::string, std::string>> premisas1;
    premisas1.push_back(std::make_tuple("Sabor", "Muy feo"));
    premisas1.push_back(std::make_tuple("Tiempo de espera", "Muy largo"));
    Regla* ptrRegla1 = new Regla(premisas1, "Baja", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas2;
    premisas2.push_back(std::make_tuple("Sabor", "Muy feo"));
    premisas2.push_back(std::make_tuple("Tiempo de espera", "Corto"));
    Regla* ptrRegla2 = new Regla(premisas2, "Normal", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas3;
    premisas3.push_back(std::make_tuple("Sabor", "Muy feo"));
    premisas3.push_back(std::make_tuple("Tiempo de espera", "Muy corto"));
    Regla* ptrRegla3 = new Regla(premisas3, "Normal", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas4;
    premisas4.push_back(std::make_tuple("Sabor", "Muy feo"));
    premisas4.push_back(std::make_tuple("Tiempo de espera", "Medio"));
    Regla* ptrRegla4 = new Regla(premisas4, "Baja", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas5;
    premisas5.push_back(std::make_tuple("Sabor", "Muy feo"));
    premisas5.push_back(std::make_tuple("Tiempo de espera", "Largo"));
    Regla* ptrRegla5 = new Regla(premisas5, "Baja", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas6;
    premisas6.push_back(std::make_tuple("Sabor", "Feo"));
    premisas6.push_back(std::make_tuple("Tiempo de espera", "Muy corto"));
    Regla* ptrRegla6 = new Regla(premisas6, "Normal", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas7;
    premisas7.push_back(std::make_tuple("Sabor", "Feo"));
    premisas7.push_back(std::make_tuple("Tiempo de espera", "Corto"));
    Regla* ptrRegla7 = new Regla(premisas7, "Normal", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas8;
    premisas8.push_back(std::make_tuple("Sabor", "Feo"));
    premisas8.push_back(std::make_tuple("Tiempo de espera", "Medio"));
    Regla* ptrRegla8 = new Regla(premisas8, "Baja", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas9;
    premisas9.push_back(std::make_tuple("Sabor", "Feo"));
    premisas9.push_back(std::make_tuple("Tiempo de espera", "Largo"));
    Regla* ptrRegla9 = new Regla(premisas9, "Baja", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas10;
    premisas10.push_back(std::make_tuple("Sabor", "Feo"));
    premisas10.push_back(std::make_tuple("Tiempo de espera", "Muy largo"));
    Regla* ptrRegla10 = new Regla(premisas10, "Baja", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas11;
    premisas11.push_back(std::make_tuple("Sabor", "Normal"));
    premisas11.push_back(std::make_tuple("Tiempo de espera", "Muy corto"));
    Regla* ptrRegla11 = new Regla(premisas11, "Alta", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas12;
    premisas12.push_back(std::make_tuple("Sabor", "Normal"));
    premisas12.push_back(std::make_tuple("Tiempo de espera", "Corto"));
    Regla* ptrRegla12 = new Regla(premisas12, "Normal", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas13;
    premisas13.push_back(std::make_tuple("Sabor", "Normal"));
    premisas13.push_back(std::make_tuple("Tiempo de espera", "Medio"));
    Regla* ptrRegla13 = new Regla(premisas13, "Normal", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas14;
    premisas14.push_back(std::make_tuple("Sabor", "Normal"));
    premisas14.push_back(std::make_tuple("Tiempo de espera", "Largo"));
    Regla* ptrRegla14 = new Regla(premisas14, "Normal", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas15;
    premisas15.push_back(std::make_tuple("Sabor", "Normal"));
    premisas15.push_back(std::make_tuple("Tiempo de espera", "Muy largo"));
    Regla* ptrRegla15 = new Regla(premisas15, "Baja", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas16;
    premisas16.push_back(std::make_tuple("Sabor", "Rico"));
    premisas16.push_back(std::make_tuple("Tiempo de espera", "Muy corto"));
    Regla* ptrRegla16 = new Regla(premisas16, "Alta", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas17;
    premisas17.push_back(std::make_tuple("Sabor", "Rico"));
    premisas17.push_back(std::make_tuple("Tiempo de espera", "Corto"));
    Regla* ptrRegla17 = new Regla(premisas17, "Alta", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas18;
    premisas18.push_back(std::make_tuple("Sabor", "Rico"));
    premisas18.push_back(std::make_tuple("Tiempo de espera", "Medio"));
    Regla* ptrRegla18 = new Regla(premisas18, "Alta", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas19;
    premisas19.push_back(std::make_tuple("Sabor", "Rico"));
    premisas19.push_back(std::make_tuple("Tiempo de espera", "Largo"));
    Regla* ptrRegla19 = new Regla(premisas19, "Normal", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas20;
    premisas20.push_back(std::make_tuple("Sabor", "Rico"));
    premisas20.push_back(std::make_tuple("Tiempo de espera", "Muy largo"));
    Regla* ptrRegla20 = new Regla(premisas20, "Baja", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas21;
    premisas21.push_back(std::make_tuple("Sabor", "Muy rico"));
    premisas21.push_back(std::make_tuple("Tiempo de espera", "Muy corto"));
    Regla* ptrRegla21 = new Regla(premisas21, "Alta", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas22;
    premisas22.push_back(std::make_tuple("Sabor", "Muy rico"));
    premisas22.push_back(std::make_tuple("Tiempo de espera", "Corto"));
    Regla* ptrRegla22 = new Regla(premisas22, "Alta", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas23;
    premisas23.push_back(std::make_tuple("Sabor", "Muy rico"));
    premisas23.push_back(std::make_tuple("Tiempo de espera", "Medio"));
    Regla* ptrRegla23 = new Regla(premisas23, "Alta", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas24;
    premisas24.push_back(std::make_tuple("Sabor", "Muy rico"));
    premisas24.push_back(std::make_tuple("Tiempo de espera", "Largo"));
    Regla* ptrRegla24 = new Regla(premisas24, "Normal", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas25;
    premisas25.push_back(std::make_tuple("Sabor", "Muy rico"));
    premisas25.push_back(std::make_tuple("Tiempo de espera", "Muy largo"));
    Regla* ptrRegla25 = new Regla(premisas25, "Normal", 0.0);

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
    std::string nVar3 = "Calidad";
    float minValVar3 = 0;
    float maxValVar3 = 100;
    std::string nBaja = "Baja";
    std::vector<std::string> cBaja = {"0", "5", "10"};
    std::string sNormal = "Normal";
    std::vector<std::string> cNormal2 = {"8", "15", "27"};
    std::string nAlta = "Alta";
    std::vector<std::string> cAlta = {"20", "30", "90", "100"};
    Termino* ptrBaja =  new Triangulo(nBaja, cBaja);
    Termino* ptrNormal = new Triangulo(sNormal, cNormal2);
    Termino* ptrAlta = new Trapecio(nAlta, cAlta);
    std::vector<Termino*> terminosLing3;
    terminosLing3.push_back(ptrBaja);
    terminosLing3.push_back(ptrNormal);
    terminosLing3.push_back(ptrAlta);
    Variable* ptrCalidad = new Variable(nVar3, terminosLing3, minValVar3, maxValVar3);

    //entrada de valores
    float sabor = 75;
    float tiempoEspera = 8;

    cout<<"\n\n---------- Iniciando fusificacion ----------\n"<<endl;
    //fusificacion para sabor
    for (int i = 0; i < variables.size(); i++) {
        if (variables[i]->getNombre() == "Sabor") {
            variables[i]->fuzificar(sabor);
        }
    }

    //fusificacion para tiempo de espera
    for (int i = 0; i < variables.size(); i++) {
        if (variables[i]->getNombre() == "Tiempo de espera") {
            variables[i]->fuzificar(tiempoEspera);
        }
    }

    //declaracion del motor de inferencia
    MotorInferencia* motor = new MotorInferencia(reglas, variables, ptrCalidad);

    //inferencia
    motor->inferir();

    //defuzificacion
    float paso = 0.001;
    float calidad = motor->defuzzificar(paso);


    return 0;
}
