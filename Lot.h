

#ifndef PROJECT_LOT_H
#define PROJECT_LOT_H
#include "Medicine.h"
#include "Node.h"
#include <iomanip>
#include <limits>
#include <ctime>
#include <fstream>
#include <sstream>

class Lot {
private:
    Medicine medicine;
    int amount_medicine;
    int volume_medicine;
    string mfg;
    string exp;
    int med_lot;
    int count_medicine;
    Node *head_medicine;
    Node *tail_medicine;
public:
    Lot();
    int string_to_int(string str);
    void read_medicine();
    void add(int lot_number, int type, string name, int amount, int volume, string mfg, string exp, int price);

    void set_med_lot(int med_lot);
    void set_amount_medicine(int amount_medicine);
    void set_volume_medicine(int volume_medicine);
    void set_mfg(string mfg);
    void set_exp(string exp);

    void add_medicine();
    void save_medicine();

    void edit_medicine();
    bool check_lot(int lot_umber, int type, string name, int volume, string mfg, string exp);
    void edit_name(int lot_umber,int type, string name);
    void edit_amount(int lot_umber,int type, string name);
    void edit_mfg_ade_exp(int lot_umber,int type, string name);

    Node *get_head();
    Node *get_tail();
    int get_count();
};


#endif //PROJECT_LOT_H
