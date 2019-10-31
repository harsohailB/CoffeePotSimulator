/*
 * CoffeePot_LED_Control.h
 *
 *  Created on: October 30, 2019
 *      Author: Harsohail Brar
 */

#ifndef COFFEPOT_LED_CONTROL_H_
#define COFFEEPOT_LED_CONTROL_H_

#include "CoffeePotUtils.h"

void turnOffLED(COFFEEPOT_DEVICE *pCoffeePot, unsigned short int LED_BIT);
void turnOnLED(COFFEEPOT_DEVICE *pCoffeePot, unsigned int LED_BIT);

#endif
