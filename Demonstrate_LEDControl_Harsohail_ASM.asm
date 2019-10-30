/*
 * Demonstrate_LEDControl_Harsohail_ASM.asm
 *
 *  Created on: October 30, 2019
 *      Author: Harsohail Brar
 */
 
 #include <blackfin.h>
 	.section program;
 	.global Demonstrate_LEDControl_Harsohail_ASM;
 
 // void Demonstrate_LEDControl_Harsohail_CPP(COFFEEPOT_DEVICE *pCoffeePot){	pCoffeepot passed through R0 
 _Demonstrate_LEDControl_Harsohail_ASM:
 
 #define COFFEEPOT_P0 P0
 #define COFFEEPOT_CTRL_REGISTER_R1 R1
 	
 	// P0 = pCoffeePot
 	COFFEEPOT_P0 = R0;
 	//