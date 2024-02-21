#include "ImageEditor.h"

int main()
{
	ImageEditor im("pikachu.png");
	Color col;
	col.r = 50;
	col.g = 50;
	col.b = 50;
	im -= col;
	im.save("pikachu2.png");
}
