#ifndef MENU_H
#define MENU_H

#include <Godot.hpp>
#include <Control.hpp>
#include <BaseButton.hpp>
//#include <ctime>

namespace godot {

class Menu : public Control {
    GODOT_CLASS(Menu, Control)

private:
   // time_t t;

public:
    static void _register_methods();

    Menu();
    ~Menu();

    void _init();

    void _ready();
    void _process(float delta);



};

}

#endif