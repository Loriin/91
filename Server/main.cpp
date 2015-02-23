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

  while (1)
    {
      nike.launch();
      std::cout << "Start" << std::endl;
      nike.wait();
    }
  return (0);
}
