#include <iostream>
#include "inclass.h"

using namespace ns;

int dialog (const char *what[]) {
    const char *errmess = "Incorrect value\nTry Again";
    int choose = 0;
    for (int i = 0; i < 7; i++)
        cout << what[i] << endl;
    do {
        enter(choose, "Enter your choose:");
        if (choose <= 0 || choose > 7)
            cout << errmess << endl;
        else break;
    } while (1);
    if (choose == 7)
        return -1;
    return choose;
}

int menu(int choose, set &new_set_1, set &new_set_2) {
    int num = 0;
    int element;
    if (choose == -1)
        return -1;
    set result_set;
    switch (choose) {
        case 1:
            enter(num, "Enter number of set to add element (1 or 2):");
            enter(element, "Enter element to add:");
            if (num == 1 || num == 2) {
                if (num == 1)
                    new_set_1 += element;
                else new_set_2 += element;
            } else cout << "Error! No such set!";
            break;
        case 2:
            result_set = new_set_1 + new_set_2;
            cout << "Result set: " << result_set << endl;
            break;
        case 3:
            result_set = new_set_1.intersection(new_set_2);
            cout << "Result set: " << result_set << endl;
            break;
        case 4:
            result_set = new_set_1 - new_set_2;
            cout << "Result set: " << result_set << endl;
            break;
        case 5:
            enter(num, "Enter number of set to add element (1 or 2):");
            enter(element, "Enter element to search:");
            if (num == 1 || num == 2) {
                if (num == 1)
                    num = new_set_1.is_in_set(element);
                else num = new_set_2.is_in_set(element);
                if (num == 1)
                    cout << "True" << endl;
                else cout << "False" << endl;
            } else cout << "Error! No such set!";
            break;
        case 6:
            cout << "First set: " << new_set_1 << endl;
            cout << "Second set: " << new_set_2 << endl;
            break;
        default:
            return 0;
    }
    return 0;
}

int main () {
    const char *what[] = {"1. Add element to set", "2. Combining sets", "3. Intersection of sets",
                          "4. Difference of sets", "5. Is element in set?",
                          "6. Print set", "7. Exit"};
    int flag;
    set new_set_1;
    set new_set_2;
    do {
        flag = menu(dialog(what), new_set_1, new_set_2);
        if (flag == -1)
            return 0;
    } while (1);
}
