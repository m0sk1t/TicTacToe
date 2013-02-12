#include "CSurface.h"

CSurface::CSurface() {
}

SDL_Surface* CSurface::OnLoad(const char* File) {
    SDL_Surface* Surf_Temp = NULL;
    SDL_Surface* Surf_Return = NULL;

    if((Surf_Temp = IMG_Load(File)) == NULL) {
        return NULL;
    }

    Surf_Return = SDL_DisplayFormat(Surf_Temp);
    SDL_FreeSurface(Surf_Temp);

    return Surf_Return;
}

bool CSurface::OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src)
{
    if(Surf_Dest == NULL || Surf_Src == NULL) {
        return false;
    }

    SDL_BlitSurface(Surf_Src, NULL, Surf_Dest, NULL);

    return true;
}

bool CSurface::OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, SDL_Rect DestR, int X, int Y)
{
    if(Surf_Dest == NULL || Surf_Src == NULL) {
        return false;
    }
    SDL_Rect SrcGrid;

    SrcGrid.x = X;
    SrcGrid.y = Y;

    SDL_BlitSurface(Surf_Src, &DestR, Surf_Dest, &SrcGrid);

    return true;
}

bool CSurface::Transparent(SDL_Surface* Surf_Dest, int R, int G, int B) {
    if(Surf_Dest == NULL) {
        return false;
    }

    SDL_SetColorKey(Surf_Dest, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(Surf_Dest->format, R, G, B));

    return true;
}
