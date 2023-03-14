#pragma once
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define Windows "Windows"
#define Mac "Mac OS X"
#define Linux "Linux"
#define IOS "IOS"
#define Android "Android"

namespace NAQH{ namespace Utils
{
    inline float hireTimeInSecond()
    {
        float time = SDL_GetTicks();
        time *= 0.001f;

        return time;
    }

    inline void Delay(Uint32 p_time)
    {
        SDL_Delay(p_time);
    }

    inline const char* ProgramPath()
    {
        return SDL_GetBasePath();
    }

    inline const char* PreferencsePath(const char* p_org, const char* p_app)
    {
        return SDL_GetPrefPath(p_org, p_app);
    }

    inline void GetBatteryPower(int* p_percent)
    {
        SDL_GetPowerInfo(NULL, p_percent);
    }

    inline void GetBatteryLife(int* p_lifeLeft)
    {
        SDL_GetPowerInfo(p_lifeLeft, NULL);
    }

    inline void GetBatteryData(int* p_lifeLeft, int* p_percent)
    {
        SDL_GetPowerInfo(p_lifeLeft, p_percent);
    }

    inline bool OnBattery()
    {    
        return (SDL_GetPowerInfo(NULL, NULL) == SDL_POWERSTATE_ON_BATTERY);
    }

    inline bool OnPlug()
    {
        return (SDL_GetPowerInfo(NULL, NULL) == SDL_POWERSTATE_NO_BATTERY);
    }

    inline bool Charging()
    {
        return (SDL_GetPowerInfo(NULL, NULL) == SDL_POWERSTATE_CHARGING);
    }

    inline bool Charged()
    {
        return (SDL_GetPowerInfo(NULL, NULL) == SDL_POWERSTATE_CHARGED);
    }

    inline bool UnknownPowerSource()
    {
        return (SDL_GetPowerInfo(NULL, NULL) == SDL_POWERSTATE_UNKNOWN);
    }

    inline const char* GetPlatform()
    {
        return SDL_GetPlatform();
    }

    inline const char* GetClipboard()
    {
        return SDL_GetClipboardText();
    }

    inline void SetClipboard(const char* p_text)
    {
        SDL_SetClipboardText(p_text);
    }

    inline bool HasClipboard()
    {
        return SDL_HasClipboardText();
    }

    inline int GetCPUCores()
    {
        return SDL_GetCPUCount();
    }

    inline int GetRAM()
    {
        return SDL_GetSystemRAM();
    }

    inline char* ExecuteCommand(char* p_command)
    {
        const char* tmp = " >> res/tmp";
        char* command;

        for(unsigned int i = 0; i < sizeof(p_command); ++i)
            command[i] = p_command[i];

        system(strncat(command, tmp, 11));
        FILE* file = fopen("res/tmp", "rb");
        fseek(file, 0, SEEK_END);
        unsigned long fileSize = ftell(file);
        fseek(file, 0, SEEK_SET);
        char* buffer;

        if (file == NULL)
        {
            fclose(file);
            printf("ERROR: CAN'T OPEN FILE: %s", tmp);
        }

        buffer = (char*)malloc(fileSize);

        if (!buffer)
        {
            fclose(file);
            printf("ERROR: NO'T ENOUGH MEMORY: %s", tmp); 
        }

        fread(buffer, fileSize, 1, file);

        fclose(file);

        if (remove("res/tmp") != 0)
        {
            printf("ERROR: Cant Delete File: %s", tmp);
        }

        return buffer;
    }

    enum WriteMode { Write, Append };

    inline char* ReadFile(const char* p_path)
    {
        FILE* file = fopen(p_path, "rb");

        if(file == NULL)
        {
            fclose(file);
            printf("ERROR: CAN'T OPEN FILE: %s\n", p_path);
        }

        fseek(file, 0, SEEK_END);
        unsigned int fileSize = ftell(file);
        fseek(file, 0, SEEK_SET);
        char* buffer = (char*)malloc(sizeof(char)*(fileSize+1));

        if(!buffer)
        {
            fclose(file);
            printf("ERROR: NO'T ENOUGH MEMORY: %s\n", p_path);
        }

        fread(buffer, 1, fileSize, file);
        buffer[fileSize] = '\0';
        fclose(file);
        return buffer;
    }

    inline int WriteFile(const char* p_path, char* p_text, WriteMode p_mode)
    {
        FILE* file;

        if(p_mode == Write)
            file = fopen(p_path, "wb");
        else if(p_mode == Append)
            file = fopen(p_path, "ab");
        

        if(file == NULL)
        {
            fclose(file);
            printf("ERROR: CAN'T OPEN FILE: %s\n", p_path);
            return -1;
        }

        if(p_text == NULL)
        {
            fclose(file);
            printf("ERROR: Text Is NULL: %s, %s\n", p_path, p_text);
            return -1;
        }

        fprintf(file, "%s", p_text);
        fclose(file);
    }
}}