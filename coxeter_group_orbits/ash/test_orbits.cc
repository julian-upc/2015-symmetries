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

#define BOOST_TEST_MODULE orbits
#include <boost/test/included/unit_test.hpp>

#include "orbit.h"
#include "stl_wrappers.h"

BOOST_AUTO_TEST_CASE( generators )
{
   std::ostringstream oss;
   oss << simple_roots_type_A(4) << std::endl
       << simple_roots_type_B(4) << std::endl
       << simple_roots_type_C(4) << std::endl
       << simple_roots_type_D(4) << std::endl
       << simple_roots_type_E6() << std::endl
       << simple_roots_type_E7() << std::endl
       << simple_roots_type_E8() << std::endl
       << simple_roots_type_F4() << std::endl
       << simple_roots_type_H3() << std::endl
       << simple_roots_type_H4() << std::endl;

   BOOST_CHECK_EQUAL(oss.str(), 
                     "{{1,-1,0,0,0},{0,1,-1,0,0},{0,0,1,-1,0},{0,0,0,1,-1}}\n"
                     "{{1,-1,0,0},{0,1,-1,0},{0,0,1,-1},{0,0,0,1}}\n"
                     "{{1,-1,0,0},{0,1,-1,0},{0,0,1,-1},{0,0,0,2}}\n"
                     "{{1,-1,0,0},{0,1,-1,0},{0,0,1,-1},{0,0,1,1}}\n"
                     "{{1,-1,0,0,0,0},{0,1,-1,0,0,0},{0,0,1,-1,0,0},{0,0,0,1,-1,0},{0,0,0,1,1,0},{-0.5,-0.5,-0.5,-0.5,-0.5,0.866025}}\n"
                     "{{1,-1,0,0,0,0,0},{0,1,-1,0,0,0,0},{0,0,1,-1,0,0,0},{0,0,0,1,-1,0,0},{0,0,0,0,1,-1,0},{0,0,0,0,1,1,0},{-0.5,-0.5,-0.5,-0.5,-0.5,-0.5,0.707107}}\n"
                     "{{1,-1,0,0,0,0,0,0},{0,1,-1,0,0,0,0,0},{0,0,1,-1,0,0,0,0},{0,0,0,1,-1,0,0,0},{0,0,0,0,1,-1,0,0},{0,0,0,0,0,1,-1,0},{0,0,0,0,0,1,1,0},{-0.5,-0.5,-0.5,-0.5,-0.5,-0.5,-0.5,-0.5}}\n"
                     "{{1,-1,0,0},{0,1,-1,0},{0,0,1,0},{-0.5,-0.5,-0.5,-0.5}}\n"
                     "{{2,0,0},{-1.61803,0.618034,-1},{0,0,2}}\n"
                     "{{1.30902,-0.309017,-0.309017,-0.309017},{-1,1,0,0},{0,-1,1,0},{0,0,-1,1}}\n"
                     );
}

//////// B ////////
struct b3_fixture {
  b3_fixture() 
    : generators(simple_roots('B', 3)) 
  {}
  GeneratorList generators;
};
struct b4_fixture {
  b4_fixture() 
    : generators(simple_roots('B', 4)) 
  {}
  GeneratorList generators;
};
struct b5_fixture {
  b5_fixture() 
    : generators(simple_roots('B', 5)) 
  {}
  GeneratorList generators;
};
struct b6_fixture {
  b6_fixture() 
    : generators(simple_roots('B', 6)) 
  {}
  GeneratorList generators;
};
struct b7_fixture {
  b7_fixture() 
    : generators(simple_roots('B', 7)) 
  {}
  GeneratorList generators;
};
struct b8_fixture {
  b8_fixture() 
    : generators(simple_roots('B', 8)) 
  {}
  GeneratorList generators;
};

//////// D ////////
struct d5_fixture {
  d5_fixture() 
    : generators(simple_roots('D', 5)) 
  {}
  GeneratorList generators;
};

//////// E ////////
struct e6_fixture {
  e6_fixture() 
    : generators(simple_roots('E', 6)) 
  {}
  GeneratorList generators;
};
struct e7_fixture {
  e7_fixture() 
    : generators(simple_roots('E', 7)) 
  {}
  GeneratorList generators;
};

//////// F ////////
struct f4_fixture {
  f4_fixture() 
    : generators(simple_roots('F', 4)) 
  {}
  GeneratorList generators;
};

