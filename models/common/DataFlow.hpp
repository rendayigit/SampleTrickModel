/*************************************************************************
PURPOSE: ( A variable type that allows the flow of data between models. )
PROGRAMMERS:
    ((Renda Yiğit) (Turkish Aerospace) (01 July 2024))
**************************************************************************/
#ifndef DATAFLOW_HPP
#define DATAFLOW_HPP

#include <vector>

template <class T> class DataFlow { // NOLINT(readability-identifier-naming)
public:
  virtual void setValue(T t) { m_currentValue = t; }

  T getValue() { return m_currentValue; }

protected:
  T m_currentValue;
};

template <class T> class InFlow : public DataFlow<T> {}; // NOLINT(readability-identifier-naming)

template <class T> class OutFlow : public DataFlow<T> { // NOLINT(readability-identifier-naming)
public:
  void connect(InFlow<T> inFlow) { m_connectedInFlows.push_back(inFlow); }

  void setValue(T t) override {
    this->m_currentValue = t;
    for (auto i : m_connectedInFlows) {
      i.setValue(t);
    }
  }

private:
  std::vector<InFlow<T>> m_connectedInFlows{};
};

#endif // DATAFLOW_HPP
