#pragma once

#include <string>
#include <vector>
#include "sciter-x.h"
#include "sciter-x-window.hpp"

class SelectNativeExplorer
{
  public:
	SelectNativeExplorer()
	{
	}


	//  : window(SW_TITLEBAR | SW_RESIZEABLE | SW_CONTROLS | SW_MAIN | SW_ENABLE_DEBUG)

	// // Pointer to the class derived from sciter window class and event handler
	// SelectNativeExplorer *pwind = new SelectNativeExplorer();

	// HWND hwnd;
	// saveOrOpen, fileOptions, defaultExtension, initialPath, dialogCaption
	// struct selectFileParameters
	// {
	// 	std::string saveOrOpen;
	// 	std::string fileOptions;
	// 	std::string defaultExtension;
	// 	std::string initialPath;
	// 	std::string dialogCaption;
	// };

	// defaultFolder, dialogCaption
	// struct selectFolderParameters
	// {
	// 	std::string defaultFolder;
	// 	std::string dialogCaption;
	// };

	// C++ -> TiScript Select file
	sciter::value TOUISelectFile(std::string saveOrOpen, std::string fileOptions, std::string defaultExtension,
								 std::string initialPath, std::string dialogCaption);

	// C++ -> TiScript Select folder
	void TOUISelectFolder(std::string defaultFolder, std::string dialogCaption);

	// sciter::value callUiScript();
	static int returnOne();

	// -----------------------------------------------------------------------------
	// SECTION: Expose to Sciter
	// -----------------------------------------------------------------------------
	// SOM_PASSPORT_BEGIN(SelectNativeExplorer)
	// SOM_FUNCS(SOM_FUNC(TOUISelectFile));
	// SOM_PASSPORT_END;
	// !SECTION
};
