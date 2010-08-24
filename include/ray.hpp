#if !defined(BUW_MATH3D_RAY_HPP)
#define BUW_MATH3D_RAY_HPP

#include <iosfwd>
#include "point.hpp"
#include "vector.hpp"

class ray
{
	public:
		math3d::point o;
		math3d::vector d;

	public:
		ray(math3d::point const& p, math3d::vector const& v)
		:o(p), d(v)
		{};
		~ray()
		{}

};

#endif // RAY_HPP
