#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
using namespace std;

struct refeicoes
{
	int nrAluno;
	string horario;
	string data;
	string consumiu;
	refeicoes*next;
};

struct refeicoes* encomendarRefeicoes(struct refeicoes*LL1, struct aluno*LL, int nrAluno);
void consumirRefeicoes(struct aluno*LL,struct refeicoes*LL1);
void listarRefeicoes(struct refeicoes*LL1);
void listarRefeicoesNumDeterminadoDia(struct refeicoes*LL1);
void guardarDadosRefeicoesTxt(struct refeicoes*LL1);
struct refeicoes* carregarInformacaoRefeicoes();
int validaData(int dia, int mes, int ano);
