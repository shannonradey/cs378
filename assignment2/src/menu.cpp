#include "menu.h"

using namespace godot;

void Menu::_register_methods() {
    register_method("_ready", &Menu::_ready);
    register_method("_process", &Menu::_process);
    register_method("join", &Menu::join);
    register_method("create", &Menu::create);
    register_method("text_changed", &Menu::text_changed);
}

Menu::Menu() {
}

Menu::~Menu() {
}

void Menu::_ready() {    
    name = "";
    get_child(4)->connect("pressed", this, "create");
    get_child(5)->connect("pressed", this, "join");
    get_child(3)->connect("text_changed", this, "text_changed");
}

void Menu::_init() {
    set_visible(true);
}

void Menu::_process(float delta) {

}


void Menu::text_changed() {
    name = get_child(3)->call("get_text");
    Godot::print(name);

}

void Menu::join() {
    Godot::print("JOIN");


}

void Menu::create() {
    Godot::print("CRWATE");



}



