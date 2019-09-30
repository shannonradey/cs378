#ifndef PLAYER_H
#define PLAYER_H

#include <Godot.hpp>
#include <KinematicBody.hpp>
#include <Input.hpp>
#include <KinematicCollision.hpp>

namespace godot {

class Player : public KinematicBody {
    GODOT_CLASS(Player, KinematicBody)

private:
    float time_passed;
    Vector3 velocity;
    Input *input;

public:
    static void _register_methods();

    Player();
    ~Player();

    void _init(); // our initializer called by Godot

    void _fixed_process(float delta);
    void _input(Variant input);

    void move();
};

}

#endif