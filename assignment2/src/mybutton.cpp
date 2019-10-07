#include "mybutton.h"

using namespace godot;

void MyButton::_register_methods() {
    register_method("_ready", &MyButton::_ready);
    register_method("mute", &MyButton::mute);
    
	register_signal<MyButton>((char*) "mute");

}

MyButton::MyButton() {

}

MyButton::~MyButton() {
}



void MyButton::_ready() {
    this->connect("pressed", this, "mute");

}

void MyButton::_init() {
}

void MyButton::mute() {
	emit_signal("mute");
    release_focus();
}