#include "Dispense.h"

Dispense::Dispense() {
    this->head_circulation = NULL;
    this->tail_circulation = NULL;
    this->count_circulation = 0;
}

int Dispense::string_to_int(string str) {
    stringstream ss;
    ss << str;
    int int_num;
    ss >> int_num;
    return int_num;
}

void Dispense::set_storage(Storage storage) {
    this->storage = storage;
}

void Dispense::bubble_sort_ascending() {
    int  count = this->storage.get_count();
    Node *head = this->storage.get_head();
    for (int i = 0; i < count; i++) {
        Node *ptmp = NULL;
        Node *tmp = this->storage.get_head();
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

bool Dispense::check_type_name(int type, string name) {
    Node *tmp = storage.get_head();
    while (tmp != NULL) {
        if (tmp->type == type && tmp->name == name) {
            return true;
        } else {
            tmp = tmp->link_lot;
        }
    }
    return false;
}

bool Dispense::check_amount(int type, string name, int amount) {
    Node *tmp = storage.get_head();
    int count = storage.get_count();
    bool t = true;
    for (int i = 0; i < count; ++i) {
        if (tmp->type == type && tmp->name == name && tmp->amount != 0) {
            if (tmp->amount < amount) {
                t = false;
                break;
            }
        } else {
            tmp = tmp->link_lot;
        }
    }
    return t;
}

string Dispense::date() {
    int day,month,year;
    string date;

    time_t now = time(0);
    tm *ltm = localtime(&now);

    year = 1900 + ltm->tm_year;
    month = 1 + ltm->tm_mon;
    day = ltm->tm_mday;

    date = to_string(day)+"/"+ to_string(month)+"/"+ to_string(year);
    return date;
}

string Dispense::comma(int amount) {
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

string Dispense::modify_type(string type) {
    if (type == "1"){
        type = "PILL";
    } else if (type == "2"){
        type = "CREAM";
    } else if (type == "3"){
        type = "LIQUID";
    }
    return type;
}


void Dispense::dispense() {
    Node *tmp = this->storage.get_head();
    int count_e = this->storage.get_count();
    int count, type, amount;
    string name;
    cout << "Amount Dispense :";
    cin >> count;
    for (int i = 0; i < count; i++) {
        cout << "Medicine[" << i+1 << "]" << endl;
        menu:
        cout << "================= MEDICINE TYPE ==================" << endl;
        cout << left << setw(3) << "||" << "1.PILL" << setw(41) << right << "||" << endl;
        cout << left << setw(3) << "||" << "2.CREAM" << setw(40) << right << "||" << endl;
        cout << left << setw(3) << "||" << "3.LIQUID" << setw(39) << right << "||" << endl;
        cout << "==================================================" << endl;
        cout << "Type Medicine :";
        while (!(cin >> type)) {
            cin.clear();
            cout << "==================================================" << endl;
            cout << "||" << setw(38) << "Invalid information, try again." << setw(10) << right << "||" << endl;
            cout << "==================================================" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Select Menu :";
        }
        if (type > 3 || type < 1){goto menu;}

        cout << "Medicine Name :";
        cin >> name;

        if (check_type_name(type,name)){
            a:
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
            if (check_amount(type,name,amount)){
                dispense_amount(type,name,amount);
                for (size_t i = 0; i < count; i++)
                {
                    if (tmp->type == type && tmp->name == name)
                    {
                      add(type,name,amount,tmp->price,date());
                    }
                    tmp = tmp->link_lot;
                }
                
            
            } else{
                cout << "==================================================" << endl;
                cout  << setw(35) << "The Number is not Enough" << setw(14) << endl;
                for (int j = 0; j < count; j++) {
                    if (tmp->type == type && tmp->name == name) {
                        if (tmp->amount != 0){
                            cout << right << setw(30) << "Remaining Amount :" << tmp->amount << endl;
                            break;
                        }
                    }
                    tmp = tmp->link_lot;
                }
                cout << "==================================================" << endl;
                goto  a;
            }
        } else{
            cout << "==================================================" << endl;
            cout << "||" << setw(38) << "Invalid information, try again." << setw(10) << right << "||" << endl;
            cout << "==================================================" << endl;
            goto menu;
        }
    }
}
void Dispense::dispense_amount(int type, string name, int amount) {
    int price;
    bubble_sort_ascending();
    Node *tmp = this->storage.get_head();
    int count = this->storage.get_count();
    Node *tail = this->storage.get_tail();
    Node *head = this->storage.get_head();
    Node *ptmp = this->storage.get_head();
    for (int i = 0; i < count; i++) {
        if (tmp->type == type && tmp->name == name && tmp->amount != 0) {
            tmp->amount = tmp->amount - amount;
            if (tmp->amount <= 0){
                tmp->amount = 0;
            }
            break;
        }
        tmp = tmp->link_lot;
    }
    update_storage();
    save_circulation(type,name,amount);
}

void Dispense::update_storage() {
    Node *tmp = storage.get_head();
    int count = storage.get_count();
    ofstream myFile("storage.txt",ios::out);
    if (myFile.is_open()){
        for (int i = 0; i < count; i++) {
            myFile << tmp->lot_number << ","
                   << tmp->type << ","
                   << tmp->name << ","
                   << tmp->amount << ","
                   << tmp->volume << ","
                   << tmp->mfg << ","
                   << tmp->exp << ","
                   << tmp->price << endl;

            tmp = tmp->link_lot;
        }
    } else{
        cout << "Can't open file" << endl;
    }
}

void Dispense::save_circulation(int type, string name, int amount) {
    Node *tmp = head_circulation;
    Node *ptmp = this->storage.get_head();
    int count = this->storage.get_count();
    int price;
    ofstream myFile("circulation.txt",ios::app);
    for (int i = 0; i < count; i++) {
        if (ptmp->type == type && ptmp->name == name){
            price = ptmp->price;
        }
        ptmp = ptmp->link_lot;
    }

    if (myFile.is_open()){
        for (int i = 0; i < count_circulation; i++) {
            myFile << type << ","
                   << name << ","
                   << amount << ","
                   << price << ","
                   << date() << endl;
            tmp = tmp->link_circulation;
        }
    }else{
        cout << "Can't open file" << endl;
    }
}


void Dispense::add(int type, string name, int amount,int price,string date) {
    Node *tmp = new Node(type,name,amount,price,date);
    tmp->type = type;
    tmp->name = name;
    tmp->amount = amount;
    tmp->price = price;
    tmp->date = date;
    if (count_circulation == 0){
        tmp->link_circulation = NULL;
        head_circulation = tmp;
        tail_circulation = tmp;
    } else{
        tmp->link_circulation = NULL;
        tail_circulation->link_circulation = tmp;
        tail_circulation = tail_circulation->link_circulation;
    }
    count_circulation++;
}

void Dispense::read_circulation() {
    int type, amount, price;
    string name,date,line;
    ifstream myFile;
    myFile.open("circulation.txt",ios::in);
    if (myFile.fail()){
        cout << "==================================" << endl;
        cout << setw(24) << "Can't open file" << endl;
        cout << "==================================" << endl;
    } else{
        while (getline(myFile,line)){
            type = string_to_int(line.substr(0,','));
            line.erase(0,line.find(',') + 1);

            name = line.substr(0,line.find(','));
            line.erase(0,line.find(',') + 1);

            amount = string_to_int(line.substr(0,','));
            line.erase(0,line.find(',') + 1);

            price = string_to_int(line.substr(0,','));
            line.erase(0,line.find(',') + 1);

            date = line.substr(0,line.find(','));
            line.erase(0,line.find(',') + 1);

            add(type,name,amount,price,date);
        }
    }
    myFile.close();
}


void Dispense::circulation() {
    Node *tmp = head_circulation;
    cout << "======================================================================================" << endl;
    cout << "||" << setw(51) << "CIRCULATION MINIMUM" << setw(33) << right << "||" << endl;
    cout << "======================================================================================" << endl;
    cout << setw(3) << left << "||" << setw(9) << "TYPE"
         << setw(3) << left << "||" << setw(22)<< "NAME"
         << setw(3) << right << "||" << setw(10) << "AMOUNT"
         << setw(3) << right << "||" << setw(10) << "PRICE"
         << setw(6) << right << "||" << setw(10) << "DATE"
         << setw(7) << "||" << endl;
    cout << "======================================================================================" << endl;
    for (int i = 0; i < count_circulation; i++) {
        cout << setw(3) << left << "||" << setw(9) << modify_type(to_string(tmp->type))
        << setw(3) << left << "||" << setw(22) << tmp->name 
        << setw(3) << right << "||" << setw(10) << comma(tmp->amount)
        << setw(3) << right << "||" << setw(10) << comma(tmp->price)
        << setw(6) << right << "||" << setw(12) << tmp->date 
        << setw(5) << "||" << endl;
        tmp = tmp->link_circulation;
    }
    cout << "======================================================================================" << endl;

}