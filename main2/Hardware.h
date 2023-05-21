#ifndef HARDWARE_H
#define HARDWARE_H

class Hardware {
public:
  Hardware(int pin);
  virtual void begin()=0;
  
protected:
  int pin;
};

#endif
