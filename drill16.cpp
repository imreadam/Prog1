/*
		g++ drill16.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill16 `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"
#include "Graph.h"

struct Lines_window : Window
{
			Lines_window(Point xy, int w, int h, const string& title);
private:
		Open_polyline linrs;
		Button next_button;
		Button quit_button;
		In_box next_x;
		In_box next_y;
		Out_box xy_out;
		Menu color_menu;
		Button menu_button;
		Menu style_menu;
		Button stylemenu_button;
		
		void change(Color c) { linrs.set_color(c); }
		void style_change(Line_style(l)) { linrs.set_style(l); }
		
		void show_menu();
		void hide_menu();
		void hide_stylemenu() { style_menu.hide(); stylemenu_button.show(); }
		void red_pressed() { change(Color::red); hide_menu(); }
		void blued_pressed() { change(Color::blue); hide_menu(); }
		void balck_pressed() { change(Color::black); hide_menu(); }
		void green_pressed() { change(Color::green); hide_menu(); }
		void menu_pressed() { menu_button.hide(); show_menu(); }
		void solid_pressed() { style_change(Line_style(Line_style::solid)); hide_stylemenu(); }
		void dash_pressed() { style_change(Line_style(Line_style::dash)); hide_stylemenu(); }
		void dot_pressed()  { style_change(Line_style(Line_style::dot)); hide_stylemenu(); }
		void stylemenu_pressed() { stylemenu_button.hide(); style_menu.show(); }
		void next();
		void quit();
		
};		
		
				
				
				
						
