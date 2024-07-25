/*************************************************************************
PURPOSE: ( A service that allows the usage of loads that use power and dissipate heat. )
PROGRAMMERS:
    ((Renda Yiğit) (Turkish Aerospace) (24 July 2024))
**************************************************************************/
#ifndef LOAD_HPP
#define LOAD_HPP

#include <string>
#include <utility>

class Load {
public:
  explicit Load(std::string configurationFile, std::string configurationItem)
      : m_configurationFile(std::move(configurationFile)),
        m_configurationItem(std::move(configurationItem)) {
    // TODO(renda): read configuration file to get the consumption and dissipation values and call
    // populateLoadConfigurations() with the values read from this file.
  }

protected:
  double m_maxCurrentConsumption{5.5}; /* A    Max Current Consumption */ // TODO (renda): set to 0.0
  double m_maxVoltageConsumption{};    /* V    Max Voltage Consumption */
  double m_maxHeatDissipation{};       /* W    Max Heat Dissipation */
  double m_minCurrentConsumption{};    /* A    Min Current Consumption */
  double m_minVoltageConsumption{};    /* V    Min Voltage Consumption */
  double m_minHeatDissipation{};       /* W    Min Heat Dissipation */
  double m_activeCurrentConsumption{}; /* A    Active Current Consumption */
  double m_activeVoltageConsumption{}; /* V    Active Voltage Consumption */
  double m_activeHeatDissipation{};    /* W    Active Heat Dissipation */

private:
  /**
   * Populate the consumption and dissipation max and min values.
   */
  void populateLoadConfigurations(double maxCurrentConsumption, double maxVoltageConsumption,
                                  double maxHeatDissipation, double minCurrentConsumption,
                                  double minVoltageConsumption, double minHeatDissipation,
                                  double activeCurrentConsumption, double activeVoltageConsumption,
                                  double activeHeatDissipation) {
    m_maxCurrentConsumption = maxCurrentConsumption;
    m_maxVoltageConsumption = maxVoltageConsumption;
    m_maxHeatDissipation = maxHeatDissipation;
    m_minCurrentConsumption = minCurrentConsumption;
    m_minVoltageConsumption = minVoltageConsumption;
    m_minHeatDissipation = minHeatDissipation;
    m_activeCurrentConsumption = activeCurrentConsumption;
    m_activeVoltageConsumption = activeVoltageConsumption;
    m_activeHeatDissipation = activeHeatDissipation;
  }

  std::string m_configurationFile;
  std::string m_configurationItem;
};

#endif // LOAD_HPP