#include "SelectNativeExplorer.h"

void SelectNativeExplorer::TOUISelectFile(std::string saveOrOpen, std::string fileOptions, std::string defaultExtension,
										  std::string initialPath, std::string dialogCaption)
{
	// sciter::value params[5] = {saveOrOpen, fileOptions, defaultExtension, initialPath, dialogCaption};
	// sciter::value returnValue;


	// // NOTE: I don't have any clue how HWND works
	// if (SciterCall(pwin->get_hwnd(), "nativeExplorerFile", 2, params, &returnValue))
	// {
	// 	int ri = returnValue.get(0);
	// }
}

void SelectNativeExplorer::TOUISelectFolder(std::string defaultFolder, std::string dialogCaption)
{
}