#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
using namespace std;

struct aluno
{
	int numero;
	string nome;
	string data;
	string morada;
	string curso;
	string senha;
	int plafond;
	aluno * next;
};


void loginLogout(struct aluno*LL,struct refeicoes* LL1);
void ordemAlfabetica(struct aluno*LL);
struct aluno* inserirAluno(struct aluno*LL);
void pesquisaDoNome(struct aluno*LL);
string letrasMaiusculas(string nomeAluno);
void pesquisaDoNumero(struct aluno*LL);
void alterarAluno(struct aluno*LL);
struct aluno* removerALuno(struct aluno*LL);
void guardarDadosAlunosTxt(struct aluno*LL);
struct aluno* carregarInformacaoAlunos();
struct aluno* carregarInformacaoAlunosOrdemAlfabetica();
void carregarPlafond(struct aluno*LL,int nrAluno);
int validaData(int dia, int mes, int ano);
bool inputValidation(string input);


