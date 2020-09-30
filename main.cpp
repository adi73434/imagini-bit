#include "MainFrame.h"

#include "Globals.h"


#include "sciter-x.h"
#include "sciter-x-window.hpp"

// #include "IncludeAllClasses.h"
#include "CrunchImage.h"

#include "resources.cpp"

int uimain(std::function<int()> run)
{
	// enable features to be used from script
	SciterSetOption(NULL, SCITER_SET_SCRIPT_RUNTIME_FEATURES,
					ALLOW_FILE_IO | ALLOW_SOCKET_IO | ALLOW_EVAL | ALLOW_SYSINFO);
	// SciterSetOption(NULL, SCITER_SET_SCRIPT_RUNTIME_FEATURES, ALLOW_SYSINFO );



	// -------------------------------------------------------------------------
	// Exposing Logic to UI
	// -------------------------------------------------------------------------
	SciterSetGlobalAsset(new CrunchImage());
	// -------------------------------------------------------------------------
	//
	// -------------------------------------------------------------------------



	// bind resources[] (defined in "resources.cpp") with the archive
	sciter::archive::instance().open(aux::elements_of(resources));

	// Create main window frame
	sciter::om::hasset<MainFrame> pwin = new MainFrame();

	// note: this:://app URL is dedicated to the sciter::archive content associated with the application
	pwin->load(WSTR("this://app/main.htm"));

	// or use this to load UI from
	//  pwin->load( WSTR("file:///home/andrew/Desktop/Project/res/main.htm") );

	pwin->expand();

	// Pass these so they can be used globally... hwnd is needed for calling TiScript from C++, among other things
	Globals::mainPwin = pwin;
	Globals::mainHwnd = pwin->get_hwnd();

	return run();
}
