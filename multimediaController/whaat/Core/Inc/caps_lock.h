#ifndef __CAPS_LOCK_H
#define __CAPS_LOCK_H

#include "stdio.h"

static uint8_t caps_lock = 0;

uint8_t get_caps ();
void set_caps (uint8_t new_caps);

#endif
