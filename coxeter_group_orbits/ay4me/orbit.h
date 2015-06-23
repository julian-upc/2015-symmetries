/* Copyright (c) 2015
   Julian Pfeifle
   julian.pfeifle@upc.edu

   This program is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the
   Free Software Foundation; either version 3, or (at your option) any
   later version: http://www.gnu.org/licenses/gpl.txt.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
--------------------------------------------------------------------------------
*/

#ifndef __ORBIT_H_
#define __ORBIT_H_

#include <vector>
#include <set>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <numeric>
#include <cmath>
#include <boost/lexical_cast.hpp>


class NotImplementedException : public std::exception {};
class InvalidInputException : public std::logic_error {
public:
  InvalidInputException():std::logic_error("no error message") {};
  InvalidInputException(const std::string& s):std::logic_error(s) {};
};
class InvalidGeneratorException : public std::logic_error {
public:
  InvalidGeneratorException():std::logic_error("no error message") {};
  InvalidGeneratorException(const std::string& s):std::logic_error(s) {};
};

//const static double epsilon = 1e-20;
//const static double epsilon = 0;
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
typedef std::set<VectorType,ImpreciseComp<NumberType>> Orbit;
//,ImpreciseComp<NumberType>

void out(std::ostream& file,const Orbit& solution, bool outputOrbit);

GeneratorList simple_roots(char type, std::size_t dim)
{
   switch(type) {
   case 'b':
   case 'B':
      if (dim != 3) throw NotImplementedException();
      return {{1,-1,0},{0,1,-1},{0,0,1}};

   default:
      throw NotImplementedException();
   }
}

void generateA(std::size_t dim, GeneratorList& generators)
{
  generators.resize(dim, VectorType(dim+1));
  for (std::size_t i=0; i<dim; ++i)
  {
    for (std::size_t j=0; j<dim+1; ++j)
    {
      if (i == j)
      {
        generators[i][j] = 1;
      }
      else if (i+1 == j)
      {
        generators[i][j] = -1;
      }
      else
      {
        generators[i][j] = 0;
      }
    }
  }
}

void generateB(std::size_t dim, GeneratorList& generators)
{
  generators.resize(dim, VectorType(dim));
  for (std::size_t i=0; i<dim; ++i)
  {
    for (std::size_t j=0; j<dim; ++j)
    {
      if (i == j)
      {
        generators[i][j] = 1;
      }
      else if (i+1 == j)
      {
        generators[i][j] = -1;
      }
      else
      {
        generators[i][j] = 0;
      }
    }
  }
}

void generateD(std::size_t dim, GeneratorList& generators)
{
  generators.resize(dim, VectorType(dim));
  for (std::size_t i=0; i<dim; ++i)
  {
    for (std::size_t j=0; j<dim; ++j)
    {
      if (i == j)
      {
        generators[i][j] = 1;
      }
      else if (i+1 == j)
      {
        generators[i][j] = -1;
      }
      else if (i == dim-1 && j == dim-2)
      {
        generators[i][j] = 1;
      }
      else
      {
        generators[i][j] = 0;
      }
    }
  }
}

void generateE6(GeneratorList& generators)
{
  VectorType v(6);
  for (int i=0; i<5; ++i)
    v[i] = -0.5;
  v[5] = 0.5 * sqrt(3);
  generateD(5, generators);
  for (int i=0; i<5; ++i)
    generators[i].push_back(0);
  generators.push_back(v);
}

void generateE7(GeneratorList& generators)
{
  VectorType v(7);
  for (int i=0; i<6; ++i)
    v[i] = -0.5;
  v[6] = 0.5 * sqrt(2);
  generateD(6, generators);
  for (int i=0; i<6; ++i)
    generators[i].push_back(0);
  generators.push_back(v);
}

void generateE8(GeneratorList& generators)
{
  VectorType v(8);
  for (int i=0; i<8; ++i)
    v[i] = -0.5;
  generateD(7,generators);
  for (int i=0; i<7; ++i)
    generators[i].push_back(0);
  generators.push_back(v);
}

void generateF4(GeneratorList& generators)
{
  generators.resize(4,VectorType(4));
  generators[0][0] = generators[1][1] = generators[2][2] = 1;
  generators[0][1] = generators[1][2] = -1;
  generators[3][0] = generators[3][1] = generators[3][2] = generators[3][3] = -0.5;
}

