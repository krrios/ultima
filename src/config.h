#ifndef ULTIMA_CONFIG_H_
#define ULTIMA_CONFIG_H_

#include "ultima.h"

class Configuration
{
	public:

		Configuration();

		void ResetToDefaults();

		void ParseArgs(int argc, const char **argv);

		// Accessors and Mutators
		bool print_help() const { return print_help_; }

		bool fullscreen() const { return fullscreen_; }

		void set_fullscreen(bool value) { fullscreen_ = value; }

		int screen_width() const { return screen_width_; }

		void set_screen_width(int value) { screen_width_ = value; }
		
		int screen_height() const { return screen_height_; }

		void set_screen_height(int value) { screen_height_ = value; }

		int screen_x() const { return screen_x_; }

		void set_screen_x(int value) { screen_x_ = value; }

		int screen_y() const { return screen_y_; }

		void set_screen_y(int value) { screen_y_ = value; }

	private:

		bool print_help_;

		bool fullscreen_;

		int screen_width_;

		int screen_height_;

		int screen_x_;

		int screen_y_;
};

#endif