//
// Created by Acer on 18/10/2565.
//

#ifndef PROJECT_MEDICINE_H
#define PROJECT_MEDICINE_H
#include <iostream>
#include <string>

using namespace std;

class Medicine {
private:
    int type, price;
    string name;
public:
    Medicine();
    void set_type(int type);
    void set_name(string name);
    void set_price(int price);
};


#endif //PROJECT_MEDICINE_H
