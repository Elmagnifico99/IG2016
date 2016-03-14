#include <Color.hpp>

/*explicit*/ ColorRGB::ColorRGB()
	: r(0.0f)
	, g(0.0f)
	, b(0.0f)
{

}

ColorRGB::ColorRGB(float cr, float cg, float cb)
	: r(cr)
	, g(cg)
	, b(cb)
{

}

ColorRGB::ColorRGB(float* components)
	: r(*components)
	, g(*(components + 1))
	, b(*(components + 2))
{

}

ColorRGB::ColorRGB(const ColorRGB& toCopy)
	: r(toCopy.r)
	, g(toCopy.g)
	, b(toCopy.b)
{

}

ColorRGB::ColorRGB(const ColorRGBA& toConvert)
	: r(toConvert.r)
	, g(toConvert.g)
	, b(toConvert.b)
{

}

/*explicit*/ ColorRGBA::ColorRGBA()
	: r(0.0f)
	, g(0.0f)
	, b(0.0f)
	, a(0.0f)
{

}

ColorRGBA::ColorRGBA(float cr, float cg, float cb, float ca)
	: r(cr)
	, g(cg)
	, b(cb)
	, a(ca)
{

}

ColorRGBA::ColorRGBA(float* components)
	: r(*components)
	, g(*(components + 1))
	, b(*(components + 2))
	, a(*(components + 3))
{

}

ColorRGBA::ColorRGBA(const ColorRGBA& toCopy)
	: r(toCopy.r)
	, g(toCopy.g)
	, b(toCopy.b)
	, a(toCopy.a)
{

}

ColorRGBA::ColorRGBA(const ColorRGB& toConvert)
	: r(toConvert.r)
	, g(toConvert.g)
	, b(toConvert.b)
	, a(1.0f)
{

}