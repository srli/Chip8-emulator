typedef unsigned char BYTE; //holds values 0 to 255
typedef unsigned short int WORD; //holds values 0 to 65535

//From hardware specifications
BYTE m_GameMemory[0xFFF]; 	//0xFFF bytes of memory
BYTE m_Registers[16]; 		//16 registers, 1 byte each
WORD m_AddressI; 			//16-bit address register 1
WORD m_ProgramCounter; 		//16-bit program m_ProgramCounter
std::vector m_Stack			//16-bit stack