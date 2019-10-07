#include "healthbar.h"

using namespace godot;

void Healthbar::_register_methods() {
    register_method("_ready", &Healthbar::_ready);
    register_method("_decrement", &Healthbar::_decrement);
    register_signal<Healthbar>((char*)"dead");
    register_signal<Healthbar>((char*)"light_hit");
}

Healthbar::Healthbar() {
}

Healthbar::~Healthbar() {
}

void Healthbar::_ready() {    
	set_value(100);
	Node *node = get_parent()->get_child(2);
	this->connect("dead", node, "_candy");
	node = get_parent()->get_child(3);
	this->connect("light_hit", node, "_candy");

}

void Healthbar::_init() {
}

void Healthbar::_decrement() {
    set_value(get_value() - 25);
    if (get_value() == 0) {
    	emit_signal("dead");
    } else {
    	emit_signal("light_hit");
    }	
}