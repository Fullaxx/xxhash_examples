#!/bin/bash

set -e

# we can do this or compile xxhash.c
# XXHDEFS="-DXXH_STATIC_LINKING_ONLY -DXXH_IMPLEMENTATION"

EXENAME="xxtest"
CFLAGS="-Wall -ansi ${XXHDEFS}"
OPTCFLAGS="${CFLAGS} -O2"
DBGCFLAGS="${CFLAGS} -ggdb3 -DDEBUG"

rm -f *.exe *.dbg

gcc ${OPTCFLAGS} *.c -o ${EXENAME}.exe
gcc ${DBGCFLAGS} *.c -o ${EXENAME}.dbg
