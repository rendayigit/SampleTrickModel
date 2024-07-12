/*************************************************************************
PURPOSE: ( A service that allows the creation of events that can be triggered by the simulator. )
PROGRAMMERS:
    ((Renda Yiğit) (Turkish Aerospace) (01 July 2024))
**************************************************************************/

#ifndef MODELEVENT_HPP
#define MODELEVENT_HPP

#include "trick/Event.hh"
#include "trick/EventManager_c_intf.hh"
#include <functional>
#include <utility>

class ModelEvent : public Trick::Event {
public:
  /**
   * Sets the event callback function for the event.
   *
   * @param eventFunction The function to be set as the event callback function.
   *
   * @throws None
   */
  void setEventFunction(std::function<void()> eventFunction) {
    m_eventFunction = std::move(eventFunction);
  }

  /**
   * Sets the trigger time for the event based on the input time.
   *
   * @param time The simulation time value to set as the trigger time
   *
   * @throws None
   */
  void setTriggerTime(double time) {
    std::cout << "Trigger Entered \t\t@ " << exec_get_time_tics() << std::endl;
    set_next_tics(time * 1000000);
  }

private:
  int process(long long) override {
    m_eventFunction();
    return 0;
  }

  void add() override {}
  void remove() override {}
  void restart() override {}

  std::function<void()> m_eventFunction;
};

#endif // MODELEVENT_HPP