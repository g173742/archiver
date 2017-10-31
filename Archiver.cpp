/* Unicamp - Universidade Estadual de Campinas
   FT - Faculdade de Tecnologia
   Limeira - SP
   Prof. Dr. Andre F. de Angelis
   Mar/2016
*/

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include "Archiver.hpp"
#include "Menu.hpp"
#include "Information.hpp"

Archiver::Archiver() {}

void Archiver::start() {
  //myMainList.clear();
  Information::wellcome("Wellcome to our Archiver! Be happy :) ");
  process();
  Information::bye();
}

void Archiver::process() {
  vector<string> opcoes({ "Exit", "List Database", "Insert Items" });
  Menu menu("Main Menu", opcoes);
  int escolha = -1;

  while(escolha) {
    escolha = menu.getEscolha();

    switch(escolha) {
    case 1: {
	cout << "List Items";
      //listItems();
    };

    break;
    case 2: {
	cout << "Insert Items";
      //insertItems();
    };

    break;
    };
  };
};
