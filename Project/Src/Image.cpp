#include <Image.hpp>

#include <PNG/cexcept.h>

/*explicit*/ Image::Image(const char* filename)
	: m_width(0)
	, m_height(0)
	, m_size(0)
	, m_bitsPerPixels(0)
	, m_pixels(nullptr)
	, m_backgroundRed(0)
	, m_backgroundGreen(0)
	, m_backgroundBlue(0)
	, m_good(true)
{
	m_good = Load(filename);
}

/*explicit*/ Image::Image(unsigned int width, unsigned int height, unsigned int bitsPerPixels)
	: m_width(width)
	, m_height(height)
	, m_size(bitsPerPixels / 4)
	, m_bitsPerPixels(bitsPerPixels)
	, m_pixels(nullptr)
	, m_backgroundRed(0)
	, m_backgroundGreen(0)
	, m_backgroundBlue(0)
	, m_good(true)
{
	if(m_size < 1 || m_size > 4)
	{
		m_size = 3;
		m_bitsPerPixels = 24;
	}
	m_pixels = new unsigned char[m_width * m_height * m_size];
	m_good = (nullptr != m_pixels);
}

/*explicit*/ Image::Image(unsigned int width, unsigned int height, unsigned int bitsPerPixels, unsigned char* bytes)
	: m_width(width)
	, m_height(height)
	, m_size(bitsPerPixels / 4)
	, m_bitsPerPixels(bitsPerPixels)
	, m_pixels(nullptr)
	, m_backgroundRed(0)
	, m_backgroundGreen(0)
	, m_backgroundBlue(0)
	, m_good(true)
{
	if(m_size < 1 || m_size > 4)
	{
		m_size = 3;
		m_bitsPerPixels = 24;
	}
	unsigned int pixelCount = m_width * m_height * m_size;
	m_pixels = new unsigned char[pixelCount];
	m_good = (nullptr != m_pixels);
	if(!m_good)
	{
		return;
	}
	for(register unsigned int i = 0; i < pixelCount; ++i)
	{
		m_pixels[i] = bytes[i];
	}
}

/*explicit*/ Image::Image(const Image& toCopy)
	: m_width(toCopy.m_width)
	, m_height(toCopy.m_height)
	, m_size(toCopy.m_size)
	, m_bitsPerPixels(toCopy.m_bitsPerPixels * 8)
	, m_pixels(nullptr)
	, m_backgroundRed(0)
	, m_backgroundGreen(0)
	, m_backgroundBlue(0)
{
	if(m_size < 1 || m_size > 4)
	{
		m_size = 3;
	}
	m_pixels = new unsigned char[m_width * m_height * m_size];
	m_good = (nullptr != m_pixels);
	if(!m_good)
	{
		return;
	}
	CopyImage(toCopy, Rect(0, 0, m_width, m_height));
}

/*virtual*/ void Image::Initialize(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4)
{
	unsigned int arraySize = (m_width + 1) * m_size * m_height;
	switch(m_size)
	{
	case 1:
		for(register unsigned int i = 0; i < arraySize; ++i)
		{
			m_pixels[i] = v1;
		}
		break;
	case 2:
		for(register unsigned int i = 0; i < arraySize; i += 2)
		{
			m_pixels[i] = v1;
			m_pixels[i + 1] = v2;
		}
		break;
	case 3:
		for(register unsigned int i = 0; i < arraySize; i += 3)
		{
			m_pixels[i] = v1;
			m_pixels[i + 1] = v2;
			m_pixels[i + 2] = v3;
		}
		break;
	default:
		for(register unsigned int i = 0; i < arraySize; i += 4)
		{
			m_pixels[i] = v1;
			m_pixels[i + 1] = v2;
			m_pixels[i + 2] = v3;
			m_pixels[i + 3] = v4;
		}
		break;
	}
}

/*virtual*/ bool Image::Load(const char* filename)
{
	return __internal_Load(filename, nullptr, 0, false);
}

/*virtual*/ bool Image::LoadFromMemory(const unsigned char* memory, unsigned int size)
{
	return __internal_Load(nullptr, memory, size, true);
}

/*virtual*/ bool Image::Save(const char* filename)
{
	unsigned int tmp;
	return __internal_Save(filename, nullptr, tmp, false);
}

/*virtual*/ bool Image::SaveToMemory(unsigned char* memory, unsigned int& size, bool fixedSize, unsigned int fsize)
{
	return __internal_Save(nullptr, memory, size, true, fixedSize, fsize);
}


