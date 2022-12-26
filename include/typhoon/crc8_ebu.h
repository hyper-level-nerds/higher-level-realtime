///\file

/******************************************************************************
The MIT License(MIT)

Embedded Template Library.
https://github.com/TYPHOONCPP/tphn
https://www.tphncpp.com

Copyright(c) 2021 John Wellbelove

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

#ifndef TYPHOON_CRC8_EBU_INCLUDED
#define TYPHOON_CRC8_EBU_INCLUDED

#include "platform.h"
#include "private/crc_implementation.h"

///\defgroup ebu 8 bit CRC calculation
///\ingroup crc

namespace tphn
{
#if TYPHOON_USING_CPP11 && !defined(TYPHOON_CRC_FORCE_CPP03_IMPLEMENTATION)
  template <size_t Table_Size>
  using crc8_ebu_t = tphn::crc_type<tphn::private_crc::crc8_ebu_parameters, Table_Size>;
#else
  template <size_t Table_Size>
  class crc8_ebu_t : public tphn::crc_type<tphn::private_crc::crc8_ebu_parameters, Table_Size>
  {
  public:

    //*************************************************************************
    /// Default constructor.
    //*************************************************************************
    crc8_ebu_t()
    {
      this->reset();
    }

    //*************************************************************************
    /// Constructor from range.
    /// \param begin Start of the range.
    /// \param end   End of the range.
    //*************************************************************************
    template<typename TIterator>
    crc8_ebu_t(TIterator begin, const TIterator end)
    {
      this->reset();
      this->add(begin, end);
    }
  };
#endif
    
  typedef tphn::crc8_ebu_t<256U> crc8_ebu_t256;
  typedef tphn::crc8_ebu_t<16U>  crc8_ebu_t16;
  typedef tphn::crc8_ebu_t<4U>   crc8_ebu_t4;
  typedef crc8_ebu_t256         crc8_ebu;
}

#endif
