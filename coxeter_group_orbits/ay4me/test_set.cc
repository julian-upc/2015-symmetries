#include <vector>
#include <set>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <numeric>
#include <cmath>
#include <boost/lexical_cast.hpp>


const static double epsilon = 0.00001;


template<typename T>
T relativeError(const std::vector<T>& x, const std::vector<T>& y)
{
  if (x.size() != y.size())
  {
    std::cout << x.size();
    std::cout << "\n different \n";
    std::cout << y.size();
    throw std::logic_error("Comparison between vectors of different size.");
  }
  std::vector<T> diff(x.size());
  T maxDiff = 0.0;
  T maxVal = 0.0;
  for (std::size_t i=0;i < x.size();++i)
  {
    diff[i] = x[i] - y[i];
    if (std::fabs(diff[i]) > maxDiff)
    {
      maxDiff = std::fabs(diff[i]);
    }
    if (std::fabs(x[i]) > maxVal)
    {
      maxVal = std::fabs(x[i]);
    }
  }
  // for (std::size_t i=0;i < x.size();++i)
  // {
  //   diff[i] = std::fabs(x[i])-std::fabs(y[i]);
  // }
  // T maxDiff = 0.0;
  // T maxVal = 0.0;
  // for (std::size_t i=0;i < x.size();++i)
  // {
  //   if (std::fabs(diff[i]) > std::fabs(maxDiff))
  //   {
  //     maxDiff = std::fabs(diff[i]);
  //   }
  //   if (std::fabs(x[i]) > std::fabs(maxVal))
  //   {
  //     maxVal = std::fabs(x[i]);
  //   }
  // }
  if (maxVal == 0.0)
  {
    //std::cout << "maximum Value was 0.\n";
    return maxDiff;
  }
  return maxDiff/maxVal;
}

template<typename T>
struct ImpreciseComp{
  bool operator()(const std::vector<T>& x, const std::vector<T>& y) const
  {
    if (relativeError(x,y) < epsilon)
    {
      //std::cout << "decided two vectors are not <, due to relativeError.\n";
      //std::cout << relativeError(x,y);
      //std::cout << "\n";
      return false;
    }
    //std::cout << "use normal compare.\n";
    return x < y;
  }
};

typedef double NumberType;  // this probably isn't going to work
typedef std::vector<NumberType> VectorType;
typedef std::vector<VectorType> GeneratorList;
typedef std::set<VectorType, ImpreciseComp<NumberType>> Orbit;

int main()
{
	Orbit x = {};
	VectorType point1 = {0.9,1,2,3};
	VectorType point2 = {1,2,3,4};
	x.insert(point1);
	std::set<VectorType>::iterator it = x.begin();
    const VectorType& currentPoint = *it;
    std::cout << currentPoint[0];
	x.erase(point1);
	std::cout << currentPoint[0];
	x.insert(point2);
	std::cout << x.size();

	std::string a = "foo";
	std::string b= a;
	a = "bar";
	std::cout << b;
}