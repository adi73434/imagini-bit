#pragma once

#include <string>
#include <vector>
#include "sciter-x.h"
#include "sciter-x-window.hpp"

class SelectNativeExplorer
{
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
	void TOUISelectFile(std::string saveOrOpen, std::string fileOptions, std::string defaultExtension,
						std::string initialPath, std::string dialogCaption);

	// C++ -> TiScript Select folder
	void TOUISelectFolder(std::string defaultFolder, std::string dialogCaption);
};
