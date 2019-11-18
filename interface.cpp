#include "interface.hpp"
using namespace std;

Interface::Interface()
{
	//carrega todos os cadastros
}

Interface::~Interface()
{
	//salva todas as modificacoes
}


void Interface::inicia_interface()
{
	string oi="456";
	int i=1;
	int a = oi[i] - '0';
	cout << oi[i] << endl;
	cout << a << endl;

	cout << "Interface iniciada com sucesso " << endl;
}