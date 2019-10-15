#include "menu.h"

using namespace godot;

void Menu::_register_methods() {
    register_method("_ready", &Menu::_ready);
    register_method("_process", &Menu::_process);

    //register_signal<Menu>((char*)"dead");
}

Menu::Menu() {
}

Menu::~Menu() {
}

void Menu::_ready() {    
   // Node* node = get_node("/root/Spatial/Control2/NinePatchRect/Label2");
    //this->connect("dead", node, "final");
}

void Menu::_init() {
    set_visible(true);
    //t = time(NULL);
   
}

void Menu::_process(float delta) {

    /*Node* node = get_node("/root/Spatial/Control4/TextureButton");
    if (node != NULL){
        BaseButton * button = node->cast_to<BaseButton>;
    }*/
    //Godot::print(node->is_pressed());
   /* if (node->_pressed()){
        //emit_signal("pressed");
        set_visible(false);
    }*/

   
    
}



