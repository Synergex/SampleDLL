# SampleDLL<br />
**Created Date:** 11/17/2009<br />
**Last Updated:** 11/17/2009<br />
**Description:** This code sample demonstrates three different use cases for returning values from a DLL routine: 1. Returning a simple integer value 2. Returning a pointer to a data structure 3. Returning a pointer to a pointer to a data structure<br />
**Platforms:** Windows<br />
**Products:** Synergy DBL; DLL API<br />
**Minimum Version:** 9.1.5<br />
**Author:** Chip Camden
<hr>

**Additional Information:**
File included:

sample.dbl Example Synergy/DE program that calls the DLL routines
and processes the returned values.
SampleDLL.sln A Microsoft Visual Studio solution for building the DLL
SampleDLL/*.* Source files for the DLL (see especially SampleDll.(cpp,h))
Release/SampleDLL.dll A 32-bit version of the DLL
x64/Release/SampleDLL.dll A 64-bit version of the DLL

NOTES ON SPECIFIC FUNCTIONS

fnSampleDLL

This function merely returns an integer value.

fnSampleDLLptr

This function returns a pointer to a data structure SAMPLESTRUCT
that is defined in SampleDLL.h and duplicated as sampleStruct in
sample.dll. Note that the C++ routine returns the address of
one of these structures, which MUST BE PERSISTENT. In this case,
we use a static. If the structure were an auto variable, then it
would be released upon return from this routine, which could cause
unpredictable failures.

In the Synergy/DE code, the pointer is dereferenced by registering
a memory handle to the address, and mapping it to the structure
that we have defined to match the structure from the DLL.

fnSampleDLLptrptr

This function returns a pointer to a pointer to the same data
structure. In this case, we must first dereference the returned
pointer to obtain a pointer to the structure. The same rules
apply with regard to the persistence of the items referenced --
in this case, both the structure and the pointer to it must
persist beyond the return from the routine, so statics are used
for both.

On the Synergy/DE side, we register a handle to the returned address,
then treat that handle as referencing an integer value of the size
D_ADDRSIZE (the size of a pointer). This will work for both 32-bit
and 64-bit platforms, because we use D_ADDRSIZE. Then we can take
that value and treat it as a pointer, the same as if it had been
returned by fnSampleDLLptr.

The same principle can be applied to pointers that are returned as
members of a data structure, or a pointer to an array of pointers.
In the latter case, simply increment the pointer to the array by
D_ADDRSIZE to access the next pointer in the array.
