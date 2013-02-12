#include "CApp.h"

bool CApp::OnInit() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    if((Surf_Display = SDL_SetVideoMode(300, 300, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
    }

    if((Surf_Grid = CSurface::OnLoad("habr_grid.png")) == NULL) {
        return false;
    }

    if((Surf_X_O = CSurface::OnLoad("habr_cross_null.png")) == NULL) {
        return false;
    }

    Nulls.x = Nulls.y = 0;
    Nulls.w = Nulls.h = 100;

    Cross.x = 100;
    Cross.y = 0;
    Cross.w = Cross.h = 100;

    CSurface::Transparent(Surf_X_O, 220, 145, 255);

    Reset();

    SDL_WM_SetCaption("Hello, HABRAHABR!!! This is TicTacToe!",0);
    return true;
}
