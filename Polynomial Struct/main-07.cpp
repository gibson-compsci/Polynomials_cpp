#include<iostream>
using std::cout; using std::endl;
#include "struct-07.h"

int main (){
    Polynomial p1({2,2,0,0});
    Polynomial p2 ({10,10});
    cout << "P1, Degree:"<<p1.degree<<", "<<p1.poly_to_string()<<endl;
    cout << "P2 Degree:"<<p2.degree<<", "<<p2.poly_to_string()<<endl;

    Polynomial p3 = p1.add(p2);
    cout << "P3, p1+p2, Degree:"<<p3.degree<<", "
	 <<p3.poly_to_string()<<endl;

    Polynomial p4 = p1.mult(100);
    cout << "P4, p1*100, Degree:"<<p4.degree<<", "
	 <<p4.poly_to_string()<<endl;

    Polynomial p5 = p1.mult(p2);
    cout << "P5, p1*p2, Degree:"<<p5.degree<<", "
	 << p5.poly_to_string()<<endl;

}
