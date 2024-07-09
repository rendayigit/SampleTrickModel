/*************************************************************************
PURPOSE: ( TODO )
PROGRAMMERS:
    (((Renda Yiğit) (Turkish Aerospace) (01 July 2024)
**************************************************************************/
#ifndef DATAFLOW_HPP
#define DATAFLOW_HPP

#include <vector>

class DataFlow {
public:
  void connect(unsigned long long t) { m_connectedVariables.push_back(t); }

  void set(unsigned long long t) {
    m_currentValue = t;
    for (auto i : m_connectedVariables) {
        
    }
  }

  unsigned long long get() { return m_currentValue; }

private:
  std::vector<unsigned long long> m_connectedVariables;
  unsigned long long m_currentValue;
};

#endif // DATAFLOW_HPP
