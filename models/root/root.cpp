#include "root.hpp"
#include <iostream>
#include <string>

Root::Root()
    : modelX(new ModelX), modelY(new ModelY), modelWithLoad(new ModelWithLoad),
      modelWithEvents(new ModelWithEvents), modelDummy(new ModelDummy), server(new Server(3310)),
      client1(new Client), client2(new Client) {
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

  // Start a TCP server.
  server->start();

  // Connect a client to the TCP server and transmit a test message.
  client1->connect("127.0.0.1", 3310);
  client1->transmit("Test Message!\n");

  // Connect another client to the TCP server and transmit a test message.
  client2->connect("127.0.0.1", 3310);
  client2->transmit("Test Message 2!\n");

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

  client1->transmit(std::to_string(exec_get_sim_time()) + "\n");

  // Transmit the number of connected clients.
  std::cout << "Online : " << server->getClients().size() << std::endl;

  // Broadcast a message to all connected clients.
  server->broadcast("May the force be with you all clients");

  return 0;
}

int Root::shutdown() {
  std::cout << "Shutdown Entered \t\t\t\t@ " << exec_get_sim_time() << std::endl;
  client1->disconnect();
  client2->disconnect();
  server->stop();
  return 0;
}