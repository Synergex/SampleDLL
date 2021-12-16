// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the SAMPLEDLL_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// SAMPLEDLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef SAMPLEDLL_EXPORTS
#define SAMPLEDLL_API __declspec(dllexport)
#else
#define SAMPLEDLL_API __declspec(dllimport)
#endif

typedef struct {
	char *strval;
	int intval;
	char charval[10];
} SAMPLESTRUCT;

extern "C" {
SAMPLEDLL_API int fnSampleDLL(void);
SAMPLEDLL_API SAMPLESTRUCT *fnSampleDLLptr(void);
SAMPLEDLL_API SAMPLESTRUCT **fnSampleDLLptrptr(void);
}