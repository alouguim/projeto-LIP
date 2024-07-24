#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <random>
#include <sstream>
#include <iomanip>
using namespace std;

class CadastroPaciente{
protected:
// Instancia o fstream para que seja possivel usar arquivos como banco de dados
    fstream file;

// Variaveis voltadas ao registro do paciente
private: 
    string Name;
    string PatientId;
    int Age;

// Variaveis dedicadas ao gerenciamento do agendamento
    string Day;
    double Price;

// Private function do generate a Randon ID based on (timestamp + randon number)
    string randonIdGenerator()
    {
        auto now = chrono::system_clock::now();
        auto now_ms = chrono::time_point_cast<chrono::milliseconds>(now);
        auto epoch = now_ms.time_since_epoch();
        long long timestamp = chrono::duration_cast<chrono::milliseconds>(epoch).count();

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1000, 9999);

        stringstream ss;
        ss << timestamp << dis(gen);

        return ss.str();
    }
public:
   //Declarações de funções da minha classe
   void cadastrarPacientes();
   void registroDePacientes();
   void historicoMedico();
};

void CadastroPaciente ::cadastrarPacientes() {
    string nome, ID;
    int idade, escolha;

    cout << "Digite 1 para registrar um paciente que ainda nao tenhha sido registrado!" << endl;
    cout << "Aperte 2 para registrar um agendamento com ID ja cadastrado!" << endl;
    cout << "Digite 5 pra sair!" << endl;
    cin >> escolha;
    cin.ignore();

    switch (escolha){
    case 1:
        cout << "Digite nome do paciente" << endl;
        getline(cin, nome);
        cout << "Digite a idade do paciente!" << endl;
        cin >> idade;
        cin.ignore();
        cout << "Gerando um ID aleatorio para o paciente!" << endl;
        ID = randonIdGenerator();

        file.open("db_pacientes.txt", ios ::out | ios ::app);
        file << ID << "*" << nome << "*" << idade << endl;
        file.close();

        cout << "Paciente foi adicionado com sucesso!" << endl;
        break;
    case 2:
        cout << "Digite nome do paciente" << endl;
        getline(cin, nome);
        cout << "Digite a idade do paciente!" << endl;
        cin >> idade;
        cin.ignore();
        cout << "Digite o ID do paciente desejado!" << endl;
        cin >> ID;

        file.open("db_pacientes.txt", ios ::out | ios ::app);
        file << ID << "*" << idade << "*" << nome << endl;
        file.close();

        cout << "Paciente foi adicionado com sucesso!" << endl;
        break;
    case 3:
        cout << "Cancelando operação!" << endl;
        break;
    }
}

void CadastroPaciente ::registroDePacientes(){
    string nome, ID, idadeStr;

    file.open("db_pacientes.txt", ios ::in);

    while (true)
    {
        getline(file, ID, '*');
        getline(file, idadeStr, '*');
        getline(file, nome, '\n');

        if (file.eof())
        {
            break;
        }

        int idade = stoi(idadeStr);

        cout << "-----------------------------------------------------------" << endl;
        cout << "ID: " << ID << endl;
        cout << "Nome: " << nome << endl;
        cout << "Idade: " << idade << endl;
    }

    cout << "-----------------------------------------------------------" << endl;

    file.close();
}

void CadastroPaciente::historicoMedico(){
    string nome, ID, idadeStr;
    int idade;
    string searchID;

    cout << "Digite o ID paciente desejado!" << endl;
    cin >> searchID;

    file.open("db_pacientes.txt", ios ::in);

    while (true)
    {
        getline(file, ID, '*');
        getline(file, idadeStr, '*');
        getline(file, nome, '\n');

        if (file.eof())
        {
            break;
        }

        idade = stoi(idadeStr);

        if(ID == searchID) {
            cout << "-----------------------------------------------------------" << endl;
            cout << "ID: " << ID << endl;
            cout << "Nome: " << nome << endl;
            cout << "Idade: " << idade << endl;
        }
        
    }

    cout << "-----------------------------------------------------------" << endl;

    file.close();
}

