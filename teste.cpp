#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include "entidades.hpp"


TEST_CASE("testa verificacao da conta","[entidades]")
{
	Conta conta_teste;

	REQUIRE(conta_teste.set_codigo_banco("231") == true);
	REQUIRE(conta_teste.set_numero_agencia("3271-4") == true);
	REQUIRE(conta_teste.set_numero_conta("481175-8") == true);
	REQUIRE(conta_teste.cadastro_completo() == true);
	REQUIRE(conta_teste.get_dados(0) == "231");
	REQUIRE(conta_teste.get_dados(1) == "3271-4");
	REQUIRE(conta_teste.get_dados(2) == "481175-8");

}

TEST_CASE("testa entrada e saida da reserva","[entidades]")
{
	Reserva reserva_teste(4,'D',1);
	REQUIRE(reserva_teste.get_dados(0) == "4");
	REQUIRE(reserva_teste.get_dados(1) == "D");
	REQUIRE(reserva_teste.get_dados(2) == "1");
	reserva_teste.set_dados("2","T","3");
	REQUIRE(reserva_teste.get_dados(0) == "2");
	REQUIRE(reserva_teste.get_dados(1) == "T");
	REQUIRE(reserva_teste.get_dados(2) == "3");
}

TEST_CASE("teste entrada e saida da carona","[entidades]")
{
	Carona carona_teste("5431","Brasilia-DF","Salvador-BH","18/11/2019","3","3","259.50");

	REQUIRE(carona_teste.get_dados(0)=="5431");
	REQUIRE(carona_teste.get_dados(1)=="Brasilia-DF");
	REQUIRE(carona_teste.get_dados(2)=="Salvador-BH");
	REQUIRE(carona_teste.get_dados(3)=="18/11/2019");
	REQUIRE(carona_teste.get_dados(4)=="3");
	REQUIRE(carona_teste.get_dados(5)=="3");
	REQUIRE(carona_teste.get_dados(6)=="259.50");
}

TEST_CASE("teste entrada e saida do usuario","[entidades")
{
	Usuario usuario_teste;
	Conta conta_teste1,conta_teste2;
	REQUIRE(conta_teste1.set_codigo_banco("231") == true);
	REQUIRE(conta_teste1.set_numero_agencia("3271-4") == true);
	REQUIRE(conta_teste1.set_numero_conta("481175-8") == true);
	REQUIRE(conta_teste1.cadastro_completo() == true);

	REQUIRE(conta_teste2.set_codigo_banco("222") == true);
	REQUIRE(conta_teste2.set_numero_agencia("2518-9") == true);
	REQUIRE(conta_teste2.set_numero_conta("721224-4") == true);
	REQUIRE(conta_teste2.cadastro_completo() == true);

	REQUIRE(usuario_teste.set_dados("Samuel","61-51-332787006","s.f.cruvinel@gmail.com","azul7","059.581.361-51",conta_teste1,conta_teste2) == true);
	REQUIRE(usuario_teste.get_dados(0) == "Samuel");
	REQUIRE(usuario_teste.get_dados(1) == "61-51-332787006");
	REQUIRE(usuario_teste.get_dados(2) == "s.f.cruvinel@gmail.com");
	REQUIRE(usuario_teste.get_dados(3) == "azul7");
	REQUIRE(usuario_teste.get_dados(4) == "059.581.361-51");

}
