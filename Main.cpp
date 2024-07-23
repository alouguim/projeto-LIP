#include <iostream>
#include <vector>
#include "appointment.cpp"

using namespace std;

int main(){
    int escolha;
    Appointment newAppointment = Appointment();

    do{
        //Menu do prompt
        cout << "Aperte 1 para gerenciar um agendamento sem ID cadastrado!" << endl;
        cout << "Aperte 2 para ver o registro de todos os pacientes da clinica!" << endl;
        cout << "Aperte 3 para ver os registros de apenas um paciente!" << endl;
        cout << "Aperte 5 to exit!" << endl;
        //Entrada para escolha da operação
        cin >> escolha;

        switch (escolha)
        {
        case 1:
            newAppointment.cadastrarPacientes();
            break;
        case 2:
            newAppointment.registroDePacientes();
            break;
        case 3:
            newAppointment.historicoMedico();
            break;
        case 5:
            // Terminar a execução!!
            cout << "Obrigado por usar nosso sistema de gerenciamento de agendamentos!!";
            break;
        }
    } while (escolha!=5);

    return 0;
}
