#include <shader.hpp>

namespace math3d
{
	shader::shader(scene& sc)
	:hit_an_object(false), local_hit_point(), vector(), rgb(), scn(sc)
	{}

	shader::~shader()
	{}
}
