#include <boost\lambda\lambda.hpp>
#include <iostream>
#include "math\Vector.h"
#include "math\Hyperplane.h"
#include "math\Universe.h"


/* MITSCHRIFTEN

valgrind.org

*/

using namespace math;

int main123(){
	std::cout << "Moin!" << std::endl;

	vector orange(0,-1,1);
	vector purple(0,0,1);
	vector yellow(1,-1,0);

	Hyperplane o_p(two_D::ZERO, orange);
	Hyperplane p_p(two_D::ZERO, purple);
	Hyperplane y_p(two_D::ZERO, yellow);

	Universe u({o_p, p_p, y_p});

	point p(1, 0, 1);
	Orbit orbit = u.getOrbit(p, 20);

	std::cout << orbit << std::endl;

	std::cin.get();
	return 0;
}