/*
DESCRIPTION
-----------
-> This code implements the "Fixed-Point Iteration method".
-> Fixed-Point Iteration is also known as "x = g(x)" method. 
-> Note that to calculate
*/

#include <iostream>
#include <cmath>
#include <cassert>
#include <functional>
#include <exception>

using NUMBER = long double;

/* 
requirements
-------------
-> x1 needs to be reasonably close to the root 
-> Note here that we are not accepting the function f(x)
-> We are accepting as a parameter the function g(x) which is
obtained from f(x) after some rearrangement.
-> To obtain g(x) just rearrange the equation f(x) = 0 ---> g(x) = x 
*/
NUMBER fixed_point_iteration(
	std::function<NUMBER(NUMBER)> g, NUMBER x1, NUMBER tlv) {

	NUMBER x2;	
	do {
		x2 = x1;
		x1 = g(x1);
	} while ( std::abs(x1-x2) >= tlv );
	return x1;
} 

int main(void) {
	auto f = [](NUMBER x) {
		return std::pow(x,2) - 2 * x - 3;
	};	
	auto g = [](NUMBER x) {
		return std::sqrt(2*x + 3); 
	};

	NUMBER root = fixed_point_iteration(g,4,0.0001);
	std::cout << root << std::endl;
}

