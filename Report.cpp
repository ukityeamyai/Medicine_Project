#include "Report.h"
void Report::set_storage(Storage storage) {
    this->obj_storage = storage;
}


string Report::comma(int amount) {
    string amount_s;
    string a = to_string(amount);
    if (a != "-") {
        if (a.length() <= 3) {
            amount_s = a;
        } else if (a.length() == 4) {
            amount_s = a.insert(1, ",");

        } else if (a.length() == 5) {
            amount_s = a.insert(2, ",");

        } else if (a.length() == 6) {
            amount_s = a.insert(3, ",");

        } else if (a.length() == 7) {
            amount_s = a.insert(1, ",");
            amount_s = a.insert(5, ",");

        } else if (a.length() == 8) {
            amount_s = a.insert(2, ",");
            amount_s = a.insert(6, ",");
        }
    }
    return amount_s;
}

string Report::modify_type(string type) {
    if (type == "1"){
        type = "PILL";
    } else if (type == "2"){
        type = "CREAM";
    } else if (type == "3"){
        type = "LIQUID";
    }
    return type;
}

void Report::modify_month_mfg() {
    Node *tmp = this->obj_storage.get_head();
    int  count = this->obj_storage.get_count();
    for (int i = 0; i < count ; i++) {
        tmp->day_mfg = tmp->mfg.substr(0, tmp->mfg.find('/'));
        tmp->mfg.erase(0, tmp->mfg.find('/') + 1);

        tmp->month_mfg = tmp->mfg.substr(0, tmp->mfg.find('/'));
        tmp->mfg.erase(0, tmp->mfg.find('/') + 1);

        tmp->year_mfg = tmp->mfg.substr(0, tmp->mfg.find('/'));
        tmp->mfg.erase(0, tmp->mfg.find('/') + 1);

        tmp->mfg = tmp->day_mfg+"/"+tmp->month_mfg+"/"+tmp->year_mfg;
        tmp = tmp->link_lot;
    }
}

void Report::modify_month_exp() {
    Node *tmp = this->obj_storage.get_head();
    int  count = this->obj_storage.get_count();
    for (int i = 0; i < count ; i++) {
        tmp->day_exp = tmp->exp.substr(0, tmp->exp.find('/'));
        tmp->exp.erase(0, tmp->exp.find('/') + 1);

        tmp->month_exp = tmp->exp.substr(0, tmp->exp.find('/'));
        tmp->exp.erase(0, tmp->exp.find('/') + 1);

        tmp->year_exp = tmp->exp.substr(0, tmp->exp.find('/'));
        tmp->exp.erase(0, tmp->exp.find('/') + 1);

        tmp->exp = tmp->day_exp+"/"+tmp->month_exp+"/"+tmp->year_exp;
        tmp = tmp->link_lot;
    }
}

string Report::modify_month(string month) {
    if (month == "1") {
        month = "Jan";
    } else if (month == "2") {
        month = "Feb";
    } else if (month == "3") {
        month = "Mar";
    } else if (month == "4") {
        month = "Apr";
    } else if (month == "5") {
        month = "May";
    } else if (month == "6") {
        month = "Jun";
    } else if (month == "7") {
        month = "Jul";
    } else if (month == "8") {
        month = "Aug";
    } else if (month == "9") {
        month = "Sep";
    } else if (month == "10") {
        month = "Oct";
    } else if (month == "11") {
        month = "Nov";
    } else if (month == "12") {
        month = "Dec";
    }
    return month;
}

void Report::bubble_sort_ascending() {
    int  count = this->obj_storage.get_count();
    Node *head = this->obj_storage.get_head();
    for (int i = 0; i < count; i++) {
        Node *ptmp = NULL;
        Node *tmp = this->obj_storage.get_head();
        while (tmp->link_lot != NULL){
            if (tmp->lot_number > tmp->link_lot->lot_number){
                if (ptmp == NULL){
                    Node *x = tmp->link_lot;
                    tmp->link_lot = x->link_lot;
                    x->link_lot = tmp;
                    ptmp = x;
                    head = ptmp;
                } else{
                    Node *x = tmp->link_lot;
                    ptmp->link_lot = x;
                    tmp->link_lot = x->link_lot;
                    x->link_lot = tmp;
                    ptmp = x;
                }
            } else{
                ptmp = tmp;
                tmp = tmp->link_lot;
            }
        }
    }
}

