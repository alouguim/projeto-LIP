#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "cadastro.cpp"

using namespace std;

class Agendamento : public CadastroPaciente {
private:
    double faturamento;
    vector<string> datas;
    vector<vector<bool>> horariosDisponiveis;
    void carregarAgendamentos();

public:
    Agendamento();
    void novoAgendamento();
    void faturamentoMensal();
    void agendarHorario();
    void mostrarHorarios(string data);
};

Agendamento::Agendamento() {
    carregarAgendamentos();
}

void Agendamento::carregarAgendamentos() {
    ifstream file("db_agendamentos.txt", ios::in);
    string data;
    int horario;

    //Leitura do arquivo
    while (file >> data >> horario) {
        bool dataExists = false;
        //Verifica se a data já existe no arquivo
        for (size_t i = 0; i < datas.size(); ++i) {
            if (datas[i] == data) {
                //Se a data e horário existem, remove ele dos horários disponíveis
                horariosDisponiveis[i][horario - 1] = false;
                dataExists = true;
                break;
            }
        }
        
        //Se não existe, adiciona o horário como disponível
        if (!dataExists) {
            datas.push_back(data);
            horariosDisponiveis.push_back(vector<bool>(5, true));
            horariosDisponiveis.back()[horario - 1] = false;
        }
    }

    file.close();
}

void Agendamento::mostrarHorarios(string data) {
    cout << "Horarios disponíveis para a data " << data << ":" << endl;
    vector<bool> horarios(5, true);

    //percorre o vetor para encontrar a data correspondente
    for (size_t i = 0; i < datas.size(); ++i) {
        if (datas[i] == data) {
            horarios = horariosDisponiveis[i];
            break;
        }
    }

    //Exibe os horários disponíveis  
    if (horarios[0]) cout << "1 - 09:00h" << endl;
    if (horarios[1]) cout << "2 - 11:00h" << endl;
    if (horarios[2]) cout << "3 - 13:00h" << endl;
    if (horarios[3]) cout << "4 - 15:00h" << endl;
    if (horarios[4]) cout << "5 - 17:00h" << endl;
}

void Agendamento::novoAgendamento() {
    int escolha;

    cout << "Aperte 1 para agendar um horario" << endl;
    cout << "Aperte 5 para sair!" << endl;
    cin >> escolha;
    cin.ignore();

    if (escolha == 1) {
        agendarHorario();
        cout << "Digite o valor da consulta!" << endl;
        cin >> faturamento;

        ofstream file("db.txt", ios::out | ios::app);
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

void Agendamento::agendarHorario() {
    string data;
    int horario;

    cout << "Digite a data para o agendamento (dd/mm): ";
    cin >> data;
    cin.ignore();

    mostrarHorarios(data);
    cout << "Selecione o horario (1-5): ";
    cin >> horario;
    cin.ignore();

    // Ajusta para o índice do vetor
    horario -= 1;

    bool dataExiste = false;
    for (size_t i = 0; i < datas.size(); ++i) {
        if (datas[i] == data) {
            //Verifica se o horário selecionado é válido
            if (horariosDisponiveis[i][horario]) {
                horariosDisponiveis[i][horario] = false;
                cout << "Horario agendado com sucesso!" << endl;

                //Salva o agendamento no arquivo 
                ofstream file("db_agendamentos.txt", ios::out | ios::app);
                file << data << " " << horario + 1 << endl;
                file.close();
            } else {
                cout << "Horario indisponível. Por favor, escolha outro horario." << endl;
            }
            dataExiste = true;
            break;
        }
    }

    if (!dataExiste) {
        //Se a data não existir, adiciona ela ao arquivo.
        datas.push_back(data);
        horariosDisponiveis.push_back(vector<bool>(5, true));
        horariosDisponiveis.back()[horario] = false;
        cout << "Horario agendado com sucesso!" << endl;

        ofstream file("db_agendamentos.txt", ios::out | ios::app);
        file << data << " " << horario + 1 << endl;
        file.close();
    }
}