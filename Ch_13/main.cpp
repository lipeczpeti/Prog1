/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"

int main()
{
	using namespace Graph_lib;

	constexpr int x_max = 1000;
	constexpr int y_max = 800;

	Simple_window win {Point{100, 100}, x_max, y_max, "CH13_Drill"};

	//making the grid
	constexpr int grid_size = 100;
	constexpr int grid_max = 800;

	Lines grid;

	for (int x = grid_size; x <= grid_max; x+=grid_size)
	{
		grid.add(Point{x,0}, Point{x, grid_max});
		grid.add(Point{0,x}, Point{grid_max, x});
	}
	
	win.attach(grid);

	//making the red squares
	Vector_ref<Rectangle> red_squares;

	for (int i = 0; i < 8; ++i)
	{
		red_squares.push_back(new Rectangle(Point{i * grid_size, i * grid_size}, grid_size, grid_size));
		red_squares[red_squares.size()-1].set_fill_color(Color::red);
		win.attach(red_squares[red_squares.size()-1]);
	}

	//placing images
	Vector_ref<Image> im;
	im.push_back(new Image(Point{0,200}, "images1.jpeg"));
	im.push_back(new Image(Point{200,400}, "images1.jpeg"));
	im.push_back(new Image(Point{300,600}, "images1.jpeg"));
	for (int i = 0; i < im.size(); ++i)
	{
		win.attach(im[i]);
	}

	//moving an image around
	Image picture{Point{0,0}, "sti.jpg"};
	
	win.attach(picture);

	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; j++)
	{
		win.wait_for_button();
		if(j < 7) picture.move(100,0);
		else picture.move(-700,100);
	}
}