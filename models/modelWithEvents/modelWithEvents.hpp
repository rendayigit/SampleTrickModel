/*************************************************************************
PURPOSE: ( A sample trick model to demonstrate events. )
**************************************************************************/
#pragma once

#include "common/modelEvent.hpp"

class ModelWithEvents {
public:
  ModelWithEvents();

  /**
   * Create a one shot event.
   */
  void createOneShotEvent();

  /**
   * Create a scheduled event.
   */
  void createScheduledEvent();

private:
  ModelEvent *m_oneShotEvent;
  ModelEvent *m_scheduledEvent;
};