#ifndef _CSURFACE_H_
    #define _CSURFACE_H_

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

class CSurface {
    public:
        CSurface();

    public:
        static SDL_Surface* OnLoad(const char* File);

        static bool OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src);

        static bool OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, SDL_Rect DestR, int X, int Y);

        static bool Transparent(SDL_Surface* Surf_Dest, int R, int G, int B);
};

#endif
