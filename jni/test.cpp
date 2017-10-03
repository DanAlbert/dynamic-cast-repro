#include <memory>

#include "first.h"
#include "firstImpl.h"
#include "second.h"

extern "C" bool test_dynamic() {
  std::shared_ptr<first> firstSRef = std::make_shared<firstImpl>();
  std::shared_ptr<second> secondSRef = std::make_shared<second>(firstSRef);
  return secondSRef->validateDynamicPointerCast();
}

extern "C" bool test_static() {
  std::shared_ptr<first> firstSRef = std::make_shared<firstImpl>();
  std::shared_ptr<second> secondSRef = std::make_shared<second>(firstSRef);
  return secondSRef->validateStaticPointerCast();
}
