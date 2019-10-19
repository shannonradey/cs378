#ifndef NETWORK_H
#define NETWORK_H

#include <Godot.hpp>
#include <Node.hpp>
// #include <NetworkedMultiplayerENet.hpp>

namespace godot {

class Network : public Node {
    GODOT_CLASS(Network, Node)

private:
	const String DEFAULT_IP = "127.0.0.1";
	const int DEFAULT_PORT = 31400;
	const int MAX_PLAYERS = 2;
	Dictionary selfData;
	Dictionary players;

public:
    static void _register_methods();

    Network();
    ~Network();

    void _init(); // our initializer called by Godot

    void _process(float delta);
    void _ready();
    
    void create_server(String playerNickname);

};

}

#endif