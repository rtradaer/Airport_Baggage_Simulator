#include "random.h"

// baggage items
const std::string Random::baggage_items[25] = {
    "Clothes", "Shoes", "Books", "Charger", "Headphones",
    "Glasses", "Hat", "Scarf", "Gloves", "Socks",
    "Towel", "Toothbrush", "Toothpaste", "Shampoo", "Deodorant",
    "Comb", "Earplugs", "Umbrella", "Camera", "Pajamas",
    "Toy", "Diapers", "Vitamins", "Medicine","Notebook",
};

const std::string Random::baggage_items_dangerous[5] = {
    "Knife",
    "Large scissors (>7cm)",
    "Aerosol spray",
    "Gas container",
    "Screwdriver (>6cm)"
};

std::queue<Passenger> Random::PassengerQueue;
LinkedList Random::blacklist;


int Random::generate_number(int x, int y)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dist(x, y);

    int random_number = dist(gen);
    return random_number;
}

int Random::generate_ID()
{
    return generate_number(10000, 99999);
}

void Random::generate_BaggageItem(Passenger& p, int item_count, int baggage_percent)
{
    int random_number = generate_number(1, 100);
    if (random_number <= baggage_percent) {
        int dang_item_count_random = generate_number(1, item_count);
        for (int i = 0; i < dang_item_count_random; i++) {
            int random_index = generate_number(0, 4);
            std::string item = baggage_items_dangerous[random_index];
            p.add_baggage(item);
        }
        for (int i = 0; i < item_count - dang_item_count_random; i++) {
            int random_index = generate_number(0, 24);
            std::string item = baggage_items[random_index];
            p.add_baggage(item);
        }
        return;
    }

    // DEFAULT (NO DANGEROUS ITEM)
    for (int i = 0; i < item_count; i++) {
        int random_index = generate_number(0, 24);
        std::string item = baggage_items[random_index];
        p.add_baggage(item);
    }
}

bool Random::blacklist_dice(int percent)
{
    int random_number = generate_number(1, 100);
    if (random_number <= percent) { return true; }
    return false;
}

const bool Random::has_dangerous_item(Passenger pass)
{
    std::stack<std::string> temp = pass.baggage;

    while (!temp.empty()) {
        for (int i = 0; i < 5; i++) {
            if (temp.top() == baggage_items_dangerous[i]) { return true; }
        }
        temp.pop();
    }
    return false;
}

const bool Random::is_in_blacklist(const Passenger& pass)
{
    for (Node* temp = blacklist.get_head(); temp != nullptr; temp = temp->next) {
        if (temp->data == pass.get_ID()) {
            return true;
        }
    }
    return false;
}

void Random::generate_passenger(int passenger_count, int blacklist_percent, int baggage_percent)
{
    for (int i = 0; i < passenger_count; i++) {
        int item_count = generate_number(5, 10);
        int id = generate_ID();
        Passenger p(id);
        if (blacklist_dice(blacklist_percent)) {
            blacklist.insertAtTail(p.ID);
        }
        generate_BaggageItem(p, item_count, baggage_percent);
        PassengerQueue.push(p);
    }
}

bool Random::is_dangerous(const std::string& baggage_item)
{
    for (const auto& dangerous_item : baggage_items_dangerous) {
        if (baggage_item == dangerous_item) {
            return true;
        }
    }
    return false;
}
