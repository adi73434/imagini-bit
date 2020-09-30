#ifndef MY_MAINFRAME_H
#define MY_MAINFRAME_H



#include "MainFrame.h"


#include "sciter-x.h"
#include "sciter-x-window.hpp"

class MainFrame : public sciter::window
{
  public:
	MainFrame() : window(SW_TITLEBAR | SW_RESIZEABLE | SW_CONTROLS | SW_MAIN | SW_ENABLE_DEBUG)
	{
	}

	// function expsed to script:
	sciter::string nativeMessage();

	sciter::string testCpp();

	sciter::string lolWtf();


	SOM_PASSPORT_BEGIN(MainFrame);
	SOM_FUNCS(SOM_FUNC(nativeMessage), SOM_FUNC(testCpp), SOM_FUNC(lolWtf));
	SOM_PASSPORT_END;
};



#endif