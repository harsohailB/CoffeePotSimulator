/*
 * My_CoffeePot_Main_Harsohail2019.cpp
 *
 *  Created on: October 30, 2019
 *      Author: Harsohail Brar
 */

#include <stdio.h>
#include "../../ENCM511_SpecificFiles/ENCM511_include/CoffeePot_SimulatorFunctions2017.h"
#include "My_CoffeePotFunctions_Harsohail2019.h"

#define MAX_SECONDS		10
#define MAX_WATER_LEVEL	600
#define MAX_TEMPERATURE	80
#define NUM_COFFEE_POTS 1

#define DESIGN_PLAN2 1
#define LATER 1
#define EVEN_LATER 1
#define FINAL_CONTROL 1
#define ASSEMBLY 1

void My_CoffeePot_Main_Harsohail2019(){

#ifdef DESIGN_PLAN1

	ShowNameProcessorUsed(); //BF533 or BF609
	//Init_CoffeePotSimulation();
	Init_CoffeePot_Harsohail();
	Activate_LED_Control_Harsohail();

	bool continueDemonstrate_LEDControl = true;
	unsigned long int secondsCounter = 0;

	while(continueDemonstrate_LEDControl){
		Demonstrate_LEDControl_Harsohail_CPP();
		if(++secondsCounter >= MAX_SECONDS){
			continueDemonstrate_LEDControl = false;
		}
	}

#endif

#ifdef DESIGN_PLAN2

	ShowNameProcessorUsed();
	Init_CoffeePotSimulation(NUM_COFFEE_POTS, USE_TEXT_GUI);

	COFFEEPOT_DEVICE *pMyCoffeePot1 = Add_CoffeePotToSystem_PlugAndPlay(COFFEEPOT1, "Harsohail's Example");

	Init_CoffeePot_Harsohail(pMyCoffeePot1);
	Activate_LED_Control_Harsohail(pMyCoffeePot1);

	bool continueDemonstrate_LEDControl = true;
	unsigned long int secondsCounter = 0;

#endif

#ifndef ASSEMBLY

	while(continueDemonstrate_LEDControl){
		Demonstrate_LEDControl_Harsohail_CPP(pMyCoffeePot1);
		if(++secondsCounter >= MAX_SECONDS){
			continueDemonstrate_LEDControl = false;
		}
	}

#endif

#ifdef LATER
#ifdef ASSEMBLY

	bool continueDemonstrate_LEDControl_ASM = true;
	while(continueDemonstrate_LEDControl_ASM){
		Demonstrate_LEDControl_Harsohail_ASM(pMyCoffeePot1);
		FastForward_OneSimulationTIC(pMyCoffeePot1); 	// TODO remove FastForward from main after testing
		if(++secondsCounter >= MAX_SECONDS){
			continueDemonstrate_LEDControl_ASM = false;
		}
	}

#endif
#endif

#ifdef EVEN_LATER

	Activate_Water_Control_Harsohail(pMyCoffeePot1);
	bool continueDemonstrate_WaterControl = true;
	secondsCounter = 0;

	while(continueDemonstrate_WaterControl){
		FillCoffeePotToWaterLevel_Harsohail(pMyCoffeePot1, MAX_WATER_LEVEL);
		FastForward_OneSimulationTic(pMyCoffeePot1);
		if(++secondsCounter >= MAX_SECONDS){
			continueDemonstrate_WaterControl = false;
		}
	}

#endif

#ifdef FINAL_CONTROL

	Activate_Heater_Control_Harsohail(pMyCoffeePot1);
	bool continueDemonstrate_Both_Temp_Water = true;
	secondsCounter = 0;

	while(continueDemonstrate_Both_Temp_Water){
		Control_Both_Temp_Water(pMyCoffeePot1, MAX_WATER_LEVEL, MAX_TEMPERATURE);
		FastForward_OneSimulationTic(pMyCoffeePot1);
		if(++secondsCounter >= MAX_SECONDS){
			continueDemonstrate_Both_Temp_Water = false;
		}
	}

#endif

}

