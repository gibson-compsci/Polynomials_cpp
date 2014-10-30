/* 
 * CSE 232 Project #7
 * File:   struct-07.cpp
 * Author: Cameron Gibson
 *      POLYNOMIAL STRUCT:
 *          - Constructors (default, initializer list, and deque)
 *			- poly_to_string() function returns a string that represents the polynomial
 *				(EX: x^2+x+1)
 *			- add(Polynomial) function returns a polynomial that represents the sum of two other polynomials
 *			- mult(Polynomial) function returns a polynomial that represents the product of two other polynomials
 *			- mult(long) function returns a polynomial that represents the product of a polynomial and constant
 *
 * Created on October 21, 2014, 4:34 PM
 */

#include<deque>
#include<string>
#include<initializer_list>
#include<sstream>

#include "struct-07.h"

using std::deque;
using std::string;
using std::initializer_list;
using std::ostringstream;

/*
 * Default constructor for the Polynomial struct
 */
Polynomial::Polynomial(){
    coefs={0};
    degree=0;
}

/*
 * Constructor for the Polynomial struct which takes in an initializer_list<long>
 */
Polynomial::Polynomial(initializer_list<long> co_list){
    for(auto arg:co_list){
        coefs.push_back(arg);
    }
    degree=(coefs.size()-1);
}
    
/*
 * Constructor for the Polynomial struct which takes in a deque<long>
 */
Polynomial::Polynomial(deque<long> & co_list){
    coefs=co_list;
    degree=(coefs.size()-1);
}
    
/*
 * poly_to_string function for the Polynomial struct
 *		- no parameters
 *		- returns a string representation of the polynomial (EX: "x^2+x+1")
 */
string Polynomial::poly_to_string(){
    //initialize variables
	ostringstream oss;
    long current_deg=degree;
    string sign="";
	//for each coefficient of the polynomial add it to the stringstream with the appropriate sign and "x^#"
    for(auto element:coefs){
		//if coefficient is 0 then don't add anything
        if(element!=0 || coefs.size()==1){
            //determine sign of the value
			if(element<0)
                sign="";
            else if(current_deg!=degree)
                sign="+";
			//add the sign and coefficient
            oss<<sign<<element;
			//check what degree goes with the coefficient and add it
            if(current_deg>1)
                oss<<"x^"<<current_deg;
            else if(current_deg==1)
                oss<<"x";
        }
		//move to the next degree
        --current_deg;
    }
	//make the stringstream into a string
    auto poly_string= oss.str();
    if(poly_string==""){poly_string="0";}
    return poly_string;
}
    
/*
 * add function for the Polynomial struct
 *		- takes one Polynomial struct as a parameter
 *		- returns a Polynomial struct which is equal to the sum of the two other Polynomials
 */
Polynomial Polynomial::add(Polynomial rhs){
    //initialize variables
	Polynomial new_poly({});
    int count=0;
    int pos=0;
	//check which Polynomial has a higher degree then add them based on which one is bigger
    if(degree>=rhs.degree){
        count=degree;
        for(auto ele:coefs){
			//add each coefficient
            new_poly.coefs.push_back(ele);
			//then add the coefficient from the other Polynomial
            if(count<=rhs.degree){
                new_poly.coefs.at(new_poly.coefs.size()-1)+=rhs.coefs.at(pos);
                ++pos;
            }
            --count;
        }
		//set the degree of the new Polynomial
        new_poly.degree=new_poly.coefs.size()-1;
    }
    else{
        count=rhs.degree;
        for(auto ele:rhs.coefs){
			//add each coefficient
            new_poly.coefs.push_back(ele);
			//then add the coefficient from the other Polynomial
            if(count<=degree){
                new_poly.coefs.at(new_poly.coefs.size()-1)+=coefs.at(pos);
                ++pos;
            }
            --count;
        }
		//set the degree of the new Polynomial
        new_poly.degree=new_poly.coefs.size()-1;
    }
	//return the new sum Polynomial 
    return new_poly;
}
    
/*
 * mult function for the Polynomial struct
 *		- takes one Polynomial struct as a parameter
 *		- returns a Polynomial struct which is equal to the product of the two other Polynomials
 */
Polynomial Polynomial::mult(Polynomial rhs){
    //initialize variables
	long new_degree= degree+rhs.degree;
    deque<long> new_coefs(new_degree+1,0);
    Polynomial new_poly(new_coefs);
    int current_deg_ele=degree;
	//for every coefficient in this Polynomial multiply each term and then add the like degrees
    for(auto ele:coefs){
		//set total degree
        int current_deg_term=rhs.degree;
        for(auto term:rhs.coefs){
			//add the new term to the new Polynomial
            new_poly.coefs.at(
                    new_poly.degree-(current_deg_ele+current_deg_term)
                    )+=ele*term;
			//move on to the next degree
            --current_deg_term;
        }
		//move on to the next degree
        --current_deg_ele;
    }
	//return the new product Polynomial
    return new_poly;
}
    
/*
 * mult function for the Polynomial struct
 *		- takes one long (integer) as a parameter
 *		- returns a new Polynomial which is equal to the product of this Polynomail and the constant (long)
 */
Polynomial Polynomial::mult(long factor){
	//initialize the new Polynomial
    Polynomial new_poly({});
	//for every coefficient in this Polynomial multiply it by the constant factor
    for(auto ele:coefs)
        new_poly.coefs.push_back(ele*factor);
	//set the degree of the new Polynomail
    new_poly.degree=new_poly.coefs.size()-1;
	//return the new product Polynomial 
    return new_poly;
}