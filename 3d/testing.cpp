#include "gtest/gtest.h"
#include "inclass.h"
#include <string>
#include <iostream>

using namespace ns;
using namespace std;

string print_set(ns::set &a) {
    testing::internal::CaptureStdout();
    cout << a;
    string output = testing::internal::GetCapturedStdout();
    return output;
}

TEST(Constructor, Clear) {
    ASSERT_NO_THROW(ns::set set);
    ns::set set;
    string str = print_set(set);
    ASSERT_EQ(str, "");
}

TEST(Constructor, Integer) {
    ASSERT_NO_THROW(ns::set set(1));
    ns::set set(1);
    string str = print_set(set);
    ASSERT_EQ(str, "1 ");
}

TEST(Constructor, Integer_plus_const) {
    const int a[] = {1, 2};
    ASSERT_NO_THROW(ns::set set(2, a));
    ns::set set(2, a);
    string str = print_set(set);
    ASSERT_EQ(str, "1 2 ");
}

TEST(Constructor, Copy) {
    ns::set new_set;
    new_set.operator+=(1);
    ASSERT_NO_THROW(ns::set set(new_set));
    ns::set set(new_set);
    string str = print_set(set);
    ASSERT_EQ(str, "1 ");
}

TEST(Constructor, Мoving) {
    ns::set new_set;
    new_set.operator+=(1);
    ASSERT_NO_THROW(ns::set set(move(new_set)));
    ns::set set(move(new_set));
    string str = print_set(set);
    ASSERT_EQ(str, "");
}

TEST(Methods, Intersection) {
    ns::set new_set;
    new_set.operator+=(1);
    ns::set set;
    set.operator+=(1);
    ns::set result;
    result = new_set.intersection(set);
    string str = print_set(result);
    ASSERT_EQ(str, "1 ");
}

TEST(Methods, Is_in_set) {
    ns::set new_set;
    new_set.operator+=(1);
    int result;
    result = new_set.is_in_set(1);
    ASSERT_EQ(result, 0);
}

TEST(Operators, Plus) {
    ns::set new_set;
    new_set.operator+=(1);
    ns::set set;
    set.operator+=(2);
    ns::set result;
    result = new_set + set;
    string str = print_set(result);
    ASSERT_EQ(str, "1 2 ");
}

TEST(Operators, Plus_Equals) {
    ns::set set;
    set.operator+=(1);
    string str = print_set(set);
    ASSERT_EQ(str, "1 ");
}

TEST(Operators, Minus) {
    ns::set new_set;
    new_set.operator+=(1);
    new_set.operator+=(2);
    ns::set set;
    set.operator+=(2);
    ns::set result;
    result = new_set - set;
    string str = print_set(result);
    ASSERT_EQ(str, "1 ");
}

TEST(Operators, Copy) {
    ns::set new_set;
    new_set.operator+=(1);
    new_set.operator+=(2);
    ns::set set;
    set = new_set;
    string str = print_set(set);
    ASSERT_EQ(str, "1 2 ");
}

TEST(Operators, Move) {
    ns::set new_set;
    new_set.operator+=(1);
    new_set.operator+=(2);
    ns::set set;
    set = move(new_set);
    string str = print_set(set);
    ASSERT_EQ(str, "1 2 ");
    str = print_set(new_set);
    ASSERT_EQ(str, "");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
