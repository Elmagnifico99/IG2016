#ifndef __COLOR_HPP
#define __COLOR_HPP

class ColorRGB
{

public:

	union
	{
		float c[3];
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
		float c[4];
		struct
		{
			float r, g, b, a;
		};
	};

};

#endif // __COLOR_HPP