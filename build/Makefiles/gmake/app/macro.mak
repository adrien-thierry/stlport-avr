# Time-stamp: <03/07/15 17:54:22 ptr>
# $Id$

PRG        := $(OUTPUT_DIR)/${PRGNAME}${EXE}
PRG_DBG    := $(OUTPUT_DIR_DBG)/${PRGNAME}${EXE}
PRG_STLDBG := $(OUTPUT_DIR_STLDBG)/${PRGNAME}${EXE}

PRG_A        := $(OUTPUT_DIR_A)/${PRGNAME}_static${EXE}
PRG_A_DBG    := $(OUTPUT_DIR_A_DBG)/${PRGNAME}_static${EXE}
PRG_A_STLDBG := $(OUTPUT_DIR_A_STLDBG)/${PRGNAME}_static${EXE}

LDFLAGS += ${LDSEARCH}