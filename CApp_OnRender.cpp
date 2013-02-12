#include "CApp.h"

void CApp::OnRender() {
    CSurface::OnDraw(Surf_Display, Surf_Grid);
    for(int i = 0;i < 9;i++) {
        int X = (i % 3) * 100;
        int Y = (i / 3) * 100;

        if(Grid[i] == GRID_TYPE_X) {
            CSurface::OnDraw(Surf_Display, Surf_X_O, Cross, X, Y);
        }else
        if(Grid[i] == GRID_TYPE_O) {
            CSurface::OnDraw(Surf_Display, Surf_X_O, Nulls, X, Y);
        }
    }
    SDL_Flip(Surf_Display);
}
