#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <locale.h>
#include "Refeicoes.h"
#include "Alunos.h"
using namespace std;

//Funcao para encomendar refeicoes
struct refeicoes*encomendarRefeicoes(struct refeicoes*LL1, struct aluno*LL,int nrAluno)
{
	string nrDeAluno;
	string dia;
	string mes;
	string ano;
	string dataRefeicao;
	string escolha;
	int valorRefeicao = 3;
	int diaAux, mesAux, anoAux;
	string opcao;
	string vazia;
	refeicoes*aux1 = LL1;
	aluno*aux = LL;
	while (aux != NULL)
	{
		if (aux->numero == nrAluno)
		{
			if (valorRefeicao <= aux->plafond)
			{
				bool estado = true;
				while (estado)
				{
					cout << "Introduza o ano da refeição" << endl;
					getline(cin, ano);
					cout << "Introduza o mes da refeição" << endl;
					getline(cin, mes);
					cout << "Introduza o dia da refeição" << endl;
					getline(cin, dia);
					if (inputValidation(ano) && inputValidation(mes) && inputValidation(dia))
					{
						anoAux = stoi(ano);
						mesAux = stoi(mes);
						diaAux = stoi(dia);
						dataRefeicao = dataRefeicao.append(ano);
						dataRefeicao = dataRefeicao.append("/");
						dataRefeicao = dataRefeicao.append(mes);
						dataRefeicao = dataRefeicao.append("/");
						dataRefeicao = dataRefeicao.append(dia);
						if (validaData(diaAux, mesAux, anoAux) == 1)
						{
							estado = false;
						}
						else
						{
							cout << "Data inválida, tente novamente" << endl;
							dataRefeicao = "";
							system("pause");
							system("cls");
						}
					}
					else
					{
						cout << "Data introduzida inválida, tente novamente" << endl;
						system("pause");
						system("cls");
					}
				}
				bool estado1 = true;
				while (estado1)
				{
					system("cls");
					cout << "1-Almoço" << endl;
					cout << "2-Jantar" << endl;
					cout << endl;
					cout << "Escolha uma das opções acima <1-2>" << endl;
					getline(cin, opcao);
					if ((inputValidation(opcao)) && (opcao.length() < 6)&&(((opcao.compare("1"))==0)||(opcao.compare("2"))==0))//FAzer ciclo so aqui neste menu
					{
						estado1 = false;
					}
					else
					{
						cout << "Opção não válida, tente novamente" << endl;
						system("pause");
						system("cls");
					}
					}
					int opcaoEscolhida = stoi(opcao);
					refeicoes*newNode = new refeicoes;
					switch (opcaoEscolhida)
					{
					case 1:
						newNode->horario = "Almoço";
						break;
					case 2:
						newNode->horario = "Jantar";
						break;
					default:
						cout << "Opção não válida, tente novamente" << endl;
						system("pause");
						system("cls");
						break;
					}
							newNode->data = dataRefeicao;
							newNode->nrAluno = nrAluno;
							newNode->consumiu = "Por consumir";
							aux->plafond = aux->plafond - valorRefeicao;
							newNode->next = NULL;

							if (LL1 == NULL)
							{
								newNode->next = NULL;
								LL1 = newNode;
								cout << "Refeição marcada com sucesso!" << endl;
								return LL1;
							}

							refeicoes*anterior = LL1;
							refeicoes*seguinte = anterior->next;
							if (((anterior->data.compare(newNode->data)) > 0))
							{
								newNode->next = anterior;
								LL1 = newNode;
								cout << "Refeição marcada com sucesso!" << endl;
								return LL1;
							}
							else
							{
								while ((seguinte != NULL) && ((seguinte->data.compare(newNode->data)) < 0))

								{

									anterior = seguinte;
									seguinte = seguinte->next;
								}
								anterior->next = newNode;
								newNode->next = seguinte;
								cout << "Refeição marcada com sucesso!" << endl;
								return LL1;
							}
			}
				cout << "Plafond insuficiente" << endl;
				return LL1;
			}
			aux = aux->next;
	}
	return LL1;
}


//Fncao para consumir refeicoes

