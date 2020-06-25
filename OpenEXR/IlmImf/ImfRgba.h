///////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2004, Industrial Light & Magic, a division of Lucas
// Digital Ltd. LLC
// 
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
// *       Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
// *       Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
// *       Neither the name of Industrial Light & Magic nor the names of
// its contributors may be used to endorse or promote products derived
// from this software without specific prior written permission. 
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
///////////////////////////////////////////////////////////////////////////


#ifndef INCLUDED_IMF_RGBA_H
#define INCLUDED_IMF_RGBA_H

//-----------------------------------------------------------------------------
//
//	class Rgbad
//
//-----------------------------------------------------------------------------

#include "half.h"
#include "ImfNamespace.h"

OPENEXR_IMF_INTERNAL_NAMESPACE_HEADER_ENTER


//
// RGBA pixel
//

struct Rgbad
{
    half	r;
    half	g;
    half	b;
    half	a;
    half    d;
    
    Rgbad () {}
    Rgbad (half r, half g, half b, half a = 1.f, half d = 0.5f):
    r (r), g (g), b (b), a (a), d (d) {}

    Rgbad & operator = (const Rgbad &other)
    {
    	r = other.r;
    	g = other.g;
    	b = other.b;
        a = other.a;
        d = other.d;

    	return *this;
    }
};


//
// Channels in an RGBA file
//

enum RgbaChannels
{
    WRITE_R	= 0x01,		// Red
    WRITE_G	= 0x02,		// Green
    WRITE_B	= 0x04,		// Blue
    WRITE_A	= 0x08,		// Alpha

    WRITE_Y	= 0x10,		// Luminance, for black-and-white images,
    				// or in combination with chroma

    WRITE_C	= 0x20,		// Chroma (two subsampled channels, RY and BY,
    				// supported only for scanline-based files)

    WRITE_D = 0x40,     // Depth (my custom mod zz)

    WRITE_RGB	= 0x07,		// Red, green, blue
    WRITE_RGBA	= 0x0f,		// Red, green, blue, alpha
    WRITE_RGBD  = 0x47,     // Red, green, blue, depth
    WRITE_RGBAD = 0x4f,     // Red, green, blue, alpha, depth

    WRITE_YC	= 0x30,		// Luminance, chroma
    WRITE_YA	= 0x18,		// Luminance, alpha
    WRITE_YCA	= 0x38		// Luminance, chroma, alpha
};


OPENEXR_IMF_INTERNAL_NAMESPACE_HEADER_EXIT





#endif
