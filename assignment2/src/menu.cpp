#include "menu.h"
#include <SceneTree.hpp>
#include <ResourceLoader.hpp>
#include <Engine.hpp>
#include <ClassDB.hpp>
#include <ProjectSettings.hpp>

using namespace godot;

void Menu::_register_methods()
{
    register_method("_init", &Menu::_init, GODOT_METHOD_RPC_MODE_DISABLED);
    register_method("_on_TextField_text_changed", &Menu::_on_TextField_text_changed, GODOT_METHOD_RPC_MODE_DISABLED);
    register_method("_load_game", &Menu::_load_game, GODOT_METHOD_RPC_MODE_DISABLED);
    register_method("_on_CreateButton_pressed", &Menu::_on_CreateButton_pressed, GODOT_METHOD_RPC_MODE_DISABLED);
    register_method("_on_JoinButton_pressed", &Menu::_on_JoinButton_pressed, GODOT_METHOD_RPC_MODE_DISABLED);

    register_property<Menu, String>("playerName", &Menu::playerName, "", GODOT_METHOD_RPC_MODE_DISABLED);
}

Menu::Menu(){};
Menu::~Menu(){};

void Menu::_init()
{
    playerName = "";
}

void Menu::_on_TextField_text_changed(String newText)
{
    playerName = newText;
}

void Menu::_on_CreateButton_pressed()
{
    if(playerName == "")
    {
        return;
    }

    get_node("/root/Network")->call("create_server", playerName);
    _load_game();
}

void Menu::_on_JoinButton_pressed()
{
    if(playerName == "")
    {
        return;
    }

    get_node("/root/Network")->call("connect_to_server", playerName);
    _load_game();
}

void Menu::_load_game()
{
    get_tree()->change_scene("res://main.tscn");
}

// using namespace godot;

// void Menu::_register_methods() {
//     register_method("_ready", &Menu::_ready);
//     register_method("_process", &Menu::_process);

//     //register_signal<Menu>((char*)"dead");
// }

// Menu::Menu() {
// }

// Menu::~Menu() {
// }

// void Menu::_ready() {    
//    // Node* node = get_node("/root/Spatial/Control2/NinePatchRect/Label2");
//     //this->connect("dead", node, "final");
// }

// void Menu::_init() {
//     set_visible(true);
//     //t = time(NULL);
   
// }

// void Menu::_process(float delta) {

//     /*Node* node = get_node("/root/Spatial/Control4/TextureButton");
//     if (node != NULL){
//         BaseButton * button = node->cast_to<BaseButton>;
//     }*/
//     //Godot::print(node->is_pressed());
//    /* if (node->_pressed()){
//         //emit_signal("pressed");
//         set_visible(false);
//     }*/

   
    
// }
