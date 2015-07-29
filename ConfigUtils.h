#pragma once

#include <QList>
#include <QRect>

class CoderPostion
{
public:
	int left;
	int right;
	int top;
	int bottom;
	int maxRows;
	int space;
};

class ConfigUtils
{
public:
	ConfigUtils(void);
	~ConfigUtils(void);

	static QList<QRect> CaculateButtonRects(int size, int width, int height, CoderPostion postion);
};

