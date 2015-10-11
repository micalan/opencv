/*M///////////////////////////////////////////////////////////////////////////////////////
//
//  IMPORTANT: READ BEFORE DOWNLOADING, COPYING, INSTALLING OR USING.
//
//  By downloading, copying, installing or using the software you agree to this license.
//  If you do not agree to this license, do not download, install,
//  copy or use the software.
//
//
//                           License Agreement
//                For Open Source Computer Vision Library
//
// Copyright (C) 2000-2008, Intel Corporation, all rights reserved.
// Copyright (C) 2009, Willow Garage Inc., all rights reserved.
// Third party copyrights are property of their respective owners.
//
// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:
//
//   * Redistribution's of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//
//   * Redistribution's in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//
//   * The name of the copyright holders may not be used to endorse or promote products
//     derived from this software without specific prior written permission.
//
// This software is provided by the copyright holders and contributors "as is" and
// any express or implied warranties, including, but not limited to, the implied
// warranties of merchantability and fitness for a particular purpose are disclaimed.
// In no event shall the Intel Corporation or contributors be liable for any direct,
// indirect, incidental, special, exemplary, or consequential damages
// (including, but not limited to, procurement of substitute goods or services;
// loss of use, data, or profits; or business interruption) however caused
// and on any theory of liability, whether in contract, strict liability,
// or tort (including negligence or otherwise) arising in any way out of
// the use of this software, even if advised of the possibility of such damage.
//
//M*/

#ifndef _GRFMT_JPEG_H_
#define _GRFMT_JPEG_H_

#include "grfmt_base.hpp"
#include "bitstrm.hpp"

#ifdef HAVE_JPEG

// IJG-based Jpeg codec

namespace cv
{

//Picture orientation which may be taken from JPEG's EXIF
//Orientation usually matters when the picture is taken by
//smartphone or other camera with orientation sensor support
//Corresponds to EXIF 2.3 Specification
enum JpegOrientation
{
    JPEG_ORIENTATION_TL = 1, //0th row == visual top, 0th column == visual left-hand side
    JPEG_ORIENTATION_TR = 2, //0th row == visual top, 0th column == visual right-hand side
    JPEG_ORIENTATION_BR = 3, //0th row == visual bottom, 0th column == visual right-hand side
    JPEG_ORIENTATION_BL = 4, //0th row == visual bottom, 0th column == visual left-hand side
    JPEG_ORIENTATION_LT = 5, //0th row == visual left-hand side, 0th column == visual top
    JPEG_ORIENTATION_RT = 6, //0th row == visual right-hand side, 0th column == visual top
    JPEG_ORIENTATION_RB = 7, //0th row == visual right-hand side, 0th column == visual bottom
    JPEG_ORIENTATION_LB = 8  //0th row == visual left-hand side, 0th column == visual bottom
};

class JpegDecoder : public BaseImageDecoder
{
public:

    JpegDecoder();
    virtual ~JpegDecoder();

    bool  readData( Mat& img );
    bool  readHeader();
    void  close();

    ImageDecoder newDecoder() const;

protected:

    FILE* m_f;
    void* m_state;

private:

    int m_orientation;
    int getOrientation();
    void setOrientation(Mat& img);
};


class JpegEncoder : public BaseImageEncoder
{
public:
    JpegEncoder();
    virtual ~JpegEncoder();

    bool  write( const Mat& img, const std::vector<int>& params );
    ImageEncoder newEncoder() const;
};

}

#endif

#endif/*_GRFMT_JPEG_H_*/
