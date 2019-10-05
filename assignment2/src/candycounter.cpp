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

}

void CandyCounter::_init() {
    candy_count = -1;
    set_text(String::num_int64(candy_count));
}

void CandyCounter::_increment() {
    set_text(String::num_int64(++candy_count));
}

int CandyCounter::get_count() {
    return candy_count;
}
