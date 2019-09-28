#include "player.h"

using namespace godot;

void Player::_register_methods() {
    register_method("_physics_process", &Player::_fixed_process);
    register_method("_input", &Player::_input);
    register_method("move", &Player::move);
}

Player::Player() {

}

Player::~Player() {
    // add your cleanup here
}

void Player::_init() {
    // initialize any variables here
    time_passed = 0.0;
    velocity = Vector3(0, 0, 0);
    input = Input::get_singleton();
}

void Player::_input(Variant input) {
    // event = (InputEvent) input;
}

void Player::_fixed_process(float delta) {
    velocity = Vector3();
    if (input->is_action_pressed("ui_down")) {
        velocity.x += 0.1;
    } if (input->is_action_pressed("ui_up")) {
        velocity.x -= 0.1;
    } if (input->is_action_pressed("ui_left")) {
        velocity.z += 0.1;
    } if (input->is_action_pressed("ui_right")) {
        velocity.z -= 0.1;
    } 
	KinematicCollision *collision = *move_and_collide(velocity);
}

void Player::move() {

}