#include <stdio.h>
#include "My_CoffeePotFunctions_Harsohail2019.h"

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

void Init_CoffeePot_Harsohail(void){
	Show_Function_Stub_Information("Init_CoffeePot_Harsohail(COFFEE_DEVICE *pCoffeePot)");
}

void Activate_LED_Control_Harsohail(void){
	Show_Function_Stub_Information("Activate_LED_Control_Harsohail(COFFEE_DEVICE *pCoffeePot)");
}

void Demonstrate_LEDControl_Harsohail_CPP(void){
	Show_Function_Stub_Information("Demonstrate_LEDControl_Harsohail_CPP(COFFEE_DEVICE *pCoffeePot)");
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
		turnOffLEDS(pCoffeePot);
		turnOnLED(pCoffeePot, LED1_BIT);
		break;

	case 1:
		turnOffLEDS(pCoffeePot);
		turnOnLED(pCoffeePot, LED2_BIT);
		break;

	default:
		printf("Illegal State");
		break;
	}

	FastForward_OneSimulationTIC(pCoffeePot);
}







