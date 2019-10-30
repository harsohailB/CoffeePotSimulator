/*
 * Demonstrate_LEDControl_Harsohail_ASM.asm
 *
 *  Created on: October 30, 2019
 *      Author: Harsohail Brar
 */
 
 #include <blackfin.h>
 	.section program;
 	.global _Demonstrate_LEDControl_Harsohail_ASM;
 
 // void Demonstrate_LEDControl_Harsohail_CPP(COFFEEPOT_DEVICE *pCoffeePot){	pCoffeepot passed through R0 
 _Demonstrate_LEDControl_Harsohail_ASM:
 
 #define COFFEEPOT_P0 P0
 #define COFFEEPOT_CTRL_REGISTER_R1 R1
 #define LED_MASK 0x3000
 #define LED_1_BIT	0x1000
 #define LED_2_BIT	0x2000 
 
 	
 	// P0 = pCoffeePot
 	COFFEEPOT_P0 = R0;
 	
 	// R1 = pCoffeePot->contorlRegister
 	COFFEEPOT_CTRL_REGISTER_R1 = W[COFFEEPOT_P0](Z);
 	
 	// Get active LEDs bit pattern to decide which LED to turn on next
 	R2 = LED_MASK;
#define ACTIVE_LED_R0 R0
	ACTIVE_LED_R0 = COFFEEPOT_CTRL_REGISTER_R1 & R2;

 	// if LED 1 is off then turn it on
 	// if(ACTIVE_LED_R0 != LED_1_BIT) jump to TURN_LED_1_ON else TURN_LED_2_ON
 	R2 = LED_1_BIT;
 	CC = ACTIVE_LED_R0 == R2;
 	IF !CC JUMP ELSE;
 
 // TURN ON LED 2
 
 	// reset LED bit pattern 
 	// pCoffeePot->controlRegister &= ~LED_MASK
 	R2 = LED_MASK;
 	R2 = ~R2;
 	R0 = COFFEEPOT_CTRL_REGISTER_R1 & R2;
 	// turn on LED 2
 	// pCoffeePot->controlRegister |= LED_2_BIT
 	R3 = LED_2_BIT;
 	COFFEEPOT_CTRL_REGISTER_R1 = R0 | R3;
 	
 	JUMP END_IF;

ELSE:	// TURN ON LED 1
 
 	// reset LED bit pattern 
 	// pCoffeePot->controlRegister &= ~LED_MASK
 	R2 = LED_MASK;
 	R2 = ~R2;
 	R0 = COFFEEPOT_CTRL_REGISTER_R1 & R2;
 	// turn on LED 1
 	// pCoffeePot->controlRegister |= LED_1_BIT
 	R3 = LED_1_BIT;
 	COFFEEPOT_CTRL_REGISTER_R1 = R0 | R3;

 END_IF:
 	
 	// pCoffeePot->controlRegister = COFFEEPOT_CTRL_REGISTER_R1
 	[COFFEEPOT_P0] = COFFEEPOT_CTRL_REGISTER_R1;
 	
 _Demonstrate_LEDControl_Harsohail_ASM.END:
 	RTS;