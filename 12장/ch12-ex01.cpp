
#include "Simple_window.h"
#include "Graph.h"

int main()
{
	Simple_window win{ Point{100, 100}, 600, 400, "Canvas" };

	Graph_lib::Rectangle rec{ Point{100, 100}, Point{250, 200} };
	rec.set_color(Color::blue);
	win.attach(rec);

	Graph_lib::Polygon pol;
	pol.add(Point{ 300, 200 });
	pol.add(Point{ 350, 100 });
	pol.add(Point{ 400, 200 });
	pol.set_color(Color::red);
	win.attach(pol);

	win.wait_for_button();
	return 0;
}

