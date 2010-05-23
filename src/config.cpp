#include "config.h"
#include <iostream>
#include <sstream>

#ifdef WIN32
	#define WIN32_LEAN_AND_MEAN
	#define VC_EXTRALEAN
	#include <Windows.h>
#endif

Configuration::Configuration()
{
	ResetToDefaults();
}

void Configuration::ResetToDefaults()
{
	print_help_ = false;
	fullscreen_ = false;
	screen_width_ = 1024;
	screen_height_ = 768;
	screen_x_ = 10;
	screen_y_ = 10;
}

void Configuration::ParseArgs(int argc, const char **argv)
{
	std::stringstream ss;

	for (int i = 0; i < argc; ++i)
	{
		if (std::strcmp(argv[i], "-help") == 0)
		{
			print_help_ = true;
		}

		if (std::strcmp(argv[i], "-fs") == 0)
		{
			fullscreen_ = true;
		}
		
		if (std::strcmp(argv[i], "-w") == 0)
		{
			if (argc + 1 > argc)
			{
				ss << argv[++i];			
				ss >> screen_width_;
				ss.clear();
			}
		}
		
		if (std::strcmp(argv[i], "-h") == 0)
		{
			if (argc + 1 > argc)
			{
				ss << argv[++i];			
				ss >> screen_height_;
				ss.clear();
			}
		}
		
		if (std::strcmp(argv[i], "-x") == 0)
		{
			if (argc + 1 > argc)
			{
				ss << argv[++i];			
				ss >> screen_x_;
				ss.clear();
			}
		}
		
		if (std::strcmp(argv[i], "-y") == 0)
		{
			if (argc + 1 > argc)
			{
				ss << argv[++i];			
				ss >> screen_y_;
				ss.clear();
			}
		}
	}
}