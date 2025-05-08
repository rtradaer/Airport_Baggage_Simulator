#include "passenger.h"

Passenger::Passenger(int ID)
{
    this->ID = ID;
}

int Passenger::get_ID() const
{
    return this->ID;
}


std::ostream& operator<<(std::ostream& os, const Passenger& p)
{
    os << "Passenger ID: " << p.ID;
    return os;
}
