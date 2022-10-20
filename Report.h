#ifndef PROJECT_REPORT_H
#define PROJECT_REPORT_H
#include "Storage.h"

class Report {
    private:
        Storage obj_storage;
    public:
        void set_storage(Storage storage);
        string comma(int amount);
        string modify_type(string type);
        void modify_month_mfg();
        void modify_month_exp();
        string modify_month(string month);
        void bubble_sort_ascending();

        void print_all_medicine();
        void print_medicine_by_name();

};

#endif //PROJECT_REPORT_H