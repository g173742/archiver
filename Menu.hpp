/* Unicamp - Universidade Estadual de Campinas
   FT - Faculdade de Tecnologia
   Limeira - SP
   Prof. Dr. Andre F. de Angelis
   Maio/2015
*/

#ifndef MENU_H
  #define MENU_H

  #include <string>
  #include <vector>

using namespace std;

class Menu {
  private:
    string titulo;
    vector<string> opcoes;

  public:
    Menu(string titulo, vector<string> opcoes);
    const virtual int getEscolha();
};

#endif

/* fim de arquivo */
