/*************************************************************************
PURPOSE: ( TODO in)
PROGRAMMERS:
    (((Renda Yiğit) (Turkish Aerospace) (01 July 2024)
ICG: (No)
**************************************************************************/

#ifndef INFLOW_HPP
#define INFLOW_HPP


#include "common/DataFlow.hpp"
template <class T> class InFlow : public DataFlow<T> {
public:
  void set(T t) { this->m_currentValue = t; }
};

#endif