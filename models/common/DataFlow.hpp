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
  virtual void set(T t) { m_currentValue = t; }

  T get() { return m_currentValue; }

protected:
  T m_currentValue;
};

template <class T> class InFlow : public DataFlow<T> {};

template <class T> class OutFlow : public DataFlow<T> {
public:
  void connect(InFlow<T> inFlow) { m_connectedInFlows.push_back(inFlow); }

  void set(T t) override {
    this->m_currentValue = t;
    for (auto i : m_connectedInFlows) {
      i.set(t);
    }
  }

private:
  std::vector<InFlow<T>> m_connectedInFlows;
};

#endif // DATAFLOW_HPP
