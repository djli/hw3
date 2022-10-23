#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : public std::vector<T>
{
public:
    Stack(){

    }

    ~Stack(){

    }

    size_t size() const{
        return std::vector<T>::size();
    }

    bool empty() const{
        return std::vector<T>::empty();
    }

    void push(const T& item){
        std::vector<T>::push_back(item);
    }

    void pop(){
        if(empty()){
            throw std::underflow_error("Stack is empty");
        }
        std::vector<T>::pop_back();
    }

    T const & top() const{
        if(empty()){
            throw std::underflow_error("Stack is empty");
        }
        return std::vector<T>::back();
    }
};


#endif