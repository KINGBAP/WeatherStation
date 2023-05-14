#ifndef FIGURE_H 
#define FIGURE_H


class Figure {
private:
  static int cpt;
public:
  Figure();
  virtual int perimetre()=0;
  virtual void afficherCaracteristiques()=0;
  static int getCpt();
 
};

#endif
