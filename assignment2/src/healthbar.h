#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include <Godot.hpp>
#include <TextureProgress.hpp>
#include <Range.hpp>

namespace godot {

class Healthbar : public TextureProgress {
    GODOT_CLASS(Healthbar, TextureProgress)

private:
    time_t time_hit;


public:
    static void _register_methods();

    Healthbar();
    ~Healthbar();

    void _ready();

    void _init(); // our initializer called by Godot

    void _decrement();

    // void _process(float delta);

    // void _on_body_entered(int body_id, Node *body, int body_shape, int area_shape);
};

}

#endif