#include <dlfcn.h>
#include <stdlib.h>

#include <iostream>

typedef bool (*test_func)();

void *load_library(const char *name) {
  void *lib = dlopen(name, RTLD_NOW);
  if (lib == nullptr) {
    std::cerr << dlerror() << std::endl;
    abort();
  }
  return lib;
}

test_func load_func(void *lib, const char *name) {
  test_func sym = reinterpret_cast<test_func>(dlsym(lib, name));
  if (sym == nullptr) {
    std::cerr << dlerror() << std::endl;
    abort();
  }
  return sym;
}

int main(int argc, char**) {
  // Explicitly loading libfirst.so before libtest.so causes the test to fail.
  if (argc == 1) {
    load_library("libfirst.so");
  }

  void *libtest = load_library("libtest.so");

  test_func do_test = load_func(libtest, "do_test");
  if (!do_test()) {
    std::cout << "do_test() failed!" << std::endl;
    return EXIT_FAILURE;
  } else {
    std::cout << "do_test() passed!" << std::endl;
  }

  return EXIT_SUCCESS;
}
