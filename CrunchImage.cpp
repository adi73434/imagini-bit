#include "CrunchImage.h"
#include <stdio.h>
#include <iostream>

// -------------------------------------------------------------------------
// SECTION: Set Input Image location URL
// -------------------------------------------------------------------------

sciter::value CrunchImage::FROMUISetInputImageLocation(sciter::value varFromUi)
{
	// -------------------------------------------------------------------------
	// Get first value
	// -------------------------------------------------------------------------
	// Use template to convert value to string
	// CrunchImage::inputImageLocations[0] = varFromUi.get<sciter::string>();

	// -------------------------------------------------------------------------
	// Push UI array to class vector
	// -------------------------------------------------------------------------

	// Clear vector to only store the "newly" dropped file dir
	CrunchImage::inputImageLocations.clear();
	// Push varFromUi parameter to class state
	for (int i = 0; i < varFromUi.length(); i++)
	{
		CrunchImage::inputImageLocations.push_back(varFromUi[i]);
	}

	// Return void
	return sciter::value();
}

// !SECTION



// -------------------------------------------------------------------------
// SECTION: Set Intended Size
// -------------------------------------------------------------------------

sciter::value CrunchImage::FROMUISetImageDesiredSize()
{

	// Return void
	return sciter::value();
}

// !SECTION



// -----------------------------------------------------------------------------
// SECTION: Set Output Image Location URL
// -----------------------------------------------------------------------------

sciter::value CrunchImage::FROMUISetOutputImageLocation()
{

	// Return void
	return sciter::value();
}

// !SECTION



// -------------------------------------------------------------------------
// SECTION: Click Compute/Save As button
// -------------------------------------------------------------------------

sciter::value CrunchImage::FROMUIComputeSaveButtonClick()
{
	// If button state is 0, handle click as "compute"
	// If button state is 1, handle click as "save as"
	switch (CrunchImage::uiButtonState)
	{
		case 0:
			CrunchImage::triggerComputeJpeg();
			CrunchImage::uiButtonState = 1;
			break;
		case 1:
			CrunchImage::triggerSaveToDisk();
			// TODO: Set state back to 0 so process can be repeated
			// CrunchImage::uiButtonState = 0;
			break;
		default:
			break;
	}
	// Return void
	return sciter::value();
}

sciter::value CrunchImage::TOUIUpdateCompeSaveButtonText()
{
	return sciter::value();
}

sciter::value CrunchImage::triggerComputeJpeg()
{

	// Return void
	// TODO: Return a confirmation if compressAndEvaluateSize is successful
	return sciter::value();
}

sciter::value CrunchImage::triggerSaveToDisk()
{
	// sciter::value params
	// TODO: use SelectNativeExplorer:: class
	// Return void
	return sciter::value();
}

// !SECTION



// -----------------------------------------------------------------------------
// SECTION: UI Output
// -----------------------------------------------------------------------------

sciter::value CrunchImage::TOUIReturnTestString()
{
	// -------------------------------------------------------------------------
	// This returns sample array; vector is dynamic size
	// -------------------------------------------------------------------------
	// std::vector<sciter::value> vectorData;
	// for (int i = 0; i < 9; i++)
	// {
	// vectorData.push_back(i);
	// }
	// return vectorData;

	// -------------------------------------------------------------------------
	// This returns list (?) of things; you have to specify the size
	// -------------------------------------------------------------------------
	// sciter::value vectorData[3] = { "1", "2", "3"};
	// return sciter::value(vectorData, 3);

	// -------------------------------------------------------------------------
	// This returns class state of image locations, or a default "no value"
	// -------------------------------------------------------------------------
	return CrunchImage::inputImageLocations;
}

sciter::value CrunchImage::TOUIShowGeneratedImageSizeInUi()
{

	// Return void
	return sciter::value();
}
// !SECTION


// -----------------------------------------------------------------------------
// SECTION: Compression
// -----------------------------------------------------------------------------

unsigned char CrunchImage::readOriginalImageFile()
{
	// TODO: Read file from given URL. Store in memory
}

void CrunchImage::compressImageToJpeg()
{
	// -------------------------------------------------------------------------
	// TODO
	// - Compress image using library and given parameters
	// - Change return type to be the image data
	// -------------------------------------------------------------------------
}

void CrunchImage::compressAndEvaluateSize()
{
	// -------------------------------------------------------------------------
	// TODO
	// - Compress the JPEG and check it against desired size
	// - Log used paramteres and size to compressionParameterOutcomeSizeHistory
	// - If size is close (just below), finish the computing
	// -------------------------------------------------------------------------
}

// !SECTION
