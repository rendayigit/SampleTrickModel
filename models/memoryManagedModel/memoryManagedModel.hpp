/* PURPOSE: A sample trick model created to demonstrate Object pointer usage */
#pragma once

// https://github.com/nasa/trick/issues/1833

#include <string>
#include <vector>

class Foo {
public:
  int a = 1;
  std::string someString = "hello";
};

class MemoryManagedModel {
public:
  MemoryManagedModel();
  ~MemoryManagedModel();

private:
  std::vector<Foo *> m_myVector;
  Foo *m_foo;
};