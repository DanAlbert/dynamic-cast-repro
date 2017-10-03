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

int main() {
  test_func test_dynamic;
  test_func test_static;

  // Commenting out these two lines makes both tests pass.
  void *libfirst = load_library("libfirst.so");
  void *libsecond = load_library("libsecond.so");

  void *libtest = load_library("libtest.so");

  test_dynamic = load_func(libtest, "test_dynamic");
  test_static = load_func(libtest, "test_static");

  if (!test_static()) {
    std::cout << "test_static() failed!" << std::endl;
    return EXIT_FAILURE;
  } else {
    std::cout << "test_static() passed!" << std::endl;
  }

  if (!test_dynamic()) {
    std::cout << "test_dynamic() failed!" << std::endl;
    return EXIT_FAILURE;
  } else {
    std::cout << "test_dynamic() passed!" << std::endl;
  }

  return EXIT_SUCCESS;
}
