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

#ifndef LIBLETLIB_LIBLETLIB_PATTERN_MATCHING_HPP
#define LIBLETLIB_LIBLETLIB_PATTERN_MATCHING_HPP

#ifndef LIBLETLIB_FREESTANDING

namespace libletlib
{
	namespace detail
	{
	#if (__cplusplus >= 201103L)
		/// \brief Facilitates matching expressions with the ->* operator.
		class match_condition final
		{
		public:
			var pattern;
			var expression;

			/// \brief Basic constructor.
			/// \param _pattern pattern to match.
			/// \param _expression to produce result.
			match_condition(var const& _pattern, var const& _expression) noexcept
			{
				pattern    = _pattern;
				expression = _expression;
			}
		};

		/// \brief
		/// \param _type
		/// \param _expression
		/// \return
		match_condition operator->*(var const& _type, var const& _expression) noexcept
		{
			return match_condition(_type, _expression);
		}

		/// \brief Class to facilitate pattern matching.
		/// \tparam Size amount of match condition variables.
		template<std::size_t Size>
		class matcher final
		{
		public:
			bool matched = false;
			var matchees;
			var pattern;
			var result = var();

			/// \brief Construct a list of the matchees and establish the pattern to match.
			/// \tparam Arguments to this class.
			/// \param _matchees arguments to this class.
			template<typename... Arguments>
			matcher(Arguments... _matchees) noexcept
			{
				matchees = backing::list(_matchees...);
				pattern  = libletlib::detail::pattern_(var(), matchees);
			}

			/// \brief Facilitate match conditions with pattern:
			///  match(x) with
			///  | expression ->* expression
			/// syntax.
			/// \param _condition to match against.
			/// \return the result for this case.
			matcher& operator|(match_condition const& _condition) noexcept
			{
				if (!matched)
				{
					if ('=' == type_id(_condition.pattern)
					    && var::flatten_and_invoke(_condition.pattern, matchees,
					                               libletlib::detail::make_index_sequence<Size> {}))
					{
						result  = var::flatten_and_invoke(_condition.expression, matchees,
                                                         libletlib::detail::make_index_sequence<Size> {});
						matched = true;
					}
					else if (pattern == _condition.pattern || _condition.pattern == '_')
					{
						result  = var::flatten_and_invoke(_condition.expression, matchees,
                                                         libletlib::detail::make_index_sequence<Size> {});
						matched = true;
					}
				}
				return *this;
			}

			/// \brief Simple conversion operator.
			/// \return result of this pattern matching.
			operator var() const noexcept
			{
				return this->result;
			}
		};
	#endif
	}// namespace detail
}// namespace libletlib

#endif

#endif//LIBLETLIB_LIBLETLIB_PATTERN_MATCHING_HPP
