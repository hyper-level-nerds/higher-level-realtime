///\file

/******************************************************************************
The MIT License(MIT)

Embedded Template Library.
https://github.com/TYPHOONCPP/tphn
https://www.tphncpp.com

Copyright(c) 2018 John Wellbelove

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

#ifndef TYPHOON_MACROS_INCLUDED
#define TYPHOON_MACROS_INCLUDED

#define TYPHOON_CONCAT2(X, Y)  X##Y
#define TYPHOON_CONCAT(X, Y)   TYPHOON_CONCAT2(X, Y)
#define TYPHOON_STRINGIFY2(X)  #X
#define TYPHOON_STRINGIFY(X)   TYPHOON_STRINGIFY2(X)
#define TYPHOON_STRING(X)      TYPHOON_CONCAT(  , TYPHOON_STRINGIFY(X))
#define TYPHOON_WIDE_STRING(X) TYPHOON_CONCAT( L, TYPHOON_STRINGIFY(X))
#define TYPHOON_U8_STRING(X)   TYPHOON_CONCAT(u8, TYPHOON_STRINGIFY(X))
#define TYPHOON_U16_STRING(X)  TYPHOON_CONCAT( u, TYPHOON_STRINGIFY(X))
#define TYPHOON_U32_STRING(X)  TYPHOON_CONCAT( U, TYPHOON_STRINGIFY(X))

#endif

