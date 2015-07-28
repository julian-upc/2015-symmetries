#include "../math/Vector.h"
#include <boost\test\included\unit_test.hpp>

BOOST_AUTO_TEST_SUITE( vector )

BOOST_AUTO_TEST_CASE( simple_vec_test )
{
	math::Vector vec({ 1, 1, 1 });
	BOOST_CHECK_EQUAL( vec.getDimension(), 3 );
}

BOOST_AUTO_TEST_SUITE_END()