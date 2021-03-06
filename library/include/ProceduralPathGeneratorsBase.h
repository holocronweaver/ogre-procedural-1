/*
-----------------------------------------------------------------------------
This source file is part of ogre-procedural

For the latest info, see http://code.google.com/p/ogre-procedural/

Copyright (c) 2010-2013 Michael Broutin

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
-----------------------------------------------------------------------------
*/
#ifndef PROCEDURAL_PATH_GENERATORS_BASE_INCLUDED
#define PROCEDURAL_PATH_GENERATORS_BASE_INCLUDED

#include "ProceduralPath.h"
#include "ProceduralSplines.h"

namespace Procedural
{
//-----------------------------------------------------------------------
/**
 * \ingroup pathgrp
 * Base class for Path generators
 */
template<class T>
class BaseSpline3
{
protected:
	/// The number of segments between 2 control points
	unsigned int mNumSeg;
	/// Tells if the spline is closed or not
	bool mClosed;
public:
	BaseSpline3() : mNumSeg(4), mClosed(false) {}

	/// Sets the number of segments between 2 control points
	/// \exception Ogre::InvalidParametersException Minimum of numSeg is 1
	inline T& setNumSeg(unsigned int numSeg)
	{
		if (numSeg == 0)
			OGRE_EXCEPT(Ogre::Exception::ERR_INVALIDPARAMS, "There must be more than 0 segments", "Procedural::BaseSpline3::setNumSeg(unsigned int)");
		mNumSeg = numSeg;
		return (T&)*this;
	}

	/// Closes the spline
	inline T& close()
	{
		mClosed = true;
		return (T&)*this;
	}
};
}
#endif