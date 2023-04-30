#pragma once
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

static inline ALLEGRO_DISPLAY* display;
static inline ALLEGRO_KEYBOARD_STATE key_state;
static inline ALLEGRO_EVENT_QUEUE* event_queue;
static inline ALLEGRO_TIMER* timer;
static inline ALLEGRO_TRANSFORM camera_transform;
static inline ALLEGRO_STATE previous_state;

static inline ALLEGRO_KEYBOARD_STATE keys;
static inline ALLEGRO_COLOR white = { 255.f, 255.f, 255.f, 0.f };
static inline ALLEGRO_COLOR blue = { 0.f,0.f,255.f,0.f };
static inline ALLEGRO_COLOR green = { 0.f,255.f,0.f,0.f };
static inline ALLEGRO_COLOR red = { 255.f,0.f,0.f,0.f };

static inline void m_setup() {
	al_init();
	al_install_keyboard();
	al_init_primitives_addon();
	al_init_image_addon();

	//set up game screen, event queue, and timer
	display = al_create_display(1000, 1000);
	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / 1000.0);
	//register stuff
	al_start_timer(timer);
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_store_state(&previous_state, ALLEGRO_STATE_TRANSFORM);
}
