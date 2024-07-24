/*************************************************************************
PURPOSE: ( A sample trick model to demonstrate loads. )
PROGRAMMERS:
    ((Renda Yiğit) (Turkish Aerospace) (24 July 2024))
**************************************************************************/
#include "modelWithLoad.hpp"

#include <iostream>

#include "sim_services/Executive/include/exec_proto.h"

ModelWithLoad::ModelWithLoad() : Load("myConfigurationFile", "ModelWithLoad"), m_state(OFF) {}

void ModelWithLoad::update() {
  switch (m_state) {
  case ON:
    m_activeCurrentConsumption = m_maxCurrentConsumption;
    m_activeVoltageConsumption = m_maxVoltageConsumption;
    m_activeHeatDissipation = m_maxHeatDissipation;
    break;
  case OFF:
    m_activeCurrentConsumption = m_minCurrentConsumption;
    m_activeVoltageConsumption = m_minVoltageConsumption;
    m_activeHeatDissipation = m_minHeatDissipation;
    break;
  }

  std::cout << "ModelWithLoad state: " << m_state
            << " current consumption: " << m_activeCurrentConsumption << std::endl;
}

void ModelWithLoad::turnOn() {
  if (m_state == ON) {
    return;
  }

  m_state = ON;

  update();
}

void ModelWithLoad::turnOff() {
  if (m_state == OFF) {
    return;
  }

  m_state = OFF;

  update();
}