void generateG2(GeneratorList& generators)
{
  generators.resize(2,VectorType(3));
  generators[0][0] = 1;
  generators[0][1] = generators[1][0] = generators[1][2] = -1;
  generators[1][1] = 2;
}

void generateH3(GeneratorList& generators)
{
  const NumberType tau(0.5 + 0.5 * sqrt(5)); // golden ratio
  generators.resize(3,VectorType(3));
  generators[0][0] = generators[2][2] = 2;
  generators[1][0] = -tau; 
  generators[1][1] = tau - 1; 
  generators[1][2] = -1;
}

void generateH4(GeneratorList& generators)
{
  const NumberType tau(0.5 + 0.5 * sqrt(5)); // golden ratio
  generators.resize(4, VectorType(4));
  generators[0][0] = (1+tau) * 0.5;
  generators[0][1] = generators[0][2] = generators[0][3] = (1-tau) * 0.5;
  for (int i=0; i<3; ++i)
  {
    generators[i+1][i] = -1;
    generators[i+1][i+1] = 1;
  }
}

void input(std::string filename, VectorType& point, GeneratorList& generators)
{
  std::ifstream input( filename );
  std::string line; 
  getline( input, line );
    //process first line
  if(line.length() < 2)
  {
    throw InvalidInputException("No valid coxeter.");
  }
  char letter = line[0];
  std::size_t dim;
  std::istringstream s(line.substr(1));
  s >> dim;
  point.resize(dim);
  switch(letter) {
    case 'A':
        generateA(dim, generators);
        break;
    case 'B':
        generateB(dim, generators);
        break;
    case 'D':
        generateD(dim, generators);
        break;
    case 'E':
        switch(dim) {
          case 6:
            generateE6(generators);
            break;
          case 7:
            generateE7(generators);
            break;
          case 8:
            generateE8(generators);
            break;
          default:
            throw InvalidInputException("E with wrong dimension number.");
        }
        out(std::cout, Orbit(generators.begin(),generators.end()),true);
        break;
    case 'F':
        if (dim != 4)
        {
          throw InvalidInputException("F with wrong dimension number.");
        }
        generateF4(generators);
        break;
    case 'G':
        if (dim != 2)
        {
          throw InvalidInputException("G with wrong dimension number.");
        }
        generateG2(generators);
        break;
    case 'H':
        if( dim != 3 && dim != 4)
        {
          throw InvalidInputException("H with wrong dimension number.");
        }
        else if(dim == 3)
        {
          generateH3(generators);
        }
        else
        {
          generateH4(generators);
        }
        break;
    case 'I':
        break;
    default:
       throw InvalidInputException("Infinite or unknown coxeter group.");
  }
  getline( input, line );
  //process second line
  if(line.length() < 2*dim+1) //at least one number per dimension and number of dimension minus one many spaces in between, 2 brackets
  {
    throw InvalidInputException("Point vector too short.");
  }
  if(line[0]!='{' || line[line.length()-1]!='}')
  {
    throw InvalidInputException("Malformed point vector.");
  }
  std::stringstream lineIn(line.substr(1,line.length()-2));
  for(std::size_t i = 0; i < dim; ++i)
  {
    lineIn >> point[i];
  }
  if(getline( input, line ))
  {
    throw InvalidInputException("Wrong number of lines.");
  }
}

int factorial(int n)
{
  if (n == 0 || n == 1)
  {
    return 1;
  }
  return factorial(n-1)*n;
}

bool divisor(int d, int n)
{
  return n%d == 0;
}

void sanityCheck(int orbitSize, std::string filename)
{
  std::ifstream input( filename );
  std::string line; 
  getline( input, line );
  char letter = line[0]; //get name of coxeter
  std::size_t dim = line[1]-'0'; //get dimension of coxeter
  int maxOrbit = 0;
  switch(letter) {
    case 'A':
        maxOrbit = factorial(dim+1);
        if (!divisor(orbitSize,maxOrbit))
        {
          throw InvalidGeneratorException("Orbitsize is not divisor of the maximum one.");
        }
        break;
    case 'B':
        if (dim < 4)
        {
          maxOrbit = factorial(dim+1);
        }
        else
        {
          maxOrbit = (1<<dim)*factorial(dim);
        }
        if (!divisor(orbitSize,maxOrbit))
        {
          throw InvalidGeneratorException("Orbitsize is not divisor of the maximum one.");
        }
        break;
    case 'D':
        if (dim < 4)
        {
          maxOrbit = factorial(dim+1);
        }
        else
        {
          maxOrbit = (1<<(dim-1))*factorial(dim);
        }
        if (!divisor(orbitSize,maxOrbit))
        {
          throw InvalidGeneratorException("Orbitsize is not divisor of the maximum one.");
        }
        break;
    case 'E':
        break;
    case 'F':
        break;
    case 'G':
        break;
    case 'H':
        break;
    case 'I':
        break;
    default:
       throw InvalidInputException("Infinite or unknown coxeter group.");
  }
}

