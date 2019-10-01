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
    x = 0;
    gravity = -9.8;
}

void Player::_input(Variant input) {

}

void Player::_fixed_process(float delta) {
    velocity = Vector3(0, 0, 0);

    if (input->is_action_pressed("ui_down")) {
        velocity += get_global_transform().basis.z.rotated(Vector3(0, 1, 0), -M_PI/2); 
    } 
    if (input->is_action_pressed("ui_up")) {
        velocity += get_global_transform().basis.z.rotated(Vector3(0, 1, 0), M_PI/2);
    } 
    if (input->is_action_pressed("ui_left")) {
        rotate_y(0.01);
    } 
    if (input->is_action_pressed("ui_right")) {
        rotate_y(-0.01);
    }
    if (input->is_key_pressed(39)) {
        velocity.y = 1;
    }
    velocity.y += gravity * delta;
	KinematicCollision *collision = *move_and_collide(velocity);
    // if (collision != NULL)
    //     Godot::print(collision->get_normal());
}

void Player::move() {

}