#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <locale.h>
#include "Alunos.h"
#include "Refeicoes.h"
using namespace std;


//Funcao login/logout
void loginLogout(struct aluno*LL, struct refeicoes*LL1)
{
	aluno*aux = LL;
	string opcao;
	string numeroFuncionario;
	string password;
	int numeroFuncCerto = 112233;
	int passwordFuncionarioCerta = 2725;
	int passFunc;
	int numeroFunc;
	int nrAluno;
	string numeroAluno;
	struct aluno*LOA = NULL;

	
	bool estado2 = true;
	while(estado2)
	{
		bool estado = true;
		bool estado1 = true;
		bool estado3 = true;
		bool estado4 = true;
		bool estado5 = true;

	cout << "Login" << endl;
	cout << "******************************************" << endl;
	cout << "Funcionário ou aluno?" << endl;
	cout << "1- " << "Funcionário" << endl;
	cout << "2- " << "Aluno" << endl;
	cout << "3- " << "Sair" << endl;
	cout << endl;
	cout << "Escolha uma das opções acima <1-3>" << endl;
	getline(cin, opcao);
	if ((inputValidation(opcao)))
	{
		int opcaoEscolhida1 = stoi(opcao);
			switch (opcaoEscolhida1)
			{
			case 1:
				system("cls");
				while (estado4)
				{
					cout << "Número de funcionário" << endl;
					getline(cin, numeroFuncionario);
					if ((inputValidation(numeroFuncionario)) && ((numeroFuncionario.compare("112233")) == 0))
					{
						numeroFunc = stoi(numeroFuncionario);
						estado4 = false;
					}
					else
					{
					cout << "Número de funcionário errado, tente novamente" << endl;
					system("pause");
					system("cls");
					}
				}
					while (estado3)
					{
						cout << "Password" << endl;
						getline(cin, password);
						if ((inputValidation(password))&&((password.compare("2725"))==0))
						{
							passFunc = stoi(password);
							estado3 = false;
						}
						else
						{
							cout << "Passord inválida, tente novamente" << endl;
							system("pause");
							system("cls");
						}
					}
					system("cls");
					while (estado)
					{
						system("cls");
						cout << endl;
						cout << "Menu do funcionário" << endl;
						cout << "**************************************************" << endl;
						cout << "1- Inserir Aluno" << endl;
						cout << "2- Pesquisar aluno pelo primeiro nome" << endl;
						cout << "3- Pesquisar aluno pelo número mecanográfico" << endl;
						cout << "4- Listar alunos por ordem alfabética" << endl;
						cout << "5- Alterar alunos" << endl;
						cout << "6- Remover ALuno" << endl;
						cout << "7- Consumir refeições" << endl;
						cout << "8- Listar refeições" << endl;
						cout << "9- Listar refeições num determinado dia" << endl;
						cout << "10- " << "Sair" << endl;
						cout << "***************************************************" << endl;
						cout << endl;
						cout << "Introduza o número da opção que quer aceder <1-10>" << endl;
						getline(cin, opcao);
						if ((inputValidation(opcao)))
						{
							int opcaoEscolhida2 = stoi(opcao);
								switch (opcaoEscolhida2)
								{
								case 1:
									system("cls");
									LL = inserirAluno(LL);
									guardarDadosAlunosTxt(LL);
									guardarDadosRefeicoesTxt(LL1); 
									system("pause"); break;
								case 2:
									system("cls");
									pesquisaDoNome(LL); 
									system("pause"); break;
								case 3:
									system("cls");
									pesquisaDoNumero(LL);
									system("pause"); break;
								case 4:
									system("cls");
									guardarDadosAlunosTxt(LL);
									LOA = carregarInformacaoAlunosOrdemAlfabetica();
									ordemAlfabetica(LOA); 
									system("pause"); break;
								case 5:
									system("cls");
									alterarAluno(LL);
									guardarDadosAlunosTxt(LL);
									guardarDadosRefeicoesTxt(LL1); 
									system("pause"); break;
								case 6:
									system("cls");
									LL = removerALuno(LL);
									guardarDadosAlunosTxt(LL);
									guardarDadosRefeicoesTxt(LL1);
									system("pause");
									break;
								case 7:
									system("cls");
									consumirRefeicoes(LL,LL1);
									guardarDadosAlunosTxt(LL);
									guardarDadosRefeicoesTxt(LL1);
									system("pause"); break;
								case 8:
									system("cls");
									listarRefeicoes(LL1);
									guardarDadosAlunosTxt(LL);
									guardarDadosRefeicoesTxt(LL1); 
									system("pause"); break;
								case 9:
									system("cls");
									listarRefeicoesNumDeterminadoDia(LL1);
									guardarDadosAlunosTxt(LL);
									guardarDadosRefeicoesTxt(LL1); 
									system("pause"); break;
								case 10:
									system("cls");
									cout << "Escolheu a opção sair, obrigado" << endl;
									guardarDadosAlunosTxt(LL);
									guardarDadosRefeicoesTxt(LL1); estado = false; break;
								default:
									cout << "Opção não válida, tente novamente" << endl;
									system("pause");
									system("cls");
									break;
								}
						}
						else
						{
							cout << "Opção não válida, tente novamente" << endl;
							system("pause");
							system("cls");
						}
					}
				break;

			case 2:
				system("cls");
				aux = LL;
				while (estado5)
				{
					cout << "Número de aluno" << endl;
					getline(cin, numeroAluno);
					if (inputValidation(numeroAluno))
					{
						estado5 = false;
					}
					else
					{
					cout << "Número de aluno não válido" << endl;
					system("pause");
					system("cls");
					numeroAluno = "";
					}
				}
					nrAluno = stoi(numeroAluno);
					cout << "Password" << endl;
					getline(cin, password);

					while (aux != NULL)
					{
						if ((aux->numero == nrAluno) && ((aux->senha.compare(password)) == 0))
						{

							while (estado1)
							{
								system("cls");
								cout << endl;
								cout << "Menu do aluno" << endl;
								cout << "********************************" << endl;
								cout << "1- Encomendar refeições" << endl;
								cout << "2- Carregar plafond" << endl;
								cout << "3- " << "Sair" << endl;
								cout << "**********************************" << endl;
								cout << endl;
								cout << "Introduza o número da opcao que quer aceder <1-3>" << endl;
								getline(cin, opcao);
								if (inputValidation(opcao))
								{
									int opcaoEscolhida3 = stoi(opcao);
										switch (opcaoEscolhida3)
										{
										case 1:
											system("cls");
											LL1 = encomendarRefeicoes(LL1, LL,nrAluno);
											guardarDadosAlunosTxt(LL);
											guardarDadosRefeicoesTxt(LL1); 
											system("pause"); break;
										case 2:
											system("cls");
											carregarPlafond(LL,nrAluno);
											guardarDadosAlunosTxt(LL);
											guardarDadosRefeicoesTxt(LL1);
											system("pause"); break;
										case 3:
											estado1 = false; break;
										default:
											cout << "Opção não válida, tente novamente" << endl;
											system("pause");
											guardarDadosAlunosTxt(LL);
											guardarDadosRefeicoesTxt(LL1);
											break;
										}
								}
								else
								{
									cout << "Opção não válida, tente novamente" << endl;
									system("pause");
									system("cls");
								}
							}
							return;
						}
						aux = aux->next;
					}
					cout << "Aluno não registado no sistema" << endl;
					system("pause");
					system("cls");
						break;
			case 3:
				cout << "Escolheu a opção sair, obrigado" << endl;
				guardarDadosAlunosTxt(LL);
				guardarDadosRefeicoesTxt(LL1);
				estado2 = false;
				return;
			}
	}
	else
	{
		cout << "Opção não válida, tente novamente" << endl;
		system("pause");
		system("cls");
	}
	system("cls");
   }
}

