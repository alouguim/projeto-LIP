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
        //Menu do prompt
        cout << "Press 1 para gerenciar um agendamento!" << endl;
        cout << "Press 2 consultar registros de todos os pacientes!" << endl;
        cout << "Digite 3 para consultar o hirtorico medico do paciente!" << endl;
        cout << "Digite 4 para checar o faturamento da clinica!" << endl;
        cout << "Press 5 to exit!" << endl;

        //Entrada para escolha da operação
        cin >> escolha;

        switch (escolha)
        {
        case 1:
            //Gerenciamento para agendar um consulta
            cout << "Gerenciando agendamento! " << endl;
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
            //Gustavo alessandro
            agenda.push_back(Appointment(nome, id, idade, dia, valor));
            id++;
            break;
        case 2:
            //Todos os pacientes já cadastrados
            cout << "Vendo registros de pacientes!" << endl;
            for (int i = 0; i < int(agenda.size()); i++){
                agenda[i].registroDePacientes();
            }
            break;
        case 3:
            //Todos os registros de consultas de um paciente (usando ID)
            cout << "Digite o id do paciente para ver seu registro medico! " << endl;
            cin >> checkId;
            for (int i = 0; i < int(agenda.size()); i++){
                agenda[i].historicoMedico(checkId);
            }\
            cout << "Historico medico do paciente: " << endl;
            break;
        case 4:
            //Faturamento total da clinica
            for (int i = 0; i < int(agenda.size()); i++){
                fatTotal += (agenda[i].faturamento());
            }
            cout << "O faturamento da clinica foi de: " << fatTotal << " R$" << endl;
            fatTotal = 0;
            break;
        case 5:
            // Terminar a execução!!
            cout << "Obrigado por usar nosso sistema de gerenciamento de agendamentos!!";
            break;
        }
    } while (escolha!=5);

    return 0;
}
