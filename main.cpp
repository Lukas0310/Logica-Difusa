#include <iostream>
#include <string>
#include <vector>

#include "Variable.h"
#include "Triangulo.h"
#include "Trapecio.h"
#include "Regla.h"
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
    
    /*
    R1: SI (sabor es muy feo Y espera es muy largo) ENTONCES (propina baja)​
    R2: SI (sabor es muy feo Y espera es corto) ENTONCES (propina normal)​
    R3: SI (sabor es muy feo Y espera es muy corto) ENTONCES (propina normal)​
    R4: SI (sabor es muy feo Y espera es medio) ENTONCES (propina baja)​
    R5: SI (sabor es muy feo Y espera es largo) ENTONCES (propina baja)​
    R6: SI (sabor es feo  Y espera es muy corto) ENTONCES (propina normal)​
    R7: SI (sabor es feo  Y espera es corto) ENTONCES (propina normal)​
    R8: SI (sabor es feo  Y espera es medio) ENTONCES (propina baja)​
    R9: SI (sabor es feo  Y espera es largo) ENTONCES (propina baja)​
    R10: SI (sabor es feo  Y espera es muy largo) ENTONCES (propina baja)​
    R11: SI (sabor es normal Y espera es muy corto) ENTONCES (propina alta)​
    R12: SI (sabor es normal Y espera es corto) ENTONCES (propina normal)​
    R13: SI (sabor es normal Y espera es medio) ENTONCES (propina normal)​
    R14: SI (sabor es normal Y espera es alta) ENTONCES (propina normal)​
    R15: SI (sabor es normal Y espera es muy alto) ENTONCES (propina baja)​
    R16: SI (sabor es rico Y espera es muy corto) ENTONCES (propina alta)​
    R17: SI (sabor es rico Y espera es corto) ENTONCES (propina alta)​
    R18: SI (sabor es rico Y espera es medio) ENTONCES (propina alta)​
    R19: SI (sabor es rico Y espera es alta) ENTONCES (propina normal)​
    R20: SI (sabor es rico Y espera es muy alta) ENTONCES (propina baja)​
    R21: SI (sabor es muy rico Y espera es muy corto) ENTONCES (propina alta)​
    R22: SI (sabor es muy rico Y espera es corto) ENTONCES (propina alta)​
    R23: SI (sabor es muy rico Y espera es medio) ENTONCES (propina alta)​
    R24: SI (sabor es muy rico Y espera es larga) ENTONCES (propina normal)​
    R25: SI (sabor es muy rico Y espera es muy larga) ENTONCES (propina normal)​
    */

   //declaracion de reglas
    std::vector<Regla*> reglas;

    std::vector<std::tuple<std::string, std::string>> premisas1;
    premisas1.push_back(std::make_tuple("Sabor", "Muy feo"));
    premisas1.push_back(std::make_tuple("Espera", "Muy largo"));
    Regla* ptrRegla1 = new Regla(premisas1, "baja", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas2;
    premisas2.push_back(std::make_tuple("Sabor", "Muy feo"));
    premisas2.push_back(std::make_tuple("Espera", "Corto"));
    Regla* ptrRegla2 = new Regla(premisas2, "normal", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas3;
    premisas3.push_back(std::make_tuple("Sabor", "Muy feo"));
    premisas3.push_back(std::make_tuple("Espera", "Muy corto"));
    Regla* ptrRegla3 = new Regla(premisas3, "normal", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas4;
    premisas4.push_back(std::make_tuple("Sabor", "Muy feo"));
    premisas4.push_back(std::make_tuple("Espera", "Medio"));
    Regla* ptrRegla4 = new Regla(premisas4, "baja", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas5;
    premisas5.push_back(std::make_tuple("Sabor", "Muy feo"));
    premisas5.push_back(std::make_tuple("Espera", "Largo"));
    Regla* ptrRegla5 = new Regla(premisas5, "baja", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas6;
    premisas6.push_back(std::make_tuple("Sabor", "Feo"));
    premisas6.push_back(std::make_tuple("Espera", "Muy corto"));
    Regla* ptrRegla6 = new Regla(premisas6, "normal", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas7;
    premisas7.push_back(std::make_tuple("Sabor", "Feo"));
    premisas7.push_back(std::make_tuple("Espera", "Corto"));
    Regla* ptrRegla7 = new Regla(premisas7, "normal", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas8;
    premisas8.push_back(std::make_tuple("Sabor", "Feo"));
    premisas8.push_back(std::make_tuple("Espera", "Medio"));
    Regla* ptrRegla8 = new Regla(premisas8, "baja", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas9;
    premisas9.push_back(std::make_tuple("Sabor", "Feo"));
    premisas9.push_back(std::make_tuple("Espera", "Largo"));
    Regla* ptrRegla9 = new Regla(premisas9, "baja", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas10;
    premisas10.push_back(std::make_tuple("Sabor", "Feo"));
    premisas10.push_back(std::make_tuple("Espera", "Muy largo"));
    Regla* ptrRegla10 = new Regla(premisas10, "baja", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas11;
    premisas11.push_back(std::make_tuple("Sabor", "Normal"));
    premisas11.push_back(std::make_tuple("Espera", "Muy corto"));
    Regla* ptrRegla11 = new Regla(premisas11, "alta", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas12;
    premisas12.push_back(std::make_tuple("Sabor", "Normal"));
    premisas12.push_back(std::make_tuple("Espera", "Corto"));
    Regla* ptrRegla12 = new Regla(premisas12, "normal", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas13;
    premisas13.push_back(std::make_tuple("Sabor", "Normal"));
    premisas13.push_back(std::make_tuple("Espera", "Medio"));
    Regla* ptrRegla13 = new Regla(premisas13, "normal", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas14;
    premisas14.push_back(std::make_tuple("Sabor", "Normal"));
    premisas14.push_back(std::make_tuple("Espera", "Alta"));
    Regla* ptrRegla14 = new Regla(premisas14, "normal", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas15;
    premisas15.push_back(std::make_tuple("Sabor", "Normal"));
    premisas15.push_back(std::make_tuple("Espera", "Muy alto"));
    Regla* ptrRegla15 = new Regla(premisas15, "baja", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas16;
    premisas16.push_back(std::make_tuple("Sabor", "Rico"));
    premisas16.push_back(std::make_tuple("Espera", "Muy corto"));
    Regla* ptrRegla16 = new Regla(premisas16, "alta", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas17;
    premisas17.push_back(std::make_tuple("Sabor", "Rico"));
    premisas17.push_back(std::make_tuple("Espera", "Corto"));
    Regla* ptrRegla17 = new Regla(premisas17, "alta", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas18;
    premisas18.push_back(std::make_tuple("Sabor", "Rico"));
    premisas18.push_back(std::make_tuple("Espera", "Medio"));
    Regla* ptrRegla18 = new Regla(premisas18, "alta", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas19;
    premisas19.push_back(std::make_tuple("Sabor", "Rico"));
    premisas19.push_back(std::make_tuple("Espera", "Alta"));
    Regla* ptrRegla19 = new Regla(premisas19, "normal", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas20;
    premisas20.push_back(std::make_tuple("Sabor", "Rico"));
    premisas20.push_back(std::make_tuple("Espera", "Muy alta"));
    Regla* ptrRegla20 = new Regla(premisas20, "baja", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas21;
    premisas21.push_back(std::make_tuple("Sabor", "Muy rico"));
    premisas21.push_back(std::make_tuple("Espera", "Muy corto"));
    Regla* ptrRegla21 = new Regla(premisas21, "alta", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas22;
    premisas22.push_back(std::make_tuple("Sabor", "Muy rico"));
    premisas22.push_back(std::make_tuple("Espera", "Corto"));
    Regla* ptrRegla22 = new Regla(premisas22, "alta", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas23;
    premisas23.push_back(std::make_tuple("Sabor", "Muy rico"));
    premisas23.push_back(std::make_tuple("Espera", "Medio"));
    Regla* ptrRegla23 = new Regla(premisas23, "alta", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas24;
    premisas24.push_back(std::make_tuple("Sabor", "Muy rico"));
    premisas24.push_back(std::make_tuple("Espera", "Larga"));
    Regla* ptrRegla24 = new Regla(premisas24, "normal", 0.0);

    std::vector<std::tuple<std::string, std::string>> premisas25;
    premisas25.push_back(std::make_tuple("Sabor", "Muy rico"));
    premisas25.push_back(std::make_tuple("Espera", "Muy larga"));
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

    


    

    return 0;
}
