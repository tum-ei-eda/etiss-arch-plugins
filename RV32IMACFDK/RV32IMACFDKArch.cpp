/**
 * Generated on Thu, 27 Feb 2025 14:13:34 +0100.
 *
 * This file contains the architecture class for the RV32IMACFDK core architecture.
 */

/*********************************************************************************************************************************

* Modification guidelines:

	 1. The initial value of SP register should be initialized by ctr0.S/board.S. If not, it could be initialized
		 through utility class etiss::VirtualStruct::Field.

	 2. Debug mode print out all assignment results. GDB in 8 is prefered.

	 3. Manually copy the content in bracket ["return ETISS_RETURNCODE_CPUFINISHED; \n"] to terminating instruction,
		 otherwise the emulation can not be ended.

	 4. If subset of encoding error occurs, it means the format of the encoding in the input model was not appropriate

	 5. If the PC register points to wrong address, please notice that some assembly may cause branch operation
		 implicitly such as "MOV Rd Rn" in ARMv6-M

	 6. If a variable is the result of dynamic slicing such as, var_1 = var_2<Hshift-1..Lshift-2>, the size would be
		 calculated during process (if possible), otherwise it is assumed to be the register size. Problems may occur when
		 var_1 encounters bit manipulation such as "~" due to bit expansion. To change the nml model with explicit slicing
		 e.g var_1 = val_2<3..0> or avoid bit manipulation for dynamic sliced variable. Otherwise, you have to manually
		 correct it.

	 7. Implementation dependent functionalities such as exception handling should be manully added. Corresponding interfaces
		 are provided in RV32IMACFDKArchSpecificImp.h

	 8. RV32IMACFDKGDBCore.h provides the GDBCore class to support gdb flavor debugging feature, modify iy if in need.

 *********************************************************************************************************************************/

#include "RV32IMACFDKArch.h"
#include "RV32IMACFDKFuncs.h"

#define RV32IMACFDK_DEBUG_CALL 0
using namespace etiss ;
using namespace etiss::instr ;

RV32IMACFDKArch::RV32IMACFDKArch(unsigned int coreno):CPUArch("RV32IMACFDK"), coreno_(coreno)
{
	headers_.insert("Arch/RV32IMACFDK/RV32IMACFDK.h");
}

const std::set<std::string> & RV32IMACFDKArch::getListenerSupportedRegisters()
{
	return listenerSupportedRegisters_;
}

ETISS_CPU * RV32IMACFDKArch::newCPU()
{
	ETISS_CPU * ret = (ETISS_CPU *) new RV32IMACFDK() ;
	resetCPU (ret, 0);
	return ret;
}

