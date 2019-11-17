#include "bits/stdc++.h"

using namespace std;


/*
Funcoes Bool retornam false quando os valores recebidos sao invalidos porem esses valores serao salvos
Variavel "completo" sera true quando o cadastro for completado de maneira adequada
*/


class Conta
{
private:
	vector<string> dados;
	bool completo;

	bool verifica_codigo_banco(string codigo_banco);
	bool verifica_numero_agencia(string numero_agencia);
	bool verifica_numero_conta(string numero_conta);

public:
	Conta();
	~Conta();
	
	bool cadastro_completo();

	bool set_codigo_banco(string codigo_banco);
	bool set_numero_agencia(string numero_agencia);
	bool set_numero_conta(string numero_conta);

	string get_dados(int tipo);
	vector<string> get_dados();

};

class Reserva
{
private:
	vector<string> dados;

public:
	int codigo,bagagem;
	char assento;

	Reserva();
	Reserva(int codigo,char assento,int bagagem);
	Reserva(string codigo, string assento, string bagagem);
	~Reserva();

	bool set_dados(int codigo, char assento, int bagagem);
	bool set_dados(string codigo, string assento, string bagagem);
	vector<string> get_dados();
};

class Carona
{
private:
	vector<string> dados;
	bool completo;

public:
	Carona();
	~Carona();

	bool set_codigo(string codigo);
	bool set_origem(string origem);
	bool set_destino(string destino);
	bool set_data(string data);
	bool set_duracao(string duracao);
	bool set_vagas(string vagas);
	bool set_preco(string preco);

	string get_dados(int tipo);
	vector<string> get_dados();
	
};


class Usuario
{

private:
	vector<string> dados;
	vector<Reserva> reservas;
	vector<Carona> caronas;
	Conta conta1,conta2;
	bool completo;

	bool verifica_nome(string nome);
	bool verifica_telefone(string telefone);
	bool verifica_email(string email);
	bool verifica_(string senha);
	bool verifica_cpf(string cpf);


public:
	Usuario();
	~Usuario();

	bool cadastro_completo();

	bool set_nome(string nome);
	bool set_telefone(string telefone);
	bool set_email(string email);
	bool set_senha(string senha);
	bool set_cpf(string cpf);

	bool nova_reserva(Reserva nova);
	bool nova_reserva(int codigo,char assento,int bagagem);
	bool nova_reserva(string codigo, string assento, string bagagem);

	string get_dados(int tipo);
	vector<string> get_dados();
	
};