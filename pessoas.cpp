#include <iostream>
#include <string>
using namespace std;

class Pessoas{
private:
    string Name;
    int PatientId;
    int Age;

public:
    //Getters
    string getName(){return Name;}
    int getPatientId(){return PatientId;}
    int getAge(){return Age;}

    //Constructor Pessoas
    Pessoas(string name, int id, int age) : Name(name), PatientId(id), Age(age) {
        Name = name;
        PatientId = id;
        Age = age;
    }
};