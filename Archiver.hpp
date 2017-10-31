/* Unicamp - Universidade Estadual de Campinas
   FT - Faculdade de Tecnologia
   Limeira - SP
   Prof. Dr. Andre F. de Angelis
   Mar/2016
*/

using namespace std;

#ifndef ARCHIVER_H
  #define ARCHIVER_H

  #include <vector>

class Archiver {

  public:
    Archiver();
    //void start(char**);    
    void start();	

  private:
    //vector<Archive *> myMainList;
    void process(void);
};

#endif

/* fim de arquivo */