VectorType mirror(const VectorType& v, const VectorType& plane)
{
  std::cout << "first entry: ";
  std::cout << v[0];
  std::cout << " \n ";
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

void recorbit(const GeneratorList& generators, const VectorType& v, Orbit& history)
{
  if(history.find(v) != history.end())
  {
    return;
  }  
  history.insert(v);
  for(const auto& plane : generators)
  {
    VectorType newVector = mirror(v,plane);
    recorbit(generators,newVector,history);
  }
  return;
}

//template <class T1, class T2> struct pair;

void iterorbit(const GeneratorList& generators, const VectorType& v, Orbit& history)
{
  std::set<VectorType,ImpreciseComp<NumberType>> unmirroredPoints = {v};
  //history = {v};
  //, ImpreciseComp<NumberType>
  while(!unmirroredPoints.empty())
  {
    std::set<VectorType>::iterator it = unmirroredPoints.begin();
    const VectorType& currentPoint = *it;
    //const VectorType& currentPoint(*(unmirroredPoints.begin()));
    std::pair<std::set<VectorType,ImpreciseComp<NumberType>>::iterator, bool> p = history.insert(currentPoint);
    std::cout << p.second;
    std::cout << "\n";
    std::cout << currentPoint[0];
    std::cout << "  ";
    // std::cout << currentPoint[1];
    // std::cout << "  ";
    // std::cout << currentPoint[2];
    // std::cout << "  ";
    // std::cout << currentPoint[3];
    // std::cout << "  ";
    // std::cout << currentPoint[4];
    // std::cout << "  ";
    // std::cout << currentPoint[5];
    // std::cout << "\n";
    unmirroredPoints.erase(it);
    std::cout << "\n";
    std::cout << currentPoint[0];
    std::cout << "  ";
    std::cout << "before mirroring\n";
    out(std::cout, history, true);
    for(const auto& plane : generators)
    {
      std::cout << "first entry: ";
      std::cout << currentPoint[0];
      std::cout << " \n ";
      VectorType mirroredPoint = mirror(currentPoint,plane);
      //mirroredPoint = mirror(currentPoint,plane);
      // if(history.find({-2,  7,  4.69615,  0,  1,  -3.86603}) == history.end())
      // {
      //   std::cout << "not in";
      // }
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
      if(history.find(mirroredPoint) == history.end())
      {
        unmirroredPoints.insert(mirroredPoint);
      }
      // else{
      //   std::cout << "found";
      // }
    }
    std::cout << "after mirroring\n";
    out(std::cout, history, true);
    // std::cout << history.size();
    // //out(std::cout, history, true);
    // std::cout << "\n";
    // std::cout << "ToDo:\n";
    // // out(std::cout, unmirroredPoints, true);
    // std::cout << unmirroredPoints.size();
    // std::cout << "\n";
    // unmirroredPoints.erase(it);
    // std::cout << i;
    // std::cout << "\n";
  }
  return;
}

Orbit orbit(const GeneratorList& generators, const VectorType& v)
{
  Orbit solution = {};
  iterorbit(generators, v, solution);
  return solution;
}


void out(std::ostream& file,const Orbit& solution, bool outputOrbit)
{
  if(outputOrbit)
  {
    file << "{\n";
    for (const auto& point:solution)
    {
      file << "  {";
      bool first = true;
      for (const auto& val: point)
      {
        if(!first)
        {
          file << " ";
        }
        file << val;
        first = false;
      }
      file << "}\n";
    }
    file << "}\n";
  }
  file << boost::lexical_cast<std::string>(solution.size());
}


#endif // __ORBIT_H_

// Local Variables:
// mode:C++
// c-basic-offset:3
// indent-tabs-mode:nil
// End:

//out(std::cout, Orbit(generators.begin(),generators.end()),true);
