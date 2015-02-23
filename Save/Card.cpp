#include "Card.hh"
#include "Engine.hh"

const	sf::Color	Card::ColorClan[5] = {sf::Color::Blue, sf::Color::Red,
					      sf::Color::Magenta, sf::Color::Green,
					      sf::Color::Cyan};

Card::Card(Engine *engine, Clan clan) : _engine(engine),
					_picture(0),
					_backCard(0),
					_name(""),
					_unitValue(0),
					_groupeValue(0),
					_clan(clan),
					_rectCard(sf::Vector2f(200, 300)),
					_x(0),
					_y(0),
					_front(false)
{
  _rectCard.setFillColor(Card::ColorClan[_clan]);
  _backCard = new Stikers(_engine->getRender(), 0, 0, 0, 200, 300);
}

Card::~Card()
{
  delete (_picture);
  delete (_backCard);
}

std::string		Card::getClanName() const
{
  switch(_clan)
    {
    case 0 :
      return ("Igvar");
      break;
    case 1 :
      return ("Shadow");
      break;
    case 2 :
      return ("Krion");
      break;
    case 3 :
      return ("Starn");
      break;
    case 4 :
      return ("Zarron");
      break;
    default :
      return ("");
    }
}

std::string		Card::getName() const
{
  return (_name);
}

void			Card::setPosition(std::size_t x, std::size_t y)
{
  _x = x;
  _y = y;
  _rectCard.setPosition(_x, _y);
  _picture->setPosition(_x + 5, _y + 5);
  _backCard->setPosition(_x, _y);
}

void			Card::drawCard()
{
  _engine->getRender()->draw(_rectCard);
  if (_front)
    _engine->getRender()->draw(*_picture);
}

bool			Card::clickOn(std::size_t x, std::size_t y)
{
  return (_backCard->isClicked(x, y));
}

void			Card::flip(bool a)
{
  _front = a;
}
