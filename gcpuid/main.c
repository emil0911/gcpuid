#include <stdio.h>
#include <intrin.h>
#define EAX 0
#define EBX 1
#define ECX 2
#define EDX 3

// thanks for https://en.wikipedia.com/wiki/CPUID.

// and thanks to boxmein for sample, that working with CPUID from C.

int main(){
	int cpuinfo[4];

	__cpuid(cpuinfo, 0);

	printf("Brand: %c%c%c%c%c%c%c%c%c%c%c%c\n",
    		cpuinfo[EBX]       & 0xff, 
    		cpuinfo[EBX] >> 8  & 0xff, 
    		cpuinfo[EBX] >> 16 & 0xff, 
    		cpuinfo[EBX] >> 24 & 0xff,
    		cpuinfo[EDX]       & 0xff,
    		cpuinfo[EDX] >> 8  & 0xff,
    		cpuinfo[EDX] >> 16 & 0xff,
    		cpuinfo[EDX] >> 24 & 0xff,
		cpuinfo[ECX]       & 0xff,
    		cpuinfo[ECX] >> 8  & 0xff,
    		cpuinfo[ECX] >> 16 & 0xff,
    		cpuinfo[ECX] >> 24 & 0xff);

	__cpuid(cpuinfo, 1);

	printf("MMX: %d\n", cpuinfo[EDX] >> 23 & 1);
	printf("SSE: %d\n", cpuinfo[EDX] >> 25 & 1);
	printf("SSE2: %d\n", cpuinfo[EDX] >> 26 & 1 && cpuinfo[EDX] >> 19 & 1);
	printf("SSE3: %d\n", cpuinfo[ECX] & 1 && cpuinfo[ECX] >> 3 & 1);
	printf("SSSE3: %d\n", cpuinfo[ECX] >> 9 & 1);
	printf("SSE4.1: %d\n", cpuinfo[ECX] >> 19 & 1);
	printf("SSE4.2: %d\n", cpuinfo[ECX] >> 20 & 1 && cpuinfo[ECX] >> 23 & 1);
	printf("AVX: %d\n", cpuinfo[ECX] >> 28 & 1);
	printf("VMX: %d\n", cpuinfo[ECX] >> 5 & 1);
	printf("SMX: %d\n", cpuinfo[ECX] >> 6 & 1);
	printf("EIST: %d\n", cpuinfo[ECX] >> 7 & 1);
	printf("TM2: %d\n", cpuinfo[ECX] >> 8 & 1 && cpuinfo[EDX] >> 29 & 1);
	printf("FMA3: %d\n", cpuinfo[ECX] >> 12 & 1);
	printf("AES: %d\n", cpuinfo[ECX] >> 25 & 1);
	printf("FPU: %d\n", cpuinfo[EDX] >> 0 & 1);
	printf("VME: %d\n", cpuinfo[EDX] >> 1 & 1);
	printf("PSE: %d\n", cpuinfo[EDX] >> 3 & 1);
	printf("TSC: %d\n", cpuinfo[EDX] >> 4 & 1);
	printf("MSR: %d\n", cpuinfo[EDX] >> 5 & 1);
	printf("PAE: %d\n", cpuinfo[EDX] >> 6 & 1);
	printf("MCE: %d\n", cpuinfo[EDX] >> 7 & 1);
	printf("APIC: %d\n", cpuinfo[EDX] >> 9 & 1);
	printf("MTRR: %d\n", cpuinfo[EDX] >> 12 & 1);
	printf("PGE: %d\n", cpuinfo[EDX] >> 13 & 1);
	printf("MCA: %d\n", cpuinfo[EDX] >> 14 & 1);
	printf("CMOV: %d\n", cpuinfo[EDX] >> 15 & 1);
	printf("PSE-36: %d\n", cpuinfo[EDX] >> 17 & 1);
	printf("Self-Snoop: %d\n", cpuinfo[EDX] >> 27 & 1);
	printf("PBE: %d\n", cpuinfo[EDX] >> 31 & 1);

	__cpuid(cpuinfo, 7);

	printf("AVX2: %d\n", cpuinfo[EBX] >> 5 & 1);
	printf("SHA: %d\n", cpuinfo[EBX] >> 29 & 1 );

	__cpuid(cpuinfo, 0x80000001);

	printf("MMX+: %d\n", cpuinfo[EDX] >> 22 & 1);
	printf("3DNow!: %d\n", cpuinfo[EDX] >> 31 & 1);
	printf("Extended 3DNow!: %d\n", cpuinfo[EDX] >> 30 & 1);
	printf("SSE4A: %d", cpuinfo[ECX] >> 6 & 1);
}
