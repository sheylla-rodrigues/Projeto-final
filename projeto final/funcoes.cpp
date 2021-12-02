#include<iostream>
#include "funcoes.h"
#include<string>
using namespace std;

char menu () {	
	char escolha = ' ';
	cout << "\n NA nome aluno";
	cout << "\n MTA matricula aluno";
	cout << "\n NP nota prova";
	cout << "\n NAEP nota aep";
	cout << "\n MDA media >=6 aprovado";
	cout << "\n MDR media <2 reprovado";
	cout << "\n MB media bimestral <6 sustitutiva";
	cout << "\n LD ler dados";
	cout << "\n EO escolher opcao n";
	cin >> escolha;
	system("cls");
	return escolha;
}

bool cadastraAluno (Aluno aluno) {
	ofstream arquivo;
	arquivo.open("database.csv", fstream::app);
	
	if (!arquivo.is_open()) {
		cout << "Houve um erro ao abrir o arquivo!\n";
		return false;	
	}
	
	arquivo << aluno.nome << ";" 
			<< aluno.matricula << ";"
			<< aluno.prova1 << ";"
			<< aluno.aep1 << ";"
			<< aluno.prova2 << ";"
			<< aluno.aep2 << ";"
			<< aluno.media << ";"
			<< aluno.status << "\n";
	
	arquivo.close();
	return true;
}


bool realizaLeituraArquivo () {
	ifstream arquivo;
	arquivo.open("database.csv");
	if (!arquivo.is_open()) {
		std::cout << "Houve um erro ao abrir o arquivo!\n";
		return false;	
	}
	
	{
	string nome;
	int matricula;
	 float nota1,nota2, somanota, mediaaluno;
	
	cout<<"Cadastro de alunos";
	cout<<"\n Nome do aluno: ";
	cin>>nome;
	
	cout<<"\n Numero da matricula: ";
	cin>>matricula;
	 float nota1,nota2, somanota, mediaaluno;
   
    int i, aprovado=0, reprovado=0, substitutiva=0;
    for(i=1; i<100; i++)
    {
        cout<<"\n Digite a primeira nota: ";
        cin>>nota1;
        cout<<"\n Digite a nota da primeira AEP: ";
        cin>>nota2;
        somanota= nota1+nota2;
        mediaaluno= somanota/2;
        if(mediaaluno>=6)
        {
            cout<<"\n Parabens voce foi aprovado!";    
        }
        else if(mediaaluno<6)
        {
            cout<<"\n Marcar prova substitutiva!";
        }
        else if(mediaaluno<2)
        {
        	cout<<"\n Infelizmente voce Reprovou!";
		}
	}
	
	
	string linha;
	int indexAluno = 0;
	while (std::getline(arquivo, linha)) {
//		cout << linha << "\n"; string == array char
		int coluna = 0;
		int controleColuna = 0;
		string conteudo = "";
		for (int i = 0; i < linha.size(); i++) {
			if (coluna == 1 && controleColuna == 0)  {
				alunos[indexAluno].nome = conteudo;	
				conteudo = "";
				controleColuna = 1;
			} else if (coluna == 2 && controleColuna == 1) {
				alunos[indexAluno].matricula = conteudo;	
				conteudo = "";
				controleColuna = 2;
			}
			if (linha[i] == ';') {
				coluna++;				
				continue;
			}
			conteudo.push_back(linha[i]);					
		}
		indexAluno++;
	}
	arquivo.close();
	
	// teste
	for (int i = 0; i < 100; i++) {
		cout << "Aluno n " << i+1 << "\n";
		cout << "Nome: " << alunos[i].nome << "\n";
		cout << "Matricula: " << alunos[i].matricula << "\n";
	}
	
	return true;
}

void teste () {
	Aluno alunoTeste;
	alunoTeste.nome = "Aluno Teste";
	alunoTeste.matricula = "1234";
	alunoTeste.aep1 = 1.3;
	alunoTeste.prova1 = 5.2;
	alunoTeste.aep2 = 1.8;
	alunoTeste.prova2 = 6.2;
	alunoTeste.media = 0;
	alunoTeste.sub = 0;
	alunoTeste.status = "nao calculado";
	
	if (cadastraAluno (alunoTeste)) {
		cout << "Aluno teste cadastrado\n";
	} else {
		cout << "Erro ao cadastrar aluno teste\n";
	}
}
