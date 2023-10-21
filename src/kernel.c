#include <math.h>
#include <console/console.h>

void k_main()
{
	//write
	clear_console();
	printText("welcome to z0S");
	printText("v0.1");

	//draw
	fill('~'); // fill screen to `~`
	drawPoint(10, 10); // draw a point (██)
};