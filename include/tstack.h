// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_
#include <string>

template<typename T>
class TStack {
 private:
    T array[100];
    int top;

 public:
    Tstack() :top(-1) {}
    void push(T value) {
        if (isFull())
            throw std::string("Full!");
        else
            array[++top] = value;
    }
    const T& pop() {
        if (isEmpty())
            throw std::string("Empty!");
        else
            return array[top--];
    }
    const T& get() {
        return array[top];
    }
    bool isFull() const {
        return (top == 100);
    }
    bool isEmpty() const {
        return (top == -1);
    }
};

#endif  // INCLUDE_TSTACK_H_
