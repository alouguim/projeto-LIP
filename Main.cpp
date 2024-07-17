#include <iostream>
#include <vector>
#include "appointment.cpp"

using namespace std;

int main(){
    vector<Appointment> agenda;

    string nome, dia;
    int id, idade, escolha, checkId;
    double valor, fatTotal;

    do{

        cout << "Press 1 para gerenciar um agendamento!" << endl;
        cout << "Press 2 consultar registros de todos os pacientes!" << endl;
        cout << "Digite 3 para consultar o hirtorico medico do paciente!" << endl;
        cout << "Digite 4 para checar o faturamento da clinica!" << endl;
        cout << "Press 5 to exit!" << endl;

        cin >> escolha;

        switch (escolha)
        {
        case 1:
            cout << "Registrando paciente! " << endl;
            cout << "Digite o seu nome: " << endl;
            cin >> nome;
            cout << "Digite o ID do paciente!" << endl;
            cin >> id;
            cout << "Digite a sua idade: " << endl;
            cin >> idade;
            cout << "Digite o dia da consulta!" << endl;
            cin >> dia;
            cout << "Digite o valor da consulta!" << endl;
            cin >> valor;

            agenda.push_back(Appointment(nome, id, idade, dia, valor));
            id++;
            break;
        case 2:
            cout << "Vendo registros de pacientes!" << endl;
            for (int i = 0; i < int(agenda.size()); i++){
                agenda[i].registroDePacientes();
            }
            break;
        case 3:
            cout << "Digite o id do paciente para ver seu registro medico! " << endl;
            cin >> checkId;
            for (int i = 0; i < int(agenda.size()); i++){
                agenda[i].historicoMedico(checkId);
            }\
            cout << "Historico medico do paciente: " << endl;
            break;
        case 4:
            for (int i = 0; i < int(agenda.size()); i++){
                fatTotal += (agenda[i].faturamento());
            }
            cout << "O faturamento da clinica foi de: " << fatTotal << " R$" << endl;
            fatTotal = 0;
            break;
        case 5:
            // Terminar a execução!!
            break;
        }
    } while (escolha!=5);

    return 0;
}
