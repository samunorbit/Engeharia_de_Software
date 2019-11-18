#include "interface.hpp"
using namespace std;

Interface::Interface()
{
    fstream file;
    file.open("save.txt",ios::in);
    string temp;
    int n,m;
    if(file.is_open())
    {
        while(!file.eof())
        {
            file >> temp;
            file >> temp;
            n=stoi(temp);
            for (int i = 0; i < n; ++i)
            {
                vector<string> aux;
                string nome, telefone, email, senha, cpf, codigo_banco1, numero_agencia1, numero_conta1, codigo_banco2, numero_agencia2, numero_conta2;
                Usuario user;
                file >> nome;
                file >> telefone;
                file >> email;
                file >> senha;
                file >> cpf;
                file >> codigo_banco1;
                file >> numero_agencia1;
                file >> numero_conta1;
                file >> codigo_banco2;
                file >> numero_agencia2;
                file >> numero_conta2;
                user.set_dados(nome, telefone, email, senha, cpf, codigo_banco1, numero_agencia1, numero_conta1, codigo_banco2, numero_agencia2, numero_conta2);
                usuarios.push_back(user);
                file >> temp;
                m = stoi(temp);
                for (int j = 0; j < m; ++j)
                {
                    string codigo;
                    file >> codigo;
                    usuarios[i].nova_reserva(codigo);
                }

                file >> temp;
                m = stoi(temp);
                for (int j = 0; j < m; ++j)
                {
                    string codigo;
                    file >> codigo;
                    usuarios[i].nova_carona(codigo);
                }

            }

            file >> temp;
            m = stoi(temp);
            for (int j = 0; j < m; ++j)
            {
                string codigo,assento,bagagem;
                file >> codigo >> assento >> bagagem;

                Reserva r(codigo,assento,bagagem);
                reservas.push_back(r);

            }

            file >> temp;
            m = stoi(temp);
            for (int j = 0; j < m; ++j)
            {
                string codigo, origem, destino, data, duracao, vagas, preco;
                file >>codigo>>origem>>destino>>data>>duracao>>vagas>>preco;
                Carona c(codigo, origem, destino, data, duracao, vagas, preco);
                caronas.push_back(c);
            }
            file >> temp;


        }
    }
    file.close();
}

Interface::~Interface()
{
    fstream file;
    file.open("save.txt",ios::out | ios::trunc);
    vector<string> temp;
    if(file.is_open())
    {
        file <<"INICIO"<<endl;
        file << usuarios.size()<<endl;
        for (int i = 0; i < usuarios.size(); ++i)
        {
            temp = usuarios[i].get_dados();
            for (int j = 0; j < temp.size(); ++j)
            {
                file << temp[j]<<endl;

            }
            for (int k = 0; k < 2; ++k)
            {
                for (int j = 0; j < 3; ++j)
                {
                    file << usuarios[i].get_dados_conta(j,k)<<endl;
                }
            }

            temp = usuarios[i].get_reservas();
            file << temp.size()<<endl;
            for (int j = 0; j < temp.size(); ++j)
            {
                file << temp[i]<<endl;
            }
            temp = usuarios[i].get_caronas();
            file << temp.size()<<endl;
            for (int j = 0; j < temp.size(); ++j)
            {
                file << temp[i]<<endl;
            }
        }

        file<<reservas.size()<<endl;
        for (int i = 0; i < reservas.size(); ++i)
        {
            temp = reservas[i].get_dados();
            for (int j = 0; j < temp.size(); ++j)
            {
                file<<temp[j]<<endl;
            }
        }

        file<<caronas.size()<<endl;
        for (int i = 0; i < caronas.size(); ++i)
        {
            temp = caronas[i].get_dados();
            for (int j = 0; j < temp.size(); ++j)
            {
                file<<temp[j]<<endl;
            }
        }
    }
    file<<"FIM";
    file.close();
}