void consumirRefeicoes(struct aluno*LL, struct refeicoes*LL1)
{
	
	string nrAluno, ano, mes, dia,dataRefeicao,opcao;
	int anoAux, mesAux, diaAux;
	aluno*aux = LL;
	refeicoes*aux1 = LL1;
	bool estado = true;
	while (estado)
	{
		cout << "Introduza o número de aluno" << endl;
		getline(cin, nrAluno);
		if (inputValidation(nrAluno))
		{
			estado = false;
		}
		else
		{
			cout << "Número de aluno inválido, tente novamente" << endl;
			system("pause");
			system("cls");
		}
	}
	int nr = stoi(nrAluno);
	while (aux != NULL)
	{
		if (aux->numero == nr)
		{
			estado = true;
			while (estado)
			{
				system("cls");
				cout << "Introduza o ano da refeição" << endl;
				getline(cin, ano);
				cout << "Introduza o mes da refeição" << endl;
				getline(cin, mes);
				cout << "Introduza o dia da refeição" << endl;
				getline(cin, dia);
				if (inputValidation(ano) && inputValidation(mes) && inputValidation(dia))
				{
					anoAux = stoi(ano);
					mesAux = stoi(mes);
					diaAux = stoi(dia);
					if (validaData(diaAux, mesAux, anoAux)==1)
					{
						estado = false;
					}
					else
					{
						cout << "Data inválida, tente novamente" << endl;
						dataRefeicao = "";
						system("pause");
						system("cls");
					}
				}
				else
				{
					cout << "Data inválida, tente novamente" << endl;
					system("pause");
					system("cls");
				}
			}
			dataRefeicao = dataRefeicao.append(ano);
			dataRefeicao = dataRefeicao.append("/");
			dataRefeicao = dataRefeicao.append(mes);
			dataRefeicao = dataRefeicao.append("/");
			dataRefeicao = dataRefeicao.append(dia);
			estado = true;
			while (estado)
			{
				system("cls");
				cout << "Almoço ou jantar?" << endl;
				cout << "1- Almoço" << endl;
				cout << "2- Jantar" << endl;
				cout << "3- Sair" << endl;
				cout << "Escolha uma das opções acima <1-3>" << endl;
				getline(cin, opcao);
				if ((inputValidation(opcao))&&((opcao.compare("1")==0)||(opcao.compare("2")==0)||(opcao.compare("3")==0)))
				{
					estado = false;
				}
				else
				{
					cout << "Opção não válida, tente novamente" << endl;
					system("pause");
					system("cls");
				}
			}
			int opcaoEscolhida = stoi(opcao);
			switch (opcaoEscolhida)
			{
			case 1:
				while (aux1 != NULL)
				{
					if ((aux1->nrAluno==nr)&&((aux1->horario.compare("Almoço"))==0)&&(((aux1->data.compare(dataRefeicao)) == 0)))
					{
						aux1->consumiu = "Consumida";
						cout << "Refeição marcada como consumida" << endl;
						return;
					}
					aux1 = aux1->next;
				}
				cout << "Nenhuma refeição encontrada" << endl;
				return;
				break;
			case 2:
				while (aux1 != NULL)
				{
					if ((aux1->nrAluno == nr) && ((aux1->horario.compare("Jantar")) == 0) && (((aux1->data.compare(dataRefeicao)) == 0)))
					{
						aux1->consumiu = "Consumida";
						cout << "Refeição marcada como consumida" << endl;
						return;
					}
					aux1 = aux1->next;
				}
				cout << "Nenhuma refeição encontrada" << endl;
				return;
				break;
			case 3:
				cout << "Escolheu a opção sair, obrigado" << endl;
				return;
			}

		}
		aux = aux->next;
	}
	cout << "Aluno não registado no sistema" << endl;
	return;
}

//Funcao para listar refeiçoes

void listarRefeicoes(struct refeicoes*LL1)
{
	string nrAluno;
	string opcao;
	string vazia;
	string estado = "Consumida";
	int contador = 0;
	refeicoes*aux = LL1;
	bool estado1 = true;
	bool estado2 = true;
	while (estado1)
	{
		cout << "Qual das opções deseja aceder?" << endl;
		cout << "1- " << "Listar refeições de um só aluno" << endl;
		cout << "2- " << "Listar refeições de todos os alunos" << endl;
		cout << endl;
		cout << "Escolha uma das opções acima <1-2>" << endl;
		getline(cin, opcao);
		if (inputValidation(opcao))
		{
			estado1 = false;
			int opcaoEscolhida = stoi(opcao);
			switch (opcaoEscolhida)
			{
			case 1:

				while (estado2)
				{
					cout << "Insira o número de aluno" << endl;
					getline(cin, nrAluno);
					if ((inputValidation(nrAluno)))
					{
						system("cls");
						cout << "RESULTADOS DA PESQUISA:" << endl;
						estado2 = false;
						while (aux != NULL)
						{
							int number = stoi(nrAluno);
							if ((aux->nrAluno==number) && ((estado.compare(aux->consumiu)) == 0))
							{
								cout << endl;
								cout << "Número de aluno: " << aux->nrAluno << endl;
								cout << "Data da refeição: " << aux->data << endl;
								cout << "Horário: " << aux->horario << endl;
								cout << "Estado, consumido/por comsumir: " << aux->consumiu << endl;
								cout << endl;
								contador++;
							}
							aux = aux->next;
						}
						cout << "Resultados: " << contador << endl;
					}
					else
					{
						cout << "Número de aluno inválido, tente novamente" << endl;
						system("pause");
						system("cls");
					}
				}
				break;
			case 2:
				system("cls");
				cout << "RESULTADOS DA PESQUISA" << endl;
				while (aux != NULL)
				{
					if (((aux->data.compare(vazia)) != 0) && (estado.compare(aux->consumiu)) == 0)
					{
						cout << endl;
						cout << "Número de aluno: " << aux->nrAluno << endl;
						cout << "Data da refeição: " << aux->data << endl;
						cout << "Horário: " << aux->horario << endl;
						cout << "Estado, consumido/por comsumir: " << aux->consumiu << endl;
						cout << endl;
						contador++;
					}

					aux = aux->next;

				}
				cout << "Resultados: " << contador << endl;
				break;
			default:
				cout << "Opção não válida, tente novamente" << endl;
				estado1 = true;
				system("pause");
				system("cls");
			}
		}
		else
		{
			cout << "Opção não válida, tente novamente" << endl;
			system("pause");
			system("cls");
		}
	}
}

