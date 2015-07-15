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

struct h3_fixture {
  GeneratorList h3generators;
  h3_fixture() 
    : h3generators()
  {generateH3(h3generators); }
  ~h3_fixture() {}
};

struct h4_fixture {
  GeneratorList h4generators;
  h4_fixture() 
    : h4generators()
  {generateH4(h4generators); }
  ~h4_fixture() {}
};


BOOST_FIXTURE_TEST_CASE( h3_orbit, h3_fixture )
{
  BOOST_CHECK_EQUAL(orbit(h3generators, {1, 2, 3}).size(), (size_t) 120);
}

BOOST_FIXTURE_TEST_CASE( h4_orbit_1, h4_fixture )
{
  BOOST_CHECK_EQUAL(orbit(h4generators, {1, 2, 3, 4}).size(), (size_t) 14400);
}

BOOST_FIXTURE_TEST_CASE( h4_orbit_2, h4_fixture )
{
  BOOST_CHECK_EQUAL(orbit(h4generators, {1, 2.4, 3, 3.8}).size(), (size_t) 14400);
}
