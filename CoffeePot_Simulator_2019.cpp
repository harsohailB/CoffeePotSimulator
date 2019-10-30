/*****************************************************************************
 * CoffeePot_Simulator_2019.cpp
 *****************************************************************************/

#include <sys/platform.h>
#include "adi_initialize.h"
#include "CoffeePot_Simulator_2019.h"
#include <stdio.h>

/** 
 * If you want to use command program arguments, then place them in the following string. 
 */
char __argv_string[] = "";

int main(int argc, char *argv[])
{
	/**
	 * Initialize managed drivers and/or services that have been added to 
	 * the project.
	 * @return zero on success 
	 */
	adi_initComponents();
	
	/* Begin adding your custom code here */

	My_CoffeePot_Main_Harsohail2019();

	return 0;
}

