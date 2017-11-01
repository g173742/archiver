/* Unicamp - Universidade Estadual de Campinas
   FT - Faculdade de Tecnologia
   Limeira - SP
   Prof. Dr. Andre F. de Angelis
   Mar/2016
*/

#include <iostream>
#include "Information.hpp"

using namespace std;

const string Information::project     = "File Structs - Archiver";
const string Information::team        = "Alexandre Katao, Guilherme Garcia, Lais Bueno";
const string Information::decoration  = "************************************************************************\n";

const string Information::getProject() {
  return (project);
};

const string Information::getTeam() {
  return (team);
};

const void Information::wellcome() {
  wellcome("");
};

const void Information::wellcome(string message) {
  cout << decoration;
  cout << Information::getProject() << "\n" << Information::getTeam() << "\n";

  cout << decoration;
  if(message != ""){		
     cout << message << endl;
  }
};

const void Information::bye() {
  cout << decoration;
  cout << "Bye, we see you ! \n";
  cout << decoration;
  cout << "\n\n" << endl;
};

/* fim de arquivo */
