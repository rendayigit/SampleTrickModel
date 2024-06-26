/********************************* TRICK HEADER *******************************
PURPOSE: ( A sample trick model created using only cpp. Renda. )
LIBRARY DEPENDENCY:
    ((Renda.o))
*******************************************************************************/
#include "Renda.hpp"
#include <iostream>
#include <vector>

#include "sim_services/Executive/include/exec_proto.h"

int Renda::default_data() {
  std::cout << "Default Data Entered" << std::endl;
  a[0] = 0.0;
  a[1] = 6578000.0;
  b[0] = 7905.0;
  b[1] = 0.0;
  c = 900;

  std::vector<int> myList;

  // Notice clangd suggests using range-based for loop instead
  for (int i = 0; i < myList.size(); i++) {
    myList.at(i) = 0;
  }

  return 0;
}

int Renda::init() {
  std::cout << "Initialization Entered" << std::endl;
  b[1] = add(1, 2);
  c = sub(500, 2);
  return 0;
}

int Renda::scheduled() {
  std::cout << "Scheduled Entered" << std::endl;
  c++;
  return 0;
}

int Renda::shutdown() {
  std::cout << "Shutdown Entered" << std::endl;
  std::cout << "Sim Time: " << exec_get_sim_time() << std::endl;
  return 0;
}

double Renda::getSimeTime() { return exec_get_sim_time(); }

int Renda::add(int a, int b) { return a + b; }

int Renda::sub(int a, int b) { return a - b; }

int Renda::mul(int a, int b) { return a * b; }

int Renda::div(int a, int b) { return a / b; }