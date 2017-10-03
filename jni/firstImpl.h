#ifndef TWO_LIBS_FIRSTIMPL_H
#define TWO_LIBS_FIRSTIMPL_H

#include "first.h"

class firstImpl : public first {
public:
  firstImpl();

  void init() override;

  void prepare() override;

  void run() override;
};

#endif // TWO_LIBS_FIRSTIMPL_H
