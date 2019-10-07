#ifndef CAM_H
#define CAM_H

#include <Godot.hpp>
#include <Input.hpp>
#include <cmath>
#include <Camera.hpp>

namespace godot {

class Cam : public Camera {
    GODOT_CLASS(Cam, Camera)

private:
    //int jumps;
    //int MAX_JUMPS;

public:
    static void _register_methods();

    Cam();
    ~Cam();

    void _init(); // our initializer called by Godot

    void _process(float delta);
    
};

}

#endif