/*virtual*/ bool Image::GetPixel(unsigned int x, unsigned int y, unsigned char* c) const
{
	if(0 < x || 0 < y || x >= m_width || y >= m_height)
	{
		return false;
	}
	for(register unsigned int i = 0; i < m_size; ++i)
	{
		c[i] = m_pixels[(x * m_height + y) * m_size + i];
	}
	return true;
}

/*virtual*/ bool Image::SetPixel(unsigned int x, unsigned int y, unsigned char* c)
{
	if(0 < x || 0 < y || x >= m_width || y >= m_height || nullptr == c)
	{
		return false;
	}
	for(register unsigned int i = 0; i < m_size; ++i)
	{
		m_pixels[(x * m_height + y) * m_size + i] = c[i];
	}
	return true;
}

/*virtual*/ bool Image::CopyImage(const Image& toCopy, Rect& dest, Rect& src)
{
	if(Image::Rect(0, 0, 0, 0) == dest)
	{
		dest = Rect(0, 0, m_width, m_height);
	}
	if(Image::Rect(0, 0, 0, 0) == src)
	{
		src = Rect(0, 0, toCopy.m_width, toCopy.m_height);
	}
	if(	dest.left >= m_width || 
		dest.top >= m_height ||
		src.left >= toCopy.m_width ||
		src.top >= toCopy.m_height ||
		0 == dest.width ||
		0 == dest.height)
	{
		return false;
	}
	if(	dest.left + dest.width > m_width)
	{
		dest.width = m_width - dest.left;
	}
	if(	dest.top + dest.height > m_height)
	{
		dest.height = m_height - dest.top;
	}
	if(	src.left + src.width > toCopy.m_width)
	{
		src.width = toCopy.m_width - src.left;
	}
	if(	src.top + src.height > toCopy.m_height)
	{
		src.height = toCopy.m_height - src.top;
	}
	unsigned char pixel[4] = {255, 255, 255, 255};
	for(register unsigned int i = 0; i < dest.width; ++i)
	{
		for(register unsigned int j = 0; j < dest.height; ++j)
		{
			toCopy.GetPixel(
				src.left + src.width * (int)(i / (float)dest.width), 
				src.top + src.height * (int)(j / (float)dest.height), 
				pixel);
			SetPixel(dest.left + i, dest.top + j, pixel);
		}
	}
	return true;
}

