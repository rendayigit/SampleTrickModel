/*************************************************************************
PURPOSE: ( TODO )
PROGRAMMERS:
    (((Renda Yiğit) (Turkish Aerospace) (01 July 2024)
**************************************************************************/

#ifndef MODELEVENT_HH
#define MODELEVENT_HH

#include "trick/Event.hh"
#include "trick/EventManager_c_intf.hh"
#include <functional>
#include <utility>

class ModelEvent : public Trick::Event {
public:
  void setEventFunction(std::function<void()> eventFunction) {
    m_eventFunction = std::move(eventFunction);
  }

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

#endif // MODELEVENT_HH