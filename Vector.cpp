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

void Vector::push_front(const int value) {
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

Vector Vector::operator+(const Vector& other) const {
    if (this->size != other.size) {
        cerr << "Векторы должны иметь одинаковый размер для сложения" << endl;
        return Vector(0);
    }

    Vector result(this->size);
    for (size_t i = 0; i < this->size; ++i) {
        result.data[i] = this->data[i] + other.data[i];
    }
    return result;
}

Vector Vector::operator-(const Vector& other) const {
    if (this->size != other.size) {
        cerr << "Векторы должны иметь одинаковый размер для вычитания" << endl;
        return Vector(0);
    }

    Vector result(this->size);
    for (size_t i = 0; i < this->size; ++i) {
        result.data[i] = this->data[i] - other.data[i];
    }
    return result;
}

Vector Vector::operator*(const int scalar) const {
    Vector result(this->size);
    for (size_t i = 0; i < this->size; ++i) {
        result.data[i] = this->data[i] * scalar;
    }
    return result;
}

bool Vector::operator==(const Vector& other) const {
    if (this->size != other.size) return false;
    for (size_t i = 0; i < this->size; ++i) {
        if (this->data[i] != other.data[i]) return false;
    }
    return true;
}

bool Vector::operator!=(const Vector& other) const {
    return !(*this == other);
}

bool Vector::operator<(const Vector& other) const {
    return this->size < other.size;
}

bool Vector::operator>(const Vector& other) const {
    return this->size > other.size;
}

bool Vector::operator<=(const Vector& other) const {
    return this->size <= other.size;
}

bool Vector::operator>=(const Vector& other) const {
    return this->size >= other.size;
}