#include <stdio.h>
#include <klib/Exception.h>

using namespace klib;

int main()
{
    printf("Hello\n");
    throw klib::Exception("good");
    return 0;
}
