#include<deque>
using std::deque;
#include<string>
using std::string;
#include<initializer_list>
using std::initializer_list;

#ifndef POLY_CLASS
#define POLY_CLASS

struct Polynomial{
    deque<long> coefs;
    long degree;

    Polynomial(initializer_list<long> co_list);
    Polynomial(deque<long> & co_list);
    Polynomial();
    string poly_to_string();
    Polynomial add(Polynomial rhs);
    Polynomial mult(Polynomial rhs);
    Polynomial mult(long factor);
};

#endif
