#include "44b.h"
#include "gpio.h"

/* Port B interface implementation */

int portB_conf(int pin, enum port_mode mode)
{
	int ret = 0;
	if (pin < 0 || pin > 10)
		return -1;

	if (mode == SIGOUT){
		// COMPLETAR si es necesario
		rPCONB = rPCONB | (1 << pin);
	}
	else if (mode == OUTPUT){
		// COMPLETAR: tomar la implementaci贸n pr谩cticas anteriores
		rPCONB = rPCONB & ~(1 << pin);
	}
	else{
		ret = -1;
	}
	return ret;
}

int portB_write(int pin, enum digital val)
{
	if (pin < 0 || pin > 10)
		return -1;

	if (val < 0 || val > 1)
		return -1;

	if (val){
		// COMPLETAR: tomar la implementaci贸n pr谩cticas anteriores
		rPDATB = rPDATB | (1 << pin);
	}
	else{
		// COMPLETAR: tomar la implementaci贸n pr谩cticas anteriores
		rPDATB = rPDATB & ~(1 << pin);
	}
	return 0;
}

/* Port G interface implementation */

int portG_conf(int pin, enum port_mode mode)
{
	int pos  = pin*2;

	if (pin < 0 || pin > 7)
		return -1;

	switch (mode) {
		case INPUT:
		// COMPLETAR: tomar la implementaci贸n pr谩cticas anteriores
			rPCONG= rPCONG & ~(1 << pos);//Pone un 0 en la posici髇 pos de rPCONG
			rPCONG= rPCONG & ~(1 << (pos+1));//Pone un 0 en la posici髇 pos+1 de rPCONG
			break;
		case OUTPUT:
		// COMPLETAR: tomar la implementaci贸n pr谩cticas anteriores
			rPCONG= rPCONG | (1 << pos);//Pone un 1 en la posici髇 pos de rPCONG
			rPCONG= rPCONG & ~(1 << (pos+1));//Pone un 0 en la posici髇 pos+1 de rPCONG
			break;
		case SIGOUT:
		// COMPLETAR: tomar la implementaci贸n pr谩cticas anteriores
			rPCONG= rPCONG & ~(1 << pos);//Pone un 0 en la posici髇 pos de rPCONG
			rPCONG= rPCONG | (1 << (pos+1));//Pone un 1 en la posici髇 pos+1 de rPCONG
			break;
		case EINT:
		// COMPLETAR: tomar la implementaci贸n pr谩cticas anteriores
			rPCONG= rPCONG | (1 << pos);//Pone un 1 en la posici髇 pos de rPCONG
			rPCONG= rPCONG | (1 << (pos+1));//Pone un 1 en la posici髇 pos+1 de rPCONG
			break;
		default:
			return -1;
	}

	return 0;
}

