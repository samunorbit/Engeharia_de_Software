#include "bits/stdc++.h"

using namespace std;

/*
Funcoes Bool retornam false quando os valores recebidos sao invalidos porem esses valores serao salvos
Variavel "completo" sera true quando o cadastro for completado de maneira adequada
*/

class Conta
{
private:
	string codigo_banco,numero_agencia,numero_conta;
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
	string get_dados(int tipo);
	vector<string> get_dados();
};

class Carona
{
private:
	vector<string> dados;

	bool verifica_data(string data);
	bool verifica_dados(string codigo, string origem, string destino, string data, string duracao, string vagas, string preco);

public:
	Carona();
	Carona(string codigo, string origem, string destino, string data, string duracao, string vagas, string preco);
	~Carona();

	bool set_dados(string codigo, string origem, string destino, string data, string duracao, string vagas, string preco);

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
	bool verifica_senha(string senha);
	bool verifica_cpf(string cpf);


public:
	Usuario();
	~Usuario();

	bool set_dados(string nome, string telefone, string email, string senha, string cpf, Conta conta1, Conta conta2);

	bool nova_reserva(Reserva nova);
	bool nova_reserva(int codigo,char assento,int bagagem);
	bool nova_reserva(string codigo, string assento, string bagagem);

	bool nova_carona(Carona nova);
	bool nova_carona(string codigo, string origem, string destino, string data, string duracao, string vagas, string preco);

	string get_dados(int tipo);
	vector<string> get_dados();
	
};