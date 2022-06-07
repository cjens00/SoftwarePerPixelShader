#pragma once

#include <olcPixelGameEngine.h>


class Demo : public olc::PixelGameEngine
{
    olc::Pixel *bufferPrev; // PREVIOUS
    olc::Pixel *bufferNext; // CURRENT
    int x, y, xMax, yMax, bufferLen;
    int red, blue, green, alpha;
public:
    Demo();

    ~Demo() override;

    bool OnUserCreate() override; // Called once at start
    bool OnUserUpdate(float fDeltaTime) override; // Called each frame

    // Type T is a functor which must return an olc::Pixel type
    template<typename T>
    void PerPixelShader(T shader);

    void SwapBufferAndRender();

    olc::Pixel GetPixel(int x, int y);

    void SetPixel(int x, int y, olc::Pixel p);
};