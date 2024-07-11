/*************************************************************************
PURPOSE: ( TODO in)
PROGRAMMERS:
    (((Renda Yiğit) (Turkish Aerospace) (01 July 2024)
ICG: (No)
**************************************************************************/

#ifndef OUTFLOW_HPP
#define OUTFLOW_HPP

#include "common/DataFlow.hpp"
#include "common/InFlow.hpp"
template <class T> class OutFlow : public DataFlow<T> {
public:
  void connect(InFlow<T> inFlow) { m_connectedInFlows.push_back(inFlow); }

  void set(T t) {
    this->m_currentValue = t;
    for (auto i : m_connectedInFlows) {
      i.set(t);
    }
  }

private:
  std::vector<InFlow<T>> m_connectedInFlows;
};

#endif