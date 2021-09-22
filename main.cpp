#include "BMP.h"
#include <cmath>
#include <iostream>
using namespace std;

int centerx = 100; // my version of (0,0)
int centery = 100;
float a = floor(768/10);
float b = floor(384/10);
void CirclePoints(int x,int y, BMP &bmpNew);
int main() {
  float yc;
	BMP bmpNew(200, 200, false);
	bmpNew.fill_region(0, 0, 200, 200, 0, 0, 0, 0);
	for (int i = 0; i <= 199; i++) {
		 //bmpNew.set_pixel(i, 100, 255, 255, 255, 0);
	}
  int previousYpos = b;
  for (int x = 0; x <= a; x++) 
  {
    previousYpos--;
    yc = sqrt((b*b)-(((b*b)*(x*x))/(a*a)));
    bool track = false;
    for (int y = 0; y <= b; y++) 
    {
      if (y == round(yc))
      {
        int offset = previousYpos-y;
        CirclePoints(x, y, bmpNew);
        while(y<=previousYpos)
        {
          int ypos = previousYpos - y;
          CirclePoints(x, y+ypos, bmpNew);
          previousYpos--;
        }
        previousYpos = y;
      }
    }
    yc = 0;
  }
	bmpNew.write("output.bmp");

}


void CirclePoints(int x, int y, BMP &bmpNew) {
	bmpNew.set_pixel(centerx + x, centery + y, 255, 255, 255, 0);
	bmpNew.set_pixel(centerx - x, centery + y, 255, 255, 255, 0);
	// bmpNew.set_pixel(centerx+x , centery-y , 255, 255, 255, 0);
	// bmpNew.set_pixel(centerx-x, centery-y, 255, 255, 255, 0);
};

