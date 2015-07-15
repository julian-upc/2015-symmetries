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

struct b8_fixture {
  GeneratorList b8generators;
  b8_fixture() 
    : b8generators()
  {generateB(8,b8generators); }
};

struct d8_fixture {
  GeneratorList d8generators;
  d8_fixture() 
    : d8generators()
  {generateD(8,d8generators); }
};

BOOST_FIXTURE_TEST_CASE( b8_orbit, b8_fixture )
{
  BOOST_CHECK_EQUAL(orbit(b8generators, {1, 2, 3, 4, 5, 6, 7, 8}).size(), (size_t) 10321920);
}

BOOST_FIXTURE_TEST_CASE( d8_orbit, d8_fixture )
{
  BOOST_CHECK_EQUAL(orbit(d8generators, {1, 2, 3, 4, 5, 6, 7, 8}).size(), (size_t) 5160960);
}