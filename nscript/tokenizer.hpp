#ifndef __MYUN2_GITHUB_COM__NSCRIPT__TOKENIZER_HPP__
#define __MYUN2_GITHUB_COM__NSCRIPT__TOKENIZER_HPP__

#include <string>
#include <vector>

namespace myun2
{
	namespace nscript
	{
		class tokenizer
		{
		public:
			typedef ::std::vector< ::std::string> token_list_type, token_list;
			token_list parse(const char* data)
			{
				token_list_type tokens;
				const char* p = data;
				const char* token_started = data;
				char c;

				while((c = *p) != '\0')
				{
					if ( is_split_char(c) || is_symbol_char(c) ) {
						unsigned long length = p - token_started;
						if ( length != 0 ) {
							::std::string token(token_started, length);
							tokens.push_back(token);
							token_started = p;
						}
						if ( is_split_char(c) )
							token_started = p + 1;
					}
					p++;
				}
				return tokens;
			}
			bool is_split_char(char c) {
				if ( c == ' ' || c == '\t' || c == '\r' || c == '\n' ) return true;
				return false;
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

#endif///__MYUN2_GITHUB_COM__NSCRIPT__TOKENIZER_HPP__
