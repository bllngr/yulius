#include "../include/camera.hpp"
#include <iosfwd>
#include <cmath>

namespace math3d
{
	camera::camera(double const& fovx)
	: fovx_(fovx)
	{}

	void
	camera::calc_dist(double const& width) 
	{
		distance_ = (width/2.0)/tan((fovx_/2.0)*(M_PI/180.0));
	}

	double
	camera::get_dist() const
	{
		return distance_;
	}

	camera::~camera()
	{
	}
}
