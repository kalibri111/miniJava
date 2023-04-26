//
// Created by Иван Лескин on 14/04/2023.
//

#include "PStack.h"
template<typename T>
T PStack<T>::Top() {
    return buf.back();
}

template<typename T>
void PStack<T>::Push(T value) {
    buf.push_back(std::move(value));
}

template<typename T>
T PStack<T>::PopBack() {
    auto val = buf.back();
    buf.pop_back();
    return val;
}


template<typename T>
void PStack<T>::Pop() {
    buf.pop_back();
}
