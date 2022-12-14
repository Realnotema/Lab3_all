#include <iostream>
#include <stdexcept>
#include "inclass.h"

using namespace ns;

set::set(int len) {
    data = new int[len];
    for (int i = 0; i < len; i++) {
        data[i] = i + 1;
    }
    length = len;
    max_length = len;
}

set::set(int len, const int *array) {
    for (int i = 0; i < len; i++) {
        (*this) += array[i];
    }
}

set set::intersection(set &inter_data) const {
    set new_data;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < inter_data.length; j++) {
            if (data[i] == inter_data.data[j])
                new_data += (data[i]);
        }
    }
    return new_data;
}

int set::is_in_set(int value) {
    for (int i = 0; i < length; i++)
        if (data[i] == value)
            return 0;
    return 1;
}

std::ostream &ns::operator<<(std::ostream &c, const set &data) {
    for (int i = 0; i < data.length; i++) {
        c << data.data[i] << " ";
    }
    return c;
}

std::istream &ns::operator>>(std::istream &s, set &data) {
    int value;
    s >> data.length;
    for (int i = 0; i  < data.length; i++) {
        s >> value;
        data += value;
    }
    return s;
}

const set set::operator+(set &merge_data) {
    set new_data;
    for (int i = 0; i < length; i++)
        new_data += data[i];
    for (int i = 0; i < merge_data.length; i++)
        new_data += merge_data.data[i];
    return new_data;
}

set &set::operator+=(int value) {
    if (length == max_length){
        max_length = 2 * (max_length + 1);
        int *temp = new int[max_length];
        std::move(data, (data + length), temp);
        delete[] data;
        data = temp;
    }
    for (int i = 0; i < length; i++)
        if (data[i] == value)
            throw std::range_error("Element is of the data already");
    data[length] = value;
    length++;
    return *this;
}

const set set::operator-(set &sub_data) {
    set inter_data = intersection(sub_data);
    set new_data;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < inter_data.length; j++) {
            if (inter_data.is_in_set(data[i]))
                new_data += data[i];
        }
    }
    return new_data;
}

set::~set() {
    delete[] data;
}

set::set(set &other) { // ????????????????????
    length = other.length;
    max_length = other.max_length;
    data = new int[max_length];
    for (int i = 0; i < other.length; i++) {
        data[i] = other.data[i];
    }
}

set::set(set &&other) noexcept { // ????????????????????????
    data = other.data;
    length = other.length;
    max_length = other.max_length;
    other.data = nullptr;
    other.length = 0;
    other.max_length = 0;
}

set &set::operator=(const set &other) {
    delete[] data;
    length = other.length;
    max_length = other.max_length;
    data = new int[max_length];
    for (int i = 0; i < other.length; i++) {
        data[i] = other.data[i];
    }
    return *this;
}

set &set::operator=(set &&other) {
    delete[] data;
    data = other.data;
    length = other.length;
    max_length = other.max_length;
    other.data = nullptr;
    other.length = 0;
    other.max_length = 0;
    return *this;
}
