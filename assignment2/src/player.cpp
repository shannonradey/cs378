#include "player.h"

using namespace godot;

void Player::_register_methods() {
    register_method("_physics_process", &Player::_fixed_process);
    register_method("_hang", &Player::_hang);
}

Player::Player() {

}

Player::~Player() {
    // add your cleanup here
}

void Player::_init() {
    // initialize any variables here
    gravity = 9.8;
    time_passed = 0.0;
    velocity = Vector3(0, 0, 0);
    input = Input::get_singleton();
    x = 0;
    is_hanging = false;
    edge = "";
}



void Player::_fixed_process(float delta) {
    velocity = Vector3(0, 0, 0);
    Vector3 cur;
    Vector3 floor_normal = Vector3(0, 1, 0);


    if (is_hanging == true){
        gravity = 0.0;
        if (edge == "Ledge"){
            set_rotation(Vector3(0, 0,-0.2));
            if (input->is_action_pressed("k_up")){
                    velocity.z -= 2;
                    set_rotation(Vector3(0,0,0));
                    gravity = 9.8;
                    is_hanging = false;
                
                }
            if (input->is_action_pressed("l_down")){
                set_rotation(Vector3(0,0,0));
                velocity.z += 4;
                gravity =9.8;
                is_hanging = false;
                }
        }
        if (edge == "Ledge2"){
            set_rotation(Vector3(0.2, 0,0));
            if (input->is_action_pressed("k_up")){
                    velocity.x -= 2;
                    set_rotation(Vector3(0,0,0));
                    gravity = 9.8;
                    is_hanging = false;
                
                }
            if (input->is_action_pressed("l_down")){
                set_rotation(Vector3(0,0,0));
                velocity.x += 4;
                gravity =9.8;
                is_hanging = false;
                }
        }
        if (edge == "Ledge3"){
            set_rotation(Vector3(0, 0,0.2));
            if (input->is_action_pressed("k_up")){
                    velocity.z += 2;
                    set_rotation(Vector3(0,0,0));
                    gravity = 9.8;
                    is_hanging = false;
                
                }
            if (input->is_action_pressed("l_down")){
                set_rotation(Vector3(0,0,0));
                velocity.z -= 4;
                gravity =9.8;
                is_hanging = false;
                }
        }
         if (edge == "Ledge4"){
            set_rotation(Vector3(-0.2, 0,0));
            if (input->is_action_pressed("k_up")){
                    velocity.x += 2;
                    set_rotation(Vector3(0,0,0));
                    gravity = 9.8;
                    is_hanging = false;
                
                }
            if (input->is_action_pressed("l_down")){
                set_rotation(Vector3(0,0,0));
                velocity.x -= 4;
                gravity =9.8;
                is_hanging = false;
                }
        }

    }
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
        rotate_y(0.01);
    }
    if (input->is_action_pressed("ui_right")) {
        rotate_y(-0.01);
    } 
    
    if (input->is_action_just_pressed("ui_accept")) {
        velocity.y += 1;
    }
    velocity.y -= gravity * delta;
	move_and_collide(velocity);

   //Godot::print(get_translation());

}
   

void Player::_hang(String led) {
    is_hanging = true;
    edge = led;

}
