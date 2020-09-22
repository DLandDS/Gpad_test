#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

SDL_Joystick *gamepad;
SDL_Event *even;
int joy;


int checkJoyStick(){
    int indexJoysticks, i;
    indexJoysticks = SDL_NumJoysticks();
    printf("%d joysticks found\n", indexJoysticks);
    if (indexJoysticks == 1) {
        printf("%s\n", SDL_JoystickName(SDL_JoystickOpen(0)));
        return 0;
    } else {
        for(i = 0; i < indexJoysticks; i++)
        {
            printf("Select your gamepad");
            printf("%d. %s\n", i+1, SDL_JoystickName(SDL_JoystickOpen(i)));
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
        if ((gamepad = SDL_JoystickOpen(joy = checkJoyStick()))){
            SDL_JoystickEventState(SDL_ENABLE);
            SDL_Log("Connected");

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
