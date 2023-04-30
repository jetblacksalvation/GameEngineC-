#pragma once
#include "ISystem.h"
#include "GameInit.hpp"
#include "PositionComponent.h"
#include "PlayerInputComponent.h"
#include "RectangleComponent.h"
class DrawRectangleSystem :
    public ISystem
{
    virtual void Process(double x) {
        for (auto it : SceneTree::GetGameObjects({ "PlayerInputComponent" , "PositionComponent" , "RectangleComponent"})) {

            ALLEGRO_EVENT ev;
            al_wait_for_event(event_queue, &ev);
            al_get_keyboard_state(&keys);

            auto& xpos = ((PositionComponent*)(*it)["PositionComponent"])->x;
            auto& ypos = ((PositionComponent*)(*it)["PositionComponent"])->y;

            auto& width = ((RectangleComponent*)(*it)["RectangleComponent"])->width;
            auto& height = ((RectangleComponent*)(*it)["RectangleComponent"])->hieght;

            auto& fill_color = ((RectangleComponent*)(*it)["RectangleComponent"])->fill_color;
            auto& outline_color = ((RectangleComponent*)(*it)["RectangleComponent"])->outline_color;

            if (al_key_down(&keys, ALLEGRO_KEY_A)) {
                xpos -= 1;

            }
            if (al_key_down(&keys, ALLEGRO_KEY_D)) {
                xpos += 1;

            }
            if (al_key_down(&keys,ALLEGRO_KEY_W)) {
                ypos -= 1;
            }
            if (al_key_down(&keys, ALLEGRO_KEY_S)) {
                ypos += 1;
            }
            if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
                std::cout << "you closed the window\n";
                exit(0);
            }
            //std::cout << xpos << " : xpos\n";
            //std::cout << ypos << " : ypos\n";
            al_draw_rectangle(xpos, ypos, xpos + width, ypos + height, outline_color, 1);
        }
        
    }
};

