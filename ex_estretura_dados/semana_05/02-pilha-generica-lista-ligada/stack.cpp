#include <iostream>
#include "Stack.h"
using namespace std;

template <typename T> 
Stack<T>::Stack() { 
    size_ = 0;
    top_ = nullptr;
}

template <typename T> 
Stack<T>::~Stack() { // serve para limpar a pilha
    while (top_ != nullptr) {
        node<T>* sacrifice = top_;
        top_ = top_->next; //
        size_--;
        delete sacrifice;
    } 
}

template <typename T> 
size_t Stack<T>::size() const { 
    return size_;
}

template <typename T> 
bool Stack<T>::peek(T& elem) const { 
    if (top_ != nullptr) {
        elem = top_->value;
        return true; 
    }
    return false;
}

template <typename T> 
bool Stack<T>::pop(T& elem) {
    bool k = false;

    if (top_ != nullptr) {
        elem = top_->value;
        
        node<T>* sacrifice = top_;
        top_ = top_->next;
        size_--;
        delete sacrifice;

        k = true; 
    }
    return k;
}

template <typename T> 
void Stack<T>::push(const T& elem) { 
        node<T>* fresh_on_the_block = new node<T>{elem, top_}; // criar novo node com o valor necessário e o top_ atual
        top_ = fresh_on_the_block; // este passa a ser o novo topo
        size_++;     // a stack cresce mais um bocadinho
}



int main() {
    { Stack<int> s;
  const Stack<int>& r = s;
  int v = -1;
  cout << r.size()  << ' ' << boolalpha
       << r.peek(v) << ' ' << v << ' '
       << s.pop(v)  << ' ' << v << ' '
       << s.size() << '\n'; }

    return 0;
}