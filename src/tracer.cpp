#include <tracer.hpp>

tracer::tracer()
{}

tracer::tracer(scene* s_ptr)
:s_ptr(NULL)
{}

tracer::tracer(scene* s_ptr)
:scene_ptr(s_ptr)
{}

rgb
tracer::trace_ray(ray const& r) const
{
	return rgb(0,0,0);
}
