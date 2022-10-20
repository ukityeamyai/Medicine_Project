//
// Created by Acer on 18/10/2565.
//

#include "Node.h"
Node::Node(int lot_number, int type, string name, int amount, int volume, string mfg, string exp, int price) {
    this->lot_number = lot_number;
    this->type = type;
    this->name = name;
    this->amount = amount;
    this->volume = volume;
    this->mfg = mfg;
    this->exp = exp;
    this->price = price;
    this->link_lot = NULL;
}

Node::Node(int type, string name, int amount,int price,string date) {
    this->type = type;
    this->name = name;
    this->amount = amount;
    this->price = price;
    this->date = date;
    this->link_circulation = NULL;
}