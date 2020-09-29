#include <string>
#include <vector>
#include "sciter-x.h"
#include "sciter-x-window.hpp"


class CrunchImage : public sciter::om::asset<CrunchImage>
{
  public:
	CrunchImage()
	{
	}

	std::string yeetString();

	sciter::value returnTestString();



	// -------------------------------------------------------------------------
	// User input variables
	// -------------------------------------------------------------------------
	std::vector<sciter::value> inputImageLocations;
	std::string outputImageLocation;
	int outputImageDesiredSizeInBytes;

	//// Get user input variables

	// Get image input location from the UI
	sciter::value uiCaptureInputImageLocation(sciter::value uiInput);

	// Get image output location from the UI
	sciter::value uiCaptureOutputImageLocation();

	// Get desired output image size from the UI
	void uiCaptureImageDesiredSize();



	// -------------------------------------------------------------------------
	// Read Original Image
	// -------------------------------------------------------------------------

	// Image, placeholder. Get the original image file based on user image input location
	// I think I'll need to create a variable to hold this, and then the function to shit it out into that var?
	// idk. I am not programmer
	unsigned char readOriginalImageFile();



	// -------------------------------------------------------------------------
	// Compression
	// -------------------------------------------------------------------------

	// Default compression parameters, adjusted as the output size is auto-matched to desired size
	std::string placeholder_compressionParameter1;
	std::string placeholder_compressionParameter2;
	std::string placeholder_compressionParameter3;
	int placeholder_outputImageOutcomeSizeInBytes;

	// Compress the read image to a file
	void compressImageToJpegFile();

	// Check the compressed image size against the desired size
	void evaluateCompressedImageSize();

	// Use compressImageToJpegFile and evaluateCompressedImageSize until output JPEG size is near desired size
	void compressImageUntilMatchInSize();



	// -------------------------------------------------------------------------
	// Confirmation
	// -------------------------------------------------------------------------

	// Output to UI the generated size
	sciter::string showGeneratedImageSizeInUi();

	// User confirmed to save image as it was last generated: Commit compressed image with last parameters
	void comitCompressedImageToDisk();



	// -----------------------------------------------------------------------------
	// Expose to Sciter
	// -----------------------------------------------------------------------------
	SOM_PASSPORT_BEGIN(CrunchImage)
	SOM_FUNCS(
		SOM_FUNC(returnTestString),
		SOM_FUNC(uiCaptureInputImageLocation));
	SOM_PASSPORT_END;
};
