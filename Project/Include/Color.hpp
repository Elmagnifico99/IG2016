#ifndef __COLOR_HPP
#define __COLOR_HPP

class ColorRGBA;

class ColorRGB
{

public:

	explicit ColorRGB(void);
	ColorRGB(float cr, float cg, float cb);
	ColorRGB(float* components);
	ColorRGB(const ColorRGB& toCopy);
	ColorRGB(const ColorRGBA& toConvert);

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

	explicit ColorRGBA(void);
	ColorRGBA(float cr, float cg, float cb, float ca);
	ColorRGBA(float* components);
	ColorRGBA(const ColorRGBA& toCopy);
	ColorRGBA(const ColorRGB& toConvert);

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