#include "candycounter.h"

using namespace godot;

void CandyCounter::_register_methods() {
    register_method("_ready", &CandyCounter::_ready);
    register_method("_increment", &CandyCounter::_increment);
    register_method("get_count", &CandyCounter::get_count);
}

CandyCounter::CandyCounter() {

}

CandyCounter::~CandyCounter() {
    // add your cleanup here
}

void CandyCounter::_ready() {
    Node *node = get_node("/root/Spatial/Spatial2/Area");
    node->connect("candy_hit", this, "_increment");
    
    node = get_node("/root/Spatial/Spatial3/Area");
    
    node->connect("candy_hit", this, "_increment");

}

void CandyCounter::_init() {
    candy_count = 0;
    set_text(String::num_int64(candy_count));
}

void CandyCounter::_increment() {
    set_text(String::num_int64(++candy_count));
}

int CandyCounter::get_count() {
    return candy_count;
}
