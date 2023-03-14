#include "Input.h"
using namespace NAQH;

namespace NAQH{
    Input::Input()
    {
        SDL_Init(SDL_INIT_GAMECONTROLLER);
        keyboardState = SDL_GetKeyboardState(&keyLength);
        prevKeyboardState = new Uint8[keyLength];
        memcpy(prevKeyboardState, keyboardState, keyLength);
    }

    bool Input::KeyDown(Keys p_scanCode)
    {
        return keyboardState[p_scanCode];
    }

    bool Input::KeyPressed(Keys p_scanCode)
    {
        return !prevKeyboardState[p_scanCode] && keyboardState[p_scanCode];
    }

    bool Input::KeyReleased(Keys p_scanCode)
    {
        return prevKeyboardState[p_scanCode] && !keyboardState[p_scanCode];
    }

    bool Input::MouseButtonDown(MouseButton p_button)
    {
        Uint32 mask;

        switch (p_button)
        {
            case left:
                mask = SDL_BUTTON_LMASK;
                break;
            case right:
                mask = SDL_BUTTON_RMASK;
                break;
            case middle:
                mask = SDL_BUTTON_MMASK;
                break;
            case back:
                mask = SDL_BUTTON_X1MASK;
                break;
            case forward:
                mask = SDL_BUTTON_X2MASK;
                break;
        }

        return (mouseState & mask);
    }

    bool Input::MouseButtonPressed(MouseButton p_button)
    {
        Uint32 mask;

        switch (p_button)
        {
            case left:
                mask = SDL_BUTTON_LMASK;
                break;
            case right:
                mask = SDL_BUTTON_RMASK;
                break;
            case middle:
                mask = SDL_BUTTON_MMASK;
                break;
            case back:
                mask = SDL_BUTTON_X1MASK;
                break;
            case forward:
                mask = SDL_BUTTON_X2MASK;
                break;
        }

        return !(prevMouseState & mask) && (mouseState & mask);
    }

    bool Input::MouseButtonReleased(MouseButton p_button)
    {
        Uint32 mask;

        switch (p_button)
        {
            case left:
                mask = SDL_BUTTON_LMASK;
                break;
            case right:
                mask = SDL_BUTTON_RMASK;
                break;
            case middle:
                mask = SDL_BUTTON_MMASK;
                break;
            case back:
                mask = SDL_BUTTON_X1MASK;
                break;
            case forward:
                mask = SDL_BUTTON_X2MASK;
                break;
        }

        return (prevMouseState & mask) && !(mouseState & mask);
    }

    Vector2 Input::MousePosition()
    {
        return Vector2((float)mouseX, (float)mouseY);
    }

    Vector2 Input::GlobalMousePosition()
    {
        return Vector2((float)globalMouseX, (float)globalMouseY);
    }
        
    int GamePadNumber()
    {
        return SDL_NumJoysticks();
    }

    void Input::Update()
    {
        mouseState = SDL_GetMouseState(&mouseX, &mouseY);
        globalMouseState = SDL_GetGlobalMouseState(&globalMouseX, &globalMouseY);
    }

    void Input::UpdatePrev()
    {
        memcpy(prevKeyboardState, keyboardState, keyLength);
        prevMouseState = mouseState;
        globalPrevMouseState = globalMouseState;
    }
}