#include <iostream>
#include <string>
#include "pessoas.cpp"
using namespace std;

class Appointment : Pessoas{
private:
    string Day;
    double Price;
public:
    //Getters
    string getDay(){return Day;}
    double getPrice(){return Price;}

    //Constructor Appointment
    Appointment(string name, int id, int age, string day, double price)
        :Pessoas(name, id, age){
            Day = day;
            Price = price;
    }

    void registroDePacientes(){
        cout << "--------------------------" << endl;
        cout << "Id do paciente: " << getPatientId() << endl;
        cout << "Nome do paciente: " << getName() << endl;
        cout << "Idade do paciente: " << getAge() << endl;
        cout << "--------------------------" << endl;
    }

    double faturamento(){
        return getPrice();
    }

    void historicoMedico(int id) {
        if(id == getPatientId()){
            cout << "--------------------------" << endl;
            cout << "Dia: " << getDay() << endl;
            cout << "Preco: " << getPrice() << endl;
            cout << "--------------------------" << endl;
        }
    }
};