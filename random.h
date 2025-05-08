#ifndef RANDOM_H
#define RANDOM_H

#include <random>
#include "passenger.h"
#include <queue>
#include "linkedlist.h"

class Random {
public:
    static const std::string baggage_items[25];
    static const std::string baggage_items_dangerous[5];
    static std::queue<Passenger> PassengerQueue;
    static LinkedList blacklist;
    static const bool has_dangerous_item(Passenger pass);
    static const bool is_in_blacklist(const Passenger& pass);

    static int generate_number(int x, int y);

    static int generate_ID();

    static void generate_BaggageItem(Passenger& p, int item_count, int baggage_percent);

    static bool blacklist_dice(int percent);

    static void generate_passenger(int passenger_count, int blacklist_percent, int baggage_percent);

    static bool is_dangerous(const std::string &baggage_item);
};
#endif // RANDOM_H
