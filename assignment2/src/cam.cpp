#include "cam.h"

using namespace godot;

void Cam::_register_methods() {
    register_method("_process", &Cam::_process);
}

Cam::Cam() {

}

Cam::~Cam() {
    // add your cleanup here
}

void Cam::_init() {
    // initialize any variables here
}



void Cam::_process(float delta) {
    //Godot::print(get_camera_transform());
 
}
