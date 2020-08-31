#include <stdio.h>
#include <intrin.h>

int main(){
	int cpuinfo[4];

	__cpuid(cpuinfo, 1);

	printf("MMX: %d\n", cpuinfo[3] >> 23 & 1);
	printf("SSE: %d\n", cpuinfo[3] >> 25 & 1);
	printf("SSE2: %d\n", cpuinfo[3] >> 26 & 1 && cpuinfo[3] >> 19 & 1);
	printf("SSE3: %d\n", cpuinfo[2] & 1 && cpuinfo[2] >> 3 & 1);
	printf("SSSE3: %d\n", cpuinfo[2] >> 9 & 1);
	printf("SSE4.1: %d\n", cpuinfo[2] >> 19 & 1);
	printf("SSE4.2: %d\n", cpuinfo[2] >> 20 & 1 && cpuinfo[2] >> 23 & 1);
	printf("AVX: %d\n", cpuinfo[2] >> 28 & 1);
	printf("VMX: %d\n", cpuinfo[2] >> 5 & 1);
	printf("SMX: %d\n", cpuinfo[2] >> 6 & 1);
	printf("EIST: %d\n", cpuinfo[2] >> 7 & 1);
	printf("TM2: %d\n", cpuinfo[2] >> 8 & 1 && cpuinfo[3] >> 29 & 1);
	printf("FMA3: %d\n", cpuinfo[2] >> 12 & 1);
	printf("AES: %d\n", cpuinfo[2] >> 25 & 1);
	printf("FPU: %d\n", cpuinfo[3] >> 0 & 1);
	printf("VME: %d\n", cpuinfo[3] >> 1 & 1);
	printf("PSE: %d\n", cpuinfo[3] >> 3 & 1);
	printf("TSC: %d\n", cpuinfo[3] >> 4 & 1);
	printf("MSR: %d\n", cpuinfo[3] >> 5 & 1);
	printf("PAE: %d\n", cpuinfo[3] >> 6 & 1);
	printf("MCE: %d\n", cpuinfo[3] >> 7 & 1);
	printf("APIC: %d\n", cpuinfo[3] >> 9 & 1);
	printf("MTRR: %d\n", cpuinfo[3] >> 12 & 1);
	printf("PGE: %d\n", cpuinfo[3] >> 13 & 1);
	printf("MCA: %d\n", cpuinfo[3] >> 14 & 1);
	printf("CMOV: %d\n", cpuinfo[3] >> 15 & 1);
	printf("PSE-36: %d\n", cpuinfo[3] >> 17 & 1);
	printf("Self-Snoop: %d\n", cpuinfo[3] >> 27 & 1);
	printf("PBE: %d\n", cpuinfo[3] >> 31 & 1);

	__cpuid(cpuinfo, 7);

	printf("AVX2: %d\n", cpuinfo[1] >> 5 & 1);

	__cpuid(cpuinfo, 0x80000001);

	printf("MMX+: %d\n", cpuinfo[3] >> 22 & 1);
	printf("3DNow!: %d\n", cpuinfo[3] >> 31 & 1);
	printf("Extended 3DNow!: %d", cpuinfo[3] >> 30 & 1);
}