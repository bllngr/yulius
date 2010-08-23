#if !defined TRACER_HPP
#define TRACER_HPP

#include "ray.hpp"
#include "scnene.hpp"
#include "rgb.hpp"

namespace math3d
{
	class tracer
	{
		public:
			tracer();
			tracer(scene*);
			~tracer();

			virtual rgb trace_ray(ray const&) const;

		protected:
			scene* scene_ptr;
	};
}
#endif
