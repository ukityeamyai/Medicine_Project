//
// Created by Acer on 18/10/2565.
//

#include "Lot.h"
Lot::Lot() {
    this->med_lot = 0;
    this->amount_medicine = 0;
    this->volume_medicine = 0;
    this->mfg = "";
    this->exp = "";
    this->count_medicine = 0;
    this->head_medicine = NULL;
    this->tail_medicine = NULL;
}

int Lot::string_to_int(string str) {
    stringstream ss;
    ss << str;
    int int_num;
    ss >> int_num;
    return int_num;
}

void Lot::add(int lot_number, int type, string name, int amount, int volume, string mfg, string exp, int price) {
    Node *tmp = new Node(lot_number,type,name,amount,volume,mfg,exp,price);
    tmp->lot_number = lot_number;
    tmp->type = type;
    tmp->name = name;
    tmp->amount = amount;
    tmp->volume = volume;
    tmp->mfg = mfg;
    tmp->exp = exp;
    tmp->price = price;
    if (count_medicine == 0){
        tmp->link_lot = NULL;
        head_medicine = tmp;
        tail_medicine = tmp;
    } else {
        tmp->link_lot = NULL;
        tail_medicine->link_lot = tmp;
        tail_medicine = tail_medicine->link_lot;
    }
    count_medicine++;
}

void Lot::read_medicine() {
    int type, amount, volume, price, lot_number;
    string name, mfg, exp,line;
    ifstream myFile;
    myFile.open("storage.txt",ios::in);
    if (myFile.fail()){
        cout << "==================================" << endl;
        cout << setw(24) << "Can't open file" << endl;
        cout << "==================================" << endl;
    } else{
        while (getline(myFile,line)){
            lot_number = string_to_int(line.substr(0,','));
            line.erase(0,line.find(',') + 1);

            type = string_to_int(line.substr(0,','));
            line.erase(0,line.find(',') + 1);

            name = line.substr(0,line.find(','));
            line.erase(0,line.find(',') + 1);

            amount = string_to_int(line.substr(0,','));
            line.erase(0,line.find(',') + 1);

            volume = string_to_int(line.substr(0,','));
            line.erase(0,line.find(',') + 1);

            mfg = line.substr(0,line.find(','));
            line.erase(0,line.find(',') + 1);

            exp = line.substr(0,line.find(','));
            line.erase(0,line.find(',') + 1);

            price = string_to_int(line.substr(0,','));
            line.erase(0,line.find(',') + 1);

            add(lot_number,type,name,amount,volume,mfg,exp,price);
        }
    }
    myFile.close();
}


void Lot::set_med_lot(int med_lot) {
    this->med_lot = med_lot;
}

void Lot::set_amount_medicine(int amount_medicine) {
    this->amount_medicine = amount_medicine;
}

void Lot::set_volume_medicine(int volume_medicine) {
    this->volume_medicine = volume_medicine;
}


void Lot::set_mfg(string mfg) {
    this->mfg = mfg;
}

void Lot::set_exp(string exp) {
    this->exp = exp;
}


