/******************************************************************************
The MIT License(MIT)

Embedded Template Library.
https://github.com/TYPHOONCPP/tphn
https://www.tphncpp.com

Copyright(c) 2017 John Wellbelove

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

#ifndef TYPHOON_TIMER_INCLUDED
#define TYPHOON_TIMER_INCLUDED

#include "platform.h"
#include "atomic.h"

#include <stdint.h>

//*****************************************************************************
// Definitions common to timers.
//*****************************************************************************

namespace tphn
{
#ifdef TYPHOON_TIMER_SEMAPHORE_TYPE
  typedef TYPHOON_TIMER_SEMAPHORE_TYPE timer_semaphore_t;
#else
  #if TYPHOON_HAS_ATOMIC
    typedef tphn::atomic_uint32_t timer_semaphore_t;
  #endif
#endif

  //***************************************************************************
  /// Common definitions for the timer framework.
  //***************************************************************************
  struct timer
  {
    // Timer modes.
    struct mode
    {
      enum
      {
        SINGLE_SHOT = false,
        REPEATING   = true
      };

      typedef bool type;
    };

    // Timer start status.
    struct start
    {
      enum
      {
        DELAYED   = false,
        IMMEDIATE = true
      };

      typedef bool type;
    };

    // Timer id.
    struct id
    {
      enum
      {
        NO_TIMER = 255
      };

      typedef uint_least8_t type;
    };

    // Timer state.
    struct state
    {
      enum
      {
        INACTIVE = 0xFFFFFFFFUL
      };
    };
  };
}

#endif
