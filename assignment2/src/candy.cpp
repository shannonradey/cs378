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
    this->connect("body_shape_entered", this, "_on_body_entered");
    Node *node = get_node("/root/Spatial/GUI/HBoxContainer/Counters/Counter/Background/Number");
    this->connect("candy_hit", node, "_increment");
}


void Candy::_on_body_entered(int body_id, Node *body, int body_shape, int area_shape) {
    if (is_visible()) {
        emit_signal("candy_hit");
        set_visible(false);
        time_hit = time(NULL);
    }
}


void Candy::_init() {
}

void Candy::_process(float delta) {
    rotate_y(.1);
    if (!is_visible()) {
        if (time(NULL) - 10 > time_hit) {
            set_visible(true);
        }

    }
}
