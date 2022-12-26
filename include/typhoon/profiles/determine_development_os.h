///\file

/******************************************************************************
The MIT License(MIT)

Embedded Template Library.
https://github.com/TYPHOONCPP/tphn
https://www.tphncpp.com

Copyright(c) 2019 John Wellbelove

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

#ifndef TYPHOON_DETERMINE_DEVELOPMENT_OS_INCLUDED
#define TYPHOON_DETERMINE_DEVELOPMENT_OS_INCLUDED

#if !defined(TYPHOON_DEVELOPMENT_OS_WINDOWS) && \
    !defined(TYPHOON_DEVELOPMENT_OS_LINUX) && \
    !defined(TYPHOON_DEVELOPMENT_OS_UNIX) && \
    !defined(TYPHOON_DEVELOPMENT_OS_APPLE) && \
    !defined(TYPHOON_DEVELOPMENT_OS_BSD) && \
    !defined(TYPHOON_DEVELOPMENT_OS_GENERIC)

  #if !defined(TYPHOON_DEVELOPMENT_OS_DETECTED) && !defined(TYPHOON_DEVELOPMENT_OS_WINDOWS)
    #if defined(WIN32) || defined(WIN64)
      #define TYPHOON_DEVELOPMENT_OS_WINDOWS
      #define TYPHOON_DEVELOPMENT_OS_DETECTED
    #endif
  #endif

  #if !defined(TYPHOON_DEVELOPMENT_OS_DETECTED) && !defined(TYPHOON_DEVELOPMENT_OS_LINUX)
    #if defined(__linux__)
      #define TYPHOON_DEVELOPMENT_OS_LINUX
      #define TYPHOON_DEVELOPMENT_OS_DETECTED
    #endif
  #endif

  #if !defined(TYPHOON_DEVELOPMENT_OS_DETECTED) && !defined(TYPHOON_DEVELOPMENT_OS_UNIX)
    #if defined(__unix__)
      #define TYPHOON_DEVELOPMENT_OS_UNIX
      #define TYPHOON_DEVELOPMENT_OS_DETECTED
    #endif
  #endif

  #if !defined(TYPHOON_DEVELOPMENT_OS_DETECTED) && !defined(TYPHOON_DEVELOPMENT_OS_APPLE)
    #if defined(__APPLE__)
      #define TYPHOON_DEVELOPMENT_OS_APPLE
      #define TYPHOON_DEVELOPMENT_OS_DETECTED
    #endif
  #endif

#if !defined(TYPHOON_DEVELOPMENT_OS_DETECTED) && !defined(TYPHOON_DEVELOPMENT_OS_BSD)
  #if defined(BSD)
    #define TYPHOON_DEVELOPMENT_OS_BSD
    #define TYPHOON_DEVELOPMENT_OS_DETECTED
  #endif
#endif

  #if !defined(TYPHOON_DEVELOPMENT_OS_DETECTED)
    #define TYPHOON_DEVELOPMENT_OS_GENERIC
    #define TYPHOON_DEVELOPMENT_OS_DETECTED

  #endif
#endif

#endif
