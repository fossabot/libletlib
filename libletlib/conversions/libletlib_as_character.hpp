// Copyright (c) 2020-2021, Ville Rissanen
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this
//    list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
// ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// __        __  __        __                    __      __        __  __
// /  |      /  |/  |      /  |                  /  |    /  |      /  |/  |
// $$ |      $$/ $$ |____  $$ |        ______   _$$ |_   $$ |      $$/ $$ |____
// $$ |      /  |$$      \ $$ |       /      \ / $$   |  $$ |      /  |$$      \.
// $$ |      $$ |$$$$$$$  |$$ |      /$$$$$$  |$$$$$$/   $$ |      $$ |$$$$$$$  |
// $$ |      $$ |$$ |  $$ |$$ |      $$    $$ |  $$ | __ $$ |      $$ |$$ |  $$ |
// $$ |_____ $$ |$$ |__$$ |$$ |_____ $$$$$$$$/   $$ |/  |$$ |_____ $$ |$$ |__$$ |
// $$       |$$ |$$    $$/ $$       |$$       |  $$  $$/ $$       |$$ |$$    $$/
// $$$$$$$$/ $$/ $$$$$$$/  $$$$$$$$/  $$$$$$$/    $$$$/  $$$$$$$$/ $$/ $$$$$$$/

#ifndef LIBLETLIB_LIBLETLIB_AS_CHARACTER_HPP
#define LIBLETLIB_LIBLETLIB_AS_CHARACTER_HPP

namespace libletlib
{
	namespace detail
	{
		/// \brief Function to return char value of previous bool type.
		///
		/// \param _value to convert.
		/// \return character value of the argument.
		LIBLETLIB_NODISCARD inline char boolean_as_character(var const& _value) noexcept
		{
			return _value.value.bool_type ? '1' : '0';
		}

		/// \brief Function to return char value of previous char type.
		///
		/// \param _value to convert.
		/// \return character value of the argument.
		LIBLETLIB_NODISCARD inline char character_as_character(var const& _value) noexcept
		{
			return _value.value.char_type;
		}

		/// \brief Function to return char value of previous signed char type.
		///
		/// \param _value to convert.
		/// \return character value of the argument.
		LIBLETLIB_NODISCARD inline char signed_character_as_character(var const& _value) noexcept
		{
			return static_cast<char>(_value.value.signed_char_type);
		}

		/// \brief Function to return char value of an unsigned char type.
		///
		/// \param _value to convert.
		/// \return character value of the argument.
		LIBLETLIB_NODISCARD inline char unsigned_character_as_character(var const& _value) noexcept
		{
			return static_cast<char>(_value.value.unsigned_char_type);
		}

		/// \brief Function to return char value of previous wchar_t type.
		///
		/// \param _value to convert.
		/// \return character value of the argument.
		LIBLETLIB_NODISCARD inline char wide_character_as_character(var const& _value) noexcept
		{
			return static_cast<char>(_value.value.wchar_type);
		}

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		/// \brief Function to return char value of previous char8_t type.
		///
		/// \param _value to convert.
		/// \return character value of the argument.
		LIBLETLIB_NODISCARD inline char bit8_character_as_character(var const& _value) noexcept
		{
			return static_cast<char>(_value.value.char8_type);
		}
	#endif

		/// \brief Function to return char value of previous char16_t type.
		///
		/// \param _value to convert.
		/// \return character value of the argument.
		LIBLETLIB_NODISCARD inline char bit16_character_as_character(var const& _value) noexcept
		{
			return static_cast<char>(_value.value.char16_type);
		}

		/// \brief Function to return char value of previous char32_t type.
		///
		/// \param _value to convert.
		/// \return character value of the argument.
		LIBLETLIB_NODISCARD inline char bit32_character_as_character(var const& _value) noexcept
		{
			return static_cast<char>(_value.value.char32_type);
		}

#endif

		/// \brief Function to return char value of previous short type.
		///
		/// \param _value to convert.
		/// \return character value of the argument.
		LIBLETLIB_NODISCARD inline char short_as_character(var const& _value) noexcept
		{
			return static_cast<char>(_value.value.short_type);
		}

		/// \brief Function to return char value of an unsigned short type.
		///
		/// \param _value to convert.
		/// \return character value of the argument.
		LIBLETLIB_NODISCARD inline char unsigned_short_as_character(var const& _value) noexcept
		{
			return static_cast<char>(_value.value.unsigned_short_type);
		}

		/// \brief Function to return char value of an int type.
		///
		/// \param _value to convert.
		/// \return character value of the argument.
		LIBLETLIB_NODISCARD inline char integer_as_character(var const& _value) noexcept
		{
			return static_cast<char>(_value.value.int_type);
		}

		/// \brief Function to return char value of an unsigned int type.
		///
		/// \param _value to convert.
		/// \return character value of the argument.
		LIBLETLIB_NODISCARD inline char unsigned_integer_as_character(var const& _value) noexcept
		{
			return static_cast<char>(_value.value.unsigned_int_type);
		}

