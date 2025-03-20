/**
 * Generated on Thu, 27 Feb 2025 14:13:34 +0100.
 *
 * This file contains the function implementations for the RV32IMACFDK core architecture.
 */

#include "RV32IMACFDKFuncs.h"

etiss_uint8 RV32IMACFDK_extension_enabled(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int8 extension)
{
{ // block
return (*((RV32IMACFDK*)cpu)->CSR[769LL] >> (extension - 65ULL)) & 1ULL;
} // block
}

etiss_uint8 RV32IMACFDK_get_rm(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint8 rm)
{
{ // block
if (rm == 7ULL) { // conditional
rm = ((((((RV32IMACFDK*)cpu)->FCSR) >> (5ULL)) & 7ULL)) & 0x7;
} // conditional
if (rm > 4ULL) { // conditional
RV32IMACFDK_raise(cpu, system, plugin_pointers, 0LL, 2LL);
} // conditional
return rm;
} // block
}

etiss_uint32 RV32IMACFDK_sstatus_mask(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
{ // block
etiss_uint32 mask = 0LL;
if (RV32IMACFDK_extension_enabled(cpu, system, plugin_pointers, 83ULL)) { // conditional
{ // block
mask = mask | 5767458ULL;
if (RV32IMACFDK_extension_enabled(cpu, system, plugin_pointers, 86ULL)) { // conditional
mask = mask | 1536LL;
} // conditional
if (RV32IMACFDK_extension_enabled(cpu, system, plugin_pointers, 70ULL)) { // conditional
mask = mask | 24576LL;
} // conditional
if (RV32IMACFDK_extension_enabled(cpu, system, plugin_pointers, 88ULL)) { // conditional
mask = mask | 98304LL;
} // conditional
if ((RV32IMACFDK_get_field(*((RV32IMACFDK*)cpu)->CSR[384LL], 2147483648ULL))) { // conditional
mask = mask | 262144LL;
} // conditional
} // block
} // conditional
return mask;
} // block
}

etiss_uint32 RV32IMACFDK_mstatus_mask(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
{ // block
etiss_uint32 mask = 6280ULL;
return mask | RV32IMACFDK_sstatus_mask(cpu, system, plugin_pointers);
} // block
}

etiss_uint32 RV32IMACFDK_csr_read(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr)
{
{ // block
if (csr == 1LL) { // conditional
return *((RV32IMACFDK*)cpu)->CSR[3LL] & 31ULL;
} // conditional
if (csr == 2LL) { // conditional
return (*((RV32IMACFDK*)cpu)->CSR[3LL] >> 5ULL) & 7ULL;
} // conditional
if (csr == 3072LL) { // conditional
return etiss_get_cycles(cpu, system, plugin_pointers);
} // conditional
if (csr == 3200LL) { // conditional
return etiss_get_cycles(cpu, system, plugin_pointers) >> 32ULL;
} // conditional
if (csr == 3073LL) { // conditional
return etiss_get_time();
} // conditional
if (csr == 3201LL) { // conditional
return etiss_get_time() >> 32ULL;
} // conditional
if (csr == 3074LL) { // conditional
return etiss_get_instret(cpu, system, plugin_pointers);
} // conditional
if (csr == 3202LL) { // conditional
return etiss_get_instret(cpu, system, plugin_pointers) >> 32ULL;
} // conditional
if (csr == 768LL || csr == 256LL) { // conditional
return *((RV32IMACFDK*)cpu)->CSR[768LL] | 8589934592ULL | 34359738368ULL;
} // conditional
if (csr == 769LL) { // conditional
return (((1ULL) << 30) | ((((*((RV32IMACFDK*)cpu)->CSR[769LL]) >> (0LL)) & 1073741823ULL)));
} // conditional
return *((RV32IMACFDK*)cpu)->CSR[csr];
} // block
}

void RV32IMACFDK_csr_write(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr, etiss_uint32 val)
{
{ // block
if (csr == 1LL) { // conditional
*((RV32IMACFDK*)cpu)->CSR[3LL] = (*((RV32IMACFDK*)cpu)->CSR[3LL] & 224ULL) | (val & 31ULL);
} // conditional
 else if (csr == 2LL) { // conditional
*((RV32IMACFDK*)cpu)->CSR[3LL] = ((val & 7ULL) << 5ULL) | (*((RV32IMACFDK*)cpu)->CSR[3LL] & 31ULL);
} // conditional
 else if (csr == 3LL) { // conditional
*((RV32IMACFDK*)cpu)->CSR[3LL] = val & 255ULL;
} // conditional
 else if (csr == 768LL) { // conditional
*((RV32IMACFDK*)cpu)->CSR[768LL] = val & RV32IMACFDK_mstatus_mask(cpu, system, plugin_pointers);
} // conditional
 else if (csr == 256LL) { // conditional
*((RV32IMACFDK*)cpu)->CSR[768LL] = val & RV32IMACFDK_sstatus_mask(cpu, system, plugin_pointers);
} // conditional
 else if (csr != 769LL) { // conditional
*((RV32IMACFDK*)cpu)->CSR[csr] = val;
} // conditional
} // block
}

