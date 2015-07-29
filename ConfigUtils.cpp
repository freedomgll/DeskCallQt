#include "ConfigUtils.h"


ConfigUtils::ConfigUtils(void)
{
}


ConfigUtils::~ConfigUtils(void)
{
}

QList<QRect> ConfigUtils::CaculateButtonRects(int size, int cx, int cy, CoderPostion postion)
{
	QList<QRect> lRects;

	int maxRows = postion.maxRows;
	int space = postion.space;

	int col = (size + maxRows -1)/maxRows;
	int row = (size + col -1)/col;

	int width = cx*(postion.right - postion.left)/100;
	int height = cy*(postion.bottom - postion.top)/100;

	int xOffset = width/col;
	int yOffset = height/row;

	int xOffw = xOffset*(100-space)/200;
	int yOffh = yOffset*(100-space)/200;
	
	int xStart = (cx*postion.left/100) + xOffset/2;
	int yStart = (cy*postion.top)/100 + yOffset/2;

	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			int px = xStart + xOffset*j;
			int py = yStart + yOffset*i;

			lRects.push_back(QRect(px - xOffw,py - yOffh,2*xOffw,2*yOffh));
		}
	}


	return lRects;
}
