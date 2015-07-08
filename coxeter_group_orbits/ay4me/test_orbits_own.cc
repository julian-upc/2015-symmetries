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
};

struct d6_fixture {
  GeneratorList d6generators;
  d6_fixture() 
    : d6generators()
  {generateD(6,d6generators); }
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

struct e6_fixture {
  GeneratorList e6generators;
  e6_fixture() 
    : e6generators()
  {generateE6(e6generators); }
};

struct e7_fixture {
  GeneratorList e7generators;
  e7_fixture() 
    : e7generators()
  {generateE7(e7generators); }
};

struct e8_fixture {
  GeneratorList e8generators;
  e8_fixture() 
    : e8generators()
  {generateE8(e8generators); }
};

//B testcases 3-8
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

BOOST_FIXTURE_TEST_CASE( b8_orbit, b8_fixture )
{
  BOOST_CHECK_EQUAL(orbit(b8generators, {1, 2, 3, 4, 5, 6, 7, 8}).size(), (size_t) 10321920);
}

//D testcases 3-8
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

BOOST_FIXTURE_TEST_CASE( d8_orbit, d8_fixture )
{
  BOOST_CHECK_EQUAL(orbit(d8generators, {1, 2, 3, 4, 5, 6, 7, 8}).size(), (size_t) 5160960);
}