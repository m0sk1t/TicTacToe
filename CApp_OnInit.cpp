#include "CApp.h"

bool CApp::OnInit() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    if((Surf_Display = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
    }

    if((Surf_Test = CSurface::OnLoad("skuller.png")) == NULL) {
        return false;
    }

    SDL_WM_SetCaption("Hello, HABRAHABR!!!",0);
    return true;
}
