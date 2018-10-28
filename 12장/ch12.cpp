
#include "Simple_window.h"
#include "Graph.h"
using namespace Graph_lib;

const int WINDOW_WEIGHT = 800;
const int WINDOW_HEIGHT = 600;

int main()
{
	// Make a window
	Simple_window win(Point{ 0, 0 }, WINDOW_WEIGHT, WINDOW_HEIGHT, "Canvas");

	// Make factors and attach them into the window
	Axis xa{ Axis::x, Point{20, 300}, 280, 10, "x axis" };
	xa.set_color(Color::black);
	win.attach(xa);

	Axis ya{ Axis::y, Point{20, 300}, 280, 10, "y axis" };
	ya.set_color(Color::cyan);
	ya.label.set_color(Color::dark_red);
	win.attach(ya);

	Function sine{ sin, 0, 100, Point{20, 150}, 1000, 50, 50 };
	sine.set_color(Color::blue);
	win.attach(sine);

	Graph_lib::Polygon poly;
	poly.add(Point{ 300, 200 });
	poly.add(Point{ 350, 100 });
	poly.add(Point{ 400, 200 });
	poly.set_color(Color::red);
	poly.set_style(Line_style(Line_style::dash, 4));
	win.attach(poly);

	Graph_lib::Rectangle r{ Point{200, 200}, 100, 50 };
	r.set_color(Color::black);
	r.set_fill_color(Color::yellow);
	win.attach(r);

	Closed_polyline poly_rect;
	poly_rect.add(Point{ 100, 50 });
	poly_rect.add(Point{ 200, 50 });
	poly_rect.add(Point{ 200, 100 });
	poly_rect.add(Point{ 100, 100 });
	poly_rect.add(Point{ 50, 75 });
	poly_rect.set_color(Color::black);
	poly_rect.set_style(Line_style(Line_style::dash, 2));
	poly_rect.set_fill_color(Color::green);
	win.attach(poly_rect);

	Text t{ Point{150, 150}, "Hello, graphical world!" };
	t.set_color(Color::black);
	t.set_font(Font::times_bold);
	t.set_font_size(20);
	win.attach(t);

	Image image{ Point{100, 50}, "image.jpg" };
	image.move(100, 200);
	win.attach(image);

	//-------------------------------------------------------------
	Circle c{ Point{100, 200}, 50 };
	c.set_color(Color::black);
	Graph_lib::Ellipse e{ Point{100, 200}, 75, 25 };
	e.set_color(Color::dark_red);
	Mark m{ Point{100, 200}, 'x' };

	ostringstream oss;
	oss << "screen size: " << x_max() << '*' << y_max()
		<< "; window size: " << win.x_max() << '*' << win.y_max();
	Text sizes{ Point{100, 20}, oss.str() };
	sizes.set_color(Color::black);

	Image cal{ Point{225, 225}, "snow_cpp.gif" };
	cal.set_mask(Point{ 40, 40 }, 200, 150);

	win.attach(c);
	win.attach(m);
	win.attach(e);

	win.attach(sizes);
	win.attach(cal);
	//-------------------------------------------------------------

	// Set label of the window
	win.set_label("Canvas #12");

	// Show the window
	win.wait_for_button();
	return 0;
}

