#include <iostream>
#include "Information.hpp"

using namespace std;

const string Information::project     = "Archiver";
const string Information::team        = "Alex Rafael, Guilherme Garcia, Lais Bueno";
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
  cout << "Te vejo na próxima! \n";
  cout << decoration;
  cout << "\n\n" << endl;
};

/* fim de arquivo */
