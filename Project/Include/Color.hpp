#ifndef __COLOR_HPP
#define __COLOR_HPP

class ColorRGB
{

public:

	union
	{
		float rgb[3];
		struct
		{
			float r, g, b;
		};
	};

};

class ColorRGBA
{

public:

	union
	{
		float rgba[4];
		struct
		{
			float r, g, b, a;
		};
	};

};

#endif // __COLOR_HPP