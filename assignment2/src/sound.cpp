#include "sound.h"

using namespace godot;

void Sound::_register_methods() {
    register_method("_ready", &Sound::_ready);
    register_method("_candy", &Sound::_candy);
}

Sound::Sound() {

}

Sound::~Sound() {
}

void Sound::_ready() {    
	
}

void Sound::_init() {
    
}

void Sound::_candy() {
	play();
}