//Funcao para inserir aluno
struct aluno* inserirAluno(struct aluno*LL)
{
	string nrAux, nomeAux, dataAux, moradaAux, cursoAux, senhaAux, plafondAux, opcaoAux,dia,ano,mes;
	int opcao = 2;
	bool estado = true;
	while (opcao == 2)
	{
		system("cls");
		cout << "Introduza o número de aluno" << endl;
		getline(cin, nrAux);
		if ((inputValidation(nrAux)))
		{
			system("cls");
			cout << "Introduza o nome do aluno" << endl;
			getline(cin, nomeAux);
			nomeAux = letrasMaiusculas(nomeAux);
			estado = true;
			while(estado)
			{
				system("cls");
			cout << "Introduza a data de nascimento do aluno" << endl;
			cout << "Introduza o ano" << endl;
			getline(cin, ano);
			cout << "Introduza o mes" << endl;
			getline(cin, mes);
			cout << "Introduza o dia" << endl;
			getline(cin, dia);
			if (inputValidation(ano) && inputValidation(mes) && inputValidation(dia))
			{
				dataAux = "";
				int anoAux = stoi(ano);
				int mesAux = stoi(mes);
				int diaAux = stoi(dia);
				dataAux = dataAux.append(ano);
				dataAux = dataAux.append("/");
				dataAux = dataAux.append(mes);
				dataAux = dataAux.append("/");
				dataAux = dataAux.append(dia);
				dataAux;
				estado = false;
				if (validaData(diaAux, mesAux, anoAux) == 0)
				{
					cout << "Data inválida" << endl;
					cout << endl;
					estado = true;
					system("pause");
				}
			}
			else
			{
				cout << "Data inválida, tente novamente" << endl;
				system("pause");
				system("cls");
			}
		}
			system("cls");
			cout << "Introduza a morada do aluno" << endl;
			getline(cin, moradaAux);
			system("cls");
			cout << "Introduza o curso do aluno" << endl;
			getline(cin, cursoAux);
			system("cls");
			cout << "Introduza a senha do aluno" << endl;
			getline(cin, senhaAux);
				cout << endl;
				system("cls");
				cout << "Os dados introduzidos estao certos?" << endl;
				cout << endl;
				cout << "Número: " << nrAux << endl;
				cout << "Nome: " << nomeAux << endl;
				cout << "Data de nascimento: " << dataAux << endl;
				cout << "Morada: " << moradaAux << endl;
				cout << "Curso: " << cursoAux << endl;
				cout << "Senha: " << senhaAux << endl;
				cout << "Plafond: 0" << endl;
				cout << endl;
				cout << "1- Sim" << endl;
				cout << "2- Não" << endl;
				cout << endl;
				cout << "Escolha uma das opções acima <1-2>" << endl;
				getline(cin, opcaoAux);
				if ((inputValidation(opcaoAux)))
				{
					opcao = stoi(opcaoAux);
				}
				else
				{
					cout << "Opção não válida, tente novamente" << endl;
					system("pause");
					system("cls");
				}
		}
			else
			{
				cout << "Número de aluno não válido, tente novamente" << endl;
				system("pause");
				system("cls");
			}
		}
		int nr = stoi(nrAux);
		aluno* newAluno = new aluno;
		newAluno->numero = nr;
		newAluno->nome = nomeAux;
		newAluno->data = dataAux;
		newAluno->morada = moradaAux;
		newAluno->curso = cursoAux;
		newAluno->senha = senhaAux;
		newAluno->plafond = 0;

