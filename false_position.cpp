/*
DESCRIPTION
-----------
-> false position method is also known as "linear interpolation"
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
-> x0 & x1 need to be reasonably close to the root 
-> x0 & x1 need to bracket the root
-> the function f needs to be a continuous function
-> tlv is the tolerance value
*/
NUMBER false_position(
	std::function<NUMBER(NUMBER)> f, 
	NUMBER x0, NUMBER x1, NUMBER tlv) {
	
	NUMBER x2;
	do {
		x2 = x1 - f(x1) * ( (x0 - x1) / (f(x0) - f(x1)) ); 
		if (f(x2)*f(x0) < 0)
			x1 = x2;
		else
			x0 = x2;
	} while ( std::abs(f(x2)) >= tlv );	
	return x2;
} 

int main(void) {
	auto f = [](NUMBER x) {
		return 3*x + std::sin(x) - std::exp(x);
	};	
	NUMBER root = false_position(f,0.0,0.6,0.00001);
	std::cout << root << std::endl;
}

