/*
DESCRIPTION
-----------
-> This code implements "the Newton's method" of finding roots to 
nonlinear equations f(x) = 0.
-> Newton's method is based on a linear approximation of the function,
but does so using a tangent to the curve.
-> It is widely used 
*/

#include <iostream>
#include <cmath>
#include <cassert>
#include <functional>
#include <exception>

using NUMBER = long double;

#define NEWTONS_METHOD_NOT_VALID 1 

/* 
requirements
-------------
-> x0 needs to be reasonably close to the root 
-> the function f needs to be a continuous function
-> the function f_prime is the derivative of the function f
*/
NUMBER newtons_method(
	std::function<NUMBER(NUMBER)> f, std::function<NUMBER(NUMBER)> f_prime,
	NUMBER x0, NUMBER tlv1, NUMBER tlv2) {

	NUMBER result1 = f(x0);	
	NUMBER result2 = f_prime(x0);	
	
	if (result1 == 0) 
		return x0; // we have found the root simply
	if (result2 == 0) {
		//newton's method is not valid in this case
		throw NEWTONS_METHOD_NOT_VALID;
	}
	NUMBER x1;
	do {
		x1 = x0;
		x0 = x0 - (f(x0)/f_prime(x0));	
	} while ( (std::abs(x1-x0) >= tlv1) and (std::abs(f(x0)) >= tlv2) );	
	return x0;
} 

int main(void) {
	auto f = [](NUMBER x) {
		return 3*x + std::sin(x) - std::exp(x);
	};	
	auto f_prime = [](NUMBER x) {
		return 3  + std::cos(x) - std::exp(x);
	};

	NUMBER root = newtons_method(f,f_prime,0.0,0.000001,0.00001);
	std::cout << root << std::endl;
}

