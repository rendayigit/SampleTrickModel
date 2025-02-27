// https://github.com/nasa/trick/issues/1833

#include "memoryManagedModel/memoryManagedModel.hpp"
#include "trick/MemoryManager.hh"

// These varaibles are listed under <Dynamic Allocations> in Trick TV

MemoryManagedModel::MemoryManagedModel()
    // Name these declarations as '<Type> <unique_name>'. They will be displayed as <unique_name>
    // under <Dynamic Allocations> in Trick TV
    : m_foo(static_cast<Foo *>(trick_MM->declare_var("Foo foo0"))) {
  m_myVector.push_back(static_cast<Foo *>(trick_MM->declare_var("Foo foo1")));
  m_myVector.push_back(static_cast<Foo *>(trick_MM->declare_var("Foo foo2")));
  m_myVector.push_back(static_cast<Foo *>(trick_MM->declare_var("Foo foo3")));
  m_myVector.push_back(static_cast<Foo *>(trick_MM->declare_var("Foo foo4")));
}

MemoryManagedModel::~MemoryManagedModel() {
  trick_MM->delete_var(m_foo);
  for (auto &foo : m_myVector) {
    trick_MM->delete_var(foo);
  }
}