etiss_uint64 RV32IMACFDK_get_field(etiss_uint64 reg, etiss_uint64 mask)
{
{ // block
if (!(mask)) { // conditional
return 0LL;
} // conditional
return (reg & mask) / (mask & ~((mask << 1ULL)));
} // block
}

etiss_uint64 RV32IMACFDK_set_field(etiss_uint64 reg, etiss_uint64 mask, etiss_uint64 val)
{
{ // block
return ((reg & ~(mask)) | ((val * (mask & ~((mask << 1ULL)))) & mask));
} // block
}

etiss_uint8 RV32IMACFDK_ctz(etiss_uint64 val)
{
{ // block
if (!(val)) { // conditional
return 0LL;
} // conditional
etiss_uint8 res = 0LL;
if ((val << 32ULL) == 0LL) { // conditional
{ // block
res = res + 32ULL;
val = val >> 32ULL;
} // block
} // conditional
if ((val << 48ULL) == 0LL) { // conditional
{ // block
res = res + 16ULL;
val = val >> 16ULL;
} // block
} // conditional
if ((val << 56ULL) == 0LL) { // conditional
{ // block
res = res + 8ULL;
val = val >> 8ULL;
} // block
} // conditional
if ((val << 60ULL) == 0LL) { // conditional
{ // block
res = res + 4ULL;
val = val >> 4ULL;
} // block
} // conditional
if ((val << 62ULL) == 0LL) { // conditional
{ // block
res = res + 2ULL;
val = val >> 2ULL;
} // block
} // conditional
if ((val << 63ULL) == 0LL) { // conditional
{ // block
res = res + 1ULL;
val = val >> 1ULL;
} // block
} // conditional
return res;
} // block
}

void RV32IMACFDK_raise(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int32 irq, etiss_uint32 mcause)
{
cpu->return_pending = 1;
cpu->exception = 0;
{ // block
etiss_uint32 epc = cpu->instructionPointer;
etiss_uint32 deleg = 0LL;
etiss_uint32 vector = 0LL;
etiss_uint32 bit = mcause;
etiss_int32 irq2 = (mcause & 2147483648ULL) != 0LL;
if (irq2) { // conditional
{ // block
deleg = ((((RV32IMACFDK*)cpu)->PRIV <= 1LL)) ? (*((RV32IMACFDK*)cpu)->CSR[771LL]) : (0LL);
bit = bit & 2147483647ULL;
} // block
} // conditional
else { // conditional
{ // block
deleg = ((((RV32IMACFDK*)cpu)->PRIV <= 1LL)) ? (*((RV32IMACFDK*)cpu)->CSR[770LL]) : (0LL);
} // block
} // conditional
if (((RV32IMACFDK*)cpu)->PRIV <= 1LL && (deleg >> bit) & 1ULL) { // conditional
{ // block
vector = ((*((RV32IMACFDK*)cpu)->CSR[261LL] & 1ULL) && irq2) ? (bit * 4ULL) : (0LL);
cpu->nextPc = (*((RV32IMACFDK*)cpu)->CSR[261LL] & -2LL) + vector;
*((RV32IMACFDK*)cpu)->CSR[321LL] = epc;
*((RV32IMACFDK*)cpu)->CSR[322LL] = mcause;
etiss_uint32 s = RV32IMACFDK_csr_read(cpu, system, plugin_pointers, 256LL);
s = RV32IMACFDK_set_field(s, 32LL, RV32IMACFDK_get_field(s, 2LL));
s = RV32IMACFDK_set_field(s, 256LL, ((RV32IMACFDK*)cpu)->PRIV);
s = RV32IMACFDK_set_field(s, 2LL, 0LL);
RV32IMACFDK_csr_write(cpu, system, plugin_pointers, 256LL, s);
((RV32IMACFDK*)cpu)->PRIV = (1LL) & 0x7;
} // block
} // conditional
else { // conditional
{ // block
vector = ((*((RV32IMACFDK*)cpu)->CSR[773LL] & 1ULL) && irq2) ? (bit * 4ULL) : (0LL);
cpu->nextPc = (*((RV32IMACFDK*)cpu)->CSR[773LL] & -2LL) + vector;
*((RV32IMACFDK*)cpu)->CSR[833LL] = epc;
*((RV32IMACFDK*)cpu)->CSR[834LL] = mcause;
etiss_uint32 s = RV32IMACFDK_csr_read(cpu, system, plugin_pointers, 768LL);
s = RV32IMACFDK_set_field(s, 128LL, RV32IMACFDK_get_field(s, 8LL));
s = RV32IMACFDK_set_field(s, 6144LL, ((RV32IMACFDK*)cpu)->PRIV);
s = RV32IMACFDK_set_field(s, 8LL, 0LL);
RV32IMACFDK_csr_write(cpu, system, plugin_pointers, 768LL, s);
((RV32IMACFDK*)cpu)->PRIV = (3LL) & 0x7;
} // block
} // conditional
} // block
}