void Interface::inicia_interface()
{
    int opt=-1;

    while(opt!=0)
    {
        cout << "Digite 1 para ver caronas disponiveis" <<endl;
        cout << "Digite 2 para cadastrar um novo usuario"<<endl;
        cout << "Digite 3 para loggar como um usuario"<<endl;
        cout << "Digite 0 para sair"<<endl;
        cin >> opt;

        if(opt==1)
        {
            if(caronas.size()==0)
            {
                cout<<"Nenhuma carona disponivel"<<endl;
            }
            else
            {
                for (int i = 0; i < caronas.size(); ++i)
                {
                    vector<string> temp = caronas[i].get_dados();
                    for (int j = 0; j < temp.size(); ++j)
                    {
                        cout << temp[j]<<'\t';
                    }
                    cout << endl;
                }
            }
        }

        if(opt==2)
        {
            Usuario temp;
            string nome, telefone, email, senha, cpf, codigo_banco1, numero_agencia1, numero_conta1, codigo_banco2, numero_agencia2, numero_conta2;
            cout <<"Digite seu nome:" <<endl;
            cin >>nome;
            cout <<"Digite seu telefone" <<endl;
            cin >>telefone;
            cout <<"Digite seu email" <<endl;
            cin >>email;
            cout <<"Digite sua senha" <<endl;
            cin >>senha;
            cout <<"Digite seu CPF" <<endl;
            cin >>cpf;
            cout << "Informa os dados da sua conta 1" <<endl;
            cout <<"Digite codigo do banco" <<endl;
            cin >>codigo_banco1;
            cout <<"Digite numero da agencia" <<endl;
            cin >>numero_agencia1;
            cout <<"Digite numero da sua conta" <<endl;
            cin >>numero_conta1;
            cout << "Informa os dados da sua conta 2" <<endl;
            cout <<"Digite codigo do banco" <<endl;
            cin >>codigo_banco2;
            cout <<"Digite numero da agencia" <<endl;
            cin >>numero_agencia2;
            cout <<"Digite numero da sua conta" <<endl;
            cin >>numero_conta2;
            if(temp.set_dados(nome,telefone,email,senha,cpf,codigo_banco1, numero_agencia1, numero_conta1, codigo_banco2, numero_agencia2, numero_conta2))
            {
                cout << "Cadastro feito com sucesso!!!"<<endl;
                usuarios.push_back(temp);
            }
            else
            {
                cout << "Impossivel completar a operação"<<endl;
            }
        }

        if(opt==3)
        {
            string nome,senha;
            int log;
            cout << "Digite o nome do usuario"<<endl;
            cin >> nome;
            cout << "Digite sua senha"<<endl;
            cin >> senha;
            log = loggin(nome,senha);

            if(log!=-1)
            {
                cout << "Voce esta logado como "<<nome<<endl;
                int opt2=-1;
                while(opt2 !=0)
                {
                    cout<<"Digite 1 para fazer uma nova reserva"<<endl;
                    cout<<"Digite 2 para criar uma nova carona"<<endl;
                    cout<<"Digite 0 para sair"<<endl;
                    cin >> opt2;
                    if(opt2 ==1)
                    {
                        string codigo,assento,bagagem;
                        int r;
                        cout <<"Digite o codigo da reserva"<<endl;
                        cin>>codigo;
                        r = reserva(codigo);
                        if(r != -1)
                        {
                            cout << "Digite o assento"<<endl;
                            cin >> assento;
                            cout << "Digite a quantidade de bagagem"<<endl;
                            cin >> bagagem;
                            Reserva temp(codigo,assento,bagagem);
                            reservas.push_back(temp);
                            usuarios[log].nova_reserva(codigo);
                        }
                        else
                        {
                            cout<<"Nenhuma carona com esse codigo"<<endl;
                        }
                    }

                    if(opt2==2)
                    {
                        string codigo, origem, destino, data, duracao, vagas, preco;
                        cout<< "Digite o codigo da carona"<<endl;
                        cin >>codigo;
                        cout<< "Digite a origem"<<endl;
                        cin >> origem;
                        cout<< "Digite o destino"<<endl;
                        cin>> destino;
                        cout<< "Digite a data"<< endl;
                        cin >> data;
                        cout<< "Digite a duracao"<<endl;
                        cin >> duracao;
                        cout<< "Digite o numero de vagas"<<endl;
                        cin>> vagas;
                        cout<< "Digite o preco"<< endl;
                        cin >> preco;
                        Carona temp(codigo, origem, destino, data, duracao, vagas, preco);
                        caronas.push_back(temp);
                        usuarios[log].nova_carona(codigo);


                    }
                }
            }
            else
            {
                cout <<"Usuario ou senha invalido"<<endl;
            }

        }

    }


}
