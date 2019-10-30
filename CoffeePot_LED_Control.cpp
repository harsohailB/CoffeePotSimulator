#include "CoffeePot_LED_Control.h"

void turnOffLEDS(COFFEEPOT_DEVICE *pCoffeePot){
	pCoffeePot->controlRegister &= ~LED_MASK;
}

void turnOnLED(COFFEEPOT_DEVICE *pCoffeePot, unsigned int LED_BIT){
	pCoffeePot->controlRegister |= LED_BIT;
}
