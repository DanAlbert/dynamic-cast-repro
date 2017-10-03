#ifndef TWO_LIBS_SECOND_H
#define TWO_LIBS_SECOND_H

#include <memory>

#include "first.h"

class second {
public:
  second(const std::shared_ptr<first> &firstSRef);

  bool validateDynamicPointerCast() const;

  bool validateStaticPointerCast() const;

private:
  std::shared_ptr<first> _firstSRef;
};

#endif // TWO_LIBS_SECOND_H
