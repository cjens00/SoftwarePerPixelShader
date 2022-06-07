#define OLC_PGE_APPLICATION

#include "Demo.h"

Demo::Demo()
{
    bufferPrev = bufferNext = nullptr;
    x = y = xMax = yMax = bufferLen = 0;
    red = blue = green = alpha = 255;
    sAppName = "Visualizer";
}

bool Demo::OnUserCreate()
{
    x = y = 0;
    yMax = ScreenHeight();
    xMax = ScreenWidth();
    bufferLen = xMax * yMax;
    bufferPrev = (olc::Pixel *)
            malloc(sizeof(olc::Pixel) * bufferLen);
    bufferNext = (olc::Pixel *)
            malloc(sizeof(olc::Pixel) * bufferLen);

    olc::Pixel *pixA = bufferPrev;
    auto bufferEnd = pixA + bufferLen;
    for (; pixA != bufferEnd; pixA++)
    {
        *pixA = olc::Pixel{olc::BLACK};
    }
    memcpy(bufferNext, bufferPrev, sizeof(olc::Pixel) * bufferLen);
    return true;
}

bool Demo::OnUserUpdate(float fDeltaTime)
{
    PerPixelShader([&]
                   {
                       std::clamp(red, 0, 255);
                       std::clamp(green, 0, 255);
                       std::clamp(blue, 0, 255);
                       return olc::Pixel(red,
                                         blue,
                                         green);
                   });
    SwapBufferAndRender();
    return true;
}

template<typename T>
void Demo::PerPixelShader(T shader)
{
    olc::Pixel *pix = this->bufferNext;
    auto bufferEnd = pix + bufferLen;
    for (; pix != bufferEnd; pix++)
    {
        *pix = shader();
    }
}

void Demo::SwapBufferAndRender()
{
    memcpy(bufferPrev, bufferNext, sizeof(olc::Pixel) * bufferLen);
    for (int sx = 0; sx < xMax; sx++)
        for (int sy = 0; sy < yMax; sy++)
            Draw(sx, sy, GetPixel(sx, sy));
}

olc::Pixel Demo::GetPixel(int px, int py)
{
    return *(bufferPrev + (px * py) - 1);
}

void Demo::SetPixel(int px, int py, olc::Pixel p)
{
    *(bufferNext + (px * py) - 1) = p;
}

Demo::~Demo()
{
    free(bufferPrev);
    free(bufferNext);
}