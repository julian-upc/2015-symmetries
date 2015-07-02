#include "orbit.h"
#include <ctime>
#include <fstream>
#include <functional>

int power(int n, int e)
{
	int p = n;
	while (e>1)
	{
		p = p*n;
		e = e-1;
	}
	return p;
}

int createOrbit(std::function<void (std::size_t,GeneratorList&)> generatingFunction,VectorType point)
{
	Orbit generatedOrbit;
	GeneratorList generators;
	generatingFunction(point.size(),generators);
	generatedOrbit = orbit(generators,point);
	return generatedOrbit.size();
}

int createOrbit(std::function<void (GeneratorList&)> generatingFunction,VectorType point)
{
	Orbit generatedOrbit;
	GeneratorList generators;
	generatingFunction(generators);
	generatedOrbit = orbit(generators,point);
	return generatedOrbit.size();
}

void analysis_out(std::ofstream& file, int coxeter_orbit, int coxeter_orbit_computed, std::string coxeter_name, double runtime)
{
	file << coxeter_name;
	file << "\n got: ";
	file << coxeter_orbit_computed;
	file << " wanted: ";
	file << coxeter_orbit;
	file << "\n";
	file << "runtime: ";
	file << runtime;
	file << "\n\n";
	file << std::flush;
}

int main()
{   
	clock_t start;
	clock_t stop;
	double runtime = 0.0;

	std::ofstream file;
	file.open ("analysis_output.txt");

	//B3
	assert((start = clock())!=-1);
	int b3 = createOrbit(generateB, {1,2,3});
	stop = clock();
	runtime = (double) (stop - start) / CLOCKS_PER_SEC;
	analysis_out(file, power(2,3) * factorial(3), b3, "B3", runtime);

	//D3
	assert((start = clock())!=-1);
	int d3 = createOrbit(generateD, {1,2,3});
	stop = clock();
	runtime = (double) (stop - start) / CLOCKS_PER_SEC;
	analysis_out(file, power(2,3-1) * factorial(3), d3, "D3", runtime);

	//B4
	assert((start = clock())!=-1);
	int b4 = createOrbit(generateB, {1,2,3,4});
	stop = clock();
	runtime = (double) (stop - start) / CLOCKS_PER_SEC;
	analysis_out(file, power(2,4) * factorial(4), b4, "B4", runtime);

	//D4
	assert((start = clock())!=-1);
	int d4 = createOrbit(generateD, {1,2,3,4});
	stop = clock();
	runtime = (double) (stop - start) / CLOCKS_PER_SEC;
	analysis_out(file, power(2,4-1) * factorial(4), d4, "D4", runtime);

	//B5
	assert((start = clock())!=-1);
	int b5 = createOrbit(generateB, {1,2,3,4,5});
	stop = clock();
	runtime = (double) (stop - start) / CLOCKS_PER_SEC;
	analysis_out(file, power(2,5) * factorial(5), b5, "B5", runtime);

	//D5
	assert((start = clock())!=-1);
	int d5 = createOrbit(generateD, {1,2,3,4,5});
	stop = clock();
	runtime = (double) (stop - start) / CLOCKS_PER_SEC;
	analysis_out(file, power(2,5-1) * factorial(5), d5, "D5", runtime);

	//B6
	assert((start = clock())!=-1);
	int b6 = createOrbit(generateB, {1,2,3,4,5,6});
	stop = clock();
	runtime = (double) (stop - start) / CLOCKS_PER_SEC;
	analysis_out(file, power(2,6) * factorial(6), b6, "B6", runtime);

	//D6
	assert((start = clock())!=-1);
	int d6 = createOrbit(generateD, {1,2,3,4,5,6});
	stop = clock();
	runtime = (double) (stop - start) / CLOCKS_PER_SEC;
	analysis_out(file, power(2,6-1) * factorial(6), d6, "D6", runtime);

	//B7
	assert((start = clock())!=-1);
	int b7 = createOrbit(generateB, {1,2,3,4,5,6,7});
	stop = clock();
	runtime = (double) (stop - start) / CLOCKS_PER_SEC;
	analysis_out(file, power(2,7) * factorial(7), b7, "B7", runtime);

	//D7
	assert((start = clock())!=-1);
	int d7 = createOrbit(generateD, {1,2,3,4,5,6,7});
	stop = clock();
	runtime = (double) (stop - start) / CLOCKS_PER_SEC;
	analysis_out(file, power(2,7-1) * factorial(7), d7, "D7", runtime);

	//E6
	assert((start = clock())!=-1);
	int e6 = createOrbit(generateE6, {1,2,3,4,5,6});
	stop = clock();
	runtime = (double) (stop - start) / CLOCKS_PER_SEC;
	analysis_out(file, 51840, e6, "E6", runtime);

	//F4
	assert((start = clock())!=-1);
	int f4 = createOrbit(generateF4, {1,-3,5,-4});
	stop = clock();
	runtime = (double) (stop - start) / CLOCKS_PER_SEC;
	analysis_out(file, 1152, f4, "F4", runtime);

	//H3
	assert((start = clock())!=-1);
	int h3 = createOrbit(generateH3, {1,2,3});
	stop = clock();
	runtime = (double) (stop - start) / CLOCKS_PER_SEC;
	analysis_out(file, 120, h3, "H3", runtime);

	// //B8
	// assert((start = clock())!=-1);
	// int b8 = createOrbit(generateB, {1,2,3,4,5,6,7,8});
	// stop = clock();
	// runtime = (double) (stop - start) / CLOCKS_PER_SEC;
	// analysis_out(file, power(2,8) * factorial(8), b8, "B8", runtime);

	// //D8
	// assert((start = clock())!=-1);
	// int d8 = createOrbit(generateD, {1,2,3,4,5,6,7,8});
	// stop = clock();
	// runtime = (double) (stop - start) / CLOCKS_PER_SEC;
	// analysis_out(file, power(2,8-1) * factorial(8), d8, "D8", runtime);

	// //E7
	// assert((start = clock())!=-1);
	// int e7 = createOrbit(generateE7, {1,2,3,4,5,6,7});
	// stop = clock();
	// runtime = (double) (stop - start) / CLOCKS_PER_SEC;
	// analysis_out(file, 2903040, e7, "E7", runtime);

	//H4
	assert((start = clock())!=-1);
	int h4 = createOrbit(generateH4, {1,2,3,4});
	stop = clock();
	runtime = (double) (stop - start) / CLOCKS_PER_SEC;
	analysis_out(file, 14400, h4, "H4", runtime);

	//E8
	assert((start = clock())!=-1);
	int e8 = createOrbit(generateE8, {1,2,3,4,5,6,7,8});
	stop = clock();
	runtime = (double) (stop - start) / CLOCKS_PER_SEC;
	analysis_out(file, 696729600, e8, "E8", runtime);
}
