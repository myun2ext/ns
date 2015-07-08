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
		private:
			const char* separators;
			const char* symbols;
		public:
			torkenizer(const char* sep_chars = " \t\r\n",
					const char* symbol_chars = "{}[]\"'!#$%&()-=^~\|@`;+:*,<.>/?") : separators(sep_charas) {}
			bool parse(const char* data)
			{
				const char* p = data;
				while(*p != '\0')
				{
					p++;
				}
			}
		};
	}
}

#endif///__MYUN2_GITHUB_COM__NSCRIPT__TORKENIZER_HPP__
