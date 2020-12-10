#include "headers/segmentation.h"

SDL_Surface* Detect_RLSA_Block(SDL_Surface* image, int n)
{
    SDL_Surface* image_temp = Image_Copy(image);
    SDL_LockSurface(image);
    SDL_LockSurface(image_temp);

    int c = 0;
    int c2 = 0;
    bool breaking = false;

    for (int x = 0; x < image->w; x++)
    {
        for (int y = 0; y < image->h; y++)
        {
            c = Pixel_GetR(SDL_GetPixel32(image,x,y));
            if (c == 255)
            {
                for (int x2 = x-n; x2 <= x + n; x2++)
                {
                    for (int y2 = y-n; y2 <= y + n; y2++)
                        if (Pixel_Exist(image,x2,y2))
                        {
                            c2 = Pixel_GetR(SDL_GetPixel32(image,x2,y2));
                            if (c2 == 0)
                            {
                                SDL_PutPixel32(image_temp,x,y,Pixel_RGBto32(255,0,0
                                        ,0));
                                breaking = true;
                                break;
                            }
                        }
                    if (breaking)
                    {
                        breaking = false;
                        break;
                    }
                }
            }
        }
    }
    SDL_UnlockSurface(image);
    SDL_UnlockSurface(image_temp);
    return image_temp;
}