#include "sciter-x.h"
#include "sciter-x-window.hpp"

#include "CrunchImage.h"

class frame : public sciter::window
{
  public:
	frame()
		: window(SW_TITLEBAR | SW_RESIZEABLE | SW_CONTROLS | SW_MAIN | SW_ENABLE_DEBUG)
	{
	}
	SOM_PASSPORT_BEGIN(frame);
	SOM_FUNCS(
		SOM_FUNC(nativeMessage),
		SOM_FUNC(testCpp));
	SOM_PASSPORT_END;

	// function expsed to script:
	sciter::string nativeMessage()
	{
		return WSTR("FromC++ - C++ World");
	}

	sciter::string testCpp()
	{
		return WSTR("FromC++ - G++");
	}
};

#include "resources.cpp" // resources packaged into binary blob.

int uimain(std::function<int()> run)
{

	sciter::archive::instance().open(aux::elements_of(resources)); // bind resources[] (defined in "resources.cpp") with the archive

	// -------------------------------------------------------------------------
	// Exposing Logic to UI
	// -------------------------------------------------------------------------
	SciterSetGlobalAsset(new CrunchImage());
	// -------------------------------------------------------------------------
	//
	// -------------------------------------------------------------------------

	sciter::om::hasset<frame> pwin = new frame();

	// note: this:://app URL is dedicated to the sciter::archive content associated with the application
	pwin->load(WSTR("this://app/main.htm"));
	//or use this to load UI from
	//  pwin->load( WSTR("file:///home/andrew/Desktop/Project/res/main.htm") );

	pwin->expand();

	return run();
}
