#include "caps_lock.h"

uint8_t get_caps (){
	return caps_lock;
}
void set_caps (uint8_t new_caps){
	caps_lock = new_caps;
}
