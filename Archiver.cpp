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
#include <math.h>

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
	
	archives.clear();
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
		    cout << "\nPróximo arquivo: ";
		    getline(cin, buffer);
				    
	    }else{
	    	cout << "\n\nO arquivo " << nameArchive << " não foi adicionado pois já está na lista de arquivos." << endl; 
			cout << "\nPróximo arquivo: ";
	    	getline(cin, buffer);
	    }
	}

	nameArchive = "";
	buffer.clear();
	cin.clear();

	if(this->archives.size() > 0){

		ofstream fs (this->name, std::ofstream::binary);

		if(fs){
			
			//escreve quantidade de arquivos a serem incluidos
			fs.seekp(0);
			std::string qtdArc = std::to_string(this->archives.size());

			for(int i=0; i<qtdArc.size(); i++){
				fs.put(qtdArc[i]);
			}
			
			//escreve cabeçalho
			for(string arc : this->archives){						
				
				ifstream fsArchive (arc, std::ifstream::binary);
				if(fsArchive){

					// get length of file:
					fsArchive.seekg (0, fsArchive.end);
					int length = fsArchive.tellg();
					fsArchive.seekg (0, fsArchive.beg);

					char * bufferArc = new char [length];			

					if (fsArchive){
					
						fs.write("V", 1);

						//escreve nome do arquivo
						for(int i =0; i<arc.size(); i++){
							fs.put(arc[i]);
						}					

						fs.put('/');							

						std::string str = std::to_string(length);

						//escreve tamanho do arquivo
						for(int i=0; i<str.size(); i++){
							fs.put(str[i]);
						}					
					  
					}else{
					  cout << "Erro ao ler o arquivo  " << arc << "\n";
					}
					fsArchive.close();

					// ...buffer contains the entire file...
					delete[] bufferArc;
					
				}else{
					cout << "Houve um erro ao abrir o arquivo " << arc << "\n";
				}				
			}			

			fs.write("###!|aagl\n",10);

			//escreve arquivos
			for(string arc : this->archives){						
				
				ifstream fsArchive (arc, std::ifstream::binary);		
				if(fsArchive){

					// get length of file:
					fsArchive.seekg (0, fsArchive.end);
					int length = fsArchive.tellg();
					fsArchive.seekg (0, fsArchive.beg);

					char * bufferArc = new char [length];			
					
					// read data as a block:
					fsArchive.read (bufferArc,length);

					if (fsArchive){										
					
						fs.write (bufferArc,length);							
					  
					}else{
					  cout << "Erro ao ler o arquivo  " << arc << "\n";
					}
					fsArchive.close();

					// ...buffer contains the entire file...
					delete[] bufferArc;
					
				}else{
					cout << "Houve um erro ao abrir o arquivo " << arc << "\n";
				}				
			}
		}else{
			cout << "Houve um erro ao criar o arquivador.\n";
		}	

		fs.close();

		cout << archives.size() << " arquivo(s) adicionado(s).";

	}else{
           cout << "Nenhum arquivo foi adicionado.";		
	}
}

void Archiver::listArchives(){
	
	string buffer;
	string nameArchive;
	char valido;

	cout << "------------------------------\nListar Arquivos:\n------------------------------\n";

	cout << "Digite o nome do archive desejado: "; getline(cin, buffer);
	setName(buffer);

	ifstream fs (this->name, std::ifstream::binary);

	if(fs){

		char qtdArcTemp;
		int qtdArc;
		string nameArquivo;
		int cont = 0;		

		//pega quantidade de arquivos no archive
		fs.get(qtdArcTemp);
		qtdArc = (int) qtdArcTemp;


		cout << "\nArquivos encontrados em " << getName() << ":\n";

		for(int i=0; i<qtdArc; i++){
			fs.get(valido);

			nameArquivo = "";

			if(valido == 'V'){
				char c;
				fs.get(c);

				while(c != '/'){
					
					nameArquivo += c;
					fs.get(c);
				}

				cout << ++cont << " - " <<  nameArquivo << "\n";
			}
		}
		
	}else{
		cout << "Houve um erro ao abrir o archive " << this->name << "\n";
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
	this->name = name+".txt";
}
