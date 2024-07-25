/*************************************************************************
PURPOSE: ( The Root of all models. This model is a container of all other models. )
PROGRAMMERS:
    (((Yusuf Can Anar) (Turkish Aerospace) (09 July 2024))
     ((Renda Yigit) (Turkish Aerospace) (09 July 2024)))
**************************************************************************/

#include "root.hpp"
#include "common/network/client/client.hpp"
#include "common/network/server/server.hpp"

#include <iostream>
#include <string>

auto *server = new Server(3310);
auto *client = new Client();

Root::Root()
    : modelX(new ModelX), modelY(new ModelY), modelWithLoad(new ModelWithLoad),
      modelWithEvents(new ModelWithEvents), modelDummy(new ModelDummy) {
  std::cout << "Root object created \t\t\t\t@ " << exec_get_sim_time() << std::endl;
};

int Root::default_data() {
  std::cout << "Default Data Entered \t\t\t\t@ " << exec_get_sim_time() << std::endl;
  return 0;
}

int Root::init() {
  std::cout << "Initialization Entered \t\t\t\t@ " << exec_get_sim_time() << std::endl;

  // Create a one shot event.
  modelWithEvents->createOneShotEvent();

  // Create a scheduled event.
  modelWithEvents->createScheduledEvent();

  // Connection establishment must done after all models including root are instantiated.
  modelX->establishConnections();

  // start TCP server
  server->start();

  // connect client to the open TCP server
  client->connect("127.0.0.1", 3310);
  client->transmit("Deneme!\n");

  return 0;
}

int Root::scheduled() {
  std::cout << "Scheduled Entered \t\t\t\t@ " << exec_get_sim_time() << std::endl;

  /* Models that are loads can be controled similar to this way */
  if (modelWithLoad->getState() == ModelWithLoad::ON) {
    modelWithLoad->turnOff();
  } else {
    modelWithLoad->turnOn();
  }

  client->transmit(std::to_string(exec_get_sim_time()) + "\n");

  // Show how many clients are online( connected )
  std::cout << "Online : " << server->getClients().size() << std::endl;

  server->broadcast("May the force be with you all clients");

  return 0;
}

int Root::shutdown() {
  std::cout << "Shutdown Entered \t\t\t\t@ " << exec_get_sim_time() << std::endl;
  client->disconnect();
  server->stop();
  return 0;
}