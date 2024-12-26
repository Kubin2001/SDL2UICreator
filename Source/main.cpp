#include <iostream>
#include "SDL.h"
#include "Program.h"
#include "GlobalVariables.h"

int main(int argv, char* argc[])
{
    //srand(time(0));
    srand(0);

    Program* program = new Program();

    program->Start();
    Global::TickTimer = SDL_GetTicks();
    Global::LogicTimeEnd = Global::TickTimer + Global::frameDelay;
    Global::RenderingTimeEnd = Global::TickTimer + 16;
    while (Global::status)
    {
        SDL_Delay(1);
        Global::TickTimer = SDL_GetTicks();
        if (Global::TickTimer > Global::LogicTimeEnd) {
            Global::LogicTimeEnd = Global::TickTimer + Global::frameDelay;
            program->GameLogic();
        }

        if (Global::TickTimer > Global::RenderingTimeEnd) {
            Global::RenderingTimeEnd = Global::TickTimer + 16;
            program->GameConstant();
        }
    }

    delete program;
    return 0;
}
