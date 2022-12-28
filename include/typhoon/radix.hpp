///\file

/******************************************************************************
The MIT License(MIT)

Embedded Template Library.
https://github.com/TYPHOONCPP/tphn
https://www.tphncpp.com

Copyright(c) 2014 John Wellbelove

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
******************************************************************************/

#ifndef TYPHOON_RADIX_HPP
#define TYPHOON_RADIX_HPP

#include "platform.hpp"
#include "enum_type.hpp"

#include <stdint.h>

///\defgroup radix radix
/// Radix constants for binary, octal, decimal and hex.
///\ingroup tphn

namespace tphn
{
  /// \ingroup radix
  struct radix
  {
    enum enum_type
    {
      undefined = 0,
      binary    = 2,
      octal     = 8,
      decimal   = 10,
      hex       = 16
    };

    TYPHOON_DECLARE_ENUM_TYPE(radix, uint_least8_t)
    TYPHOON_ENUM_TYPE(undefined, "undefined")
    TYPHOON_ENUM_TYPE(binary,    "binary")
    TYPHOON_ENUM_TYPE(octal,     "octal")
    TYPHOON_ENUM_TYPE(decimal,   "decimal")
    TYPHOON_ENUM_TYPE(hex,       "hex")
    TYPHOON_END_ENUM_TYPE
  };
}

#endif
