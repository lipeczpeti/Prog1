/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

double one(double x) {return 1;}
double slope(double x) {return x/2;}
double square(double x) {return x*x;}
double sloping_cos(double x) {return cos(x) + slope(x);}

int main()
{
	using namespace Graph_lib;
	Simple_window win {Point{100,100},600,600, "Function graphs"};

	//axes
	Axis xa {Axis::x, Point{100,300}, 400, 20, "x axis"};
	xa.set_color(Color::red);
	win.attach(xa);
	Axis ya {Axis::y, Point{300, 500}, 400, 20, "y axis"};
	ya.set_color(Color::red);
	win.attach(ya);

	constexpr int r_min = -10;
	constexpr int r_max = 11;
	constexpr int num_points = 400;
	constexpr int x_scale = 20;
	constexpr int y_scale = 20;
	const Point orig {300,300};

	Function f_one {one, r_min, r_max, orig, num_points, x_scale, y_scale};
	

	Function f_slope {slope, r_min, r_max, orig, num_points, x_scale, y_scale};
	
	Text slope_label {Point{100,385}, "x/2"};
	win.attach(slope_label);

	Function f_square {square, r_min, r_max, orig, num_points, x_scale, y_scale};
	

	Function f_cos {cos, r_min, r_max, orig, num_points, x_scale, y_scale};
	f_cos.set_color(Color::blue);
	

	Function f_sloping_cos {sloping_cos, r_min, r_max, orig, num_points, x_scale, y_scale};
	

    win.attach(f_one);
    win.attach(f_slope);
	win.attach(f_square);
	win.attach(f_cos);
	win.attach(f_sloping_cos);
	win.wait_for_button();
}