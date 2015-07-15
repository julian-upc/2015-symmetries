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


struct e8_fixture {
  GeneratorList e8generators;
  e8_fixture() 
    : e8generators()
  {generateE8(e8generators); }
  ~e8_fixture() {}
};



BOOST_FIXTURE_TEST_CASE( e8_orbit, e8_fixture )
{
  BOOST_CHECK_EQUAL(orbit(e8generators, {1, 2, 3, 4, 5, 6, 7, 8}).size(), (size_t) 696729600);
}