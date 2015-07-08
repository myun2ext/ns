#ifndef __MYUN2_GITHUB_COM__NSCRIPT__TORKENIZER_HPP__
#define __MYUN2_GITHUB_COM__NSCRIPT__TORKENIZER_HPP__

#include <string>
#include <vector>

namespace myun2
{
	namespace nscript
	{
		class torkenizer
		{
		public:
			typedef ::std::vector<::std::string> token_list_type, token_list;
			bool parse(const char* data)
			{
				token_list_type tokens;
				const char* p = data;
				const char* started = data;

				while((char c = *p) != '\0')
				{
					if ( is_split_char(c
					p++;
				}
			}
			bool is_split_char(char c) {
				if ( c == ' ' || c == '\t' || c == '\r' || c == '\n' ) return true;
			}
			bool is_symbol_char(char c) {
				if ( c > ' ' && c < '0' ) return true;
				if ( c > '9' && c < 'A' ) return true;
				if ( c > 'Z' && c < 'a' && c != '_' ) return true;
				if ( c > 'z' && c <= '~' ) return true;
				return false;
			}
		};
	}
}

#endif///__MYUN2_GITHUB_COM__NSCRIPT__TORKENIZER_HPP__