bool Image::__internal_Load(const char* filename, const unsigned char* memory, unsigned int size, bool fromMemory)
{
	png_structp png_ptr = nullptr;
	png_infop info_ptr = nullptr;
	unsigned long piWidth;
	unsigned long piHeight;
	png_byte pbSig[8];
	int iBitDepth;
	int iColorType;
	double dGamma;
	png_color_16 *pBackground;
	png_uint_32 ulChannels;
	png_uint_32 ulRowBytes;
	png_byte *pbImageData = nullptr;
	png_byte **ppbRowPointers = nullptr;
	FILE *pfFile;
	Image::MemoryStream memoryStream;
	if(fromMemory)
	{
		memoryStream.m_bytes = memory;
		memoryStream.m_position = 0;
		memoryStream.m_size = size;
		for(int i = 0; i < 8; ++i)
		{
			pbSig[i] = memoryStream.m_bytes[i];
			memoryStream.m_position++;
		}
	}
	else
	{
		pfFile = fopen(filename,"rb");
		if(!pfFile)
		{
			return(false);
		}
		fread(pbSig,1,8,pfFile);
	}
	if(!png_check_sig(pbSig,8))
	{
		if(!fromMemory)
		{
			fclose(pfFile);
		}
		return(false);
	}
	png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, (png_error_ptr)__internal_PNG_ERROR, (png_error_ptr)NULL);
	if(!png_ptr)
	{
		if(!fromMemory)
		{
			fclose(pfFile);
		}
		return(false);
	}
	info_ptr = png_create_info_struct(png_ptr);
	if(!info_ptr)
	{
		png_destroy_read_struct(&png_ptr, NULL, NULL);
		if(!fromMemory)
		{
			fclose(pfFile);
		}
		return(false);
	}
	if(fromMemory)
	{
		png_set_read_fn(png_ptr, (png_voidp)&memoryStream, __internal_PNG_READ);
	}
	else
	{
		png_init_io(png_ptr, pfFile);
	}
	png_set_sig_bytes(png_ptr, 8);
	png_read_info(png_ptr, info_ptr);
	png_get_IHDR(png_ptr, info_ptr, &piWidth, &piHeight, &iBitDepth, &iColorType, NULL, NULL, NULL);
	if(iBitDepth == 16)
	{
		png_set_strip_16(png_ptr);
	}
	if(iColorType == PNG_COLOR_TYPE_PALETTE || iBitDepth < 8 || png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS))
	{
		png_set_expand(png_ptr);
	}
	if(iColorType == PNG_COLOR_TYPE_GRAY || iColorType == PNG_COLOR_TYPE_GRAY_ALPHA)
	{
		png_set_gray_to_rgb(png_ptr);
	}
	if(png_get_bKGD(png_ptr, info_ptr, &pBackground))
	{
		png_set_background(png_ptr, pBackground, PNG_BACKGROUND_GAMMA_FILE, 1, 1.0);
		m_backgroundRed = (unsigned char)pBackground->red;
		m_backgroundGreen = (unsigned char)pBackground->green;
		m_backgroundBlue = (unsigned char)pBackground->blue;
	}
	// if required set gamma conversion
	if (png_get_gAMA(png_ptr, info_ptr, &dGamma))
	{
		png_set_gamma(png_ptr, (double)2.2, dGamma);
	}

	// after the transformations have been registered update info_ptr data
	png_read_update_info(png_ptr, info_ptr);

	// get again width,height and the new bit-depth and color-type
	png_get_IHDR(png_ptr, info_ptr, &piWidth, &piHeight, &iBitDepth, &iColorType, NULL, NULL, NULL);

	// row_bytes is the width x number of channels

	ulRowBytes = png_get_rowbytes(png_ptr, info_ptr);
	ulChannels = png_get_channels(png_ptr, info_ptr);

	// now we can allocate memory to store the image
	pbImageData = new png_byte[ulRowBytes * piHeight];
	if(nullptr == pbImageData)
	{
		png_error(png_ptr,"PNG error: Allocating memory for image data");
	}

	// and allocate memory for an array of row-pointers
	ppbRowPointers = new png_bytep[piHeight];
	if(nullptr == ppbRowPointers)
	{
		png_error(png_ptr,"PNG error: Allocating memory for row pointers");
	}

	// set the individual row-pointers to point at the correct offsets
	for(register unsigned int i = 0; i < (piHeight); ++i)
	{
		ppbRowPointers[i] = pbImageData + i * ulRowBytes;
	}

	// now we can go ahead and just read the whole image
	png_read_image(png_ptr,ppbRowPointers);

	// read the additional chunks in the PNG file (not really needed)
	png_read_end(png_ptr,NULL);

	// and we're done

	delete[](ppbRowPointers);
	ppbRowPointers = nullptr;

	// yepp,done

	png_destroy_read_struct(&png_ptr,&info_ptr,NULL);

	if(nullptr != m_pixels)
	{
		delete[](m_pixels);
	}
	m_width = piWidth;
	m_height = piHeight;
	m_bitsPerPixels = ulChannels * 8;
	m_size = ulChannels;
	unsigned int pixelCount = m_width * m_height * m_size;
	m_pixels = new unsigned char[pixelCount];
	for(register unsigned int i = 0; i < pixelCount; ++i)
	{
		m_pixels[(piHeight - (i / ulRowBytes) - 1) * ulRowBytes + i % ulRowBytes] = pbImageData[i];
	}

	delete[](pbImageData);
	if(!fromMemory)
	{
		fclose(pfFile);
	}
	return(true);
}

