#ifndef PLAYER_H
#define PLAYER_H

#include <Godot.hpp>
#include <KinematicBody.hpp>
#include <Input.hpp>
#include <KinematicCollision.hpp>
#include <cmath>
#include <Transform.hpp>
#include <candycounter.h>

namespace godot {

class Player : public KinematicBody {
    GODOT_CLASS(Player, KinematicBody)

private:
    float time_passed;
    Vector3 velocity;
    Input *input;
    int x;

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