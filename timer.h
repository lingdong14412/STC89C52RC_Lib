#ifndef __TIMER_H_
#define __TIMER_H_

#include "register.h"
#include <stddef.h>
#include "config.h"
#include "typedef.h"

typedef void (*timer_callback_t)(void);

void timer_init();
void timer_set_callback(timer_callback_t callback);
u8 tim_set_arv(u16 x);

#endif