#ifndef TWO_LIBS_FIRST_H
#define TWO_LIBS_FIRST_H

class first {
public:
  virtual ~first(){};

  virtual void init() = 0;

  virtual void prepare() = 0;

  virtual void run() = 0;
};

#endif // TWO_LIBS_FIRST_H
