#include "entidades.hpp"
using namespace std;

Conta::Conta(){}
Conta::~Conta(){}

bool Conta::verifica_codigo_banco(string codigo_banco)
{
	//cout << codigo_banco.size() << endl;
	if(codigo_banco.size() == 3)
	{
		for (int i = 0; i < 3; ++i)
		{
			if(codigo_banco[i]<'0' || codigo_banco[i]>'9')
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

bool Conta::verifica_numero_agencia(string numero_agencia)
{
	int soma=0,aux;
	
	if(numero_agencia.size()!=6)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < 4 ; ++i)
		{
			aux = (int)numero_agencia[i] - '0';
			if((numero_agencia[i] -'0') * (1 + i%2) < 10)
			{
				soma += aux * (1 + i%2);
			}
			else
			{
				soma += (aux * (1 + i%2)) - 9;	
			}
		}

		if((soma+numero_agencia[5] -'0') %10 == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

bool Conta::verifica_numero_conta(string numero_conta)
{
	int soma=0,aux;
	
	if(numero_conta.size()!=8)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < 6 ; ++i)
		{
			aux = (int)numero_conta[i] - '0';
			if((numero_conta[i] -'0') * (1 + i%2) < 10)
			{
				soma += aux * (1 + i%2);
			}
			else
			{
				soma += (aux * (1 + i%2)) - 9;	
			}
		}

		if((soma+numero_conta[7] -'0') %10 == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

bool Conta::cadastro_completo()
{
	if(completo)
	{
		if(dados.size()<3)
		{
			dados.clear();
			dados.push_back(codigo_banco);
			dados.push_back(numero_agencia);
			dados.push_back(numero_conta);
		}
		return true;
	}
	else
	{
		if(verifica_codigo_banco(codigo_banco) && verifica_numero_agencia(numero_agencia) && verifica_numero_conta(numero_conta))
		{
			completo = true;
			return cadastro_completo();
		}
		else
		{
			completo = false;
			return false;
		}
	}
	return false;
}

bool Conta::set_codigo_banco(string codigo_banco)
{
	this-> codigo_banco = codigo_banco;
	return verifica_codigo_banco(codigo_banco);
}
bool Conta::set_numero_agencia(string numero_agencia)
{
	this->numero_agencia = numero_agencia;
	return verifica_numero_agencia(numero_agencia);
}
bool Conta::set_numero_conta(string numero_conta)
{
	this->numero_conta = numero_conta;
	return verifica_numero_conta(numero_conta);
}

string Conta::get_dados(int tipo){return dados[tipo];}
vector<string> Conta::get_dados(){return dados;}


Reserva::Reserva(){}
Reserva::Reserva(int codigo, char assento, int bagagem)
{
	set_dados(codigo,assento,bagagem);
}

Reserva::Reserva(string codigo, string assento, string bagagem)
{
	set_dados(codigo,assento,bagagem);
}

Reserva::~Reserva(){}

bool Reserva::set_dados(int codigo,char assento,int bagagem)
{
	dados.clear();
	this->codigo = codigo;
	this->assento = assento;
	this->bagagem = bagagem;
	dados.push_back(to_string(codigo));
	string aux(1,assento);
	dados.push_back(aux);
	dados.push_back(to_string(bagagem));
}

bool Reserva::set_dados(string codigo, string assento, string bagagem)
{
	dados.clear();
	dados.push_back(codigo);
	dados.push_back(assento);
	dados.push_back(bagagem);
	this->codigo = stoi(codigo);
	this->assento = assento[0];
	this->bagagem = stoi(bagagem);
}
string Reserva::get_dados(int tipo){return dados[tipo];}
vector<string> Reserva::get_dados(){return dados;}

Carona::Carona(){}
Carona::Carona(string codigo, string origem, string destino, string data, string duracao, string vagas, string preco)
{
	set_dados(codigo, origem, destino, data, duracao, vagas, preco);
}
Carona::~Carona(){}

bool Carona::verifica_data(string data)
{
	return true;
}

bool Carona::verifica_dados(string codigo, string origem, string destino, string data, string duracao, string vagas, string preco)
{
	bool ok=true;

	if(codigo.size() != 5){ok=false;}
	if(!verifica_data(data)){ok=false;}
	if(stoi(duracao)<1 || stoi(duracao) > 48){ok = false;}
	if(stoi(vagas) <1 || stoi(vagas)>4){ok=false;}

	return ok;
}

bool Carona::set_dados(string codigo, string origem, string destino, string data, string duracao, string vagas, string preco)
{
	dados.clear();
	dados.push_back(codigo);
	dados.push_back(origem);
	dados.push_back(destino);
	dados.push_back(data);
	dados.push_back(duracao);
	dados.push_back(vagas);
	dados.push_back(preco);

	return verifica_dados(codigo, origem, destino, data, duracao, vagas, preco);
}

string Carona::get_dados(int tipo){return dados[tipo];}
vector<string> Carona::get_dados(){return dados;}

Usuario::Usuario(){}
Usuario::~Usuario(){}

bool Usuario::verifica_nome(string nome)
{
	if(nome[0] < 'A' || nome[0] > 'Z')
	{
		return false;
	}

	for (int i = 1; i < nome.size(); ++i)
	{
		if(nome[i] < 'a' || nome[i] > 'z')
		{
			return false;
		}
	}
	return true;
}

bool Usuario::verifica_telefone(string telefone)
{
	if(telefone.size()!=15)
	{
		return false;
	}
	if(telefone[0] =='0' & telefone[1] =='0')
	{
		return false;
	}
	if(telefone[3] =='0' & telefone[4] =='0')
	{
		return false;
	}
	bool aux = false;
	for (int i = 6; i < telefone.size(); ++i)
	{
		if(telefone[i]!='0')
		{
			aux = true;
			return true;
		}
	}
	return false;
}

bool Usuario::verifica_email(string email)
{
	int i=0;
	if(email[i] < 'a' || email[i] > 'z')
	{
		return false;
	}

	for (i = 1; i < email.size(); ++i)
	{
		if(email[i]=='@')
		{
			break;
		}
		if((email[i] < 'a' || email[i] > 'z') && email[i] !='.')
		{
			return false;
		}

		if(email[i-1]=='.' && email[i] =='.')
		{
			return false;
		}
	}

	for (i = i+1; i < email.size(); ++i)
	{
		if((email[i] < 'a' || email[i] > 'z') && email[i] !='.')
		{
			return false;
		}

		if(email[i-1]=='.' && email[i] =='.')
		{
			return false;
		}
		
	}
	return true;
}
bool Usuario::verifica_senha(string senha)
{
	bool letra = false, digito = false;
	if(senha.size() !=5)
	{
		return false;
	}

	return true;

}
bool Usuario::verifica_cpf(string cpf)
{
	int soma=0, aux=10;
	for (int i = 0; i < 11; ++i)
	{
		if(cpf[i]=='.')
		{
		}
		else
		{
			soma += (cpf[i]-'0') * aux;
			aux--;
		}	
	}

	if(soma%11 <= 1 && (cpf[12]-'0') != 0)
	{
		return false;
	}
	if(soma%11 >1 && (cpf[12]-'0') != 11 - soma%11)
	{
		return false;
	}

	soma=0;
	aux=11;
	for (int i = 0; i < 13; ++i)
	{
		if(cpf[i]=='.' || cpf[i]=='-')
		{
		}
		else
		{
			soma += (cpf[i]-'0') * aux;
			aux--;
		}	
	}

	if(soma%11 <= 1 && (cpf[13]-'0') != 0)
	{
		return false;
	}
	if(soma%11 >1 && (cpf[13]-'0') != 11 - soma%11)
	{
		return false;
	}

	return true;
}

bool Usuario::set_dados(string nome, string telefone, string email, string senha, string cpf, Conta conta1, Conta conta2)
{
	bool aux = (verifica_nome(nome) && verifica_telefone(telefone) && verifica_email(email) && verifica_senha(senha) && verifica_cpf(cpf));
	dados.clear();
	dados.push_back(nome);
	dados.push_back(telefone);
	dados.push_back(email);
	dados.push_back(senha);
	dados.push_back(cpf);
	this->conta1 = conta1;
	this->conta2 = conta2;
	return aux;
}

string Usuario::get_dados(int tipo){return dados[tipo];}
vector<string> Usuario::get_dados(){return dados;}