		if (LL == NULL)
		{
			newAluno->next = NULL;
			LL = newAluno;
			cout << "Aluno inserido com sucesso" << endl;
			return LL;
		}

		aluno*anterior = LL;
		aluno*seguinte = anterior->next;
		if (newAluno->numero<anterior->numero)
		{
			newAluno->next = anterior;
			LL = newAluno;
			cout << "Aluno inserido com sucesso" << endl;
			return LL;
		}

		else
		{
			while ((seguinte != NULL) && ((newAluno->numero>seguinte->numero)))

			{

				anterior = seguinte;
				seguinte = seguinte->next;
			}
			anterior->next = newAluno;
			newAluno->next = seguinte;
			cout << "Aluno inserido com sucesso" << endl;
			return LL;
		}

		return LL;
	}

//Funcao para pesquisar pelo primeiro nome

void pesquisaDoNome(struct aluno*LL)
{
	int i = 0;
	string nomeAluno;
	string nome;
	string primNome;
	int contador = 0;
	cout << "Introduza o nome do aluno" << endl;
	getline(cin, nomeAluno);
	nomeAluno = letrasMaiusculas(nomeAluno);
	cout << endl;
	nomeAluno = letrasMaiusculas(nomeAluno);
	while (nomeAluno[i] != ' '&& nomeAluno[i] != '\0')
	{
		primNome += nomeAluno[i];
		i++;
	}
	primNome;

	if (LL == NULL)
	{
		cout << "Lista de alunos vazia" << endl;
	}
	else
	{
		aluno*aux = LL;
		cout << "RESULTADOS DA PESQUISA: " << endl;
		while (aux != NULL)
		{
			nome = aux->nome.substr(0, primNome.size());
			if ((primNome.compare(nome)) == 0)
			{
				cout << endl;
				cout << "Aluno:" << endl;
				cout << "Nome: " << aux->nome << endl;
				cout << "Número: " << aux->numero << endl;
				cout << endl;
				contador++;
			}
			aux = aux->next;
		}
		cout << "Nomes encontrados na pesquisa: "<< contador << endl;
	}
}

