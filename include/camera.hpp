#if !defined CAMERA_HPP
#define CAMERA_HPP

#include "point.hpp"

namespace math3d
{
	class camera
	{
		public:
			camera(double const&);
			void calc_dist(double const& width) const;
			double get_dist() const;
			
			double get_pos();
			
			~camera();

		private:
			double fovx_;	
			double distance_;
			point position_;

	};
}


#endif //CAMERA_HPP
