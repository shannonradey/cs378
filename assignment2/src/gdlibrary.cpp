#include "player.h"
#include "candy.h"
#include "candycounter.h"
#include "sound.h"
#include "attacklight.h"
#include "healthbar.h"
#include "mybutton.h"

extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options *o) {
    godot::Godot::gdnative_init(o);
}

extern "C" void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options *o) {
    godot::Godot::gdnative_terminate(o);
}

extern "C" void GDN_EXPORT godot_nativescript_init(void *handle) {
    godot::Godot::nativescript_init(handle);
    godot::register_class<godot::Player>();
    godot::register_class<godot::Candy>();
    godot::register_class<godot::CandyCounter>();
    godot::register_class<godot::Sound>();
    godot::register_class<godot::AttackLight>();
    godot::register_class<godot::Healthbar>();
    godot::register_class<godot::MyButton>();
}
