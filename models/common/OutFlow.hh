/*************************************************************************
PURPOSE: ( TODO out)
PROGRAMMERS:
    (
      ((Renda Yiğit) (Turkish Aerospace) (01 July 2024))
      ((Yusuf Can Anar) (Turkish Aerospace) (01 July 2024))
    )
ICG: (No)
**************************************************************************/

#ifndef OUTFLOW_HH
#define OUTFLOW_HH

#include "common/DataFlow.hh"
#include "common/InFlow.hh"
template <class T> class OutFlow : public DataFlow<T> {
public:
  void connect(InFlow<T> inFlow) { m_connectedInFlows.push_back(inFlow); }

  void set_my_t(T t) {
    this->m_currentValue = t;
    for (auto i : m_connectedInFlows) {
      i.set(t);
    }
  }

private:
  std::vector<InFlow<T>> m_connectedInFlows;
};

#endif