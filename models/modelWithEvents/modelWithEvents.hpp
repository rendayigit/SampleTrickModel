/*************************************************************************
PURPOSE: ( A sample trick model to demonstrate events. )
PROGRAMMERS:
    ((Renda Yiğit) (Turkish Aerospace) (24 July 2024))
**************************************************************************/
#ifndef MODELWITHEVENTS_HPP
#define MODELWITHEVENTS_HPP

class ModelWithEvents {
public:
  /**
   * Create a one shot event.
   */
  void createOneShotEvent();

  /**
   * Create a scheduled event.
   */
  void createScheduledEvent();
};

#endif // MODELWITHEVENTS_HPP