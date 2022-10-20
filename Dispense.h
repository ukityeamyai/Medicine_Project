#ifndef PROJECT_DISPENSE_H
#define PROJECT_DISPENSE_H
#include "Storage.h"

class Dispense {
private:
    Storage storage;
    Node *head_circulation;
    Node *tail_circulation;
    int count_circulation;
public:
    Dispense();
    int string_to_int(string str);
    void set_storage(Storage storage);
    void bubble_sort_ascending();
    bool check_type_name(int type, string name);
    bool check_amount(int type, string name,int amount);
    void dispense();
    string date();
    string comma(int amount);
    string modify_type(string type);

    
    void dispense_amount(int type, string name, int amount);
    void update_storage();
    void save_circulation(int type, string name, int amount);


    void add(int type, string name, int amount,int price,string date);
    void read_circulation();
    void circulation();

};


#endif //PROJECT_DISPENSE_H