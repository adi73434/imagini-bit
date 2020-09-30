#include "MainFrame.h"

// function expsed to script:
sciter::string MainFrame::nativeMessage()
{
	return WSTR("FromC++ - C++ World");
}

sciter::string MainFrame::testCpp()
{
	return WSTR("FromC++ - G++");
}

sciter::string MainFrame::lolWtf()
{

	sciter::window::call_function("alertUserTest");

	return WSTR("1");
}
