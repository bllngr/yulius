#include "../include/camera.hpp"
#include <iosfwd>
#include <cmath>

camera::camera(double fovx)
: fovx_(fovx)
{}

void
camera::calc_dist(double width)
{
	distance_ = (width/2.0)/tan((fovx_/2.0)*(M_PI/180.0));
}

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
