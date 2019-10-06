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
    t = time(NULL);
}

void Player::_input(Variant input) {
}

void Player::_fixed_process(float delta) {
    velocity = Vector3(0, 0, 0);
    Vector3 cur;

    bool player_can_jump = false;
    if (time(NULL) - 1 > t)
        player_can_jump = true;

    if (input->is_action_pressed("ui_down")) {
        cur = get_global_transform().basis.z; 
        cur.y = 0;
        velocity += cur.rotated(Vector3(0, 1, 0), -M_PI/2);
    }
    if (input->is_action_pressed("ui_up")) {
        cur = get_global_transform().basis.z;
        cur.y = 0;
        velocity += cur.rotated(Vector3(0, 1, 0), M_PI/2);
    }
    if (input->is_action_pressed("ui_left")) {
        rotate_y(0.02);
    }
    if (input->is_action_pressed("ui_right")) {
        rotate_y(-0.02);
    } 
        if (input->is_action_pressed("ui_accept") && player_can_jump) {
        velocity.y += 2;
        t = time(NULL);
    }
    if (input->is_key_pressed(39))
        velocity.y += .7;
    velocity.y -= gravity * delta;
    move_and_collide(velocity);
	
}

void Player::move() {

}