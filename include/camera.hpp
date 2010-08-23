#if !defined CAMERA_HPP
#define CAMERA_HPP

#include "point.hpp"

class camera
{
	public:
		camera(double);
		void calc_dist(double width);
		double get_dist() const;
		
		double get_pos();
		
		~camera();

	private:
		double fovx_;	
		double distance_;
		math3d::point position_;

};

#endif // CAMERA_HPP
