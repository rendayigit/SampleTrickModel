#include <array>
#include <iostream>
#include <string>
#include <vector>

class Foo {
public:
  int a = 5;
  std::string someString = "hello";
};

class MyModel {
public:
  Foo *foo;
  std::vector<int> bar;
  std::array<int, 2> bar2;
  int bar3[2];

  MyModel() {
    foo = new Foo;
    bar.push_back(1);
    bar.push_back(2);
    bar.push_back(3);
    bar.push_back(4);

    bar2[0] = 5;
    bar2[1] = 6;

    bar3[0] = 7;
    bar3[1] = 8;

    std::cout << bar[0] << std::endl;
  }
};