		/// \brief Function to return char value of previous long type.
		///
		/// \param _value to convert.
		/// \return character value of the argument.
		LIBLETLIB_NODISCARD inline char long_as_character(var const& _value) noexcept
		{
			return static_cast<char>(_value.value.long_type);
		}

		/// \brief Function to return char value of an unsigned long type.
		///
		/// \param _value to convert.
		/// \return character value of the argument.
		LIBLETLIB_NODISCARD inline char unsigned_long_as_character(var const& _value) noexcept
		{
			return static_cast<char>(_value.value.unsigned_long_type);
		}

#if (__cplusplus >= 201103L)

		/// \brief Function to return char value of previous long long type.
		///
		/// \param _value to convert.
		/// \return character value of the argument.
		LIBLETLIB_NODISCARD inline char long_long_as_character(var const& _value) noexcept
		{
			return static_cast<char>(_value.value.long_long_type);
		}

		/// \brief Function to return char value of an unsigned long long type.
		///
		/// \param _value to convert.
		/// \return character value of the argument.
		LIBLETLIB_NODISCARD inline char unsigned_long_long_as_character(var const& _value) noexcept
		{
			return static_cast<char>(_value.value.unsigned_long_long_type);
		}

#endif

		/// \brief Function to return char value of previous float type.
		///
		/// \param _value to convert.
		/// \return character value of the argument.
		LIBLETLIB_NODISCARD inline char float_as_character(var const& _value) noexcept
		{
			return float_round<float, char>(_value.value.float_type);
		}

		/// \brief Function to return char value of previous double type.
		///
		/// \param _value to convert.
		/// \return character value of the argument.
		LIBLETLIB_NODISCARD inline char double_as_character(var const& _value) noexcept
		{
			return float_round<double, char>(_value.value.double_type);
		}

		/// \brief Function to return char value of previous long double type.
		///
		/// \param _value to convert.
		/// \return character value of the argument.
		LIBLETLIB_NODISCARD inline char long_double_as_character(var const& _value) noexcept
		{
			return float_round<long double, char>(_value.value.long_double_type);
		}

		/// \brief Function to return char value of previous raw string type.
		///
		/// \param _value to convert.
		/// \return character value of the argument.
		LIBLETLIB_NODISCARD inline char string_as_character(var const& _value) noexcept
		{
			return _value.value.string_type[0];
		}

		/// \brief Function to return char value of previous wide string type.
		///
		/// \param _value to convert.
		/// \return character value of the argument.
		LIBLETLIB_NODISCARD inline char wide_string_as_character(var const& _value) noexcept
		{
			return static_cast<char>(_value.value.wide_string_type[0]);
		}

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		/// \brief Function to return char value of previous 8 bit string type.
		///
		/// \param _value to convert.
		/// \return character value of the argument.
		LIBLETLIB_NODISCARD inline char bit8_string_as_character(var const& _value) noexcept
		{
			return static_cast<char>(_value.value.bit8_string_type[0]);
		}
	#endif

		/// \brief Function to return char value of previous 16 bit string type.
		///
		/// \param _value to convert.
		/// \return character value of the argument.
		LIBLETLIB_NODISCARD inline char bit16_string_as_character(var const& _value) noexcept
		{
			return static_cast<char>(_value.value.bit16_string_type[0]);
		}

		/// \brief Function to return char value of previous 32 bit string type.
		///
		/// \param _value to convert.
		/// \return character value of the argument.
		LIBLETLIB_NODISCARD inline char bit32_string_as_character(var const& _value) noexcept
		{
			return static_cast<char>(_value.value.bit32_string_type[0]);
		}

#endif

		/// \brief Function to return char value of previous void pointer type.
		///
		/// \param _value to convert.
		/// \return character value of the argument.
		LIBLETLIB_NODISCARD inline char pointer_as_character(var const& _value) noexcept
		{
			return *(reinterpret_cast<char*>(_value.value.void_pointer_type));
		}

#ifndef LIBLETLIB_FREESTANDING

		/// \brief Function to return char value of previous array type.
		///
		/// \return character value of the argument.
		LIBLETLIB_NODISCARD inline char array_as_character(var const& _value) noexcept
		{
			return (*_value.value.array_type).behaviour->as_character(_value);
		}

		/// \brief Function to return char value of previous subroutine type.
		///
		/// \return character value of the argument.
		LIBLETLIB_NODISCARD inline char subroutine_as_character(var const&) LIBLETLIB_NOEXCEPT
		{
			return '\0';
		}

		/// \brief Function to return char value of previous function type.
		///
		/// \return character value of the argument.
		LIBLETLIB_NODISCARD inline char function_as_character(var const& _value) noexcept
		{
			var result = var(_value.value.function_type)();
			return result.behaviour->as_character(result);
		}

#endif
#if (__cplusplus >= 201103L)
		/// \brief Function to return char value of previous nullptr_t type.
		///
		/// \return character value of the argument.
		LIBLETLIB_NODISCARD inline char null_as_character(var const&) noexcept
		{
			return '\0';
		}

#endif
	}// namespace detail
}// namespace libletlib

#endif//LIBLETLIB_LIBLETLIB_AS_CHARACTER_HPP