//Funcao para pesquisar pelo nr mecanografico

void pesquisaDoNumero(struct aluno*LL)
{
	string nrAux;
	bool estado = true;
	while (estado)
	{
		cout << "Introduza o número do aluno que pretende pesquisar" << endl;
		getline(cin, nrAux);
		if ((inputValidation(nrAux)))
		{
			int nr = stoi(nrAux);

			aluno* aux = LL;
			while (aux != NULL)
			{
				if (aux->numero == nr)
				{
					cout << endl;
					cout << "Dados do aluno: " << endl;
					cout << endl;
					cout << "Número: " << aux->numero << endl;
					cout << "Nome: " << aux->nome << endl;
					cout << "Data de nascimento: " << aux->data << endl;
					cout << "Morada: " << aux->morada << endl;
					cout << "Curso: " << aux->curso << endl;
					cout << "Senha: " << aux->senha << endl;
					cout << "Plafond: " << aux->plafond << endl;
					return;
				}
				aux = aux->next;
			}
			cout << "Nenhum aluno registado com o número introduzido" << endl;
			system("pause");
			system("cls");
		}
		else
		{
			cout << "Número de aluno não válido, tente novamente" << endl;
			system("pause");
			system("cls");

		}
	}
}

void ordemAlfabetica(struct aluno*LOA)
{
	aluno*aux = LOA;
	if (aux == NULL)
	{
		cout << "Nenhum aluno inserido" << endl;
	}
	else
		cout << "RESULTADOS: " << endl;
	cout << endl;
		while (aux != NULL)
		{
			cout << "Número: " << aux->numero << endl;
			cout << "Nome: " << aux->nome << endl;
			cout << "Data: " << aux->data << endl;
			cout << "Morada: " << aux->morada << endl;
			cout << "Curso: " << aux->curso << endl;
			cout << "Senha: " << aux->senha << endl;
			cout << "Plafond: " << aux->plafond << endl;
			cout << endl;

			aux = aux->next;
		}
}

//Funçao para alterar o nome para letras maisculas
string letrasMaiusculas(string nomeAluno)
{
	int index = 0;
	while (index < nomeAluno.size())
	{

		nomeAluno[index] = toupper(nomeAluno[index]);

		index++;
	}

	return nomeAluno;
}

void alterarAluno(struct aluno*LL)

