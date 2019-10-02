#include "candy.h"

using namespace godot;

void Candy::_register_methods() {
    register_method("_process", &Candy::_process);
    register_method("_ready", &Candy::_ready);
    register_method("_on_body_entered", &Candy::_on_body_entered);
    register_signal<Candy>((char*)"candy_hit");

}

Candy::Candy() {

}

Candy::~Candy() {
    // add your cleanup here
}

void Candy::_ready() {
    Godot::print("Ready");
    this->connect("body_shape_entered", this, "_on_body_entered");
}

void Candy::_on_body_entered(int body_id, Node *body, int body_shape, int area_shape) {
    Godot::print("ON BODY body_entered");
    emit_signal("candy_hit");
}


void Candy::_init() {
}

void Candy::_process(float delta) {
    rotate_y(.1);
}
