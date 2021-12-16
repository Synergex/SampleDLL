// SampleDLL.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "SampleDLL.h"

static SAMPLESTRUCT s_sampleStruct = {"forty-two", 42, {'f','o','r','t','y','-','t','w','o',0}};
static SAMPLESTRUCT *s_sampleStructPtr = &s_sampleStruct; 

// This is an example of an exported function.
SAMPLEDLL_API int fnSampleDLL(void)
{
	return 42;
}

SAMPLEDLL_API SAMPLESTRUCT *fnSampleDLLptr(void)
{
	return s_sampleStructPtr;
}

SAMPLEDLL_API SAMPLESTRUCT **fnSampleDLLptrptr(void)
{
	return &s_sampleStructPtr;
}