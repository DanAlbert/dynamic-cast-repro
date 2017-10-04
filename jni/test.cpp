#include "first.h"

extern "C" bool do_test() {
  FirstImpl first;
  First* base = &first;
  return dynamic_cast<FirstImpl*>(base) != nullptr;
}
