#include "network.h"

using namespace godot;

void Network::_register_methods() {
    register_method("_ready", &Network::_ready);
    register_method("create_server", &Network::create_server);
}

Network::Network() {

}

Network::~Network() {
    // add your cleanup here
}

void Network::_init() {
	selfData["name"] = "";
	// selfData["position"] = Vector3()
}

void Network::_ready() {

}

void Network::create_server(String playerNickname) {
	selfData["name"] = playerNickname;
	players[1] = selfData;
	NetworkedMultiplayerENet *peer = NetworkedMultiplayerENet::_new();
	peer->set_bind_ip("*");
	peer->create_server(SERVER_PORT, MAX_PLAYERS);
	get_tree()->set_network_peer(peer);
}
