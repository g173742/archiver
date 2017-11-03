/* Unicamp - Universidade Estadual de Campinas
   FT - Faculdade de Tecnologia
   Limeira - SP
   Prof. Dr. Andre F. de Angelis
   Mar/2016
*/

#include <string>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "Archiver.hpp"
#include "libs/Menu.hpp"
#include "libs/Information.hpp"

Archiver::Archiver() {}
Archiver::~Archiver() {}

void Archiver::start() {
  archives.clear();
  name = "";
  indexName = "";
  Information::wellcome("Wellcome to our Archiver! Be happy :) ");
  process();
  Information::bye();
}

void Archiver::process() {
  vector<string> opcoes({ "Exit", "New Archiver", "List Archives", "Extract Archive", "Insert Archive", "Remove Archive" });
  Menu menu("Main Menu", opcoes);
  int escolha = -1;

  while(escolha) {
    escolha = menu.getEscolha();

    switch(escolha) {
	    case 1: {
	    	createArchiver();	    	
	    };
	    break;

	    case 2: {
			listArchives();
	    };
	    break;

	    case 3: {
		cout << "Extract Archive";
	    };
	    break;
	    case 4: {
		cout << "Insert Archive";
	    };
	    break;
	    case 5: {
		cout << "Remove Archive";
	    };
	    break;
    };
  };
};

void Archiver::createArchiver(){
	
	string buffer;
	string nameArchive;	

	cout << "------------------------------\nCriar Arquivador:\n------------------------------\n";

	cout << "Informe o nome do archiver (sem a extensão): "; getline(cin, buffer);
	setName(buffer);

	cout << "\nInforme os arquivos a serem adicionados no archiver\n(0 para terminar de adicionar os arquivos)";
	cout << "\nArquivo: ";
	getline(cin, buffer);

	while(buffer != "0"){

	   nameArchive = buffer;
	   cin.clear();
	   
	    if(!inArray(archives,nameArchive)){
		   	archives.insert(archives.end(), nameArchive);		    
		    cout << "Adicionado: " << nameArchive << "\n\nPróximo arquivo: ";
		    getline(cin, buffer);
				    
	    }else{
	    	cout << "O arquivo " << nameArchive << " não foi adicionado pois já está na lista de arquivos." << endl; 
			cout << "\nPróximo arquivo: ";
	    	getline(cin, buffer);
	    }
	}

	nameArchive = "";
	buffer = "";
	cin.clear();

	if(archives.size() > 0){
		
		this->name += ".acv";
		this->indexName += ".idx";

		fstream fs;
		fs.open(this->name, std::fstream::out| std::fstream::binary);

		if(fs.is_open()){
			fstream fsArchive;
			for(string arc : this->archives){
				fsArchive.open(arc, std::fstream::out | std::fstream::binary);
				if(fsArchive.is_open()){
					fs.write((char *) &eofOffset, sizeof(int));
				}				
			}
		}else{
			cout << "Houve um erro ao abrir o arquivo.\n";
		}	

		fs.close();

		cout << archives.size() << " arquivo(s) adicionado(s).";

	}else{
           cout << "Nenhum arquivo foi adicionado.";		
	}
}

void Archiver::listArchives(){
	cout << "------------------------------\nListar Arquivos:\n------------------------------\n";

	if(archives.size() > 0){
		int i =0;

		for(string v : archives)
			cout << ++i << " - " << v << endl;		
	}else{
		cout << "Não há arquivos para listar, para isso crie um arquivador com os arquivos desejados.";
	}
}

bool const Archiver::inArray(vector<string> array, string value){
	for(string v : array)
		if(v == value)
			return true;
		
	return false;
}

void Archiver::insertArchive(string nameArchive, string name){

}

string const Archiver::getName(){
	return this->name;
}

void Archiver::setName(string name){
	this->name = name;
}
