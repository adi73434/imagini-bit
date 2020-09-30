#include "SelectNativeExplorer.h"

// sciter::value SelectNativeExplorer::TOUISelectFile(std::string saveOrOpen, std::string fileOptions,
// 												   std::string defaultExtension, std::string initialPath,
// 												   std::string dialogCaption)
// {
// 	sciter::value params[5] = {saveOrOpen, fileOptions, defaultExtension, initialPath, dialogCaption};
// 	sciter::value returnValue;
// 	// pwind->

// 	// I need to somehow get get_hwnd(); to be available here
// 	// HWND hwndCurrent;
// 	// HWND hhhwnd = pwind->get_hwnd();

// 	// sciter::om::hasset<SelectNativeExplorer> asdf = new SelectNativeExplorer();

// 	// NOTE: I don't have any clue how HWND works
// 	// if (SciterCall(hhhwnd, "nativeExplorerFile", 2, params, &returnValue))
// 	// {
// 	// 	int ri = returnValue.get(0);
// 	// }
// 	// asdf->call_function("nativeExplorerFile");
// 	// sciter::window::call_function("nativeExplorerFile");
// 	// sciter::value callback = asdf->call_function()
// 	return sciter::value();
// }

// void SelectNativeExplorer::TOUISelectFolder(std::string defaultFolder, std::string dialogCaption)
// {
// }


// sciter::value SelectNativeExplorer::callUiScript() {

// 	return sciter::window::call_function("alertUserTest");

// }

int SelectNativeExplorer::returnOne()
{
	return 1;
}

