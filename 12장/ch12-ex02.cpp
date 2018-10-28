
#include "Simple_window.h"
#include "Graph.h"

int main()
{
	Simple_window win{ Point{100, 100}, 600, 400, "Canvas" };

	Graph_lib::Rectangle rec(Point{ 0, 0 }, Point{ 100, 30 });
	rec.set_color(Color::black);
	Graph_lib::Text text{ Point{rec.point(0).x + 20, rec.point(0).y + 20}, "Howdy!" };
	text.set_color(Color::black);

	win.attach(rec);
	win.attach(text);

	win.wait_for_button();
	return 0;
}

