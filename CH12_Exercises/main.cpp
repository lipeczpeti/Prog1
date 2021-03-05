/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"

int main()
{
	using namespace Graph_lib;

	Simple_window win {Point{100, 100}, 1200, 700, "Drill_Exercises_1-9"};

	//1 - rectangle and rectangle as a Polygon
	Rectangle rect1 {Point{450,100}, 100, 50};	
	rect1.set_color(Color::red);
	win.attach(rect1);

	Polygon poly;								
	poly.add(Point{600,100});
	poly.add(Point{700,100});
	poly.add(Point{700,150});
	poly.add(Point{600,150});
	poly.set_color(Color::blue);
	win.attach(poly);
	win.wait_for_button();

	//2 - howdy word in a rectangle 
	Rectangle rect2 {Point{50,150}, 100, 30};
	win.attach(rect2);

	Text t {Point(70, 170), "Howdy!"};
	win.attach(t);
	win.wait_for_button();
	
	//3 initial of my name
	Text initial1 {Point{ 95, 450}, "L"};
	Text initial2 {Point{130, 450}, "P"};
	initial1.set_font(Font::times_bold);
	initial2.set_font(Font::times_bold);
	initial1.set_font_size(60);
	initial2.set_font_size(60);
	initial1.set_color(Color::black);
	initial2.set_color(Color::magenta);
	win.attach(initial1);
	win.attach(initial2);
	win.wait_for_button();

	//4 - 3x3 tic tac toe board
	Rectangle white_base {Point{800, 50}, 150, 150};
	white_base.set_fill_color(Color::white);
	win.attach(white_base);

	Rectangle red_sq_1 {Point{850, 50}, 50, 50};
	red_sq_1.set_fill_color(Color::red);
	Rectangle red_sq_2 {Point{800, 100}, 50, 50};
	red_sq_2.set_fill_color(Color::red);
	Rectangle red_sq_3 {Point{900, 100}, 50, 50};
	red_sq_3.set_fill_color(Color::red);
	Rectangle red_sq_4 {Point{850, 150}, 50, 50};
	red_sq_4.set_fill_color(Color::red);

	win.attach(red_sq_1);
	win.attach(red_sq_2);
	win.attach(red_sq_3);
	win.attach(red_sq_4);

	win.wait_for_button();

	//5

	//6

	//7 - Pretty house
	Rectangle house_chimney{Point{770,320}, 30, 100};
	house_chimney.set_fill_color(Color::dark_red);
	win.attach(house_chimney);
	
	Rectangle house_box{Point{600, 400}, 200, 200};
	win.attach(house_box);
	house_box.set_fill_color(Color::dark_green);

	Polygon house_roof;
	house_roof.add(Point{600, 400});
	house_roof.add(Point{800, 400});
	house_roof.add(Point{700, 250});
	house_roof.set_fill_color(Color::red);
	win.attach(house_roof);

	Rectangle house_door{Point{675, 525}, 50, 75};
	house_door.set_fill_color(Color::dark_red);
	win.attach(house_door);

	Rectangle house_window1{Point{625, 460}, 40, 40};
	Rectangle house_window2{Point{735, 460}, 40, 40};
	house_window1.set_fill_color(Color::cyan);
	house_window2.set_fill_color(Color::cyan);
	win.attach(house_window1);
	win.attach(house_window2);

	//Circle smoke_1{}

	

	win.wait_for_button();



	//8 - olympic 5 rings
	Circle c1 {Point{100, 200}, 100};
	c1.set_color(Color::blue);
	Circle c2 {Point{350, 200}, 100};

	Circle c3 {Point{600, 200}, 100};
	c3.set_color(Color::red);
	Circle c4 {Point{225, 320}, 100};
	c4.set_color(Color::yellow);
	Circle c5 {Point{475, 320}, 100};
	c5.set_color(Color::green);

	c1.set_style(Line_style(Line_style::solid, 10));
	c2.set_style(Line_style(Line_style::solid, 10));
	c3.set_style(Line_style(Line_style::solid, 10));
	c4.set_style(Line_style(Line_style::solid, 10));
	c5.set_style(Line_style(Line_style::solid, 10));

	win.attach(c1);
	win.attach(c2);
	win.attach(c3);
	win.attach(c4);
	win.attach(c5);

	win.wait_for_button();

	//9 - with a friend
	Image im {Point {970,300}, "image.jpg"};


	win.attach (im);
	win.wait_for_button();
}