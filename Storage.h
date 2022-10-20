#ifndef PROJECT_STORAGE_H
#define PROJECT_STORAGE_H
#include "Lot.h"
#include <fstream>
#include <iomanip>
#include <limits>

class Storage {
private:
    Lot obj_lot;
public:
    void set_lot(Lot lot);
    Node *get_head();
    Node *get_tail();
    int get_count();
};


#endif //PROJECT_STORAGE_H