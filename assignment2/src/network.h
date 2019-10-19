#pragma once
#include <Node.hpp>
#include <Godot.hpp>
#include <SceneTree.hpp>
#include <NetworkedMultiplayerENet.hpp>
#include <ResourceLoader.hpp>
#include <player.h>
#include <candycounter.h>
#include <PackedScene.hpp>
#include <candy.h>

namespace godot{
    class Network: public Node{
        GODOT_CLASS(Network, Node)
        
        private:
            Ref<PackedScene> PlayerScene;
            const String SERVER_IP = "127.0.0.1";
            const int64_t SERVER_PORT =31400;
            const int64_t MAX_PLAYER = 3;
            Dictionary selfData;
            Dictionary players;

        public:
            static void _register_methods();
            Network();
            ~Network();

            void _init();
            void _ready();

            void create_server(String playerName);
            void connect_to_server(String playerName);
            void _connected_to_server();
            void _onplayer_disconnected(int64_t id);
            void _onplayer_connected(int64_t connectedPlayerId);
            void _request_player_info(int64_t FromId, int64_t playerdId);
            void _request_players(int64_t fromID);
            void _send_player_info(int64_t id, Dictionary info);
            void update_position(int64_t id, Vector3 position);
    };
}
// =======
// #ifndef NETWORK_H
// #define NETWORK_H

// #include <Godot.hpp>
// #include <Node.hpp>

// namespace godot {

// class Network : public Node {
//     GODOT_CLASS(Network, Node)

// private:
// 	const String DEFAULT_IP = "127.0.0.1";
// 	const int DEFAULT_PORT = 31400;
// 	const int MAX_PLAYERS = 2;
// 	Dictionary selfData;
// 	Dictionary players;

// public:
//     static void _register_methods();

//     Network();
//     ~Network();

//     void _init(); // our initializer called by Godot

//     void _process(float delta);
//     void _ready();
    
//     void create_server(String playerNickname);

// };

// }

// #endif