//Funcao para listar refeicoes num determinado dia

void listarRefeicoesNumDeterminadoDia(struct refeicoes*LL1)
{
	string dataDaRefeicao;
	string dia;
	string mes;
	string ano;
	int contador = 0;
	refeicoes*aux = LL1;
	bool estado = true;
	while (estado)
	{
		while (estado)
		{
			cout << "Introduza o ano que pretende aceder" << endl;
			getline(cin, ano);
			cout << "Introduza o mês que pretende aceder" << endl;
			getline(cin, mes);
			cout << "Introduza o dia que pretende aceder" << endl;
			getline(cin, dia);
			if (inputValidation(ano) && inputValidation(mes) && inputValidation(dia))
			{
				estado = false;
			}
			else
			{
				cout << "Data inválida, tente novamente" << endl;
				system("pause");
				system("cls");
			}
		}
		estado = true;
		int anoAux = stoi(ano);
		int mesAux = stoi(mes);
		int diaAux = stoi(dia);
		dataDaRefeicao = dataDaRefeicao.append(ano);
		dataDaRefeicao = dataDaRefeicao.append("/");
		dataDaRefeicao = dataDaRefeicao.append(mes);
		dataDaRefeicao = dataDaRefeicao.append("/");
		dataDaRefeicao = dataDaRefeicao.append(dia);
		dataDaRefeicao;
		if ((validaData(diaAux, mesAux, anoAux)) == 1)
		{
			estado = false;
			cout << endl;
			system("cls");
			cout << "RESULTADOS DA PESQUISA" << endl;
			while (aux != NULL)
			{
				if ((dataDaRefeicao.compare(aux->data)) == 0)
				{
					cout << endl;
					cout << "Número de aluno: " << aux->nrAluno << endl;
					cout << "Data da refeição: " << aux->data << endl;
					cout << "Horário: " << aux->horario << endl;
					cout << "Estado, consumido/por comsumir: " << aux->consumiu << endl;
					cout << endl;
					contador++;
				}
				aux = aux->next;
			}
		}
		else
		{
			cout << "Data inválida, tente novamente" << endl;
			dataDaRefeicao = "";
			system("pause");
			system("cls");
		}
	}

		cout << "Número de refeições para a data selecionada: " << contador << endl;
}

//Funcao para guardar dados das refeicoes em txt

void guardarDadosRefeicoesTxt(struct refeicoes*LL1)
{
	string vazia;
	refeicoes*aux = LL1;
	ofstream myfile("refeicoes.txt", ios::out);
	while (aux != NULL)
	{

		myfile << aux->nrAluno << endl;
		myfile << aux->horario << endl;
		myfile << aux->data << endl;
		myfile << aux->consumiu << endl;
		aux = aux->next;
	}
	myfile.close();
}

//Funcao para carregar dados das refeicoes

struct refeicoes* carregarInformacaoRefeicoes()
{
	string line;
	string vazia;
	struct refeicoes*LL1 = NULL;
	refeicoes*aux = LL1;
	ifstream ficheiro("refeicoes.txt", ios::out);
	while ((getline(ficheiro, line)) && ((vazia.compare(line)) != 0))
	{
		refeicoes*newNode = new refeicoes;
		int nr = stoi(line);
		newNode->nrAluno = nr;
		getline(ficheiro, line);
		newNode->horario = line;
		getline(ficheiro, line);
		newNode->data = line;
		getline(ficheiro, line);
		newNode->consumiu = line;

		if (LL1 == NULL)
		{
			LL1 = newNode;
			LL1->next = NULL;
			aux = LL1;
		}
		else
		{
			aux->next = newNode;
			aux = aux->next;
			aux->next = NULL;


		}
	}
	ficheiro.close();
	return LL1;
}