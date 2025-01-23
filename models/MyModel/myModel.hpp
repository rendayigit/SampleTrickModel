#include <string>

class Foo {
public:
  int a = 5;
  std::string someString = "hello";
};

class MyModel {
public:
  Foo *foo;

  MyModel() { foo = new Foo; }
};