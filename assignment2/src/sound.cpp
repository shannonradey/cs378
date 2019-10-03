#include "sound.h"

using namespace godot;

void Sound::_register_methods() {
    register_method("_ready", &Sound::_ready);
    register_method("_candy", &Sound::_candy);
}

Sound::Sound() {

}

Sound::~Sound() {
    // add your cleanup here
}

void Sound::_ready() {    
	// Godot::print("Sound" + get_path());
}

void Sound::_init() {
    
}

void Sound::_candy() {
	Godot::print("CANDY");
	play();
}