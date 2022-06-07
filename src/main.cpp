#include "Demo.h"

int main()
{
    Demo demo;
    if (demo.Construct(1920, 1200, 1, 1))
    {
        demo.Start();
    }
    return 0;
}