#include <stdio.h>
#include "nscript/loader.hpp"
#include "nscript.hpp"

using namespace myun2::nscript;

int main()
{
	loader l("ex.txt");
	puts(l.data());
	return 0;
}
