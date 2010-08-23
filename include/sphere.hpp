#if !defined SPHERE_HPP

#define SPHERE_HPP

#include <iosfwd>

#include "point.hpp"
#include "vector.hpp"
#include "ray.hpp"

namespace math3d
{
	class sphere
	{
		public:
			sphere(point const&, double const&);
			~sphere();

			bool hit(ray const&) const;
		
		private:
			double radius_;
			point center_;
	};
}



#endif //SPHERE_HPP
