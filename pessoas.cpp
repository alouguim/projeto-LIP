// #include <iostream>
// #include <string>
// #include <fstream>
// using namespace std;

// class Pessoas{
// private:
//     fstream file;

//     string Name;
//     int PatientId;
//     int Age;

// public:
//     //Getters
//     string getName(){return Name;}
//     int getPatientId(){return PatientId;}
//     int getAge(){return Age;}

//     //Constructor Pessoas
//     Pessoas(string name, int id, int age) : Name(name), PatientId(id), Age(age) {
//         Name = name;
//         PatientId = id;
//         Age = age;
//     }

//     void cadastroPaciente();
// };

// void Pessoas :: cadastroPaciente(){
//     string nome;
//     int ID, idade, escolha;

//     switch (escolha){
//     case 1:
//         cout << "Digite o nome do paciente!" << endl;
//         getline(cin, nome);
//         cout << "Digite o ID do paciente!" << endl;
//         cin >> idade;
//         cin.ignore();
//         cout << "Gerando o id unico do seu pet!" << endl;
//         // ID = randonIdGenerator();

//         file.open("db.txt", ios ::out | ios ::app);
//         file << ID << "*" << nome << "*" << idade << endl;
//         file.close();

//         cout << "Seu pet foi adicionado ao banco de dados!" << endl;
//         break;
//     case 2:
//         cout << "Digite o nome do paciente!" << endl;
//         getline(cin, nome);
//         cout << "Digite o ID do paciente!" << endl;
//         cin >> idade;
//         cin.ignore();
//         cout << "Digite o ID do paciente!" << endl;
//         cin >> ID;

//         file.open("db.txt", ios ::out | ios ::app);
//         file << ID << "*" << nome << "*" << idade << endl;
//         file.close();

//         cout << "Paciente foi adicionado no banco de dados!" << endl;
//         break;
//     case 3:
//         cout << "Cancelando operação!" << endl;
//         break;
//     }
// }