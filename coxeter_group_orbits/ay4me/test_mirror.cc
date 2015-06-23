#include <vector>
#include <set>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <numeric>
#include <cmath>
#include <boost/lexical_cast.hpp>


const static double epsilon = 0.1;


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

VectorType mirror(const VectorType& v, const VectorType& plane)
{
  std::cout << "now mirror:\n";
  std::cout << v.size();
  std::cout << plane.size();
  std::cout << "v:\n";
  std::cout << v[0];
  std::cout << "  ";
  std::cout << v[1];
  std::cout << "  ";
  std::cout << v[2];
  std::cout << "  ";
  std::cout << v[3];
  std::cout << "  ";
  std::cout << v[4];
  std::cout << "  ";
  std::cout << v[5];
  std::cout << "\n";
  std::cout << "plane:\n";
  std::cout << plane[0];
  std::cout << "  ";
  std::cout << plane[1];
  std::cout << "  ";
  std::cout << plane[2];
  std::cout << "  ";
  std::cout << plane[3];
  std::cout << "  ";
  std::cout << plane[4];
  std::cout << "  ";
  std::cout << plane[5];
  std::cout << "\n";
  //mirror v on plane described by vector plane
  //double init = 0.0;
  //double init2 = 0.0;
  VectorType help(v.size());
  for (std::size_t i = 0; i<plane.size();++i)
  {
    std::cout << "normal vector: ";
    std::cout << std::inner_product(v.begin(), v.end(), plane.begin(), 0.0);
    help[i] = plane[i]*(2.0*std::inner_product(v.begin(), v.end(), plane.begin(), 0.0)) /
      std::inner_product(plane.begin(), plane.end(), plane.begin(), 0.0);
    std::cout << "\nhelp vector for i: ";
    std::cout << help[i];
    std::cout << "\n";
  }
  VectorType newPoint(v.size());
  for(std::size_t i = 0; i<v.size();++i)
  {
    newPoint[i] = v[i] - help[i];
  }
  std::cout << "\ndone:\n";
  std::cout << newPoint.size();
  return newPoint;
}

int main()
{
  VectorType v = {0.9,2,3,4,5,6};
  VectorType plane = {1,-1,0,0,0,0};
  std::cout << std::inner_product(v.begin(), v.end(), plane.begin(), 0.0);
  // VectorType newPoint = std::inner_product(v.begin(), v.end(), plane.begin(), 0.0);
  // std::cout << newPoint.size();
  // std::cout << "newPoint:\n";
  // std::cout << newPoint[0];
  // std::cout << "  ";
  // std::cout << newPoint[1];
  // std::cout << "  ";
  // std::cout << newPoint[2];
  // std::cout << "  ";
  // std::cout << newPoint[3];
  // std::cout << "  ";
  // std::cout << newPoint[4];
  // std::cout << "  ";
  // std::cout << newPoint[5];
  // std::cout << "\n";
}