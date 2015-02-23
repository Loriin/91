#ifndef DECK_HH_
#define DECK_HH_

#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <SFML/Network.hpp>

class Deck
{
public:

typedef enum		eCardType
  {
    King = 0,
    Queen,
    Knigth,
    Clerc,
    Valet,
    Noble,
    Mage,
    None = 10
  }			CardType;

typedef enum		eCardClan
  {
    Igvar = 0,
    Shadow,
    Krion,
    Starn,
    Zarron,
    NoClan = 10
  }			CardClan;

typedef struct		sCard
{
  CardType		_type;
  CardClan		_clan;
}			Card;

public:
Deck();
~Deck();
  void			getCard(sf::Packet&);
  Card			makeCard(CardType, CardClan);
  void			addCard(CardClan);
  Card			popCard(); 
  void			pushCard(Deck::Card);
  void			check();
private:
  std::vector<Card>	_cards;
};

#endif
