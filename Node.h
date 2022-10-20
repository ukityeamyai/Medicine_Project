

#ifndef PROJECT_NODE_H
#define PROJECT_NODE_H
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int lot_number, amount, volume, price, type;
    string name, mfg, exp;
    Node *link_lot;

    string day_mfg, month_mfg, year_mfg;
    string day_exp, month_exp, year_exp;
    string date;
    Node *link_circulation;
public:
    Node(int lot_number, int type, string name, int amount, int volume, string mfg, string exp, int price);

    Node(int type, string name, int amount,int price,string date);
};


#endif //PROJECT_NODE_H
