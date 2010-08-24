#if !defined SHADER_HPP
#define SHADER_HPP

#include "point.hpp"
#include "rgb.hpp"
#include "vector.hpp"

class shader
{
	public:
		bool hit_an_object;
		math3d::point local_hit_point;
		math3d::vector normal;
		rgb clr;
		// scene& scn;

	public:
		// shader(scene&);
		~shader();
};

#endif // SHADER_HPP
