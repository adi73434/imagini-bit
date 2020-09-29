#include "CrunchImage.h"
#include <stdio.h>
#include <iostream>

sciter::value CrunchImage::returnTestString(){
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

// Update the state of inputImageLocation
sciter::value CrunchImage::uiCaptureInputImageLocation(sciter::value varFromUi)
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