void Lot::add_medicine() {
    int count, lot_number, type, amount, volume,price,year;
    int  day_mfg, month_mfg, year_mfg, day_exp, month_exp, year_exp;
    string name , mfg, exp;

    time_t now = time(0);
    tm *ltm = localtime(&now);
    year = 1900 + ltm->tm_year;

    cout << "Lot_id :";
    while (!(cin >> lot_number)) {
        cin.clear();
        cout << "==================================================" << endl;
        cout << "||" << setw(38) << "Invalid information, try again." << setw(10) << right << "||" << endl;
        cout << "==================================================" << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Lot_id :";
    }

    cout << "Amount of Medicine in Lot :";
    while (!(cin >> count)) {
        cin.clear();
        cout << "==================================================" << endl;
        cout << "||" << setw(38) << "Invalid information, try again." << setw(10) << right << "||" << endl;
        cout << "==================================================" << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Amount of Medicine in Lot :";
    }


    for (int i = 0; i < count; i++) {
        cout << "Medicine at [" << i+1 << "] in lot" << endl;
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
            cout << "Select Menu:";
        }
        if (type > 3 || type < 1){
            goto type;
        }

        cout << "Medicine Name :";
        cin >> name;

        cout << "Amount :";
        while (!(cin >> amount)) {
            cin.clear();
            amount:
            cout << "==================================================" << endl;
            cout << "||" << setw(38) << "Invalid information, try again." << setw(10) << right << "||" << endl;
            cout << "==================================================" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Amount :";
        }
        if (amount < 0) {
            goto amount;
        }

        cout << "Volume :";
        while (!(cin >> volume)) {
            cin.clear();
            volume:
            cout << "==================================================" << endl;
            cout << "||" << setw(38) << "Invalid information, try again." << setw(10) << right << "||" << endl;
            cout << "==================================================" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Volume :";
        }
        if (volume <= 0) {
            goto volume;
        }

        cout << "Manufacturing Date (MFG) :";
        while (!(cin >> day_mfg >> month_mfg >> year_mfg)) {
            cin.clear();
            mfg:
            cout << "==================================================" << endl;
            cout << "||" << setw(38) << "Invalid information, try again." << setw(10) << right << "||" << endl;
            cout << "==================================================" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Manufacturing Date (MFG) :";
        }
        if (day_mfg > 31 || day_mfg < 1){goto mfg;}
        if (month_mfg > 12 || month_mfg < 1){goto mfg;}
        if (year_mfg > year || year_mfg < year - 2){goto mfg;}
        mfg = to_string(day_mfg)+"/"+ to_string(month_mfg)+"/"+ to_string(year_mfg);

        cout << "Expiration Date (EXP) :";
        while (!(cin >> day_exp >> month_exp >> year_exp)) {
            cin.clear();
            exp:
            cout << "==================================================" << endl;
            cout << "||" << setw(38) << "Invalid information, try again." << setw(10) << right << "||" << endl;
            cout << "==================================================" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Expiration Date (EXP) :";
        }
        if (day_exp > 31 || day_exp < 1){goto exp;}
        if (month_exp > 12 || month_exp < 1){goto exp;}
        if (month_exp > 12 || month_exp < 1){goto exp;}
        if (year_exp > year + 2 || year_exp <  year ){goto exp;}
        if (month_mfg > month_exp && year_mfg > year_exp) {goto exp;}
        if (year_mfg > year_exp) {goto exp;}
        exp = to_string(day_exp)+"/"+ to_string(month_exp)+"/"+ to_string(year_exp);

        cout << "Price :";
        while (!(cin >> price)) {
            cin.clear();
            cout << "==================================================" << endl;
            cout << "||" << setw(38) << "Invalid information, try again." << setw(10) << right << "||" << endl;
            cout << "==================================================" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Price :";
        }

        set_med_lot(lot_number);
        medicine.set_type(type);
        medicine.set_name(name);
        set_amount_medicine(amount);
        set_volume_medicine(volume);
        set_mfg(mfg);
        set_exp(exp);
        medicine.set_price(price);
        add(lot_number,type,name,amount,volume,mfg,exp,price);
        cout << "==================================================" << endl;
    }
    cout << "                      Add Finsh                   " << endl;
    cout << "==================================================" << endl;
    save_medicine();
}

void Lot::save_medicine() {
    Node *tmp = head_medicine;
    ofstream myFile("storage.txt",ios::out);
    if (myFile.is_open()){
        for (int i = 0; i < count_medicine; i++) {
            myFile << tmp->lot_number << ","
                << tmp->type << ","
                << tmp->name << ","
                << tmp->amount << ","
                << tmp->volume << ","
                << tmp->mfg << ","
                << tmp->exp << ","
                << tmp->price<< endl;
            tmp = tmp->link_lot;
        }
    }
    myFile.close();
}


