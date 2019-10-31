/*
 * My_CoffeePotFunctions_Harsohail2019.cpp
 *
 *  Created on: October 30, 2019
 *      Author: Harsohail Brar
 */

#include <stdio.h>
#include "My_CoffeePotFunctions_Harsohail2019.h"
#include "CoffeePot_LED_Control.h"

#define SHOW_FUNCTION_STUB_INFORMATION 1

void ShowNameProcessorUsed(void){
#if defined(__ADSPBF533__)
	char processor[] = "__ADSPBF533__";
#else
	char processor[] = "__ADSPBF609__";
#endif
	printf("Harsohail Coffee Pot running on %s system\n\n", processor);
}

//WAIL Treat inline syntax as MAGIC for now
inline void Show_Function_Stub_Information(char* functionNameInformation){
	if(SHOW_FUNCTION_STUB_INFORMATION){
		printf("%s\n", functionNameInformation);
	}
}

void Init_CoffeePot_Harsohail(COFFEEPOT_DEVICE *pCoffeePot){
	Show_Function_Stub_Information("Init_CoffeePot_Harsohail(COFFEE_DEVICE *pCoffeePot)");

	//OpenChannel_CoffeePot(pCoffeePot);
	// Set the POWER_ON and INIT bit in Coffee Pot control register
	pCoffeePot->controlRegister |= INITandSTAYPOWEREDON_BIT;

	// Then in a loop -- read control register -- use bitwise AND to see if device ready
	// When ready -- exit
	// Turn statements into comments when completed

	bool isCoffeePotInited = false;
	while(!isCoffeePotInited){
		isCoffeePotInited = (pCoffeePot->controlRegister |= DEVICE_READY_BIT_RO);
		FastForward_OneSimulationTIC(pCoffeePot);
	}
}

void Activate_LED_Control_Harsohail(COFFEEPOT_DEVICE *pCoffeePot){
	Show_Function_Stub_Information("Activate_LED_Control_Harsohail(COFFEE_DEVICE *pCoffeePot)");

	// Turn on LED_POWER bit in control register, without turning off other bits
	pCoffeePot->controlRegister |= LED_DISPLAY_ENABLE_BIT;
	FastForward_OneSimulationTIC(pCoffeePot);
	// Sounds like a possible Quiz 1 questions as in
	// Build Activate_LED_Control_ASM using Activate_LED_Control_CPP() code as design idea
	// **** First parameter pointer COFFEEPOT_DEVICE *pCoffeePot will come in R0 -- THEN WHAT?
}

void Demonstrate_LEDControl_Harsohail_CPP(COFFEEPOT_DEVICE *pCoffeePot){
	Show_Function_Stub_Information("Demonstrate_LEDControl_Harsohail_CPP(COFFEE_DEVICE *pCoffeePot)");

	// Get SOMETHING to work
	// Use state machine ideas from LAB 1
	// state 0 -- turn LED1 and turn off LED 0
	unsigned short int currBits = pCoffeePot->controlRegister;

	switch(getBit(currBits, LED_CONTROL_FIELD_OFFSET)){
	case 0:
		turnOffLED(pCoffeePot, LED1_BIT);
		turnOffLED(pCoffeePot, LED2_BIT);
		turnOnLED(pCoffeePot, LED1_BIT);
		break;

	case 1:
		turnOffLED(pCoffeePot, LED1_BIT);
		turnOffLED(pCoffeePot, LED2_BIT);
		turnOnLED(pCoffeePot, LED2_BIT);
		break;
	}

	FastForward_OneSimulationTIC(pCoffeePot);
}

void Activate_Water_Control_Harsohail(COFFEEPOT_DEVICE *pCoffeePot){
	Show_Function_Stub_Information("Activate_Water_Control_Harsohail(COFFEEPOT_DEVICE *pCoffeePot)");

	// turn off LED 1 and 2 from demonstrate
	turnOffLED(pCoffeePot, LED1_BIT);
	turnOffLED(pCoffeePot, LED2_BIT);
	// enable water control
	pCoffeePot->controlRegister |= WATER_ENABLE_BIT;
	// turn on LED 3 to show water enabled
	turnOnLED(pCoffeePot, USE_LED3_TO_SHOW_WATER_ENABLED);
	FastForward_OneSimulationTic(pCoffeePot);
	// TODO fix deactivate error
}

void FillCoffeePotToWaterLevel_Harsohail(COFFEEPOT_DEVICE *pCoffeePot, unsigned int neededWaterLevel){
	Show_Function_Stub_Information("FillCoffeePotToWaterLevel_Harsohail(COFFEEPOT_DEVICE *pMyCoffeePot1, unsigned int MAX_WATER_LEVEL)");

	unsigned int currWaterLevel = CurrentWaterLevel_CPP(pCoffeePot);
	if(currWaterLevel >= neededWaterLevel){
		FastForward_OneSimulationTic(pCoffeePot);
		return;
	}

	unsigned int waterToBeAdded = neededWaterLevel - currWaterLevel;

	// TODO add response intertia
	// TODO water level not going above 88
	pCoffeePot->waterInFlowRegister = waterToBeAdded;
}


void Activate_Heater_Control_Harsohail(COFFEEPOT_DEVICE *pCoffeePot){
	Show_Function_Stub_Information("Activate_Heater_Control_Harsohail(COFFEEPOT_DEVICE *pCoffeePot)");

	// enable heater control
	pCoffeePot->controlRegister |= HEATER_ENABLE_BIT;
	// turn on LED 4 to show heater enabled
	turnOnLED(pCoffeePot, LED4_BIT);
	FastForward_OneSimulationTIC(pCoffeePot);
	// TODO fix deactivate error
}

void Control_Both_Temp_Water(COFFEEPOT_DEVICE *pCoffeePot, unsigned int neededWaterLevel, unsigned int neededTemp){
	Show_Function_Stub_Information("Control_Both_Temp_Water(unsigned int MAX_WATER_LEVEL, unsigned int MAX_TEMPERATURE)");

	// Fill Water
	FillCoffeePotToWaterLevel_Harsohail(pCoffeePot, neededWaterLevel);

	// Heat up to neededTemp
	unsigned int currTempLevel = CurrentTemperature_CPP(pCoffeePot);
	if(currTempLevel >= neededTemp){
		FastForward_OneSimulationTic(pCoffeePot);
		return;
	}

	unsigned int tempToBeAdded = neededTemp - currTempLevel;
	// TODO currTemp not working
	// TODO add response intertia
	pCoffeePot->heaterRegister = tempToBeAdded;
	pCoffeePot->heaterBoostRegister = 15;
}







