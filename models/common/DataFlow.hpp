/*************************************************************************
PURPOSE: ( TODO )
PROGRAMMERS:
    (((Renda Yiğit) (Turkish Aerospace) (01 July 2024)
ICG: (No)
**************************************************************************/
#ifndef DATAFLOW_HPP
#define DATAFLOW_HPP

#include <vector>

template <class T> class DataFlow {
public:
  virtual void set(T t) = 0;

  T get() { return m_currentValue; }

protected:
  T m_currentValue;
};

#endif // DATAFLOW_HPP
