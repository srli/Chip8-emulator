#include "chip8.h"
#include <assert.h>
#include <map>
#include <string>
#include <fstream>

//From hardware specifications
BYTE m_GameMemory[0xFFF]; 	//0xFFF bytes of memory
BYTE m_Registers[16]; 		//16 registers, 1 byte each
WORD m_AddressI; 			//16-bit address register 1
WORD m_ProgramCounter; 		//16-bit program m_ProgramCounter
std::vector<WORD> m_Stack;  //16-bit stack <--technically supposed to be a stack pointer,

void CPUReset(){
	//CPU Reset, game is loaded into memory 0x200 as 0-1FFF is for the interpreter only
	m_AddressI = 0;
	m_ProgramCounter = 0x200;
	memset(m_Registers, 0, sizeof(m_Registers)); //set registers to 0

	//load in the game
	FILE *in;
	in = fopen("/games/INVADERS", 'rb');
	fread( &m_GameMemory[0x200], 0xFFF, 1, in); //loads game into memory
	fclose(in);
}

BYTE m_ScreenData[64][32]; //Every sprite has width 8 pixels, variable height

WORD GetNextOpcode(){
	//Fetch loop
	WORD res = 0;
	res = m_GameMemory[m_ProgramCounter] ; //We're combining two 1 byte op-codes to make a 2 byte
	res <<= 8; //Shift 8 bits left
	res |= m_GameMemory[m_ProgramCounter + 1]; //Combines with next op-code
	m_ProgramCounter += 2; //Incremented twice because each op code is 2 bytes long
	return res;
}

void DecodeOpcode(){
	WORD opcode = GetNextOpcode();

	switch(opcode & 0xF000){
		case 0x0000: DecodeOpcode0(opcode); break;
		case 0x1000: Opcode1NNN(opcode); break;
		case 0x2000: Opcode2NNN(opcode); break;
		case 0x3000: Opcdoe3NNN(opcode); break;
		//reapeat for rest of op codes...
	}

int main(int argc, char const *argv[])
{
	int i = 0;
	return 0;
}