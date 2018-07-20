#include "rvector_test.h"
#include <iostream>
#include "rvector.h"

// Test driver for rvector_test
int main(int argc, char **argv) {
  std::cout << "--- Test Start ---" << std::endl;
  rz::RVectorTest test;
  test.RunTests();
  std::cout << "--- Test End ---" << std::endl;
  return 0;
}
