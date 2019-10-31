/*
 * CoffeePot_LED_Control.cpp
 *
 *  Created on: October 30, 2019
 *      Author: Harsohail Brar
 */

#include "CoffeePot_LED_Control.h"

void turnOffLED(COFFEEPOT_DEVICE *pCoffeePot, unsigned short int LEDMASK){
	pCoffeePot->controlRegister &= ~LEDMASK;
}

void turnOnLED(COFFEEPOT_DEVICE *pCoffeePot, unsigned int LED_BIT){
	pCoffeePot->controlRegister |= LED_BIT;
}
