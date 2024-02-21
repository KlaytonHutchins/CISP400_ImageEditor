#include "ImageEditor.h"

int main()
{
	ImageEditor im("pikachu.png");
//        ImageEditor im2("pikachu.png");
	Color col;
	col.r = 50;
	col.g = 50;
	col.b = 50;
//	im -= col;
//	cout << "== " << (im == im2) << endl << "!= " << (im != im2) << endl;
	im *= 3;
	im.save("pikachu2.png");
}
