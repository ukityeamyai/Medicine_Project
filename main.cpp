#include "Medicine.h"
#include "Lot.h"
#include "Storage.h"
#include "Dispense.h"
#include "Report.h"
#include <limits>

int main() {
    Lot obj_lot;
    Storage obj_storage;
    Dispense obj_dispense;
    Report obj_report;

    obj_lot.read_medicine();
    obj_dispense.read_circulation();

    obj_storage.set_lot(obj_lot);
    obj_report.set_storage(obj_storage);
    obj_dispense.set_storage(obj_storage);

    obj_report.modify_month_mfg();
    obj_report.modify_month_exp();
    int menu;

   
    main:
    cout << "==================================================" << endl;
    cout << "|| 1. Add Medicine                              ||" << endl;
    cout << "|| 2. Dispense                                  ||" << endl;
    cout << "|| 3. Print Medicine                            ||" << endl;
    cout << "|| 4. Edit Information                          ||" << endl;
    cout << "|| 5. Notification                              ||" << endl;
    cout << "|| 6. Circulation                               ||" << endl;
    cout << "|| 0. Exit Program                              ||" << endl;
    cout << "==================================================" << endl;
    cout << "Select Menu:";
    while (!(cin >> menu)) {
        cin.clear();
        menu:
        cout << "==================================================" << endl;
        cout << "||" << setw(38) << "Invalid information, try again." << setw(10) << right << "||" << endl;
        cout << "==================================================" << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Select Menu:";
    }

    if (menu > 6 || menu < 0){
        goto menu;
    }

    if (menu == 1){
        system("cls");
        cout << "==================================================" << endl;
        cout << left << setw(3) << "||" << "1. Add Medicine"<< setw(32) << right << "||" << endl;
        cout << left << setw(3) << "||" << "0. Back To Menu"<< setw(32) << right << "||" << endl;
        cout << "==================================================" << endl;
        cout << "Select Menu:";
        while (!(cin >> menu)) {
            cin.clear();
            add:
            cout << "==================================================" << endl;
            cout << "||" << setw(38) << "Invalid information, try again." << setw(10) << right << "||" << endl;
            cout << "==================================================" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Select Menu:";
        }
        if (menu > 1 || menu < 0){
            goto add;
        }

        if (menu == 1){
            obj_lot.add_medicine();
            goto main;
        } else if (menu == 0){
            goto main;
        }

    } else if (menu == 2){
        system("cls");
        cout << "==================================================" << endl;
        cout << left << setw(3) << "||" << "1. Dispense Medicine"<< setw(27) << right << "||" << endl;
        cout << left << setw(3) << "||" << "0. Back To Menu"<< setw(32) << right << "||" << endl;
        cout << "==================================================" << endl;
        cout << "Select Menu:";
        while (!(cin >> menu)) {
            cin.clear();
            dispense:
            cout << "==================================================" << endl;
            cout << "||" << setw(38) << "Invalid information, try again." << setw(10) << right << "||" << endl;
            cout << "==================================================" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Select Menu:";
        }
        if (menu > 1 || menu < 0){
            goto dispense;
        }

        if (menu == 1){
            obj_dispense.dispense();
            goto main;
        } else if (menu == 0){
            goto main;
        }

    } else if (menu == 3){
        system("cls");
        cout << "==================================================" << endl;
        cout << left << setw(3) << "||" << "1. Print All Medicine" << setw(26) << right << "||" << endl;
        cout << left << setw(3) << "||" << "2. Print Medicine by name" << setw(22) << right << "||" << endl;
        cout << left << setw(3) << "||" << "0. Back To Menu"<< setw(32) << right << "||" << endl;
        cout << "==================================================" << endl;
        cout << "Select Menu:";
        while (!(cin >> menu)) {
            cin.clear();
            print:
            cout << "==================================================" << endl;
            cout << "||" << setw(38) << "Invalid information, try again." << setw(10) << right << "||" << endl;
            cout << "==================================================" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Select Menu:";
        }
        if (menu > 2 || menu < 0){
            goto print;
        }

        if (menu == 1){
            obj_report.print_all_medicine();
            goto main;
        } else if (menu == 2){
            obj_report.print_medicine_by_name();
            goto main;
        }else if (menu == 0){
            goto main;
        }

    } else if (menu == 4){
        system("cls");
        cout << "==================================================" << endl;
        cout << left << setw(3) << "||" << "1. Edit Information"<< setw(28) << right << "||" << endl;
        cout << left << setw(3) << "||" << "0. Back To Menu"<< setw(32) << right << "||" << endl;
        cout << "==================================================" << endl;
        cout << "Select Menu:";
        while (!(cin >> menu)) {
            cin.clear();
            edit:
            cout << "==================================================" << endl;
            cout << "||" << setw(38) << "Invalid information, try again." << setw(10) << right << "||" << endl;
            cout << "==================================================" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Select Menu:";
        }
        if (menu > 1 || menu < 0){
            goto edit;
        }

        if (menu == 1){
            obj_lot.edit_medicine();
            goto main;
        } else if (menu == 0){
            goto main;
        }

    } else if (menu == 5){
        system("cls");
        cout << "==================================================" << endl;
        cout << left << setw(3) << "||" << "1. Notification Expire" << setw(25) << right << "||" << endl;
        cout << left << setw(3) << "||" << "2. Notification Minimum" << setw(24) << right << "||" << endl;
        cout << left << setw(3) << "||" << "0. Back To Menu"<< setw(32) << right << "||" << endl;
        cout << "==================================================" << endl;
        cout << "Select Menu:";
        while (!(cin >> menu)) {
            cin.clear();
            noti:
            cout << "==================================================" << endl;
            cout << "||" << setw(38) << "Invalid information, try again." << setw(10) << right << "||" << endl;
            cout << "==================================================" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Select Menu:";
        }
        if (menu > 2 || menu < 0){
            goto noti;
        }

        if (menu == 1){
            obj_report.notification_expire();
            goto main;
        } else if (menu == 2){
            obj_report.notification_minimum();
            goto main;
        }else if (menu == 0){
            goto main;
        }

    } else if (menu == 6){
        system("cls");
        obj_dispense.circulation();
        goto main;

    } else if (menu == 0){
        cout << "THANK YOU" << endl;
    }

    
    return 0;

}