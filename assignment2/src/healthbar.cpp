#include "healthbar.h"

using namespace godot;

void Healthbar::_register_methods() {
    register_method("_ready", &Healthbar::_ready);
    register_method("_decrement", &Healthbar::_decrement);
    // register_method("get_count", &Healthbar::get_count);
}

Healthbar::Healthbar() {

}

Healthbar::~Healthbar() {
    // add your cleanup here
}

void Healthbar::_ready() {    
	set_value(100);
	// set_fill_mode(99);
	// set_percent_visible(100);
	// get_node(get_path())->set_value(100);
	// set_stretch_margin(2, 2);
	// get_value();
	// Godot::print(get_fill_degrees());
	// set_fill_degrees(100);
	// Godot::print(get_path());
}

void Healthbar::_init() {
    // candy_count = -2;
    // set_text(String::num_int64(candy_count));
}

void Healthbar::_decrement() {
    set_value(get_value() - 25);
}

// int Healthbar::get_count() {
//     return candy_count;
// }
