#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <locale.h>
#include "Alunos.h"
#include "Refeicoes.h"
using namespace std;

int main()
{

	bool estado = true;
	string opcaoInserida;
	int opcaoNumerica;

	struct refeicoes*LL1 = NULL;
	struct aluno*LL = NULL;
	setlocale(LC_ALL, "Portuguese");
	while (estado)
	{

		LL = carregarInformacaoAlunos();
		LL1 = carregarInformacaoRefeicoes();
		cout << "******************************************" << endl;
		cout << "Gestão de Refeições/Cantina" << endl;
		cout << "********************************************" << endl;
		cout << "1- Login/Logout" << endl;
		cout << "2- Sair" << endl;
		cout << endl;
		cout << "Insira o número da tarefa pretendida <1-2>: " << endl;

		string opcaoInserida;
		getline(cin, opcaoInserida);
		if ((inputValidation(opcaoInserida))&&(opcaoInserida.length()<6))
		{
			opcaoNumerica = stoi(opcaoInserida);
				switch (opcaoNumerica)
				{
					
				case 1: 
					system("cls"); 
					loginLogout(LL, LL1); break;

				case 2: cout << "Escolheu a opção sair, obrigado!" << endl; 
					guardarDadosAlunosTxt(LL);
					guardarDadosRefeicoesTxt(LL1); estado = false; break;
				default:
					system("cls");
					cout << "Opção inválida, tente novamente" << endl;
					break;
				}
				system("pause");
				system("cls");
		}
		else
		{
			system("cls");
		}
		
	}
}