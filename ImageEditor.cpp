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

ImageEditor& ImageEditor::operator-()
{
	// Invert all colors and return *this (image negative)
	for (int i = 0; i < pic.height(); i++)
	{
		for (int j = 0; j < pic.width(); j++)
		{
			int red = 255 - pic.red(j,i);
			int green = 255 - pic.green(j,i);
			int blue = 255 - pic.blue(j,i);
			pic.set(j, i, red, green, blue);
		}
	}
	return *this;
}
ImageEditor& ImageEditor::operator-=(const Color& c)
{
	// subract c from all pixels
        for (int i = 0; i < pic.height(); i++)
        {
                for (int j = 0; j < pic.width(); j++)
                {  
                        int red = pic.red(j,i) - c.r;
			if (red < 0) red = 0;

                        int green = pic.green(j,i) - c.g;
                        if (green < 0) green = 0;

                        int blue = pic.blue(j,i) - c.b;
                        if (blue < 0) blue = 0;

                        pic.set(j, i, red, green, blue);
                }
        }
	return *this;
}
ImageEditor& ImageEditor::operator+=(const Color& c)
{
	// add c to all pixels
	for (int i = 0; i < pic.height(); i++)
        {
                for (int j = 0; j < pic.width(); j++)
                {
                        int red = pic.red(j,i) + c.r;
                        if (red > 255) red = 255;

                        int green = pic.green(j,i) + c.g;
                        if (green > 255) green = 255;

                        int blue = pic.blue(j,i) + c.b;
                        if (blue > 255) blue = 255;

                        pic.set(j, i, red, green, blue);
                }
        }
        return *this;
}
bool ImageEditor::operator==(const ImageEditor& ie) const
{
	// compare to another image
        return true;
}
bool ImageEditor::operator!=(const ImageEditor& ie) const
{
	// compare to another image
        return true;
}
ImageEditor& ImageEditor::operator*=(unsigned int n)
{
	// expand by factor of n by n
        return *this;
}
