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

struct e6_fixture {
  GeneratorList e6generators;
  e6_fixture() 
    : e6generators()
  {generateE6(e6generators); }
  ~e6_fixture() {}
};

struct e7_fixture {
  GeneratorList e7generators;
  e7_fixture() 
    : e7generators()
  {generateE7(e7generators); }
  ~e7_fixture() {}
};

struct e8_fixture {
  GeneratorList e8generators;
  e8_fixture() 
    : e8generators()
  {generateE8(e8generators); }
  ~e8_fixture() {}
};


BOOST_FIXTURE_TEST_CASE( e6_orbit, e6_fixture )
{
  BOOST_CHECK_EQUAL(orbit(e6generators, {1, 2, 3, 4, 5, 6}).size(), (size_t) 51840);
}

BOOST_FIXTURE_TEST_CASE( e7_orbit, e7_fixture )
{
  BOOST_CHECK_EQUAL(orbit(e7generators, {1, 2, 3, 4, 5, 6, 7}).size(), (size_t) 2903040);
}

BOOST_FIXTURE_TEST_CASE( e8_orbit, e8_fixture )
{
  BOOST_CHECK_EQUAL(orbit(e8generators, {1, 2, 3, 4, 5, 6, 7, 8}).size(), (size_t) 696729600);
}