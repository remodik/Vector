#include "Vector.h"
#include <iostream>
using namespace std;
Vector::Vector() : data(nullptr), size(0), capacity(0) {}

Vector::Vector(const size_t size) : size(size), capacity(size) {
    data = new int[capacity];
}

Vector::~Vector() {
    delete[] data;
}

void Vector::resize(const size_t newSize) {
    if (newSize > capacity) {
        capacity = newSize;
        const auto newData = new int[capacity];
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
}

void Vector::push_back(const int value) {
    if (size == capacity) {
        resize(capacity == 0 ? 1 : capacity * 2);
    }
    data[size++] = value;
}

void Vector::push_front(int value) {
    if (size == capacity) {
        resize(capacity == 0 ? 1 : capacity * 2);
    }
    for (size_t i = size; i > 0; --i) {
        data[i] = data[i - 1];
    }
    data[0] = value;
    ++size;
}

void Vector::emplace(const size_t index, const int value) {
    if (index > size) {
        cerr << "Index out of bounds!" << endl;
        return;
    }
    if (size == capacity) {
        resize(capacity == 0 ? 1 : capacity * 2);
    }
    for (size_t i = size; i > index; --i) {
        data[i] = data[i - 1];
    }
    data[index] = value;
    ++size;
}

void Vector::reversed() const {
    size_t start = 0;
    size_t end = size - 1;
    while (start < end) {
        const int temp = data[start];
        data[start] = data[end];
        data[end] = temp;
        ++start;
        --end;
    }
}


void Vector::fillVec(const int value) const {
    for (size_t i = 0; i < size; ++i) {
        data[i] = value;
    }
}

void Vector::printVec() const {
    for (size_t i = 0; i < size; ++i) {
        cout << data[i] << " ";
    }
    cout << endl;
}

size_t Vector::getSize() const {
    return size;
}
