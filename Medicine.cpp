

#include "Medicine.h"
Medicine::Medicine() {
    this->type = 0;
    this->name = "";
    this->price = 0;
}

void Medicine::set_type(int type) {
    this->type = type;
}

void Medicine::set_name(string name) {
    this->name = name;
}

void Medicine::set_price(int price) {
    this->price = price;
}