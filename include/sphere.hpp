#if !defined SPHERE_HPP

#define SPHERE_HPP

#include <iosfwd>

#include "point.hpp"
#include "vector.hpp"
#include "ray.hpp"

	class sphere
	{
		public:
			sphere(math3d::point const&, double const&);
			~sphere();

			bool hit(ray const&) const;
		
		private:
			double radius_;
			math3d::point center_;
	};


#endif //SPHERE_HPP
