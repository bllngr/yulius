#if !defined(BUW_MATH3D_RAY_HPP)
#define BUW_MATH3D_RAY_HPP

#include <iosfwd>
#include "point.hpp"
#include "vector.hpp"

namespace math3d
{
	class ray
	{
		public:
			point o;
			vector d;

		public:
			ray(point const& p, vector const& v)
			:o(p), d(v)
			{};
			~ray();

	};
}

#endif //RAY_HPP
