//
// Created by Иван Лескин on 14/04/2023.
//

#ifndef MINIJAVA_З_H
#define MINIJAVA_З_H

#include <deque>

template<typename T>
class PStack {
public:
    PStack() = default;
    T Pop();
    void Push(T value);
    T Top();
private:
    std::deque<T> buf;
};

#endif //MINIJAVA_З_H
