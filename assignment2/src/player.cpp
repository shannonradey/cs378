#include "player.h"

using namespace godot;

void Player::_register_methods() {
    register_method("_physics_process", &Player::_fixed_process);
    register_method("_hang", &Player::_hang);
    register_method("_ready", &Player::_ready);
    register_signal<Player>((char*)"dead");
}

Player::Player() {

}

Player::~Player() {
}

void Player::_init() {
    gravity = 9.8;
    time_passed = 0.0;
    velocity = Vector3(0, 0, 0);
    input = Input::get_singleton();
    x = 0;
    is_hanging = false;
    edge = "";
    t = time(NULL);
}

void Player::_ready() {
    Node *node = get_node("/root/Spatial/Control2/NinePatchRect/Label2");
    this->connect("dead", node, "final");
    node = get_node("/root/Spatial/GUI/HBoxContainer/Counters/Counter/Background/Number");
    this->connect("dead", node, "stop");
}

void Player::_fixed_process(float delta) {
    velocity = Vector3(0, 0, 0);
    Vector3 cur;
    Vector3 floor_normal = Vector3(0, 1, 0);


    if (is_hanging == true) {
        Vector3 rotation = get_rotation();
        gravity = 0.0;
        if ((edge == "Ledge") || (edge == "Ledge1A")) {
            set_rotation(Vector3(0, rotation.y,-0.2));
            if (input->is_action_pressed("k_up")) {
                velocity.z -= 2;
                set_rotation(Vector3(0,rotation.y,0));
                gravity = 9.8;
                is_hanging = false;    
            }
            if (input->is_action_pressed("l_down")) {
                set_rotation(Vector3(0,0,0));
                velocity.z += 2;
                gravity =9.8;
                is_hanging = false;
                emit_signal("dead");
            }
        }
        if (edge == "Ledge2") {
            set_rotation(Vector3(0.2, 0,0));
            if (input->is_action_pressed("k_up")) {
                velocity.x -= 2;
                set_rotation(Vector3(0,rotation.y,0));
                gravity = 9.8;
                is_hanging = false;
            }
            if (input->is_action_pressed("l_down")) {
                set_rotation(Vector3(0,rotation.y,0));
                velocity.x += 4;
                gravity =9.8;
                is_hanging = false;
                emit_signal("dead");
            }
        }
        if (edge == "Ledge3") {
            set_rotation(Vector3(0, 0,0.2));
            if (input->is_action_pressed("k_up")) {
                velocity.z += 2;
                set_rotation(Vector3(0,rotation.y,0));
                gravity = 9.8;
                is_hanging = false;
            }
            if (input->is_action_pressed("l_down")){
                set_rotation(Vector3(0,rotation.y,0));
                velocity.z -= 4;
                gravity =9.8;
                is_hanging = false;
                emit_signal("dead");
            }
        }
         if (edge == "Ledge4"){
            set_rotation(Vector3(-0.2, 0,0));
            if (input->is_action_pressed("k_up")) {
                velocity.x += 2;
                set_rotation(Vector3(0,rotation.y,0));
                gravity = 9.8;
                is_hanging = false;    
            }
            if (input->is_action_pressed("l_down")) {
                set_rotation(Vector3(0,rotation.y,0));
                velocity.x -= 4;
                gravity =9.8;
                is_hanging = false;
                emit_signal("dead");
            }
        }
        move_and_collide(velocity);

    }
    else {
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
        if (input->is_action_just_pressed("ui_accept")) {
            velocity.y += 2;
            t = time(NULL);
        }
        if (input->is_key_pressed(39))
            velocity.y += .7;
        velocity.y -= gravity * delta;
    	move_and_collide(velocity);
    }
}
   

void Player::_hang(String led) {
    is_hanging = true;
    edge = led;

}