bool Lot::check_lot(int lot_umber, int type, string name, int volume, string mfg, string exp) {
    Node *tmp = head_medicine;
    while (tmp != NULL) {
        if (tmp->lot_number == lot_umber && tmp->type == type && tmp->name == name
        && tmp->volume == volume && tmp->mfg == mfg && tmp->exp == exp){
            return true;
        } else {
            tmp = tmp->link_lot;
        }
    }
    return false;
}

void Lot::edit_medicine() {
    Node *tmp = head_medicine;
    int count, lot_number, type, amount, volume,price,year;
    int  day_mfg, month_mfg, year_mfg, day_exp, month_exp, year_exp;
    string name , mfg, exp;

    time_t now = time(0);
    tm *ltm = localtime(&now);
    year = 1900 + ltm->tm_year;
    edit:
    cout << "Lot_id :";
    while (!(cin >> lot_number)) {
        cin.clear();
        cout << "==================================================" << endl;
        cout << "||" << setw(38) << "Invalid information, try again." << setw(10) << right << "||" << endl;
        cout << "==================================================" << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Lot_id :";
    }

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
        cout << "Select Menu:";
    }
    if (type > 3 || type < 1) {
        goto type;
    }

    cout << "Medicine Name :";
    cin >> name;

    cout << "Volume :";
    while (!(cin >> volume)) {
        cin.clear();
        volume:
        cout << "==================================================" << endl;
        cout << "||" << setw(38) << "Invalid information, try again." << setw(10) << right << "||" << endl;
        cout << "==================================================" << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Volume :";
    }
    if (volume <= 0) {
        goto volume;
    }

    cout << "Manufacturing Date (MFG) :";
    while (!(cin >> day_mfg >> month_mfg >> year_mfg)) {
        cin.clear();
        mfg:
        cout << "==================================================" << endl;
        cout << "||" << setw(38) << "Invalid information, try again." << setw(10) << right << "||" << endl;
        cout << "==================================================" << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Manufacturing Date (MFG) :";
    }
    if (day_mfg > 31 || day_mfg < 1){goto mfg;}
    if (month_mfg > 12 || month_mfg < 1){goto mfg;}
    if (year_mfg > year || year_mfg < year - 2){goto mfg;}
    mfg = to_string(day_mfg)+"/"+ to_string(month_mfg)+"/"+ to_string(year_mfg);

    cout << "Expiration Date (EXP) :";
    while (!(cin >> day_exp >> month_exp >> year_exp)) {
        cin.clear();
        exp:
        cout << "==================================================" << endl;
        cout << "||" << setw(38) << "Invalid information, try again." << setw(10) << right << "||" << endl;
        cout << "==================================================" << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Expiration Date (EXP) :";
    }
    if (day_exp > 31 || day_exp < 1){goto exp;}
    if (month_exp > 12 || month_exp < 1){goto exp;}
    if (month_exp > 12 || month_exp < 1){goto exp;}
    if (year_exp > year + 2 || year_exp <  year ){goto exp;}
    if (month_mfg > month_exp && year_mfg > year_exp) {goto exp;}
    if (year_mfg > year_exp) {goto exp;}
    exp = to_string(day_exp)+"/"+ to_string(month_exp)+"/"+ to_string(year_exp);

    if (check_lot(lot_number,type,name,volume,mfg,exp)){
        int menu_edit;
        cout << "==================================================" << endl;
        cout << "                   Edit Information               " << endl;
        cout << "==================================================" << endl;
        cout << left << setw(3) << "||" << "1.Edit Name" << setw(36) << right << "||" << endl;
        cout << left << setw(3) << "||" << "2.Edit Amount" << setw(34) << right << "||" << endl;
        cout << left << setw(3) << "||" << "3.Edit MFG AND EXP" << setw(29) << right << "||" << endl;
        cout << "==================================================" << endl;
        cout << "Select Menu :";
        while (!(cin >> menu_edit)) {
            cin.clear();
            menu:
            cout << "==================================================" << endl;
            cout << "||" << setw(38) << "Invalid information, try again." << setw(10) << right << "||" << endl;
            cout << "==================================================" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Select Menu :";
        }
            if (menu_edit > 3 || menu_edit < 1){goto menu;}
            if (menu_edit == 1){
                edit_name(lot_number,type,name);
            } else if (menu_edit == 2){
                edit_amount(lot_number,type,name);
            } else if (menu_edit == 3){
                edit_mfg_ade_exp(lot_number,type,name);
            }
    } else{
        cout << "==================================================" << endl;
        cout << "||" << setw(38) << "Invalid information, try again." << setw(10) << right << "||" << endl;
        cout << "==================================================" << endl;
        goto edit;
    }
}


