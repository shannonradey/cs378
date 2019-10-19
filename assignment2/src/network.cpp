#include "network.h"
// #include <NetworkedMultiplayerENet.hpp>
// #include <SceneTree.hpp>
// #include <ResourceLoader.hpp>
// #include "player.h"

using namespace godot;

void Network::_register_methods(){
    register_method("_init", &Network::_init, GODOT_METHOD_RPC_MODE_DISABLED);
    register_method("_ready", &Network::_ready, GODOT_METHOD_RPC_MODE_DISABLED);
    register_method("create_server", &Network::create_server, GODOT_METHOD_RPC_MODE_DISABLED);
    register_method("connect_to_server", &Network::connect_to_server, GODOT_METHOD_RPC_MODE_DISABLED);
    register_method("_connected_to_server", &Network::_connected_to_server, GODOT_METHOD_RPC_MODE_DISABLED);
    register_method("_onplayer_disconnected", &Network::_onplayer_disconnected, GODOT_METHOD_RPC_MODE_DISABLED);
    register_method("_onplayer_connected", &Network::_onplayer_connected, GODOT_METHOD_RPC_MODE_DISABLED);
    register_method("_request_player_info", &Network::_request_player_info, GODOT_METHOD_RPC_MODE_REMOTE);
    register_method("_request_players", &Network::_request_players, GODOT_METHOD_RPC_MODE_REMOTE);
    register_method("_send_player_info", &Network::_send_player_info, GODOT_METHOD_RPC_MODE_REMOTE);
    register_method("update_position", &Network::update_position, GODOT_METHOD_RPC_MODE_DISABLED);

    register_property<Network, Dictionary>("selfData", &Network::selfData, Dictionary(), GODOT_METHOD_RPC_MODE_DISABLED);
    register_property<Network, Dictionary>("players", &Network::players, Dictionary(), GODOT_METHOD_RPC_MODE_DISABLED);
}
Network::Network(){}
Network::~Network(){}
void Network::_init(){
    selfData["name"] = "";
    selfData["position"] = Vector3(1, 1, 1);
}
void Network::_ready(){
    get_tree()->connect("network_peer_disconnected", this, "_onplayer_disconnected");
    get_tree()->connect("network_peer_connected", this, "_on_player_connected");
}
void Network::create_server(String playerNickname)
{
    selfData["name"] = playerNickname;
    players[1] = selfData;
    NetworkedMultiplayerENet* peer = NetworkedMultiplayerENet::_new();
    peer->set_bind_ip("*");
    peer->create_server(SERVER_PORT, MAX_PLAYER);
    get_tree()->set_network_peer(peer);
}
void Network::connect_to_server(String playerNickname)
{
    selfData["name"] = playerNickname;
    get_tree()->connect("connected_to_server", this, "_connected_to_server");
    NetworkedMultiplayerENet* peer = NetworkedMultiplayerENet::_new();
    peer->create_client(SERVER_IP, SERVER_PORT);
    get_tree()->set_network_peer(peer);
}
void Network::_connected_to_server()
{
    int64_t localPlayerId = get_tree()->get_network_unique_id();
    players[localPlayerId] = selfData;
    rpc("_send_player_info", localPlayerId, selfData);
}
void Network::_onplayer_disconnected(int64_t id)
{
    players.erase(id);
}

void Network::_onplayer_connected(int64_t connectedPlayerId)
{
    std::cout << "Player connected to server" << std::endl;
    int64_t localPlayerId = get_tree()->get_network_unique_id();
    if(!get_tree()->is_network_server())
    {
        rpc_id(1, "_request_player_info", localPlayerId, connectedPlayerId);
    }
}

void Network::_request_player_info(int64_t requestFromId, int64_t playerId)
{
    if(get_tree()->is_network_server())
    {
        rpc_id(requestFromId, "_send_player_info", playerId, players[playerId]);
    }
}

void Network::_request_players(int64_t requestFromId)
{
    if(get_tree()->is_network_server())
    {
        for(int64_t peerId = 0; peerId < players.size(); peerId++)
        {
            if(peerId != requestFromId)
            {
                rpc_id(requestFromId, "_send_player_info", peerId, players[peerId]);
            }
        }
    }
}

void Network::_send_player_info(int64_t id, Dictionary info)
{
    players[id] = info;

    ResourceLoader* resourceLoader = ResourceLoader::get_singleton();
    PlayerScene = resourceLoader->load("res://Player.tscn");
    godot::Player* player = static_cast<godot::Player*>(PlayerScene->instance());
    player->set_name(String(id));
    player->set_network_master(id);
    get_node("/root/Game")->add_child(player);
    player->init(info["name"], info["position"], true);
}

void Network::update_position(int64_t id, Vector3 position)
{
    Dictionary playerInfo = players[id];
    playerInfo["position"] = position;
}


// using namespace godot;

// void Network::_register_methods() {
//     register_method("_ready", &Network::_ready);
//     register_method("create_server", &Network::create_server);
// }

// Network::Network() {

// }

// Network::~Network() {
//     // add your cleanup here
// }

// void Network::_init() {
// 	selfData["name"] = "";
// 	// selfData["position"] = Vector3()
// }

// void Network::_ready() {

// }

// void Network::create_server(String playerNickname) {
// 	selfData["name"] = playerNickname;
// 	players[1] = selfData;
// 	NetworkedMultiplayerENet *peer = NetworkedMultiplayerENet::_new();
// 	peer->set_bind_ip("*");
// 	peer->create_server(SERVER_PORT, MAX_PLAYERS);
// 	get_tree()->set_network_peer(peer);
// }
