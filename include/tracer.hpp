#if !defined TRACER_HPP
#define TRACER_HPP

#include "ray.hpp"
#include "scene.hpp"
#include "rgb.hpp"

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

#endif
