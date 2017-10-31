#include <iostream>
#include "Archiver.hpp"

using namespace std;

int main(int argc, char* argv[]) {
	try{
  		Archiver* archiver = new Archiver();  
		archiver->start();
		delete archiver;
	}catch(exception& e){
		cout << e.what() << '\n';
	}
};

