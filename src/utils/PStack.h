//
// Created by Иван Лескин on 14/04/2023.
//

#ifndef MINIJAVA_PSTACK_H
#define MINIJAVA_PSTACK_H

#include <deque>

template<typename T>
class PStack {
public:
    PStack() = default;
    T PopBack();
    void Pop();
    void Push(T value);
    T Top();
private:
    std::deque<T> buf;
};


#endif //MINIJAVA_PSTACK_H
