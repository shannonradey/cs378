#include "sound.h"

using namespace godot;

void Sound::_register_methods() {
    register_method("_ready", &Sound::_ready);
    register_method("_candy", &Sound::_candy);
    register_method("_mute", &Sound::_mute);

    register_signal<Sound>((char *)"mute");
}

Sound::Sound() {

}

Sound::~Sound() {
}

void Sound::_ready() {    
    Node *node = get_node("/root/Spatial/Control/Button2");
	node->connect("mute", this, "_mute");
	is_muted = false;
}

void Sound::_init() {
    
}

void Sound::_candy() {
	if (!is_muted)
		play();
}

void Sound::_mute() {
	is_muted = !is_muted;
	if (is_muted)
		stop();
	else {
		if (get_path() == "/root/Spatial/Node2D/AudioStreamPlayer")
			play();
	}
}