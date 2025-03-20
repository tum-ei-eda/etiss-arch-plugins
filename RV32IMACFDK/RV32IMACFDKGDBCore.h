/**
 * Generated on Thu, 27 Feb 2025 14:13:34 +0100.
 *
 * This file contains the GDBCore adapter for the RV32IMACFDK core architecture.
 *
 * WARNING: This file contains user-added code, be mindful when overwriting this with
 * generated code!
 */

#ifndef ETISS_RV32IMACFDKArch_RV32IMACFDKGDBCORE_H_
#define ETISS_RV32IMACFDKArch_RV32IMACFDKGDBCORE_H_

#include "etiss/IntegratedLibrary/gdb/GDBCore.h"
#include <sstream>

/**
	@brief This class is the brige between RV32IMACFDK architecture and gdbserver

	@details Gdbserver integrated in ETISS calls GDBCore to read/write registers via virtualStrruct
				The index in mapRegister() should strictly follow the RV32IMACFDK gdb tool defined register
				order. Because gdbserver will send raw register data sequentially in strict order over
				RSP ->TCP/IP ->RSP protocal

				Check the order with gdb command:
				$(gdb) info all-registers
				which lists all registers supported and its order.

				By default only general purpose register and instruction pointer are supported. Further
				Special Function Register/Control and Status Register could be added manually. Meanwhile
				virtualStruct in RV32IMACFDKArch.cpp should be modified as well as well

*/
class RV32IMACFDKGDBCore : public etiss::plugin::gdb::GDBCore {
public:
	std::string mapRegister(unsigned index){
		if (index < 32){
			std::stringstream ss;
			ss << "X" << index;
			return ss.str();
		}
		switch (index){
		case 32:
			return "instructionPointer";
		/**************************************************************************
		*   Further register should be added here to send data over gdbserver	  *
		***************************************************************************/
		}
		return "";
	}

	unsigned mapRegister(std::string name){
		return INVALIDMAPPING;
	}

	unsigned mappedRegisterCount(){
		// Modify according to sent register number
		return 33;
	}

	etiss::uint64 getInstructionPointer(ETISS_CPU * cpu){
		return cpu->instructionPointer;
	}

	bool isLittleEndian(){
		// Modify according to RV32IMACFDK manual
		return true;
	}
};

#endif
