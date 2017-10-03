#include "second.h"
#include "firstImpl.h"

second::second(const std::shared_ptr<first> &firstSRef)
    : _firstSRef(firstSRef) {}

bool second::validateDynamicPointerCast() const {
  if (_firstSRef != nullptr) {
    auto firstImplSRef = std::dynamic_pointer_cast<firstImpl>(_firstSRef);
    if (firstImplSRef != nullptr) {
      return true;
    }
  }
  return false;
}

bool second::validateStaticPointerCast() const {
  if (_firstSRef != nullptr) {
    auto firstImplSRef = std::static_pointer_cast<firstImpl>(_firstSRef);
    if (firstImplSRef != nullptr) {
      return true;
    }
  }
  return false;
}
