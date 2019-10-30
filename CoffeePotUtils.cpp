#include "CoffeePotUtils.h"

bool getBit(unsigned short int bitPattern, unsigned int bit){
	unsigned short int shiftedBitPattern = bitPattern >> bit;
	return shiftedBitPattern & 0x1;
}
