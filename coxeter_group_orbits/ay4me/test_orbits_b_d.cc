/* Copyright (c) 2015
   Julian Pfeifle
   julian.pfeifle@upc.edu
   meike.hatzel@tu-berlin.de

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

struct b3_fixture {
  GeneratorList b3generators;
  b3_fixture() 
    : b3generators()
  {generateB(3,b3generators); }
};

struct d3_fixture {
  GeneratorList d3generators;
  d3_fixture() 
    : d3generators()
  {generateD(3,d3generators); }
};

struct b4_fixture {
  GeneratorList b4generators;
  b4_fixture() 
    : b4generators()
  {generateB(4,b4generators); }
};

struct d4_fixture {
  GeneratorList d4generators;
  d4_fixture() 
    : d4generators()
  {generateD(4,d4generators); }
};

struct b5_fixture {
  GeneratorList b5generators;
  b5_fixture() 
    : b5generators()
  {generateB(5,b5generators); }
};

struct d5_fixture {
  GeneratorList d5generators;
  d5_fixture() 
    : d5generators()
  {generateD(5,d5generators); }
};

struct b6_fixture {
  GeneratorList b6generators;
  b6_fixture() 
    : b6generators()
  {generateB(6,b6generators); }
  ~b6_fixture() {}
};

struct d6_fixture {
  GeneratorList d6generators;
  d6_fixture() 
    : d6generators()
  {generateD(6,d6generators); }
  ~d6_fixture() {}
};

struct b7_fixture {
  GeneratorList b7generators;
  b7_fixture() 
    : b7generators()
  {generateB(7,b7generators); }
};

struct d7_fixture {
  GeneratorList d7generators;
  d7_fixture() 
    : d7generators()
  {generateD(7,d7generators); }
};


//B testcases 3-7
BOOST_FIXTURE_TEST_CASE( b3_orbit_1, b3_fixture )
{
  BOOST_CHECK_EQUAL(orbit(b3generators, {1, 2, 3}).size(), (size_t) 48);
}

BOOST_FIXTURE_TEST_CASE( b3_orbit_2, b3_fixture )
{
  BOOST_CHECK_EQUAL(orbit(b3generators, {1, 1, 3}).size(), (size_t) 24);
}

BOOST_FIXTURE_TEST_CASE( b4_orbit, b4_fixture )
{
  BOOST_CHECK_EQUAL(orbit(b4generators, {1, 2, 3, 4}).size(), (size_t) 384);
}

BOOST_FIXTURE_TEST_CASE( b5_orbit, b5_fixture )
{
  BOOST_CHECK_EQUAL(orbit(b5generators, {1, 2, 3, 4, 5}).size(), (size_t) 3840);
}

BOOST_FIXTURE_TEST_CASE( b6_orbit, b6_fixture )
{
  BOOST_CHECK_EQUAL(orbit(b6generators, {1, 2, 3, 4, 5, 6}).size(), (size_t) 46080);
}

BOOST_FIXTURE_TEST_CASE( b7_orbit, b7_fixture )
{
  BOOST_CHECK_EQUAL(orbit(b7generators, {1, 2, 3, 4, 5, 6, 7}).size(), (size_t) 645120);
}

//D testcases 3-7
BOOST_FIXTURE_TEST_CASE( d3_orbit_1, d3_fixture )
{
  BOOST_CHECK_EQUAL(orbit(d3generators, {1, 2, 3}).size(), (size_t) 24);
}

BOOST_FIXTURE_TEST_CASE( d3_orbit_2, d3_fixture )
{
  BOOST_CHECK_EQUAL(orbit(d3generators, {1, 1, 3}).size(), (size_t) 12);
}

BOOST_FIXTURE_TEST_CASE( d4_orbit, d4_fixture )
{
  BOOST_CHECK_EQUAL(orbit(d4generators, {1, 2, 3, 4}).size(), (size_t) 192);
}

BOOST_FIXTURE_TEST_CASE( d5_orbit, d5_fixture )
{
  BOOST_CHECK_EQUAL(orbit(d5generators, {1, 2, 3, 4, 5}).size(), (size_t) 1920);
}

BOOST_FIXTURE_TEST_CASE( d6_orbit, d6_fixture )
{
  BOOST_CHECK_EQUAL(orbit(d6generators, {1, 2, 3, 4, 5, 6}).size(), (size_t) 23040);
}

BOOST_FIXTURE_TEST_CASE( d7_orbit, d7_fixture )
{
  BOOST_CHECK_EQUAL(orbit(d7generators, {1, 2, 3, 4, 5, 6, 7}).size(), (size_t) 322560);
}
