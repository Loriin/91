#include "Server.hh"

void		loop(Server *server)
{
  server->start();
}

void		toto()
{
  Server	server;
  sf::Thread	game(&Server::start, &server);
  std::string	str;

  game.launch();
  getline(std::cin, str);
  while (str != "close")
    getline(std::cin, str);
  server.terminate();
  game.terminate();
}

int		main()
{
  sf::Thread	nike(&toto);
  std::string	str;
  Server s;
  s.start();
  return (0);
  while (1)
    {
      nike.launch();
      std::cout << "Start" << std::endl;
      nike.wait();
      std::cout << "Restart O/n ?" << std::endl;
      getline(std::cin, str);
      if (str != "O")
	return (-1);
    }
  return (0);
}
