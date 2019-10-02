#include "candycounter.h"

using namespace godot;

void CandyCounter::_register_methods() {
    register_method("_ready", &CandyCounter::_ready);
    register_method("_increment", &CandyCounter::_increment);
    register_method("get_count", &CandyCounter::get_count);
    register_signal<CandyCounter>((char*)"candy_hit");
}

CandyCounter::CandyCounter() {

}

CandyCounter::~CandyCounter() {
    // add your cleanup here
}

void CandyCounter::_ready() {
    this->connect("candy_hit", this, "increment");
}

void CandyCounter::_init() {
    candy_count = 0;
    set_text(String::num_int64(candy_count));
}

void CandyCounter::_increment() {
    Godot::print("Increment");
    ++candy_count;
    set_text(String::num_int64(candy_count));
}

int CandyCounter::get_count() {
    return candy_count;
}