void Lot::edit_name(int lot_umber,int type, string name) {
    Node *tmp = head_medicine;
    string new_name;
    for (int i = 0; i < count_medicine; i++) {
        if (tmp->lot_number == lot_umber && tmp->type == type && tmp->name == name){
            cout << "New Medicine Name :";
            cin >> new_name;
            tmp->name = new_name;
        }
        tmp = tmp->link_lot;
    }
    save_medicine();
}

void Lot::edit_amount(int lot_umber,int type, string name) {
    Node *tmp = head_medicine;
    int new_amount;
    for (int i = 0; i < count_medicine; i++) {
        if (tmp->lot_number == lot_umber && tmp->type == type && tmp->name == name){
            cout << "New Amount :";
            cin >> new_amount;
            tmp->amount = new_amount;
        }
        tmp = tmp->link_lot;
    }
    save_medicine();
}


void Lot::edit_mfg_ade_exp(int lot_umber, int type, string name) {
    Node *tmp = head_medicine;
    int day_mfg, day_exp, month_mfg, month_exp, year_mfg, year_exp;
    int year ;
    string new_mfg,  new_exp;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    year = 1900 + ltm->tm_year;
    for (int i = 0; i < count_medicine; i++) {
        if (tmp->lot_number == lot_umber && type == type && tmp->name == name){
            cout << "New Manufacturing Date (MFG) :";
            while (!(cin >> day_mfg >> month_mfg >> year_mfg)) {
                cin.clear();
                mfg:
                cout << "==================================================" << endl;
                cout << "||" << setw(38) << "Invalid information, try again." << setw(10) << right << "||" << endl;
                cout << "==================================================" << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "New Manufacturing Date (MFG) :";
            }
            if (day_mfg > 31 || day_mfg < 1){goto mfg;}
            if (month_mfg > 12 || month_mfg < 1){goto mfg;}
            if (year_mfg > year || year_mfg < year - 2){goto mfg;}
            new_mfg = to_string(day_mfg)+"/"+ to_string(month_mfg)+"/"+ to_string(year_mfg);

            cout << "New Expiration Date (EXP) :";
            while (!(cin >> day_exp >> month_exp >> year_exp)) {
                cin.clear();
                exp:
                cout << "==================================================" << endl;
                cout << "||" << setw(38) << "Invalid information, try again." << setw(10) << right << "||" << endl;
                cout << "==================================================" << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "New Expiration Date (EXP) :";
            }
            if (day_exp > 31 || day_exp < 1){goto exp;}
            if (month_exp > 12 || month_exp < 1){goto exp;}
            if (month_exp > 12 || month_exp < 1){goto exp;}
            if (year_exp > year + 2 || year_exp <  year ){goto exp;}
            if (month_mfg > month_exp && year_mfg > year_exp) {goto exp;}
            if (year_mfg > year_exp) {goto exp;}
            new_exp = to_string(day_exp)+"/"+ to_string(month_exp)+"/"+ to_string(year_exp);
            tmp->mfg = new_mfg;
            tmp->exp = new_exp;
        }
        tmp = tmp->link_lot;
    }
    save_medicine();
}

int Lot::get_count() {
    return this->count_medicine;
}

Node *Lot::get_head() {
    return this->head_medicine;
}

Node *Lot::get_tail() {
    return this->tail_medicine;
}