#include "Storage.h"
void Storage::set_lot(Lot lot) {
    this->obj_lot = lot;
}

int Storage::get_count() {
    return this->obj_lot.get_count();
}

Node *Storage::get_head() {
    return this->obj_lot.get_head();
}

Node *Storage::get_tail() {
    return this->obj_lot.get_tail();
}