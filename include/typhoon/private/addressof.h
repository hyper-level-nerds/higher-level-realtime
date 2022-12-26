///\file

/******************************************************************************
The MIT License(MIT)

Embedded Template Library.
https://github.com/TYPHOONCPP/tphn
https://www.tphncpp.com

Copyright(c) 2022 John Wellbelove

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

#ifndef TYPHOON_ADDRESSOF_INCLUDED
#define TYPHOON_ADDRESSOF_INCLUDED

#include "../platform.h"

#if defined(TYPHOON_IN_UNIT_TEST) || TYPHOON_USING_STL
  #include <memory>
#endif

///\defgroup memory memory
///\ingroup tphn

namespace tphn
{
  //*****************************************************************************
  /// Gets the address of an object.
  /// https://en.cppreference.com/w/cpp/memory/addressof
  ///\ingroup memory
  //*****************************************************************************
  template <typename T>
  TYPHOON_CONSTEXPR17 T* addressof(T& t)
  {
#if TYPHOON_USING_STL && TYPHOON_USING_CPP11
    return std::addressof(t);
#else
    return reinterpret_cast<T*>(&const_cast<char&>(reinterpret_cast<const volatile char&>(t)));
#endif
  }
}

#endif
