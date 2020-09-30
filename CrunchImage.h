#pragma once

// #include <string>
#include <vector>
#include "sciter-x.h"
// #include "sciter-x-window.hpp"

class CrunchImage : public sciter::om::asset<CrunchImage>
{
  public:
	CrunchImage()
	{
	}

	sciter::value testFuck();

	// -------------------------------------------------------------------------
	// SECTION: Set Input Image location URL
	// -------------------------------------------------------------------------

	// Image input location URL, accepts multiple strings
	std::vector<sciter::value> inputImageLocations = {"Default - no value"};

	// TiScript -> C++ Image input location
	sciter::value FROMUISetInputImageLocation(sciter::value uiInput);

	// !SECTION



	// -------------------------------------------------------------------------
	// SECTION: Set Intended Size
	// -------------------------------------------------------------------------

	// User's desired JPEG output size
	int outputImageDesiredSizeInBytes;

	// TiScript -> C++ Desired output image size
	sciter::value FROMUISetImageDesiredSize();

	// !SECTION



	// -------------------------------------------------------------------------
	// SECTION: Set Output Image Location URL
	// -------------------------------------------------------------------------

	// Image output lucation URL
	// TODO: Figure out how to specify multiple output paths/names
	// Will probably allow user only to select folder, then make the output name the same as the input - just with a
	// specified prefix
	std::string outputImageLocation;

	// TiScript -> C++ Image output location
	sciter::value FROMUISetOutputImageLocation();

	// !SECTION



	// -------------------------------------------------------------------------
	// SECTION: Click Compute/Save As button
	// -------------------------------------------------------------------------

	// What the button click wil do: 0 = Compute; 1 = Save As;
	int uiButtonState = 0;



	// TiScript -> C++ UI Button Click to Compute/Save As
	sciter::value FROMUIComputeSaveButtonClick();

	// C++ -> TiScript Update UI Button text
	sciter::value TOUIUpdateCompeSaveButtonText();

	// User clicked to start computing JPEG
	sciter::value triggerComputeJpeg();

	// User confirmed to save image as it was last generated: Commit compressed image with last parameters
	sciter::value triggerSaveToDisk();
	// !SECTION



	// -------------------------------------------------------------------------
	// SECTION: UI Output
	// -------------------------------------------------------------------------

	// C++ -> TiScript Test
	sciter::value TOUIReturnTestString();

	// C++ -> TiScript Update UI element showing the generated JPEG size
	sciter::value TOUIShowGeneratedImageSizeInUi();

	// !SECTION



	// -------------------------------------------------------------------------
	// SECTION: Compression
	// -------------------------------------------------------------------------

	// Default compression parameters, adjusted as the output size is auto-matched to desired size
	std::string placeholder_compressionParameter1;
	std::string placeholder_compressionParameter2;
	std::string placeholder_compressionParameter3;

	// Hold the outcome size of the specified compression parameters
	struct compressionParameterOutcomeSize
	{
		int outcomeSizeInBytes;
		std::string placeholder_compressionParameter1;
		std::string placeholder_compressionParameter2;
		std::string placeholder_compressionParameter3;
	};

	// Keep track of what compression parameters resulted in what JPEG size
	std::vector<compressionParameterOutcomeSize> compressionParameterOutcomeSizeHistory;

	// Image, placeholder. Get the original image file based on user image input location
	// I think I'll need to create a variable to hold this, and then the function to shit it out into that var?
	// idk. I am not programmer
	unsigned char readOriginalImageFile();

	// Compress the read image to a JPEG
	void compressImageToJpeg();

	// Compress the JPEG and check it against desired size
	void compressAndEvaluateSize();

	// !SECTION



	// -----------------------------------------------------------------------------
	// SECTION: Expose to Sciter
	// -----------------------------------------------------------------------------
	SOM_PASSPORT_BEGIN(CrunchImage)
	SOM_FUNCS(SOM_FUNC(testFuck), SOM_FUNC(TOUIReturnTestString), SOM_FUNC(FROMUISetInputImageLocation),
			  SOM_FUNC(FROMUISetImageDesiredSize));
	SOM_PASSPORT_END;
	// !SECTION
};
