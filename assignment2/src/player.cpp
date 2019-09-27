#include "player.h"

using namespace godot;

void Player::_register_methods() {
    register_method("_physics_process", &Player::_physics_process);
    register_method("_process", &Player::_process);
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
    input = InputEvent();
    velocity = Vector3(1, 0, 1);
}

void Player::_process(float delta) {
	// translate(velocity);
}

void Player::_physics_process(float delta) {

	if (input.is_action_pressed("ui_right")) {
        velocity.x += 1;
    }
	velocity = move_and_slide(velocity);

}

void Player::move() {

}