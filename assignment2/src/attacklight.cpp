#include "attacklight.h"

using namespace godot;

void AttackLight::_register_methods() {
    register_method("_process", &AttackLight::_process);
    register_method("_ready", &AttackLight::_ready);
    register_method("_on_body_entered", &AttackLight::_on_body_entered);
    
	register_signal<AttackLight>((char*)"light_hit");

}

AttackLight::AttackLight() {

}

AttackLight::~AttackLight() {
    // add your cleanup here
}

void AttackLight::_ready() {
    this->connect("body_shape_entered", this, "_on_body_entered");
    Node *node = get_node("/root/Spatial/GUI/HBoxContainer/Bars/Bar/Gauge");
    this->connect("light_hit", node, "_decrement");

    node = get_parent()->get_parent()->get_child(1);
    this->connect("light_hit", node, "_candy");
}


void AttackLight::_on_body_entered(int body_id, Node *body, int body_shape, int area_shape) {
    emit_signal("light_hit");
}


void AttackLight::_init() {
}

void AttackLight::_process(float delta) {

}
