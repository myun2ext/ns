#ifndef __MYUN2_GITHUB_COM__NSCRIPT__LOADER_HPP__
#define __MYUN2_GITHUB_COM__NSCRIPT__LOADER_HPP__

#include <stdio.h>
#include <string>

namespace myun2
{
	namespace nscript
	{
		class loader
		{
		private:
			::std::string data;
			long size;
		public:
			loader(const char* path) { load(path); }
			bool load(const char* path)
			{
				FILE *fp = fopen(path, "r");
				if ( fp == NULL ) return false;
				size = file_size(fp);
				allocate(size);
				fread(data.data(), 1, size, fp);
				return true;
			}
			long fize_size(FILE* fp) {
				fseek(fp, 0, SEEK_END);
				return ftell(fp); }
			void allocate(long size) {
				data = ::std::string(size + 1, '\0');
			}
		}
	}
}

#endif///__MYUN2_GITHUB_COM__NSCRIPT__LOADER_HPP__
