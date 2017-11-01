/* Unicamp - Universidade Estadual de Campinas
   FT - Faculdade de Tecnologia
   Limeira - SP
   Prof. Dr. Andre F. de Angelis
   Mar/2016
*/

#ifndef INFORMATION_H
  #define IN FORMATION_H

using namespace std;

class Information {
  private:
    static const string project;
    static const string team;
    static const string decoration;

  public:
    static const string getProject();
    static const string getTeam();
    static const void wellcome(void);
    static const void wellcome(string message);
    static const void wellcome(string message, bool shortMessage);
    static const void bye(void);
    static const void bye(bool shortMessage);
};

#endif

/* fim de arquivo */
