#pragma once 
#include <Godot.hpp>
#include <Control.hpp>
#include <Node2D.hpp>
#include <TextEdit.hpp>

namespace godot{
    class Menu : public Control{
        GODOT_CLASS(Menu, Control)


        private:
            String playerName;
            
        public:
            static void _register_methods();
            Menu();
            ~Menu();

            void _init();
            void _on_TextField_text_changed(String newText);
            void _on_CreateButton_pressed();
            void _on_JoinButton_pressed();
            void _load_game();
            void _ready();
            void create();
            void join();
            void text_changed();
            void _process(float delta);
    };
}