void RV32IMACFDKArch::resetCPU(ETISS_CPU * cpu,etiss::uint64 * startpointer)
{
	memset (cpu, 0, sizeof(RV32IMACFDK));
	RV32IMACFDK * rv32imacfdkcpu = (RV32IMACFDK *) cpu;

	if (startpointer) cpu->instructionPointer = *startpointer & ~((etiss::uint64)0x1);
	else cpu->instructionPointer = 0x0;   //  reference to manual
	cpu->nextPc = cpu->instructionPointer;
	cpu->mode = 1;
	cpu->cpuTime_ps = 0;
	cpu->cpuCycleTime_ps = 31250;


	for (int i = 0; i < 32; ++i) {
		rv32imacfdkcpu->ins_X[i] = 0;
		rv32imacfdkcpu->X[i] = &rv32imacfdkcpu->ins_X[i];
	}
	for (int i = 0; i < 4096; ++i) {
		rv32imacfdkcpu->ins_CSR[i] = 0;
		rv32imacfdkcpu->CSR[i] = &rv32imacfdkcpu->ins_CSR[i];
	}

	rv32imacfdkcpu->ZERO = 0;
	rv32imacfdkcpu->RA = 0;
	rv32imacfdkcpu->SP = 0;
	rv32imacfdkcpu->GP = 0;
	rv32imacfdkcpu->TP = 0;
	rv32imacfdkcpu->T0 = 0;
	rv32imacfdkcpu->T1 = 0;
	rv32imacfdkcpu->T2 = 0;
	rv32imacfdkcpu->S0 = 0;
	rv32imacfdkcpu->S1 = 0;
	rv32imacfdkcpu->A0 = 0;
	rv32imacfdkcpu->A1 = 0;
	rv32imacfdkcpu->A2 = 0;
	rv32imacfdkcpu->A3 = 0;
	rv32imacfdkcpu->A4 = 0;
	rv32imacfdkcpu->A5 = 0;
	rv32imacfdkcpu->A6 = 0;
	rv32imacfdkcpu->A7 = 0;
	rv32imacfdkcpu->S2 = 0;
	rv32imacfdkcpu->S3 = 0;
	rv32imacfdkcpu->S4 = 0;
	rv32imacfdkcpu->S5 = 0;
	rv32imacfdkcpu->S6 = 0;
	rv32imacfdkcpu->S7 = 0;
	rv32imacfdkcpu->S8 = 0;
	rv32imacfdkcpu->S9 = 0;
	rv32imacfdkcpu->S10 = 0;
	rv32imacfdkcpu->S11 = 0;
	rv32imacfdkcpu->T3 = 0;
	rv32imacfdkcpu->T4 = 0;
	rv32imacfdkcpu->T5 = 0;
	rv32imacfdkcpu->T6 = 0;
	for (int i = 0; i < 8; ++i) {
		rv32imacfdkcpu->FENCE[i] = 0;
	}
	for (int i = 0; i < 8; ++i) {
		rv32imacfdkcpu->RES[i] = 0;
	}
	rv32imacfdkcpu->PRIV = 0;
	rv32imacfdkcpu->DPC = 0;
	rv32imacfdkcpu->FCSR = 0;
	rv32imacfdkcpu->MSTATUS = 0;
	rv32imacfdkcpu->MIE = 0;
	rv32imacfdkcpu->MIP = 0;
	for (int i = 0; i < 32; ++i) {
		rv32imacfdkcpu->F[i] = 0;
	}
	rv32imacfdkcpu->RES_ADDR = 0;

 	rv32imacfdkcpu->X[0] = &rv32imacfdkcpu->ZERO;
 	rv32imacfdkcpu->X[1] = &rv32imacfdkcpu->RA;
 	rv32imacfdkcpu->X[2] = &rv32imacfdkcpu->SP;
 	rv32imacfdkcpu->X[3] = &rv32imacfdkcpu->GP;
 	rv32imacfdkcpu->X[4] = &rv32imacfdkcpu->TP;
 	rv32imacfdkcpu->X[5] = &rv32imacfdkcpu->T0;
 	rv32imacfdkcpu->X[6] = &rv32imacfdkcpu->T1;
 	rv32imacfdkcpu->X[7] = &rv32imacfdkcpu->T2;
 	rv32imacfdkcpu->X[8] = &rv32imacfdkcpu->S0;
 	rv32imacfdkcpu->X[9] = &rv32imacfdkcpu->S1;
 	rv32imacfdkcpu->X[10] = &rv32imacfdkcpu->A0;
 	rv32imacfdkcpu->X[11] = &rv32imacfdkcpu->A1;
 	rv32imacfdkcpu->X[12] = &rv32imacfdkcpu->A2;
 	rv32imacfdkcpu->X[13] = &rv32imacfdkcpu->A3;
 	rv32imacfdkcpu->X[14] = &rv32imacfdkcpu->A4;
 	rv32imacfdkcpu->X[15] = &rv32imacfdkcpu->A5;
 	rv32imacfdkcpu->X[16] = &rv32imacfdkcpu->A6;
 	rv32imacfdkcpu->X[17] = &rv32imacfdkcpu->A7;
 	rv32imacfdkcpu->X[18] = &rv32imacfdkcpu->S2;
 	rv32imacfdkcpu->X[19] = &rv32imacfdkcpu->S3;
 	rv32imacfdkcpu->X[20] = &rv32imacfdkcpu->S4;
 	rv32imacfdkcpu->X[21] = &rv32imacfdkcpu->S5;
 	rv32imacfdkcpu->X[22] = &rv32imacfdkcpu->S6;
 	rv32imacfdkcpu->X[23] = &rv32imacfdkcpu->S7;
 	rv32imacfdkcpu->X[24] = &rv32imacfdkcpu->S8;
 	rv32imacfdkcpu->X[25] = &rv32imacfdkcpu->S9;
 	rv32imacfdkcpu->X[26] = &rv32imacfdkcpu->S10;
 	rv32imacfdkcpu->X[27] = &rv32imacfdkcpu->S11;
 	rv32imacfdkcpu->X[28] = &rv32imacfdkcpu->T3;
 	rv32imacfdkcpu->X[29] = &rv32imacfdkcpu->T4;
 	rv32imacfdkcpu->X[30] = &rv32imacfdkcpu->T5;
 	rv32imacfdkcpu->X[31] = &rv32imacfdkcpu->T6;
 	rv32imacfdkcpu->CSR[3] = &rv32imacfdkcpu->FCSR;
 	rv32imacfdkcpu->CSR[768] = &rv32imacfdkcpu->MSTATUS;
 	rv32imacfdkcpu->CSR[772] = &rv32imacfdkcpu->MIE;
 	rv32imacfdkcpu->CSR[836] = &rv32imacfdkcpu->MIP;

   	rv32imacfdkcpu->PRIV = 3ULL;
   	rv32imacfdkcpu->DPC = 0LL;
  	*rv32imacfdkcpu->CSR[0] = 11ULL;
 	*rv32imacfdkcpu->CSR[256] = 11ULL;
 	*rv32imacfdkcpu->CSR[768] = 11ULL;
 	*rv32imacfdkcpu->CSR[769] = 1075056941ULL;
 	*rv32imacfdkcpu->CSR[3088] = 3ULL;
 	*rv32imacfdkcpu->CSR[772] = 4294966203ULL;
 	*rv32imacfdkcpu->CSR[260] = 4294964019ULL;
 	*rv32imacfdkcpu->CSR[4] = 4294963473ULL;
   	rv32imacfdkcpu->RES_ADDR = -1LL;

}

