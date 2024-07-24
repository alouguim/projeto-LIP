#include <iostream>
#include <fstream>
#include "cadastro.cpp"
using namespace std;

class Agendamento : public CadastroPaciente{
private:
    double faturamento;
public:
    void novoAgendamento();
    void faturamentoMensal();
};

void Agendamento::novoAgendamento(){
    int escolha;

    cout << "Aperte 1 para agendar um horario" << endl;
    cout << "Aperte 5 para sair!" << endl;
    cin >> escolha;
    cin.ignore();

    if(escolha == 1){
        cout << "Digite o valor da consulta!" << endl;
        cin >> faturamento;

        file.open("db.txt", ios ::out | ios ::app);
        file << faturamento << endl;
        file.close();
    }
}

void Agendamento::faturamentoMensal(){
    string ID, idadeStr, nome;
    string fat;
    double result=0;

    file.open("db_pacientes.txt", ios ::in);

    while (true){
        getline(file, ID, '*');
        getline(file, idadeStr, '*');
        getline(file, nome, '*');
        getline(file, fat, '\n');

        faturamento = stod(fat);

        if (file.eof())
        {
            break;
        }
        
        result += faturamento;
    }

    cout << "---------------------------------------------------" << endl;
    cout << "Faturamento total da clinica! " << endl;
    cout << result << endl;
    cout << "---------------------------------------------------" << endl;

    file.close();
}
