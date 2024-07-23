/*************************************************************************
PURPOSE: ( Tcp client )
PROGRAMMERS:
    (
      ((Yusuf Can Anar) (Turkish Aerospace) (09 July 2024))
      ((Renda Yigit) (Turkish Aerospace) (09 July 2024))
    )
**************************************************************************/
#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <boost/asio.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/read_until.hpp>
#include <boost/asio/streambuf.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <cstdint>
#include <iostream>

namespace io = boost::asio;
constexpr int RECEIVE_BUFFER_SIZE = 1024;

class Client {
public:
  Client();

  Client(const Client &) = delete;
  Client &operator=(const Client &) = delete;
  Client(Client &&) = delete;
  Client &operator=(Client &&) = delete;

  virtual ~Client();

  void connect(const std::string &serverAddress, uint16_t serverPort);

  void disconnect();

  bool isConnected();

  void transmit(const std::string &message);

  virtual void onConnect();

  virtual void onDisconnect();

  virtual void onReceive(const std::string &message);

private:
  void scheduleRead();

  void readHandler(const boost::system::error_code &errorCode);

  boost::asio::thread_pool m_ioThread;
  boost::asio::io_context m_ioContext;
  boost::asio::io_service::work m_ioWorker;
  boost::asio::ip::tcp::socket m_socket;
  boost::asio::streambuf m_buffer;
};

#endif // CLIENT_HPP
