#include "menu.h"
#include <SceneTree.hpp>
#include <ResourceLoader.hpp>
#include <Engine.hpp>
#include <ClassDB.hpp>
#include <ProjectSettings.hpp>

using namespace godot;

void Menu::_register_methods(){
    register_method("_init", &Menu::_init, GODOT_METHOD_RPC_MODE_DISABLED);
    register_method("_on_TextField_text_changed", &Menu::_on_TextField_text_changed, GODOT_METHOD_RPC_MODE_DISABLED);
    register_method("_load_game", &Menu::_load_game, GODOT_METHOD_RPC_MODE_DISABLED);
    register_method("_on_CreateButton_pressed", &Menu::_on_CreateButton_pressed, GODOT_METHOD_RPC_MODE_DISABLED);
    register_method("_on_JoinButton_pressed", &Menu::_on_JoinButton_pressed, GODOT_METHOD_RPC_MODE_DISABLED);
    register_method("_ready", &Menu::_ready);
    // register_method("_process", &Menu::_process);
    register_method("join", &Menu::join);
    register_method("create", &Menu::create);
    register_method("text_changed", &Menu::text_changed);
    register_property<Menu, String>("playerName", &Menu::playerName, "", GODOT_METHOD_RPC_MODE_DISABLED);
    register_signal<Menu>((char*)"dead");
}

Menu::Menu(){};
Menu::~Menu(){};

void Menu::_init()
{
    set_visible(true);
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
    // get_node("/root/Network")->call("create_server", playerName);
    // _load_game();
    this->create();
}

void Menu::text_changed() {
     playerName = get_child(3)->call("get_text");
    // Godot::print(playerName);
}

void Menu::_on_JoinButton_pressed()
{
    if(playerName == "")
    {
        return;
    }
    // get_node("/root/Network")->call("connect_to_server", playerName);
    // _load_game();
    this->join();
}

void Menu::_ready() {    
    playerName = "";
    get_child(4)->connect("pressed", this, "create");
    get_child(5)->connect("pressed", this, "join");
    get_child(3)->connect("text_changed", this, "text_changed");
    Node* node = get_node("/root/Spatial/Control2/NinePatchRect/Label2");
    this->connect("dead", node, "final");
}

void Menu::_load_game()
{
    get_tree()->change_scene("res://main.tscn");
}

void Menu::join() {
    Godot::print("JOIN");
    get_node("/root/Spatial/Network")->call("connect_to_server", playerName);
    _load_game();
}

void Menu::create() {
    Godot::print("CREATE");
    get_node("/root/Spatial/Network")->call("create_server", playerName);
    _load_game();
}


