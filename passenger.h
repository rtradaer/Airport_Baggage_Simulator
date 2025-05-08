#ifndef PASSENGER_H
#define PASSENGER_H

#include <iostream>
#include <vector>
#include <stack>

class Passenger {
private:
    int ID;
    std::stack<std::string> baggage;

public:
    Passenger(int ID);

    int get_ID() const;
    std::stack<std::string> get_baggage() const { return baggage; }
    void add_baggage(const std::string& item) { baggage.push(item); }

    friend std::ostream& operator<<(std::ostream& os, const Passenger& p);
    friend class Random;

};

#endif // PASSENGER_H
