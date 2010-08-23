#if !defined SHADER_HPP
#define SHADER_HPP

#include "point.hpp"
#include "rgb.hpp"
#include "vector.hpp"

	class shader
	{
		public:
			bool hit_an_object;
			point local_hit_point;
			vector normal;
			rgb clr;
			scene& scn;

		public:
			shader(scene&);
			~shader();

	};

#endif //SHADER_HPP
