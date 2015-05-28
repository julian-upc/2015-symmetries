#include <iostream>
#include "math/vec2.h"
#include "math/Universe.h"


/* MITSCHRIFTEN

valgrind.org

*/

int main(){
	std::cout << "Moin!" << std::endl;

	math::Universe universe = math::Universe();
	universe.addPlane( math::Hyperplane() );

	math::vec2 x(0,1);
	std::vector<math::vec2> list = universe.getAllReflections(x, 2);

	for (int i = 0; i < list.size(); i++){
		std::cout << list[i] << std::endl;
	}

	std::cin.get();
	return 0;
}