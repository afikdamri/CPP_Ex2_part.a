#ifndef CARD_HPP
#define CARD_HPP

#include <string>

namespace ariel{

    class Card {
    private:
        std::string suit; // stores the suit of the card (e.g. "hearts", "spades")
        std::string rank; // stores the rank of the card (e.g. "ace", "king", "queen", "jack", "10", "9", ...)
    public:
        Card(std::string cardSuit, std::string cardRand);
        ~Card();
//      std::string getSuit() const;
//      std::string getRank() const;
//      std::string getName() const;
//      int getValue() const;
//      bool operator<(const Card& other) const;
//      bool operator==(const Card& other) const;
    };

}

#endif // CARD_HPP
