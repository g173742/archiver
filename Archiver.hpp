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
  #include <string>

class Archiver {

  public:
    ~Archiver();  
    Archiver();  
    void start(void); 
    void setName(string name);
    string const getName();

  private:
    vector<string> archives;
    string name;
    string indexName;
    void process(void);
    void createArchiver(void);
    void insertArchive(void);
    void listArchives(void);
    void removeArchive(void);
    bool const inArray(vector<string> array, string value);
};

#endif

/* fim de arquivo */
