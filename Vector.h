#ifndef VECTOR_H
#define VECTOR_H

class Vector {
    int* data;
    size_t size{};
    size_t capacity{};

    void resize(size_t newSize);

public:
    Vector();

    Vector(size_t size);

    ~Vector();

    void push_back(int value);

    void push_front(int value);

    void emplace(size_t index, int value);

    void reversed() const;

    void fillVec(int value) const;

    void printVec() const;

    size_t getSize() const;
};

#endif
