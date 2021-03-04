#include "Simple_window.h"
#include "Graph.h"

double one(double) { return 1; }
double square(double x) {return x*x; }

int main()
{
	int xmax = 1270;
	int ymax = 720;

	int x_orig = xmax/2;
	int y_orig = ymax/2;

	int rmin = -11;
	int rmax = 11;

	int n_points = 400;

	Simple_window win {Point{600,400},xmax,ymax,"Canvas(Drill12)"};

    Polygon poly;

    poly.add(Point{300,200});
    poly.add(Point{350,100});
    poly.add(Point{400,200});

    poly.set_color(Color::red);
    poly.set_fill_color(Color::black);
    poly.set_style(Line_style(Line_style::dash,4));
    Point origo {x_orig, y_orig};

    int xlength = xmax-40;
    int ylength = ymax-40;

    int xscale = 30, yscale = 30;

    Function s (one, rmin, rmax, origo, n_points, xscale, yscale ); //konstans függvény
    Function sq (square, rmin, rmax, origo, n_points, xscale, yscale ); //konstans függvény
    Function cos_func ([](double x) {return cos(x); } 
    						, rmin, rmax, origo, n_points, xscale, yscale );

    s.set_color(Color::red);

    Axis x {Axis::x, Point{20,y_orig}, xlength, xlength/xscale, "x tengely"};
    Axis y {Axis::y, Point{x_orig,ylength + 20}, ylength, ylength/yscale, "y tengely"};
    x.set_color(Color::blue);
    y.set_color(Color::green);

    Rectangle r {Point{200,200}, 100, 50};
    r.set_fill_color(Color::magenta);
    r.set_style(Line_style(Line_style::solid,5));

    Text t {Point{50,50}, "Szia En vagyok a 12-es Drill"};
    t.set_font(Font::times_bold);
    t.set_font_size(20);



    Image im {Point {400,100}, "wow1.jpg"};

    Circle c {Point{900,500},100};

    Mark m {Point{900,505},'x'};


    win.attach(m);
    win.attach(c);
    win.attach(im);
    win.attach(t);
    win.attach(r);
    win.attach(cos_func);
    win.attach(s);
    win.attach(sq);
	win.attach(x);
    win.attach(y);
    win.attach (poly);
   win.wait_for_button();


}