{
	string numeroAlunoInserido;
	string camposaAlterar;
	int campos;
	string numeroMecanograficoAux;
	string nomeAux,dataAux,moradaAux,cursoAux,senhaAux,dia ,mes, ano;
	string vazia;
	int numero,diaAux,anoAux,mesAux;
	aluno*aux = LL;
	bool estado = true;
	bool estado1 = true;
	bool estado3 = true;
	while (estado)
	{
		cout << "Introduza o número do aluno que pretende alterar" << endl;
		getline(cin, numeroAlunoInserido);
		if ((inputValidation(numeroAlunoInserido)))
		{
			int nrInserido = stoi(numeroAlunoInserido);
			while (aux != NULL)
			{

				if (aux->numero == nrInserido)
				{
					while (true)
					{
						system("cls");
						cout << "Menu do aluno" << endl;
						cout << endl;
						cout << "1- " << "Número: " << aux->numero << endl;
						cout << "2- " << "Nome: " << aux->nome << endl;
						cout << "3- " << "Data de nascimento: " << aux->data << endl;
						cout << "4- " << "Morada: " << aux->morada << endl;
						cout << "5- " << "Curso: " << aux->curso << endl;
						cout << "6- " << "Password: " << aux->senha << endl;
						cout << "7- " << "Sair" << endl;
						cout << endl;
						cout << "Selecinone o número do campo que pretende alterar" << endl;
						getline(cin, camposaAlterar);
						if (inputValidation(camposaAlterar))
						{
							campos = stoi(camposaAlterar);

							switch (campos)
							{
							case 1:
								while (estado3)
								{
									system("cls");
									cout << "Introduza o novo número de aluno" << endl;
									getline(cin, numeroMecanograficoAux);
									if (inputValidation(numeroMecanograficoAux))
									{
										estado3 = false;
									}
									else
									{
										cout << "Número de aluno não válido, tente novamente" << endl;
										system("pause");
										system("cls");
									}
								}
								numero = stoi(numeroMecanograficoAux);
								aux->numero = numero;
								cout << "Número de aluno alterado com sucesso" << endl;
								cout << endl;
								system("pause");
								break;

							case 2:
								system("cls");
								cout << "Introduza o novo nome do aluno" << endl;
								getline(cin, nomeAux);
								aux->nome = letrasMaiusculas(nomeAux);
								cout << "O nome foi alterado com sucesso" << endl;
								cout << endl;
								system("pause");
								break;

							case 3:
								while (estado1)
								{
									system("cls");
									cout << "Introduza a nova data de nascimento do aluno" << endl;
									cout << "Introduza o ano" << endl;
									getline(cin, ano);
									cout << "Introduza o mês" << endl;
									getline(cin, mes);
									cout << "Introduza o dia" << endl;
									getline(cin, dia);
									if (inputValidation(ano) && inputValidation(mes) && inputValidation(dia))
									{
										anoAux = stoi(ano);
										mesAux = stoi(mes);
										diaAux = stoi(dia);
										if (validaData(diaAux, mesAux, anoAux) == 0)
										{
											cout << "Data inválida" << endl;
											system("pause");
											system("cls");
											estado1 = true;
										}
										else
										{
											dataAux = dataAux.append(ano);
											dataAux = dataAux.append("/");
											dataAux = dataAux.append(mes);
											dataAux = dataAux.append("/");
											dataAux = dataAux.append(dia);
											dataAux;
											aux->data = dataAux;
											cout << "Data de nascimento alterada com sucesso" << endl;
											cout << endl;
											estado1 = false;
										}
									}
									else
									{
										cout << "Data introduzida incorreta, tente novamente" << endl;
										system("pause");
										system("cls");
									}
								}
								break;

							case 4:
								system("cls");
								cout << "Introduza a nova morada do aluno" << endl;
								getline(cin, moradaAux);
								aux->morada = moradaAux;
								cout << "Morada do aluno alterada com sucesso" << endl;
								cout << endl;
								system("pause");
								break;

							case 5:
								system("cls");
								cout << "Introduza o novo curso do aluno" << endl;
								getline(cin, cursoAux);
								aux->curso = cursoAux;
								cout << "Curso do aluno alterado com sucesso" << endl;
								cout << endl;
								system("pause");
								break;

							case 6:
								system("cls");
								cout << "Introduza a nova senha do aluno" << endl;
								getline(cin, senhaAux);
								aux->senha = senhaAux;
								cout << "Senha do aluno alterada com sucesso" << endl;
								cout << endl;
								system("pause");
								break;


							case 7:

								cout << "Escolheu a opção sair, obrigado" << endl;
								cout << endl;

								return;
								break;

							default:

								cout << "Opção não válida, tente novamente" << endl;
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

				aux = aux->next;

			}

			cout << "Número de aluno não encontrado no sistema" << endl;
			return;
		}
		else
		{
			cout << "Número de aluno incorreto, tente novamente" << endl;
			system("pause");
			system("cls");
		}
	}
}


//Funcao para remover aluno

struct aluno* removerALuno(struct aluno*LL)
{
	string nrAux;
	bool estado = true;
	aluno*aux = LL;
	while (estado)
	{
		cout << "Introduza o número que de aluno que pretende eliminar" << endl;
		getline(cin, nrAux);
		if ((inputValidation(nrAux)))
		{
			int nr = stoi(nrAux);
			aluno*anterior = LL;
			aluno*seguinte = anterior->next;
			while (aux != NULL)
			{
				if (aux->numero == nr)
				{
					if (anterior->numero == nr)
					{
						delete anterior;
						LL = seguinte;
						cout << "Aluno eliminado com sucesso!" << endl;
						return LL;
					}
					while (seguinte->numero != nr)
					{
						anterior = seguinte;
						seguinte = seguinte->next;
					}
					anterior->next = seguinte->next;
					delete seguinte;
					cout << "Aluno eliminado com sucesso!" << endl;
					return LL;
				}
				aux = aux->next;
			}
			cout << "Aluno não registado no sistema" << endl;
			return LL;
		}

		else
		{
			cout << "Número de aluno não valido, tente novamente" << endl;
			system("pause");
			system("cls");
		}
	}
	return LL;

}

//Funcao para guardar dados dos alunos no ficheiro de texto

void guardarDadosAlunosTxt(struct aluno*LL)
{
	string vazia;
	ofstream ficheiro("aluno.txt");
	aluno*aux = LL;
	while (aux!=NULL)
	{
	ficheiro << aux->numero << endl;
	ficheiro << aux->nome << endl;
	ficheiro << aux->data << endl;
	ficheiro << aux->morada << endl;
	ficheiro << aux->curso << endl;
	ficheiro << aux->senha << endl;
	ficheiro << aux->plafond << endl;

	aux = aux->next;

	}
		ficheiro.close();
}




//Carregar dados de alunos 
struct aluno* carregarInformacaoAlunos()
{
	string line;
	string vazia;
	struct aluno*LL = NULL;
	aluno*aux = LL;
	ifstream ficheiro("aluno.txt", ios::out);
	while ((getline(ficheiro, line)) && ((vazia.compare(line)) != 0))
	{
		aluno*newNode = new aluno;
		int nr = stoi(line);
		newNode->numero = nr;
		getline(ficheiro, line);
		newNode->nome = line;
		getline(ficheiro, line);
		newNode->data = line;
		getline(ficheiro, line);
		newNode->morada = line;
		getline(ficheiro, line);
		newNode->curso = line;
		getline(ficheiro, line);
		newNode->senha = line;
		getline(ficheiro, line);
		int plaf = stoi(line);
		newNode->plafond = plaf;

		if (LL == NULL)
		{
			LL = newNode;
			LL->next = NULL;
			aux = LL;
		}
		else
		{
			aux->next = newNode;
			aux = aux->next;
			aux->next = NULL;


		}
	}
	ficheiro.close();
	return LL;
}

//Carregar dados de alunos por ordem alfabetica
struct aluno* carregarInformacaoAlunosOrdemAlfabetica()
{
	string line;
	string vazia;
	struct aluno*LOA = NULL;
	aluno*aux = LOA;
	ifstream ficheiro("aluno.txt", ios::out);
	while ((getline(ficheiro, line)) && ((vazia.compare(line)) != 0))
	{
		aux = LOA;
		aluno*newNode = new aluno;
		int nr = stoi(line);
		newNode->numero = nr;
		getline(ficheiro, line);
		newNode->nome = line;
		getline(ficheiro, line);
		newNode->data = line;
		getline(ficheiro, line);
		newNode->morada = line;
		getline(ficheiro, line);
		newNode->curso = line;
		getline(ficheiro, line);
		newNode->senha = line;
		getline(ficheiro, line);
		int plaf = stoi(line);
		newNode->plafond = plaf;
		if (LOA == NULL)
		{
			LOA = newNode;
			LOA->next = NULL;
			aux = LOA;
		}
		if (((LOA->nome.compare(newNode->nome))>0))
		{
			newNode->next = LOA;
			LOA = newNode;
			aux=LOA;
		}
		else
		{
			aluno*anterior = aux;
			aluno*seguinte = anterior->next;
			while ((seguinte != NULL) && ((seguinte->nome.compare(newNode->nome)) < 0))

			{

				anterior = seguinte;
				seguinte = seguinte->next;
			}
			anterior->next = newNode;
			newNode->next = seguinte;
		}
	}
	ficheiro.close();
	return LOA;
}



//Funçao para carregar plafond

void carregarPlafond(struct aluno*LL,int nrAluno)
{
	string plafondAux;
	string line;
	string vazia;
	aluno*aux = LL;
	bool estado = true;
	while (aux!=NULL)
	{
		if (aux->numero == nrAluno)
		{
			cout << "Dados do aluno" << endl;
			cout << endl;

			cout << "Número: " << aux->numero << endl;
			cout << "Nome: " << aux->nome << endl;
			cout << "Data de nascimento: " <<aux->data << endl;
			cout << "Morada: " << aux->morada << endl;
			cout << "Curso: " << aux->curso << endl;
			cout << "Password: " << aux->senha << endl;
			cout << "Plafond: " << aux->plafond << endl;
			cout << endl;
			while (estado)
			{
				cout << "Quanto é que pretende carregar no seu plafond?" << endl;
				getline(cin, plafondAux);
				if (inputValidation(plafondAux))
				{
					estado = false;
				}
				else
				{
					cout << "Ocorreu um erro, tente novamente" << endl;
					system("pause");
					system("cls");
				}
			}
			int plafond = stoi(plafondAux);
			aux->plafond = aux->plafond + plafond;
			cout << "O seu plafond é de: " << aux->plafond << endl;
			break;

		}
		aux = aux->next;

	}
}


//Funcao para validar data
int validaData(int dia, int mes, int ano)
{
	if ((dia >= 1 && dia <= 31) && (mes >= 1 && mes <= 12) && (ano >= 1900 && ano <= 2100))//Vereifica se os nrs sao validos
	{
		if ((dia == 29 && mes == 2) && ((ano % 4) == 0) && ((ano % 100) != 0) || ((ano % 400) == 0))//Verifica se o ano é bissexto
		{
			return 1;
		}
		if (dia <= 28 && mes == 2)
		{
			return 1;
		}
		if ((dia <= 30) && (mes == 4 || mes == 6 || mes == 9 || mes == 11))//verifica os meses com 30 dias
		{
			return 1;
		}
		if ((dia <= 31) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12))//verifica os meses de 31 dias
		{
			return 1;
		}
		else
			return 0;
	}
	else
		return 0;
}

bool inputValidation(string input)
{
	if (input.empty())//cobre o caso do utilizador introduzir somente enter
	{
		return false;
	}
	if (input.find_first_not_of("0123456789") != string::npos)
	{
		return false;
	}
	if (input.length() > 7)//cobre o caso de o nr ser muito grande e nao dar depois para converter para inteiro
	{
		return false;
	}
	return true;
}
