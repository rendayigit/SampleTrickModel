#include <iostream>
#include <string>
#include <zmq.hpp>

class Client {
public:
  static Client &getInstance() {
    static Client instance;
    return instance;
  };

  void connect(const std::string &ip, const std::string &port) {
    try {
      m_socket.connect("tcp://" + ip + ":" + port);
    } catch (const zmq::error_t &e) {
      std::cout << "Zmq Connect Error: " << e.what() << std::endl;
    }
  }

  void transmit(const std::string &message) {
    try {
      m_socket.send(zmq::buffer(message + "\n"), zmq::send_flags::none);
    } catch (const zmq::error_t &e) {
      std::cout << "Zmq Transmit Error: " << e.what() << std::endl;
    }
  }

private:
  Client() : m_context(1), m_socket(m_context, zmq::socket_type::pair) {}
//   Client() : m_context(1), m_socket(m_context, zmq::socket_type::req) {}
  zmq::context_t m_context;
  zmq::socket_t m_socket;
};