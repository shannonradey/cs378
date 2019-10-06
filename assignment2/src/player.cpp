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
}

void Player::_init() {
    time_passed = 0.0;
    velocity = Vector3(0, 0, 0);
    input = Input::get_singleton();
    x = 0;
    gravity = 9.8;
}

void Player::_input(Variant input) {
}

void Player::_fixed_process(float delta) {
    velocity = Vector3(0, 0, 0);
    Vector3 cur;

    if (input->is_action_pressed("ui_down")) {
        cur = get_global_transform().basis.z; 
        cur.y = 0;
        velocity += cur.rotated(Vector3(0, 1, 0), -M_PI/2).operator*=(8);
    }
    if (input->is_action_pressed("ui_up")) {
        cur = get_global_transform().basis.z;
        cur.y = 0;
        velocity += cur.rotated(Vector3(0, 1, 0), M_PI/2).operator*=(8);
    }
    if (input->is_action_pressed("ui_left")) {
        rotate_y(0.02);
    }
    if (input->is_action_pressed("ui_right")) {
        rotate_y(-0.02);
    } 
    move_and_slide(velocity, Vector3(0, 1, 0));
    if (input->is_action_pressed("ui_accept") && is_on_floor()) {
        velocity.y += 5;
    }
    velocity.y -= gravity * delta;
    move_and_slide(velocity);
	
}

void Player::move() {

}