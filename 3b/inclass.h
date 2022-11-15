#ifndef LAB3_3_INTCLASS_H
#define LAB3_3_INTCLASS_H

#include <iostream>

namespace ns {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::bad_alloc;

    class set {
    private:
        static const int max_length = 10;
        int length;
        int data[max_length]{};
    public:
        explicit set() : length(0) {};
        explicit set(int);
        explicit set(int, int *);

        std::ostream &print(std::ostream &); // std::ostream - cin cout
        std::istream &scan(std::istream &);
        set &merge(set &);
        void add_element(int);
        set &intersection(set &);
        set &subtraction(set &);
        int is_in_set(int);
    };

    template <class T>
    int enter (T &a, const char *what) {
        cout << what << endl;
        cin >> a;
        if (!cin.good()) {
            cout << "Error with cin \n Try again" << endl;
            return 1;
        } else
            return 0;
    }
}

#endif //LAB3_3_INTCLASS_H
