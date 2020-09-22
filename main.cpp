#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

SDL_Joystick *gamepad;
SDL_Event *even;
int joy, indexJoysticks;


int checkJoyStick(){
    int i;
    if (indexJoysticks == 1) {
        return 0;
    } else {
        for(i = 0; i < indexJoysticks; i++)
        {
            printf("Select your gamepad");
            printf("Name: %s\n", SDL_JoystickNameForIndex(i));
        }
    cin>>i;
    return i-1;
    }
}

void detectPressed(){

}

int main()
{
    if (SDL_Init(SDL_INIT_JOYSTICK) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    } else {
        SDL_Log("Program Started");
    }
    if (SDL_NumJoysticks() > 0) {
        printf("%d joysticks found\n", indexJoysticks = SDL_NumJoysticks());
        if ((gamepad = SDL_JoystickOpen(joy = checkJoyStick()))){
            SDL_JoystickEventState(SDL_ENABLE);
            SDL_Log("Connected");
            SDL_Log("%s\n", SDL_JoystickName(gamepad));
            SDL_Log("Number of Axes: %d\n", SDL_JoystickNumAxes(gamepad));
            SDL_Log("Number of Buttons: %d\n", SDL_JoystickNumButtons(gamepad));
        } else {
            SDL_Log("Couldn't find Joystick\n");
            SDL_Quit();
            return 1;
        }
    } else {
        SDL_Log("Couldn't find any Joystick\n");
        SDL_Quit();
        return 1;
    }

    SDL_Quit();
    return 0;
}
