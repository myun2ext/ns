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
				int prev_state = 0;

				while((c = *p) != '\0')
				{
					int state = 0;
					if ( is_split_char(c) ) state = 1;
					if ( is_symbol_char(c) ) state = 2;

					if ( state == 1 || state == 2 || prev_state != state ) {
						unsigned long length = p - token_started;
						if ( length != 0 ) {
							::std::string token(token_started, length);
							tokens.push_back(token);
							token_started = p;
						}
						if ( state == 1 )
							token_started = p + 1;
					}
					prev_state = state;
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
