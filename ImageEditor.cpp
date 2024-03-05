#include "ImageEditor.h"

ImageEditor::ImageEditor(string inFileName)
{
	// Declare a Picture object that opens inFileName and assign it to the pic member variable
	Picture temp(inFileName);
	pic = temp;
}

void ImageEditor::save(string outFileName)
{
	// Call save on pic and pass in outFileName as its argument
	pic.save(outFileName);
}


// operators


ImageEditor& ImageEditor::operator-()
{
	// Invert all colors and return *this (image negative)
	for (int y = 0; y < pic.height(); y++)
	{
		for (int x = 0; x < pic.width(); x++)
		{
			int red = 255 - pic.red(x, y);
			int green = 255 - pic.green(x, y);
			int blue = 255 - pic.blue(x, y);
			pic.set(x, y, red, green, blue);
		}
	}
	return *this;
}

ImageEditor& ImageEditor::operator-=(const Color& c)
{
	// subract c from all pixels
        for (int y = 0; y < pic.height(); y++)
        {
                for (int x = 0; x < pic.width(); x++)
                {  
                        int red = pic.red(x, y) - c.r;
			if (red < 0) red = 0;

                        int green = pic.green(x, y) - c.g;
                        if (green < 0) green = 0;

                        int blue = pic.blue(x, y) - c.b;
                        if (blue < 0) blue = 0;

                        pic.set(x, y, red, green, blue);
                }
        }
	return *this;
}

ImageEditor& ImageEditor::operator+=(const Color& c)
{
	// add c to all pixels
	for (int y = 0; y < pic.height(); y++)
        {
                for (int x = 0; x < pic.width(); x++)
                {
                        int red = pic.red(x, y) + c.r;
                        if (red > 255) red = 255;

                        int green = pic.green(x, y) + c.g;
                        if (green > 255) green = 255;

                        int blue = pic.blue(x, y) + c.b;
                        if (blue > 255) blue = 255;

                        pic.set(x, y, red, green, blue);
                }
        }
        return *this;
}

bool ImageEditor::operator==(const ImageEditor& ie) const
{
	// compare to another image
	if (pic.width() != ie.pic.width() || pic.height() != ie.pic.height()) return false;

	for (int y = 0; y < pic.height(); y++)
        {
                for (int x = 0; x < pic.width(); x++)
                {
                        if (pic.red(x, y) != ie.pic.red(x, y)) return false;
                        if (pic.green(x, y) != ie.pic.green(x, y)) return false;
                        if (pic.blue(x, y) != ie.pic.blue(x, y)) return false;
                }
        }
        return true;
}

bool ImageEditor::operator!=(const ImageEditor& ie) const
{
	// compare to another image
	if (pic.width() != ie.pic.width() || pic.height() != ie.pic.height()) return true;

        for (int y = 0; y < pic.height(); y++)
        {
                for (int x = 0; x < pic.width(); x++)
                {
                        if (pic.red(x, y) != ie.pic.red(x, y)) return true;
                        if (pic.green(x, y) != ie.pic.green(x, y)) return true;
                        if (pic.blue(x, y) != ie.pic.blue(x, y)) return true;
                }                                
        }
        return false;
}

ImageEditor& ImageEditor::operator*=(unsigned int n)
{
	// expand by factor of n by n
	if (n < 1 || n > 10)
	{
		throw runtime_error("Expansion ratio out of bounds\n");
	}
	Picture picOut(pic.width() * n, pic.height() * n, 255, 255, 255);

	for (int y = 0; y < pic.height(); y++)
        {
		for (int x = 0; x < pic.width(); x++)
		{
			int r = pic.red(x, y);
			int g = pic.green(x, y);
			int b = pic.blue(x, y);
			for (unsigned int dy = 0; dy < n; dy++)
			{
				for (unsigned int dx = 0; dx < n; dx++)
				{
					picOut.set((x * n) + dx, (y * n) + dy, r, g, b);
				}
			}

		}       
	}
		
	this->pic = picOut;
        return *this;
}