void RV32IMACFDKArch::deleteCPU(ETISS_CPU *cpu)
{
	delete (RV32IMACFDK *) cpu ;
}

/**
	@return 8 (jump instruction + instruction of delay slot)
*/
unsigned RV32IMACFDKArch::getMaximumInstructionSizeInBytes()
{
	return 8;
}

/**
	@return 2
*/
unsigned RV32IMACFDKArch::getInstructionSizeInBytes()
{
	return 2;
}

/**
	@brief required headers (RV32IMACFDK.h)
*/
const std::set<std::string> & RV32IMACFDKArch::getHeaders() const
{
	return headers_ ;
}

void RV32IMACFDKArch::initCodeBlock(etiss::CodeBlock & cb) const
{
	cb.fileglobalCode().insert("#include \"Arch/RV32IMACFDK/RV32IMACFDK.h\"\n");
	cb.fileglobalCode().insert("#include \"Arch/RV32IMACFDK/RV32IMACFDKFuncs.h\"\n");
	cb.functionglobalCode().insert("cpu->exception = 0;\n");
	cb.functionglobalCode().insert("cpu->return_pending = 0;\n");
	cb.functionglobalCode().insert("etiss_uint32 mem_ret_code = 0;\n");
}

etiss::plugin::gdb::GDBCore & RV32IMACFDKArch::getGDBCore()
{
	return gdbcore_;
}

const char * const reg_name[] =
{
	"X0",
	"X1",
	"X2",
	"X3",
	"X4",
	"X5",
	"X6",
	"X7",
	"X8",
	"X9",
	"X10",
	"X11",
	"X12",
	"X13",
	"X14",
	"X15",
	"X16",
	"X17",
	"X18",
	"X19",
	"X20",
	"X21",
	"X22",
	"X23",
	"X24",
	"X25",
	"X26",
	"X27",
	"X28",
	"X29",
	"X30",
	"X31",
};

etiss::instr::InstructionGroup ISA16_RV32IMACFDK("ISA16_RV32IMACFDK", 16);
etiss::instr::InstructionClass ISA16_RV32IMACFDKClass(1, "ISA16_RV32IMACFDK", 16, ISA16_RV32IMACFDK);
etiss::instr::InstructionGroup ISA32_RV32IMACFDK("ISA32_RV32IMACFDK", 32);
etiss::instr::InstructionClass ISA32_RV32IMACFDKClass(1, "ISA32_RV32IMACFDK", 32, ISA32_RV32IMACFDK);
etiss::instr::InstructionGroup ISA48_RV32IMACFDK("ISA48_RV32IMACFDK", 48);
etiss::instr::InstructionClass ISA48_RV32IMACFDKClass(1, "ISA48_RV32IMACFDK", 48, ISA48_RV32IMACFDK);

etiss::instr::InstructionCollection RV32IMACFDKISA("RV32IMACFDKISA", ISA16_RV32IMACFDKClass, ISA32_RV32IMACFDKClass, ISA48_RV32IMACFDKClass);