/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images` -std=c++11
*/
#include "Simple_window.h"
#include "Graph.h"

double one(double x) {return 1; }
double slope(double x) {return x/2; }
double square(double x) {return x*x; }
double sloping_cos(double x) {return cos(x) + slope(x); }

int main()
try{

			int xmax = 600;
			int ymax = 600;
			
			Point t1(600,50);
			Simple_window win{t1, xmax, ymax, "Function graphs"};
			
			int x_origo = xmax/2;
			int y_origo = ymax/2;
			
			Point origo(x_origo, y_origo);
			
			
			int x_scale = 20;
			int y_scale = 20;
			
			int xlength = xmax - 200;
			int ylength = ymax - 200;
			
			Axis x(Axis::x, Point(100,y_origo), xlength, xlength/x_scale, "1 == 20 pixels");
			win.attach(x);
			
			Axis y(Axis::y, Point(x_origo,500), ylength, ylength/y_scale, "1 == 20 pixels");
			win.attach(y);
			
			x.set_color(Color::red);
			y.set_color(Color::red);
			
			win.wait_for_button();
			
			int r_min = -10;
			int r_max = 11;
			int n_point = 400;
			
			Function egy(one, r_min, r_max, origo, n_point, x_scale, y_scale);
			win.attach(egy);
			win.wait_for_button();
			
			Function ferde(slope, r_min, r_max, origo, n_point, x_scale, y_scale);
			win.attach(ferde);
			win.wait_for_button(); 
			
			
			
}catch(exception& e){
					cerr << e.what() << endl;
					return 1;
}catch(...){
					cerr << "Something went wrong" << endl;
					return 2;
					
}
			
			
						
					


