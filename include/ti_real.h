// The MIT License (MIT)
//
// Copyright (c) 2019 Darrell Wright
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files( the "Software" ), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and / or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include <cstddef>
#include <string>

#include <daw/daw_string_view.h>

namespace daw::json_to_cpp::types {
	struct ti_real {
		bool is_optional = false;

		static constexpr bool is_null = false;

		constexpr ti_real( ) noexcept = default;

		constexpr size_t type( ) noexcept {
			return daw::json::json_value_t::index_of<
			  daw::json::json_value_t::real_t>( );
		}

		static constexpr daw::string_view name( ) noexcept {
			return "double";
		}

		static constexpr daw::string_view array_member_info( ) noexcept {
			return "json_number<no_name>";
		}

		inline static std::string json_name( std::string member_name ) noexcept {
			return "json_number<" + member_name + ">";
		}
	};
} // namespace daw::json_to_cpp::types