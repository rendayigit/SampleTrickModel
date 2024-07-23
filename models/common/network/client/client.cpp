#include "client.hpp"

Client::Client() : m_ioThread(1), m_ioWorker(m_ioContext), m_socket(m_ioContext) {}

Client::~Client() {
  if (not m_ioContext.stopped()) {
    m_ioContext.stop();
  }

  m_ioThread.join();
}

void Client::connect(const std::string &serverAddress, uint16_t serverPort) {
  if (isConnected()) {
    std::cerr << "Failed to connect: Already connected to server" << '\n';
    return;
  }

  post(m_ioThread, [this]() { m_ioContext.run(); });

  io::ip::tcp::resolver resolver(m_ioContext);
  io::ip::tcp::resolver::query query(serverAddress, std::to_string(serverPort));
  boost::system::error_code errorCode;

  io::connect(m_socket, resolver.resolve(query), errorCode);

  if (not errorCode) {
    onConnect();
    scheduleRead();
  } else {
    std::cerr << "Failed to connect: " << errorCode.message() << '\n';

    if (isConnected()) {
      m_socket.close();
    }
  }
}
