/*************************************************************************
PURPOSE: ( The Root of all models. This model is a container of all other models. )
LIBRARY DEPENDENCIES:
    ((root.o))
PROGRAMMERS:
    (((Yusuf Can Anar) (Turkish Aerospace) (09 July 2024))
     ((Renda Yigit) (Turkish Aerospace) (09 July 2024)))
**************************************************************************/

#include "root.hpp"
#include "common/client.hpp"
#include <iostream>

Root::Root() : modelX(new ModelX()), modelY(new ModelY()) {
  std::cout << "Root object created \t\t\t\t@ " << exec_get_sim_time() << std::endl;
};

int Root::default_data() {
  std::cout << "Default Data Entered \t\t\t\t@ " << exec_get_sim_time() << std::endl;
  return 0;
}

int Root::init() {
  std::cout << "Initialization Entered \t\t\t\t@ " << exec_get_sim_time() << std::endl;

  // Connection establishment must done after all models including root are instantiated.
  modelX->establishConnections();

  Client::getInstance().connect("127.0.0.1", "1234");
  Client::getInstance().transmit("Deneme Mesaji");

  return 0;
}

int Root::scheduled() {
  std::cout << "Scheduled Entered \t\t\t\t@ " << exec_get_sim_time() << std::endl;

  Client::getInstance().transmit(std::to_string(exec_get_sim_time()));

  return 0;
}

int Root::shutdown() {
  std::cout << "Shutdown Entered \t\t\t\t@ " << exec_get_sim_time() << std::endl;
  return 0;
}