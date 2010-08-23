#if !defined SCENE_HPP
#define SCENE_HPP

#include "sphere.hpp"
#include "camera.hpp"
#include "tracer.hpp"
#include "rgb.hpp"

namespace math3d
{
	class scene
	{
		public:
			camera cam;
			rgb bkg_clr; //background color
			sphere sphr;
			tracer* tracer_ptr;

			scene();
			void build();
			void render_scene() const;
			void open_window(int const hres, int const vres) const;
			void display_pixel(int const row, int const column, rgb const& pixel_clr) const;
			~scene();

	};
}
#endif //SCENE_HPP
