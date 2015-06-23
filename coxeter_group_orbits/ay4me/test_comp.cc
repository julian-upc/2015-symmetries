#include <vector>
#include <set>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <numeric>
#include <cmath>
#include <boost/lexical_cast.hpp>

const static double epsilon = 0.0000001;

template<typename T>
T relativeError(const std::vector<T>& x, const std::vector<T>& y)
{
  if (x.size() != y.size())
  {
    throw std::logic_error("Comparison between vectors of different size.");
  }
  std::vector<T> diff(x.size());
  T maxDiff = 0.0;
  T maxVal = 0.0;
  for (std::size_t i=0;i < x.size();++i)
  {
    diff[i] = std::fabs(x[i])-std::fabs(y[i]);
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
      return false;
    }
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
  VectorType point1 = {-6.34808,  2.65192,  0.348076 , -4.34808 , -3.34808 , 3.66506};
  VectorType point2 = {-6.34808,  2.65192,  0.348076 , -4.34808 , -3.34808 , 3.66506};
  x.insert(point1);
  x.insert(point2);
  std::cout << x.size();
}