#ifndef TWO_LIBS_FIRST_H
#define TWO_LIBS_FIRST_H

class First {
public:
  virtual ~First(){};
};

class FirstImpl : public First {
public:
  FirstImpl();
};

#endif // TWO_LIBS_FIRST_H
