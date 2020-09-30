#ifndef MY_GLOBALS_H
#define MY_GLOBALS_H



#include "sciter-x.h"
#include "sciter-x-window.hpp"

#include "MainFrame.h"

class Globals
{
  public:
	static int myglobalint;
	static sciter::om::hasset<MainFrame> mainPwin;
	static HWND mainHwnd;
};



#endif