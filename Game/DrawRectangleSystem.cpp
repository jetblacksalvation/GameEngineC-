#include "DrawRectangleSystem.h"
 void DrawRectangleSystem::Process(double x) {
    for (auto it : SceneTree::GetGameObjects({ "PositionComponent" , "RectangleComponent" })) {

       

        auto& xpos = ((PositionComponent*)(*it)["PositionComponent"])->x;
        auto& ypos = ((PositionComponent*)(*it)["PositionComponent"])->y;

        auto& width = ((RectangleComponent*)(*it)["RectangleComponent"])->width;
        auto& height = ((RectangleComponent*)(*it)["RectangleComponent"])->hieght;

        auto& fill_color = ((RectangleComponent*)(*it)["RectangleComponent"])->fill_color;
        auto& outline_color = ((RectangleComponent*)(*it)["RectangleComponent"])->outline_color;

        //std::cout << xpos << " : xpos\n";
        //std::cout << ypos << " : ypos\n";
        al_draw_rectangle(xpos, ypos, xpos + width, ypos + height, outline_color, 1);
        //memory will continue to increase for a little than eventually platou 

    }

}