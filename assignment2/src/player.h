#ifndef PLAYER_H
#define PLAYER_H

#include <Godot.hpp>
#include <KinematicBody.hpp>
#include <InputEvent.hpp>

namespace godot {

class Player : public KinematicBody {
    GODOT_CLASS(Player, KinematicBody)

private:
    float time_passed;
    Vector3 velocity;
    InputEvent input;

public:
    static void _register_methods();

    Player();
    ~Player();

    void _init(); // our initializer called by Godot

    void _physics_process(float delta);
    void _process(float delta);

    void move();
};

}

#endif