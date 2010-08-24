#include <glutwindow.hpp>
#include <ppmwriter.hpp>
#include <pixel.hpp>
#include <sphere.hpp>
#include <camera.hpp>

#include <iostream>
#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>

#ifdef __APPLE__
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif

// this is a dummy raytrace application
class rt_application 
{
public :
	void raytrace() const 
	{
		// size of a tile in checkerboard
		const std::size_t checkersize = 20;
	
		// get glutwindow instance
		glutwindow& gw = glutwindow::instance();
		
		// create a ppmwriter
		ppmwriter pw(gw.width(), gw.height(), "./checkerboard.ppm");

		// for all pixels of window
		//    v size_t
		for (size_t y = gw.height() - 1; y > 0; --y) {
			for (std::size_t x = 0; x < gw.width(); ++x) {

				// create cam
				math3d::point cam(0., 0., -40.);

				// create pixel at x,y
				pixel p(x, y);

				// 2d point for imaginary view plane
				math3d::point vp_pos( x - .5 * gw.width() + .5, y - .5 * gw.height() + .5, 0.0 );
				ray r(vp_pos, vp_pos - cam);

				// test for intersection
				sphere s(math3d::point(0.0, 0.0, 0.0), 60.0);
				sphere u(math3d::point(0.0, 0.0, 100.0), 120.0);

				// if(s.hit(r, 0.00001, t))
				if (s.hit(r))
				{
					p.color = rgb(1.0, 0, 0);
				} else
					{
					if (u.hit(r))
					{
						p.color = rgb(0, 0, 1.0);
					} else
					{
						p.color = rgb(1.0, 1.0, 1.0);
					}
				}
				
 

				// compute color for pixel
				// if ( ((x/checkersize)%2) != ((y/checkersize)%2)) {
				//	p.color = rgb(1.0, 1.0, float(x)/gw.height());
				// } else {
				//	p.color = rgb(1.0, 0.0, float(y)/gw.width());
				// }

				// write pixel to output window
				gw.write(p);

				// write pixel to image writer
				pw.write(p);
			}
		}

		// save final image
		pw.save();
	}

private : // attributes

	// you may add a scene description here

};





int main(int argc, char* argv[])
{

	// sphere* sphr_ptr = new sphere(math3d::point(0, 0, 0), 1);
	// camera* cam = new camera(45.0); 

	// set resolution and checkersize
	const std::size_t width = 400;
	const std::size_t height = 400;

	// create output window
	glutwindow::init(width, height, 100, 100, "CheckerBoard", argc, argv);
 
	// create a ray tracing application
	rt_application app;

	// start computation in thread
	boost::thread thr(boost::bind(&rt_application::raytrace, &app));
	
	// start output on glutwindow
	glutwindow::instance().run();
	
	// wait on thread
	thr.join();

	return 0;
}
