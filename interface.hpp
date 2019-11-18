#include <bits/stdc++.h>
#include "entidades.hpp"

class Interface
{
private:
	vector<Usuario> usuarios;
	vector<Carona> caronas;
	vector<Reserva> reservas;

	int loggin(string nome,string senha)
	{
		for (int i = 0; i < usuarios.size(); ++i)
		{
			if(usuarios[i].get_dados(0) == nome && usuarios[i].get_dados(3)==senha)
				{
					return i;
				}
		}
		return -1;
	}

	int reserva(string codigo)
	{
		for (int i = 0; i < caronas.size(); ++i)
		{
			if(caronas[i].get_dados(0) == codigo)
			{
				return i;
			}
		}
		return -1;
	}

public:
	Interface();

	void inicia_interface();

	~Interface();
	
};

/*
Sistema de arquivos e composto por uma informação por linha.
A primeira linha contem "INICIO" que marca o inicio do arquivo.
A segunda linha contem o numero de usuarios cadastrados.
As linhas seguintes tem os dados do usuario na seguinte ordem: Nome, Telefone, Email e Senha;
Em seguida os dados das 2 contas do usuario na seguinte ordem: Codigo de Banco, Numero de Agencia e Numero de conta.
Apos todas as informações dos usuarios a seguinte linha contem o numero de reservas feitas seguido pelas informações de cada reserva na segunte ordem:
Codigo da reserva, Assento e Bagagem.
A linha seguinte contem o numero de caronas registradas e por fim sao dados os dados das caronas registradas na seguinte ordem:
Codigo de carona, Origem, Destino, Data, Duração, Vagas, Preço.
A ultima linha contem "FIM".
*/