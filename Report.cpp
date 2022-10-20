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

void Report::print_all_medicine() {
    bubble_sort_ascending();
    Node *tmp = this->obj_storage.get_head();
    int  count = this->obj_storage.get_count();
    int type;
    cout << "================= MEDICINE TYPE ==================" << endl;
    cout << left << setw(3) << "||" << "1.PILL" << setw(41) << right << "||" << endl;
    cout << left << setw(3) << "||" << "2.CREAM" << setw(40) << right << "||" << endl;
    cout << left << setw(3) << "||" << "3.LIQUID" << setw(39) << right << "||" << endl;
    cout << "==================================================" << endl;
    cout << "Type Medicine :";
    while (!(cin >> type)) {
        cin.clear();
        type:
        cout << "==================================================" << endl;
        cout << "||" << setw(38) << "Invalid information, try again." << setw(10) << right << "||" << endl;
        cout << "==================================================" << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Type Medicine :";
    }
    if (type > 3 || type < 0){
        goto type;
    }
    cout << "===============================================================================================" << endl;
    cout << "||" << setw(57) << "MEDICINE INFORMATION" << setw(36) << right << "||" << endl;
    cout << "===============================================================================================" << endl;
    cout << setw(3) << left << "||" << setw(9) << "TYPE"
         << setw(3) << left << "||" << setw(13)<< "NAME"
         << setw(3) << right << "||" << setw(7) << "AMOUNT";
    if (type == 1){
        cout << setw(3) << right << "||" << setw(4)<< "MG";
    }
    else if (type == 2 || type == 3){
        cout << setw(3) << right << "||" << setw(4)<< "ML";
    }
    cout << setw(4) << right << "||" << setw(8)<< "MFG"
         << setw(7) << right << "||" << setw(8) << "EXP"
         << setw(7) << right << "||" << setw(13) << "PRICE" << setw(3) << "||";
    cout << endl;
    cout << "===============================================================================================" << endl;
    for (int i = 0; i < count; i++) {
        if (tmp->type == type) {
            cout    << setw(3) << left << "||" << setw(9) << modify_type(to_string(tmp->type))
                    << setw(3) << left << "||" << setw(13)<< tmp->name
                    << setw(3) << right << "||" << setw(7) << comma(tmp->amount)
                    << setw(3) << right << "||" << setw(5)<< tmp->volume
                    << setw(3) << right << "||" << setw(3)<< tmp->day_mfg << " "
                    << modify_month(tmp->month_mfg)<< " " << tmp->year_mfg
                    << setw(3) << right << "||" << setw(3) << tmp->day_exp << " "
                    << modify_month(tmp->month_exp) << " " << tmp->year_exp
                    << setw(3) << right << "||" << setw(8) << comma(tmp->price) << " Bath"
                    << setw(3) << "||";
            cout << endl;
        }
        tmp = tmp->link_lot;
    }
    cout << "===============================================================================================" << endl;
}
void Report::notification_minimum() {
    bubble_sort_ascending();
    Node *tmp = this->obj_storage.get_head();
    int  count = this->obj_storage.get_count();
    cout << "=====================================================================================================" << endl;
    cout << "||" << setw(60) << "NOTIFICATION MINIMUM" << setw(39) << right << "||" << endl;
    cout << "=====================================================================================================" << endl;
    cout << setw(3) << left << "||" << setw(9) << "LOT"
         << setw(3) << left << "||" << setw(9) << "TYPE"
         << setw(3) << left << "||" << setw(15) << "NAME"
         << setw(3) << right << "||" << setw(10) << "AMOUNT"
         << setw(5) << right << "||" << setw(7) << "VOLUME"
         << setw(4) << right << "||" << setw(8) << "MFG"
         << setw(7) << right << "||" << setw(8) << "EXP" << setw(7) << "||" << endl;
    cout << "=====================================================================================================" << endl;
    for (int i = 0; i < count; i++) {
        if (tmp->type == 1) {
            if (tmp->amount < 20 && tmp->amount != 0) {
                cout << setw(3) << left << "||" << setw(9) << tmp->lot_number
                     << setw(3) << left << "||" << setw(9) << modify_type(to_string(tmp->type))
                     << setw(3) << left << "||" << setw(15) << tmp->name
                     << setw(3) << right << "||" << setw(10) << comma(tmp->amount)
                     << setw(5) << right << "||" << setw(7) << comma(tmp->volume)
                     << setw(4) << right << "||" << setw(3) << tmp->day_mfg << " "
                     << modify_month(tmp->month_mfg) << " " << tmp->year_mfg
                     << setw(3) << right << "||" << setw(3) << tmp->day_exp << " "
                     << modify_month(tmp->month_exp) << " " << tmp->year_exp
                     << setw(3) << "||";
                cout << endl;
            }
        } else if (tmp->type == 2){
            if (tmp->amount < 50 && tmp->amount != 0) {
                cout << setw(3) << left << "||" << setw(9) << tmp->lot_number
                    << setw(3) << left << "||" << setw(9) << modify_type(to_string(tmp->type))
                     << setw(3) << left << "||" << setw(15) << tmp->name
                     << setw(3) << right << "||" << setw(10) << comma(tmp->amount)
                     << setw(5) << right << "||" << setw(7) << comma(tmp->volume)
                     << setw(4) << right << "||" << setw(3) << tmp->day_mfg << " "
                     << modify_month(tmp->month_mfg) << " " << tmp->year_mfg
                     << setw(3) << right << "||" << setw(3) << tmp->day_exp << " "
                     << modify_month(tmp->month_exp) << " " << tmp->year_exp
                     << setw(3) << "||";
                cout << endl;
            }
        } else if (tmp->type == 3){
            if (tmp->amount < 30 && tmp->amount != 0) {
                cout << setw(3) << left << "||" << setw(9) << tmp->lot_number
                    << setw(3) << left << "||" << setw(9) << modify_type(to_string(tmp->type))
                     << setw(3) << left << "||" << setw(15) << tmp->name
                     << setw(3) << right << "||" << setw(10) << comma(tmp->amount)
                     << setw(5) << right << "||" << setw(7) << comma(tmp->volume)
                     << setw(4) << right << "||" << setw(3) << tmp->day_mfg << " "
                     << modify_month(tmp->month_mfg) << " " << tmp->year_mfg
                     << setw(3) << right << "||" << setw(3) << tmp->day_exp << " "
                     << modify_month(tmp->month_exp) << " " << tmp->year_exp
                     << setw(3) << "||";
                cout << endl;
            }
        }

        tmp = tmp->link_lot;
    }
    cout << "=====================================================================================================" << endl;
}