//////// H ////////
struct h3_fixture {
  h3_fixture() 
    : generators(simple_roots('H', 3)) 
  {}
  GeneratorList generators;
};
struct h4_fixture {
  h4_fixture() 
    : generators(simple_roots('H', 4)) 
  {}
  GeneratorList generators;
};


//////// B ////////
BOOST_FIXTURE_TEST_CASE( b3_orbit_012, b3_fixture )
{
  BOOST_CHECK_EQUAL(orbit(generators, {1, 2, 3}).size(), (size_t) 48);
}

BOOST_FIXTURE_TEST_CASE( b3_orbit_12, b3_fixture )
{
  BOOST_CHECK_EQUAL(orbit(generators, {1, 1, 3}).size(), (size_t) 24);
}

BOOST_FIXTURE_TEST_CASE( b3_orbit_02, b3_fixture )
{
  BOOST_CHECK_EQUAL(orbit(generators, {1, 2, 2}).size(), (size_t) 24);
}

BOOST_FIXTURE_TEST_CASE( b3_orbit_01, b3_fixture )
{
  BOOST_CHECK_EQUAL(orbit(generators, {1, 2, 0}).size(), (size_t) 24);
}
BOOST_FIXTURE_TEST_CASE( b3_orbit_0, b3_fixture )
{
  BOOST_CHECK_EQUAL(orbit(generators, {1, 0, 0}).size(), (size_t) 6);
}
BOOST_FIXTURE_TEST_CASE( b3_orbit_1, b3_fixture )
{
  BOOST_CHECK_EQUAL(orbit(generators, {1, 1, 0}).size(), (size_t) 12);
}
BOOST_FIXTURE_TEST_CASE( b3_orbit_2, b3_fixture )
{
  BOOST_CHECK_EQUAL(orbit(generators, {1, 1, 1}).size(), (size_t) 8);
}

BOOST_FIXTURE_TEST_CASE( b5_orbit, b5_fixture )
{
  BOOST_CHECK_EQUAL(orbit(generators, {1, 2, 3, 4, 5}).size(), (size_t) 3840);
}

BOOST_FIXTURE_TEST_CASE( b6_orbit, b6_fixture )
{
  BOOST_CHECK_EQUAL(orbit(generators, {1, 2, 3, 4, 5, 6}).size(), (size_t) 46080);
}

/*
BOOST_FIXTURE_TEST_CASE( b7_orbit, b7_fixture )
{
  BOOST_CHECK_EQUAL(orbit(generators, {1, 2, 3, 4, 5, 6, 7}).size(), (size_t) 645120);
}
BOOST_FIXTURE_TEST_CASE( b8_orbit, b8_fixture )
{
  BOOST_CHECK_EQUAL(orbit(generators, {1, 0, 0, 0, 0, 0, 0, 0}).size(), (size_t) 10321920);
}
*/
//////// D ////////
BOOST_FIXTURE_TEST_CASE( d5_orbit, d5_fixture )
{
  BOOST_CHECK_EQUAL(orbit(generators, {1, 2, 3, 4, 5}).size(), (size_t) 1920);
}

//////// E ////////
BOOST_FIXTURE_TEST_CASE( e6_orbit, e6_fixture )
{
  BOOST_CHECK_EQUAL(orbit(generators, {1, 2, 3, 4, 5, 6}).size(), (size_t) 51840);
}
/*BOOST_FIXTURE_TEST_CASE( e7_orbit, e7_fixture )
{
  BOOST_CHECK_EQUAL(orbit(generators, {1, 0, 0, 0, 0, 0, 0}).size(), (size_t) 2903040);
}
*/
//////// F ////////
BOOST_FIXTURE_TEST_CASE( f4_orbit, f4_fixture )
{
  BOOST_CHECK_EQUAL(orbit(generators, {3, 2, 1, -5}).size(), (size_t) 1152);
}

//////// H ////////
BOOST_FIXTURE_TEST_CASE( h3_orbit, h3_fixture )
{
  BOOST_CHECK_EQUAL(orbit(generators, {1, 2, 3}).size(), (size_t) 120);
}
BOOST_FIXTURE_TEST_CASE( h4_orbit, h4_fixture )
{
  BOOST_CHECK_EQUAL(orbit(generators, {1, 2, 3, 4}).size(), (size_t) 14400);
}


// Local Variables:
// mode:C++
// c-basic-offset:3
// indent-tabs-mode:nil
// End:
