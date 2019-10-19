#ifndef PLAYER_H
#define PLAYER_H

#include <Godot.hpp>
#include <KinematicBody.hpp>
#include <Input.hpp>
#include <KinematicCollision.hpp>
#include <cmath>
#include <Transform.hpp>
#include <candycounter.h>
#include <Area.hpp>
#include <candy.h>
#include <ctime>

namespace godot {

        class Player : public KinematicBody {
            GODOT_CLASS(Player, KinematicBody)

        private:
            float time_passed;
            Vector3 velocity;
            Input *input;
            int x;
            float gravity;
            int speed;
            bool is_hanging;
            String edge;
            time_t t;
            bool alive;
            //int jumps;
            //int MAX_JUMPS;



        public:
            static void _register_methods();

            Player();
            ~Player();

            void _init();
            void player_on_body_entered(int body_id, Node* body, int body_shape, int area_shape);

            void _fixed_process(float delta);

            void _hang(String led);
            void _ready();
            void init(String nickname, Vector3 startPosition, bool isSlave);
            void _die();
        };

}
#endif