void RV32IMACFDK_translate_exc_code(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int32 cause)
{
{ // block
etiss_uint32 code = 0LL;
if (cause == -2147483648LL) { // conditional
return;
} // conditional
 else if (cause == -5LL) { // conditional
code = 5LL;
} // conditional
 else if (cause == -14LL) { // conditional
code = 13LL;
} // conditional
 else if (cause == -6LL) { // conditional
code = 7LL;
} // conditional
 else if (cause == -15LL) { // conditional
code = 15LL;
} // conditional
 else if (cause == -7LL) { // conditional
code = 1LL;
} // conditional
 else if (cause == -9LL) { // conditional
{ // block
code = RV32IMACFDK_calc_irq_mcause(cpu, system, plugin_pointers);
if (!(code)) { // conditional
return;
} // conditional
} // block
} // conditional
else { // conditional
code = 2LL;
} // conditional
RV32IMACFDK_raise(cpu, system, plugin_pointers, 0LL, code);
} // block
}

etiss_uint32 RV32IMACFDK_calc_irq_mcause(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
{ // block
etiss_uint32 pending_interrupts = *((RV32IMACFDK*)cpu)->CSR[772LL] & *((RV32IMACFDK*)cpu)->CSR[836LL];
if (!(pending_interrupts)) { // conditional
return 0LL;
} // conditional
etiss_uint32 mie = RV32IMACFDK_get_field(*((RV32IMACFDK*)cpu)->CSR[768LL], 8LL);
etiss_uint32 m_enabled = ((RV32IMACFDK*)cpu)->PRIV < 3LL || (((RV32IMACFDK*)cpu)->PRIV == 3LL && mie);
etiss_uint32 enabled_interrupts = pending_interrupts & ~(*((RV32IMACFDK*)cpu)->CSR[771LL]) & -(m_enabled);
if (enabled_interrupts == 0LL) { // conditional
{ // block
etiss_uint32 deleg = *((RV32IMACFDK*)cpu)->CSR[771LL];
etiss_uint32 sie = RV32IMACFDK_get_field(RV32IMACFDK_csr_read(cpu, system, plugin_pointers, 256LL), 2LL);
etiss_uint32 s_enabled = ((RV32IMACFDK*)cpu)->PRIV < 1LL || (((RV32IMACFDK*)cpu)->PRIV == 1LL && sie);
enabled_interrupts = pending_interrupts & deleg & -(s_enabled);
} // block
} // conditional
if (enabled_interrupts) { // conditional
{ // block
if (enabled_interrupts >> 12ULL) { // conditional
enabled_interrupts = enabled_interrupts >> 12ULL << 12ULL;
} // conditional
 else if (enabled_interrupts & 2048LL) { // conditional
enabled_interrupts = 2048LL;
} // conditional
 else if (enabled_interrupts & 8LL) { // conditional
enabled_interrupts = 8LL;
} // conditional
 else if (enabled_interrupts & 128LL) { // conditional
enabled_interrupts = 128LL;
} // conditional
 else if (enabled_interrupts & 512LL) { // conditional
enabled_interrupts = 512LL;
} // conditional
 else if (enabled_interrupts & 2LL) { // conditional
enabled_interrupts = 2LL;
} // conditional
 else if (enabled_interrupts & 32LL) { // conditional
enabled_interrupts = 32LL;
} // conditional
 else if (enabled_interrupts & 8192LL) { // conditional
enabled_interrupts = 8192LL;
} // conditional
 else if (enabled_interrupts & 1024LL) { // conditional
enabled_interrupts = 1024LL;
} // conditional
 else if (enabled_interrupts & 4LL) { // conditional
enabled_interrupts = 4LL;
} // conditional
 else if (enabled_interrupts & 64LL) { // conditional
enabled_interrupts = 64LL;
} // conditional
else { // conditional
return 0LL;
} // conditional
return 2147483648ULL | RV32IMACFDK_ctz(enabled_interrupts);
} // block
} // conditional
return 0LL;
} // block
}

void RV32IMACFDK_check_irq(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
{ // block
etiss_uint32 irq_mcause = RV32IMACFDK_calc_irq_mcause(cpu, system, plugin_pointers);
if (irq_mcause) { // conditional
RV32IMACFDK_raise(cpu, system, plugin_pointers, 1ULL, irq_mcause);
} // conditional
} // block
}
