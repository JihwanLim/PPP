
#include "Simple_window.h"
#include "Graph.h"
using namespace Graph_lib;

const int WINDOW_WEIGHT = 800;
const int WINDOW_HEIGHT = 600;

int main()
{
	// Make a window
	Simple_window win(Point{ 0, 0 }, WINDOW_WEIGHT, WINDOW_HEIGHT, "Canvas");

	Circle ring1{ Point{170, 200}, 100 };
	ring1.set_color(Color::blue);
	ring1.set_style(Line_style(Line_style::solid, 20));
												  
	Circle ring2{ Point{410, 200}, 100 };		  
	ring2.set_color(Color::black);				  
	ring2.set_style(Line_style(Line_style::solid, 20));
												  
	Circle ring3{ Point{650, 200}, 100 };		  
	ring3.set_color(Color::red);				  
	ring3.set_style(Line_style(Line_style::solid, 20));
												  
	Circle ring4{ Point{290, 300}, 100 };		  
	ring4.set_color(Color::yellow);				  
	ring4.set_style(Line_style(Line_style::solid, 20));
												  
	Circle ring5{ Point{530, 300}, 100 };		  
	ring5.set_color(Color::dark_green);				  
	ring5.set_style(Line_style(Line_style::solid, 20));

	win.attach(ring1);
	win.attach(ring4);
	win.attach(ring2);
	win.attach(ring5);
	win.attach(ring3);

	// Show the window
	win.wait_for_button();
	return 0;
}

