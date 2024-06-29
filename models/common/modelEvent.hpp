/*************************************************************************
PURPOSE: ( TODO )
**************************************************************************/

#ifndef MODELEVENT_HPP
#define MODELEVENT_HPP

#include "sim_services/Executive/include/exec_proto.h"
#include "trick/Event.hh"
#include "trick/EventManager_c_intf.hh"
#include <functional>
#include <utility>

class ModelEvent : public Trick::Event {
public:
  void setEventFunction(std::function<void()> eventFunction) {
    m_eventFunction = std::move(eventFunction);
  }
  int process(long long) override {
    m_eventFunction();
    return 0;
  }
  void add() override {}
  void remove() override {}
  void restart() override {}

  void setTriggerTime(double time) {
    std::cout << "Trigger Entered @ " << exec_get_time_tics() << std::endl;
    set_next_tics(time * 1000000);
  }

private:
  std::function<void()> m_eventFunction;
};

#endif // MODELEVENT_HPP