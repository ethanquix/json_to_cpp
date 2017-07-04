// The MIT License (MIT)
//
// Copyright (c) 2016 Darrell Wright
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files( the "Software" ), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include <boost/utility/string_view.hpp>
#include <boost/filesystem/path.hpp>
#include <ostream>

#include <daw/json/daw_json_link.h>

namespace daw {
	namespace json_to_cpp {
		struct config_t final {
			bool enable_jsonlink;
			std::ostream * header_stream;
			std::ostream * cpp_stream;
			boost::filesystem::path cpp_path;
			boost::filesystem::path header_path;
			boost::filesystem::path json_path;
			bool separate_files;

			config_t( ) = default;
			~config_t( ) = default;
			config_t( config_t const & ) = default;
			config_t( config_t && ) = default;
			config_t & operator=( config_t const & ) = default;
			config_t & operator=( config_t && ) = default;

			std::ostream & header_file( );
			std::ostream & cpp_file( );

		};	// config_t

		void generate_cpp( boost::string_view json_string, config_t & config );
	}	// namespace json_to_cpp
}    // namespace daw