int portG_eint_trig(int pin, enum trigger trig)
{
	int pos = pin*4;

	if (pin < 0 || pin > 7)
		return -1;

	rEXTINT = rEXTINT & ~(0x7 << pos);//Limpiamos lo que haya con 0
switch (trig) {
		case LLOW:
			// COMPLETAR: poner en rEXTINT a partir de la posici贸n pos tres bits
			// a 000, para configurar interrupciones externas por nivel bajo
			//rEXTINT = rEXTINT | (0x0 << pos);
			break;
		case LHIGH:
			// COMPLETAR: poner en rEXTINT a partir de la posici贸n pos tres bits
			// a 001, para configurar interrupciones externas por nivel alto
			rEXTINT = rEXTINT | (0x1 << pos);
			break;
		case FALLING:
			// COMPLETAR: poner en rEXTINT a partir de la posici贸n pos tres bits
			// a 010, para configurar interrupciones externas por flanco de
			// bajada
			rEXTINT = rEXTINT | (0x2 << pos);
			break;
		case RISING:
			// COMPLETAR: poner en rEXTINT a partir de la posici贸n pos tres bits
			// a 100, para configurar interrupciones externas por flanco de
			// subida
			rEXTINT = rEXTINT | (0x4 << pos);
			break;
		case EDGE:
			// COMPLETAR: poner en rEXTINT a partir de la posici贸n pos tres bits
			// a 110, para configurar interrupciones externas por cualquier
			// flanco
			rEXTINT = rEXTINT | (0x6 << pos);
			break;
		default:
			return -1;
	}
	return 0;
}
/*
int portG_eint_trig(int pin, enum trigger trig)
{
	int pos = pin*4;

	if (pin < 0 || pin > 7)
		return -1;

switch (trig) {
		case LLOW:
			// COMPLETAR: poner en rEXTINT a partir de la posici贸n pos tres bits
			// a 000, para configurar interrupciones externas por nivel bajo
			rEXTINT = rEXTINT & ~(1 << pos);
			rEXTINT = rEXTINT & ~(1 << pos + 1);
			rEXTINT = rEXTINT & ~(1 << pos + 2);
			break;
		case LHIGH:
			// COMPLETAR: poner en rEXTINT a partir de la posici贸n pos tres bits
			// a 001, para configurar interrupciones externas por nivel alto
			rEXTINT = rEXTINT | (1 << pos);
			rEXTINT = rEXTINT & ~(1 << pos + 1);
			rEXTINT = rEXTINT & ~(1 << pos + 2);
			break;
		case FALLING:
			// COMPLETAR: poner en rEXTINT a partir de la posici贸n pos tres bits
			// a 010, para configurar interrupciones externas por flanco de
			// bajada
			rEXTINT = rEXTINT & ~(1 << pos);
			rEXTINT = rEXTINT | (1 << pos + 1);
			rEXTINT = rEXTINT & ~(1 << pos + 2);
			break;
		case RISING:
			// COMPLETAR: poner en rEXTINT a partir de la posici贸n pos tres bits
			// a 100, para configurar interrupciones externas por flanco de
			// subida
			rEXTINT = rEXTINT | (1 << pos);
			rEXTINT = rEXTINT & ~(1 << pos + 1);
			rEXTINT = rEXTINT & ~(1 << pos + 2);
			break;
		case EDGE:
			// COMPLETAR: poner en rEXTINT a partir de la posici贸n pos tres bits
			// a 110, para configurar interrupciones externas por cualquier
			// flanco
			rEXTINT = rEXTINT & ~(1 << pos);
			rEXTINT = rEXTINT | (1 << pos + 1);
			rEXTINT = rEXTINT | (1 << pos + 2);
			break;
		default:
			return -1;
	}
	return 0;
}*/

int portG_write(int pin, enum digital val)
{
	int pos = pin*2;

	if (pin < 0 || pin > 7)
		return -1;

	if (val < 0 || val > 1)
		return -1;

	if ((rPCONG & (0x3 << pos)) != (0x1 << pos))
		return -1;

	if (val){
		// COMPLETAR: tomar la implementaci贸n pr谩cticas anteriores
		rPDATG = rPDATG | (1 << pin);
	}
	else{
		// COMPLETAR: tomar la implementaci贸n pr谩cticas anteriores
		rPDATG = rPDATG & ~(1 << pin);
	}
	return 0;
}

int portG_read(int pin, enum digital* val)
{
	int pos = pin*2;

	if (pin < 0 || pin > 7)
		return -1;

	if (rPCONG & (0x3 << pos))
		return -1;

	if (rPDATG & (0x1 << pin))
		// COMPLETAR: tomar la implementaci贸n pr谩cticas anteriores
		*val = HIGH;
	else
		// COMPLETAR: tomar la implementaci贸n pr谩cticas anteriores
		*val = LOW;

	return 0;
}

int portG_conf_pup(int pin, enum enable st)
{
	if (pin < 0 || pin > 7)
		return -1;

	if (st != ENABLE && st != DISABLE)
		return -1;

	if (st == ENABLE){
		// COMPLETAR: tomar la implementaci贸n pr谩cticas anteriores
		rPUPG = rPUPG & ~(1 << pin);
	}
	else{
		// COMPLETAR: tomar la implementaci贸n pr谩cticas anteriores
		rPUPG = rPUPG | (1 << pin);
	}
	return 0;
}

