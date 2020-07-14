#ifndef CLICKERLOGIC_H_
#define CLICKERLOGIC_H_

#include <iostream>
#include "strmanip.h"
#include <windows.h>
#include <map>

class ClickerLogic
{
    public:
        //Initializing the config file path
        std::string CONFIG_PATH = "config.cfg";

        //Initializing the global variables
        std::string lastFocusedWindow = "";
        char title[256];
        bool only_once = true;
        static const int max_size = 10000;
        const int mouse_accuracy = 1000000;
        const int mouse_record_delay = 5;
        int mouse_mod_size = 0;
        POINT mouse_mod[max_size];
        POINT mouse_load[max_size];
        POINT mouse_smooth[max_size];
        int mouse_event_load_left[max_size];
        int mouse_event_load_right[max_size];
        int mouse_event_left[max_size];
        int mouse_event_right[max_size];
        BYTE latest_key = NULL;
        HWND hwnd = NULL;
        RECT rect;
        POINT point;
        DWORD dwPID = 0;
        DWORD hThread;
        int width;
        int height;
        int mouse_i = 0;
        int mouse_set_i = 0;
        int mouse_pos_i = 0;
        int g_mouse_poz = 0;

        std::map<std::string, std::string> mouse_commands_map;
        std::map<std::string, std::string> keyboard_commands_map; 
        std::map<std::string, char> map_mouse = 
            {
                { "mouse_absolute", MOUSEEVENTF_ABSOLUTE },
                { "mouse_left_down",  MOUSEEVENTF_LEFTDOWN },
                { "mouse_right_down", MOUSEEVENTF_RIGHTDOWN },
                { "mouse_left_up", MOUSEEVENTF_LEFTUP },
                { "mouse_right_up", MOUSEEVENTF_RIGHTUP }
            };

        //The base functions
        void read_configs();
        void app();
        int check_for_next_bookmark(int i);
        void refocus();
        void save_preset_recording();
        void smoothing(std::string mode);
        void app_preset_load();
        void app_preset_unload();
        void app_preset_play();
        void app_preset_record();
        void getCurrentWindowHandler();
        void getWindow(int index);
        void checkForWindowInStore();
        void change_mouse_pos(std::string mode);
        void close_app();

        //The game script functions
        void clicker();
};

#endif