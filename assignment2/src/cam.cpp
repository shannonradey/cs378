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

    input = Input::get_singleton();
}



void Cam::_process(float delta) {
	if (input->is_action_pressed("ui_page_up")) {
		// Spatial * parent = get_parent_spatial();
		// Vector3 pos = get_translation(parent);
		// pos.x = 0;
		// pos.z =0 ;
		// rotate_object_local(pos, .002);
	}
 
}
