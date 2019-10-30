#ifndef MY_COFFEEPOTFUNCTIONS_HARSOHAIL2019_H_
#define MY_COFFEEPOTFUNCTIONS_HARSOHAIL2019_H_

#include "CoffeePotUtils.h"
#include "CoffeePot_LED_Control.h"

void ShowNameProcessorUsed(void);

void Activate_LED_Control_Harsohail(void);
void Init_CoffeePot_Harsohail(void);
void Demonstrate_LEDControl_Harsohail_CPP(void);

void Activate_LED_Control_Harsohail(COFFEEPOT_DEVICE *pCoffeePot);
void Init_CoffeePot_Harsohail(COFFEEPOT_DEVICE *pCoffeePot);

void Demonstrate_LEDControl_Harsohail_CPP(COFFEEPOT_DEVICE *pCoffeePot);
extern "C" void Demonstrate_LEDControl_Harsohail_ASM(void);



#endif
