/*
 * My_CoffeePotFunctions_Harsohail2019.h
 *
 *  Created on: October 30, 2019
 *      Author: Harsohail Brar
 */

#ifndef MY_COFFEEPOTFUNCTIONS_HARSOHAIL2019_H_
#define MY_COFFEEPOTFUNCTIONS_HARSOHAIL2019_H_

#include "CoffeePotUtils.h"

void ShowNameProcessorUsed(void);

void Init_CoffeePot_Harsohail(COFFEEPOT_DEVICE *pCoffeePot);

// LED CONTROL
void Activate_LED_Control_Harsohail(COFFEEPOT_DEVICE *pCoffeePot);
void Demonstrate_LEDControl_Harsohail_CPP(COFFEEPOT_DEVICE *pCoffeePot);
extern "C" void Demonstrate_LEDControl_Harsohail_ASM(COFFEEPOT_DEVICE *pCoffeePot);

// WATER CONTROL
void Activate_Water_Control_Harsohail(COFFEEPOT_DEVICE *pCoffeePot);
void FillCoffeePotToWaterLevel_Harsohail(COFFEEPOT_DEVICE *pCoffeePot, unsigned int neededWaterLevel);

// HEATER CONTROL
void Activate_Heater_Control_Harsohail(COFFEEPOT_DEVICE *pCoffeePot);
void Control_Both_Temp_Water(COFFEEPOT_DEVICE *pCoffeePot, unsigned int MAX_WATER_LEVEL, unsigned int MAX_TEMPERATURE);

#endif
