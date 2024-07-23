/*************************************************************************
PURPOSE: ( TODO )
PROGRAMMERS:
    (
      ((Renda Yiğit) (Turkish Aerospace) (01 July 2024))
      ((Yusuf Can Anar) (Turkish Aerospace) (01 July 2024))
    )
ICG: (No)
**************************************************************************/
#ifndef DATAFLOW_HH
#define DATAFLOW_HH

#include <vector>

template <class T> class DataFlow {
public:
  void set(T t) { m_currentValue = t; };

  T get() { return m_currentValue; }

protected:
  T m_currentValue;
};

#endif // DATAFLOW_HH
