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
    velocity = Vector3(1, 0, 1);
    input = Input::get_singleton();
}

void Player::_input(Variant input) {
    // event = (InputEvent) input;
}

void Player::_fixed_process(float delta) {

    if (input->is_action_pressed("ui_right")) {
        velocity.x += 1;
    } else if (input->is_action_pressed("ui_left")) {
        velocity.x -= 1;
    } else if (input->is_action_pressed("ui_up")) {
        velocity.z += 1;
    } else if (input->is_action_pressed("ui_down")) {
        velocity.z -= 1;
    }
	velocity = move_and_slide(velocity);
}

void Player::move() {

}