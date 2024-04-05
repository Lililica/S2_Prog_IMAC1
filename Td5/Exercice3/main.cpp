#include <iostream>
#include <vector>
#include <unordered_map>
#include <vector>

enum class CardKind {
    Heart = 0,
    Diamond = 13,
    Club = 26,
    Spade = 39,
};

enum class CardValue {
    Two=1,
    Three=2,
    Four=3,
    Five=4,
    Six=5,
    Seven=6,
    Eight=7,
    Nine=8,
    Ten=9,
    Jack=10,
    Queen=11,
    King=12,
    Ace=0,
};

struct Card {
    CardKind kind;
    CardValue value;
    int hash() const;
};

int Card::hash() const{
    return int(value) + int(kind);
}

bool operator==(Card const& a, Card const& b) {
    return a.kind == b.kind && a.value == b.value;
}

namespace std {
    template<>
    struct hash<Card> {
        size_t operator()(Card const& card) const {
            return card.hash();
        }
    };
}


std::vector<Card> get_cards(size_t const size) {
    std::vector<Card> cards;
    cards.reserve(size);
    for (size_t i {0}; i < size; ++i) {
        Card card{static_cast<CardKind>((rand() % 4) * 13), static_cast<CardValue>(rand() % 13)};
        cards.push_back(card);
    }
    return cards;
}


std::string card_name(Card const& card) {
    std::string name {};

    unsigned int card_value {(static_cast<unsigned int>(card.value)+2) % 14};

    if (card_value < 10) {
        name += '0' + card_value;
    }else if (card_value == 10) {
        name += "10";
    }else if (card_value == 11) {
        name += 'V';
    }else if (card_value == 12) {
        name += 'Q';
    }else if (card_value == 13) {
        name += 'K';
    }

    name += " of ";

    if (card.kind == CardKind::Heart) {
        name += "Heart";
    }else if (card.kind == CardKind::Diamond) {
        name += "Diamond";
    }else if (card.kind == CardKind::Club) {
        name += "Club";
    }else if (card.kind == CardKind::Spade) {
        name += "Spade";
    }
    return name;
}

int main(){

    Card myCard {CardKind::Diamond, CardValue::Jack};

    std::cout << myCard.hash() << std::endl;

    std::vector<Card> listOfRandomCard {get_cards(100)};

    std::unordered_map<Card, int> nbrOfCard;

    for(Card card : listOfRandomCard){
        nbrOfCard[card] += 1;
    }

    for(std::unordered_map<Card, int>::const_iterator it{nbrOfCard.begin()}; it != nbrOfCard.end(); ++it){
        std::cout << card_name(it->first) << std::endl;
    }

    return 0;
}