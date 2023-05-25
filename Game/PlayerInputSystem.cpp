#include "PlayerInputSystem.h"
void PlayerInputSystem::Process(double x) {

	for (auto player_input : SceneTree::GetGameObjects({ PlayerInputComponent::name , PositionComponent::name})) {
		ALLEGRO_EVENT ev;
        auto& xpos = ((PositionComponent*)(*player_input)["PositionComponent"])->x;
        auto& ypos = ((PositionComponent*)(*player_input)["PositionComponent"])->y;

		al_wait_for_event(event_queue, &ev);

		al_get_keyboard_state(&keys);


        if (al_key_down(&keys, ALLEGRO_KEY_A)) {
            xpos -= 1;

        }
        if (al_key_down(&keys, ALLEGRO_KEY_D)) {
            xpos += 1;

        }
        if (al_key_down(&keys, ALLEGRO_KEY_W)) {
            ypos -= 1;
        }
        if (al_key_down(&keys, ALLEGRO_KEY_S)) {
            ypos += 1;
        }
        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            std::cout << "you closed the window\n";
            exit(0);
        }
	}

};