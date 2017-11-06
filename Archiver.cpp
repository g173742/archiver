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
  Information::wellcome("Bem-vindo ao nosso Archiver!");
  process();
  Information::bye();
}

void Archiver::process() {
  vector<string> opcoes({ "Exit", "Novo Archiver", "Listar Arquivos", "Extrair Arquivo", "Inserir Arquivo", "Remover Arquivo" });
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
			insertArchive();
	    };
	    break;

	    case 5: {
			removeArchive();
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

	cout << "Digite o nome do archive desejado: (sem a extensão)"; getline(cin, buffer);
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

void Archiver::removeArchive(){
	
	string buffer;
	string nameArchive;

	cout << "------------------------------\nRemover Arquivo:\n------------------------------\n";

	cout << "Digite o nome do archive desejado (sem a extensão): "; getline(cin, buffer);
	setName(buffer);

	cout << "Digite o nome do arquivo a ser removido: "; getline(cin, buffer);
	nameArchive = buffer;

	buffer = "";

	ifstream fs (this->name, std::ifstream::binary);

	if(fs){
		
		int qtdArc = 0; //quantidade de arquivos
		string nameArquivo = ""; //nome do arquivo dentro do archive
		bool encontrou = false; //encontrou ou não o arquivo pedido pelo usuário	 
		int x = 0; // posição no conteudo


		//pega tamanho do arquivo
	    fs.seekg (0, fs.end);
	    int length = fs.tellg();
	    fs.seekg (0, fs.beg);

	    //conteudo do arquivo
	    char * conteudo = new char [length];

	    //le conteudo
	    fs.read(conteudo,length);

	    //fecha conexão
	    fs.close();

	    //pega quantidade de arquivos no archive
	    qtdArc = (int) conteudo[0];

	    //realiza operações abaixo de acordo com a quantidade de arquivos no archiver
	    for(int i = 0; i < qtdArc; i++){

	    	nameArquivo.clear();
	    		    
	    	//chega até o V ou F
	    	while(conteudo[x] != 'V' && conteudo[x] != 'F'){
				x++;	    	
	    	}	   

	    	//se o arquivo não está excluído
	    	if(conteudo[x] == 'V'){	    	

	    		//incrementa x para sair do V
	    		x++;

	    		//procura a / que indica final do nome do arquivo
	    		while(conteudo[x] != '/'){
					nameArquivo += conteudo[x];	    			
					x++;	
	    		}	    	
	    		
	    		//se o arquivo lido é o procurado pelo usuário
	    		if(nameArchive == nameArquivo){

	    			//seta arquivo como excluido
	    			conteudo[x - (nameArquivo.size()+1)] = 'F';
	    			encontrou = true;
	    		
	    			//abre arquivo novamente
	    			ofstream fs (this->name, std::ofstream::binary); 

	    			//coloca nele o novo conteudo, já com a remoção
	    			fs.write(conteudo,length);
	    			fs.close();
	    			delete[] conteudo;

	    			cout << "Exclusão realizada com sucesso.\n";

	    			break;
	    		}

	    	}
	    }

		if(!encontrou){
			cout << "O arquivo " << nameArchive << " não foi encontrado em " << getName();
		}
		
	}else{
		cout << "Houve um erro ao abrir o archive " << this->name << "\n";
	}
}


void Archiver::insertArchive(){
	
	string buffer;
	string nameArchive;

	cout << "------------------------------\nInsetir Arquivo:\n------------------------------\n";

	cout << "Digite o nome do archive desejado (sem a extensão): "; getline(cin, buffer);
	setName(buffer);

	cout << "Digite o nome do arquivo a ser inseriod: "; getline(cin, buffer);
	nameArchive = buffer;

	buffer = "";

	ifstream fs (this->name, std::ifstream::binary);

	if(fs){
		
		int x = 1; // posição no conteudo

		//pega tamanho do arquivo
	    fs.seekg (0, fs.end);
	    int length = fs.tellg();
	    fs.seekg (0, fs.beg);

	    //conteudo do arquivo
	    char * conteudo = new char [length];

	    //le conteudo
	    fs.read(conteudo,length);

	    //fecha conexão
	    fs.close();
	   	
	   	ifstream fs (nameArchive, std::fstream::binary);

	   	if(fs){
	   		fs.seekg (0, fs.end);
		    int lengthArc = fs.tellg();
		    fs.seekg (0, fs.beg);
		
			//conteudo do arquivo
	    	char * bufferArc = new char [lengthArc];

	    	int qtdArc = (int) conteudo[0]-48;
	    	qtdArc++;
	    
	    	string comeco = to_string(qtdArc);

		    string fim = "";
		    string meio = "";

		    meio = "V" + nameArchive + "/" + to_string(lengthArc) + "###!|aagl";

		   	//percorre até achar marcador de final de cabeçalho
		   	while(conteudo[x] != '#'){
		   		comeco += conteudo[x];
		   		x++;
		   	}

		   	while(conteudo[x] != '\n'){
		   		x++;
		   	}

		   	while(conteudo[x] != '\0'){
		   		fim += conteudo[x];
		   		x++;
		   	}

			string novoConteudo = comeco +""+ meio +""+ fim;

			ofstream fs (this->name, std::ofstream::binary); 

	    	//coloca nele o novo conteudo, já com a remoção
			for(int i=0; i < novoConteudo.size(); i++){
				fs.put(novoConteudo[i]);	
			}
	    	
	    	fs.close();
	    	delete[] conteudo;
	    	delete[] bufferArc;

	    	ifstream fsArchive (nameArchive, std::ifstream::binary);	    	
	    
	    	if(fsArchive){
	    		    		
	    	 	//pega tamanho do arquivo
			    fsArchive.seekg (0, fsArchive.end);
			    int length = fsArchive.tellg();
			    fsArchive.seekg (0, fsArchive.beg);

			    //conteudo do arquivo
			    char * bufferArc = new char [length];

			    //le conteudo
			    fsArchive.read(bufferArc,length);

			    //fecha conexão
			    fsArchive.close();

			    ofstream fs (this->name, std::ofstream::app);

			    if(fs){
			    	fs.write(bufferArc, length);

			    	if(fs){
			    		cout << "Arquivo inserido com sucesso!";
			    	}else{
			    		cout << "Houve um erro ao inserir o arquivo: " << getName() << "\n";
			    	}
			    }else{
			    	cout << "Erro ao inserir o arquivo. \n";
			    }

	    	}else{
	    		cout << "Erro ao inserir o arquivo. \n";
	    	}
			
	   	}else{
	   		cout << "O arquivo "<< nameArchive << " não foi encontrado \n\n";
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

string const Archiver::getName(){
	return this->name;
}

void Archiver::setName(string name){
	this->name = name+".aagl";
}
