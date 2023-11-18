// #include <assert.h>
#include <iostream>
#include <vector>
#include <memory>
#include "my_vector.h"
#include "test_my_vector.h"
#include "test_my_vector.cpp"
#include "my_vector.cpp"


int main(int argc, char *argv[]) {
  MyVector::TestMyVector tester;
  tester.RunTest();
  std::cout << "Test Finished !!!" << std::endl;
  return EXIT_SUCCESS;
}