bool Image::__internal_Save(const char* filename, unsigned char* memory, unsigned int& size, bool toMemory, bool fixedSize, unsigned int fsize)
{
	png_structp png_ptr = nullptr;
	png_infop info_ptr = nullptr;
	const int ciBitDepth = 8;
	png_uint_32 ulRowBytes;
	png_byte **ppbRowPointers = NULL;
	FILE *pfFile;
	Image::MemoryStream memoryStream;
	if(toMemory)
	{
		memoryStream.m_wbytes = memory;
		memoryStream.m_position = 0;
		if(fixedSize)
		{
			memoryStream.m_size = fsize;
		}
		else
		{
			memoryStream.m_size = -1;
		}
	}
	else
	{
		pfFile = fopen(filename,"wb");

		// open the PNG output file
		if(!pfFile)
		{
			return(false);
		}
	}

	// prepare the standard PNG structures
	png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, (png_error_ptr)__internal_PNG_ERROR, (png_error_ptr)NULL);
	if(!png_ptr)
	{
		if(!toMemory)
		{
			fclose(pfFile);
		}
		return(false);
	}

	info_ptr = png_create_info_struct(png_ptr);
	if (!info_ptr)
	{
		png_destroy_write_struct(&png_ptr, (png_infopp)NULL);
		if(!toMemory)
		{
			fclose(pfFile);
		}
		return(false);
	}

	if(toMemory)
	{
		png_set_write_fn(png_ptr, (png_voidp)pfFile, __internal_PNG_WRITE, __internal_PNG_FLUSH);
	}
	else
	{
		png_init_io(png_ptr, pfFile);
	}

	// we're going to write a very simple 3x8 bit RGB image
	switch(m_size)
	{
	case 1:
	case 2:
		png_set_IHDR(png_ptr, info_ptr, m_width, m_height, ciBitDepth, PNG_COLOR_TYPE_PALETTE, 
		PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);
		break;
	case 3:
		png_set_IHDR(png_ptr, info_ptr, m_width, m_height, ciBitDepth, PNG_COLOR_TYPE_RGB, 
		PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);
		break;
	default:
		png_set_IHDR(png_ptr, info_ptr, m_width, m_height, ciBitDepth, PNG_COLOR_TYPE_RGBA, 
		PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);
		break;
	}

	// write the file header information
	png_write_info(png_ptr,info_ptr);

	// swap the BGR pixels in the DiData structure to RGB
	png_set_bgr(png_ptr);

	// row_bytes is the width x number of channels
	ulRowBytes = m_width * m_size;

	unsigned int bytesCount = m_size * m_width * m_height;
	png_byte *pDiData = new png_byte[bytesCount];
	for(register unsigned int i = 0 ; i < bytesCount ; i += m_size)
	{
		for(register unsigned int j = 0; j < m_size; ++j)
		{
			pDiData[i + j] = (png_byte)m_pixels[i + m_size - j - 1];
		}
	}

	// we can allocate memory for an array of row-pointers
	ppbRowPointers = new png_bytep[m_height];

	// set the individual row-pointers to point at the correct offsets
	for(register unsigned i = 0; i < m_height; ++i)
	{
		ppbRowPointers[i] = pDiData + (m_height - i - 1) * ulRowBytes;
	}

	// write out the entire image data in one call
	png_write_image (png_ptr,ppbRowPointers);

	// write the additional chunks to the PNG file (not really needed)
	png_write_end(png_ptr,info_ptr);

	// and we're done
	delete[](ppbRowPointers);
	delete[](pDiData);
	ppbRowPointers = nullptr;
	pDiData = nullptr;

	// clean up after the write,and free any memory allocated
	png_destroy_write_struct(&png_ptr,&info_ptr);
	//        png_destroy_write_struct(&png_ptr,(png_infopp) NULL);

	// yepp,done
	if(toMemory)
	{
		memoryStream.m_size = memoryStream.m_position;
		size = memoryStream.m_size;
	}
	else
	{
		fclose (pfFile);
	}

	return(true);
}

/*static*/ void Image::__internal_PNG_ERROR(png_structp png_ptr, png_const_charp msg)
{
	if(png_ptr) {}
#ifndef PNG_NO_CONSOLE_IO
	fprintf(stderr,"libpng error: %s\n", msg);
#endif
}

/*static*/ void Image::__internal_PNG_READ(png_structp png_ptr, png_bytep data, png_size_t length)
{
	png_size_t check = 0;

	Image::MemoryStream* ms = ((Image::MemoryStream*)(png_ptr->io_ptr));

	if(ms->m_position >= 0)
	{
		for(register unsigned int i = 0; i < length; ++i)
		{
			if(ms->m_size <= ms->m_position)
			{
				break;
			}
			data[i] = ms->m_bytes[ms->m_position];
			ms->m_position++;
			check++;
		}
	}

	if (check != length)
	{
		png_error(png_ptr, "Read Error");
	}
}

/*static*/ void Image::__internal_PNG_WRITE(png_structp png_ptr, png_bytep data, png_size_t length)
{
	png_size_t check = 0;

	Image::MemoryStream* ms = ((Image::MemoryStream*)(png_ptr->io_ptr));

	if(ms->m_position >= 0)
	{
		for(register unsigned int i = 0; i < length; ++i)
		{
			if( ms->m_size > 0 && ms->m_size <= ms->m_position)
			{
				break;
			}
			ms->m_wbytes[ms->m_position] = data[i];
			ms->m_position++;
			check++;
		}
	}

	if (check != length)
	{
		png_error(png_ptr, "Write Error");
	}
}

/*static*/ void Image::__internal_PNG_FLUSH(png_structp png_ptr)
{

}
