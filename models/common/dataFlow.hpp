#ifndef DATAFLOW_HPP
#define DATAFLOW_HPP

#include <functional>
#include <vector>

/**
 * Forward declarations
 */
template <class T> class DataFlow; // NOLINT(readability-identifier-naming)
template <class T> class InFlow;   // NOLINT(readability-identifier-naming)
template <class T> class OutFlow;  // NOLINT(readability-identifier-naming)

/**
 * Base DataFlow class that allows the flow of data between models.
 */
template <class T> class DataFlow { // NOLINT(readability-identifier-naming)
public:
  /**
   * Constructor
   */
  DataFlow() = default;

  /**
   * Set the current value of the dataFlow variable.
   *
   * @param t The new value.
   *
   * @throws None
   */
  virtual void setValue(T t) { m_currentValue = t; }

  /**
   * Get the current value of the dataFlow variable.
   *
   * @return The current value.
   *
   * @throws None
   */
  T getValue() const { return m_currentValue; }

protected:
  /**
   * The current value of the dataFlow variable.
   */
  T m_currentValue;
};

/**
 * InFlow class that acts as an input dataFlow variable.
 */
template <class T> class InFlow : public DataFlow<T> { // NOLINT(readability-identifier-naming)
  friend class OutFlow<T>;

public:
  /**
   * Constructor
   */
  InFlow() : m_updateFunction([this](T t) { this->m_currentValue = t; }) {}

  /**
   * Sets the update callback function of the inFlow variable. This callback function is called when
   * the dataFlow variable is updated.
   *
   * @param updateFunction The function to be set as the event callback function.
   *
   * @throws None
   */
  void setUpdateFunction(std::function<void(T t)> updateFunction) {
    m_updateFunction = std::move(updateFunction);
  }

private:
  std::function<void(T)> m_updateFunction;
};

/**
 * OutFlow class that acts as an output dataFlow variable.
 */
template <class T> class OutFlow : public DataFlow<T> { // NOLINT(readability-identifier-naming)
public:
  /**
   * Constructor
   */
  OutFlow() : m_connectedInFlows({}) {}

  /**
   * Connect an inFlow variable to this outFlow variable.
   *
   * @param inFlow The inFlow variable to be connected.
   *
   * @throws None
   */
  void connect(InFlow<T> *inFlow) { m_connectedInFlows.push_back(inFlow); }

  /**
   * Set the current value of the dataFlow variable. All the connected inFlow variables will be
   * automatically updated.
   *
   * @param t The new value.
   *
   * @throws None
   */
  void setValue(T t) override {
    this->m_currentValue = t;
    for (auto i : m_connectedInFlows) {
      i->m_updateFunction(t);
    }
  }

private:
  /**
   * The connected inFlow variables.
   */
  std::vector<InFlow<T> *> m_connectedInFlows;
};

#endif // DATAFLOW_HPP
