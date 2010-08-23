#include <sphere.hpp>
#include <iosfwd>
#include <cmath>


	sphere::sphere(math3d::point const& p, double const& r)
	: radius_(r), center_(p)
	{
	}

	sphere::~sphere()
	{
	}

	bool
	sphere::hit(ray const& r) const
	{
		double t;
		math3d::vector temp = r.o - center_;
		double a = math3d::dot(r.d, r.d);
		double b = 2.0 * math3d::dot(temp, r.d);
		double c = math3d::dot(temp, temp) - radius_ * radius_;
		double disc = b * b - 4.0 * a * c;

		if(disc < 0.0)
			return false;
		else
		{
			double e = sqrt(disc);
			double denom = 2.0 * a;
			t = (-b - e)/denom;

			if(t > 0.000001)
			{
				// tmin = t;
				// sr.normal = (temp + t*r.d)/radius_;
				// sr.local_hit_point = r.o + t*r.d;
				return true;
			}

			t = (-b + e)/denom;

			if(t > 0.000001)
			{
				// tmin = t;
				// sr.normal = (temp + t*r.d)/radius_;
				// sr.local_hit_point = r.o + t*r.d;
				return true;
			}
		}

		return false;
	}

