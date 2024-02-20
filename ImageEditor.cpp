#include "ImageEditor.h"

	ImageEditor::ImageEditor(string inFileName)
	{
		// Declare a Picture object that opens inFileName and assign it to the pic member variable
	}
	void save(string outFileName)
	{
		// Call save on pic and pass in outFileName as its argument
	}

	ImageEditor::ImageEditor& operator-()
	{
		// Invert all colors and return *this (image negative)
	}
	ImageEditor::ImageEditor& operator-=(const Color& c)
	{
		// subract c from all pixels
	}
	ImageEditor::ImageEditor& operator+=(const Color& c)
	{
		// add c to all pixels
	}
	bool operator==(const ImageEditor::ImageEditor& ie) const
	{
		// compare to another image
	}
	bool operator!=(const ImageEditor::ImageEditor& ie) const
	{
		// compare to another image
	}
	ImageEditor::ImageEditor& operator*=(unsigned int n)
	{
		// expand by factor of n by n
	}
