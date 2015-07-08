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
			::std::string buffer;
			long size;
		public:
			struct load_failed {};
			loader(const char* path) { if (!load(path)) throw load_failed(); }
			bool load(const char* path)
			{
				FILE *fp = fopen(path, "r");
				if ( fp == NULL ) return false;
				size = file_size(fp);
				allocate(size);
				fread((void*)buffer.data(), 1, size, fp);
				fclose(fp);
				return true;
			}
			long file_size(FILE* fp) {
				long origin = ftell(fp);
				fseek(fp, 0, SEEK_END);
				size = ftell(fp);
				fseek(fp, origin, SEEK_SET);
				return size;
			}
			void allocate(long size) {
				buffer = ::std::string(size + 1, '\0');
			}
			const char* data() const { return buffer.data(); }
		};
	}
}

#endif///__MYUN2_GITHUB_COM__NSCRIPT__LOADER_HPP__
