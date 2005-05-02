# -*- makefile -*- Time-stamp: 
# $Id: macro.mak

!message build\Makefiles\borland\lib\macro.mak

RELEASE_SUFFIX = rr
DBG_SUFFIX     = dr
STLDBG_SUFFIX  = dd

# Shared libraries:

SO_NAME             = $(LIBNAME)_$(COMPILER_NAME)_s$(RELEASE_SUFFIX).$(SO)
LIB_NAME            = $(LIBNAME)_$(COMPILER_NAME)_s$(RELEASE_SUFFIX).$(LIB)

SO_NAME_OUT         = $(OUTPUT_DIR)\$(SO_NAME)
LIB_NAME_OUT        = $(OUTPUT_DIR)\$(LIB_NAME)

SO_NAME_DBG         = $(LIBNAME)_$(COMPILER_NAME)_s$(DBG_SUFFIX).$(SO)
LIB_NAME_DBG        = $(LIBNAME)_$(COMPILER_NAME)_s$(DBG_SUFFIX).$(LIB)

SO_NAME_OUT_DBG     = $(OUTPUT_DIR_DBG)\$(SO_NAME_DBG)
LIB_NAME_OUT_DBG    = $(OUTPUT_DIR_DBG)\$(LIB_NAME_DBG)

SO_NAME_STLDBG      = $(LIBNAME)_$(COMPILER_NAME)_s$(STLDBG_SUFFIX).$(SO)
LIB_NAME_STLDBG     = $(LIBNAME)_$(COMPILER_NAME)_s$(STLDBG_SUFFIX).$(LIB)

SO_NAME_OUT_STLDBG  = $(OUTPUT_DIR_STLDBG)\$(SO_NAME_STLDBG)
LIB_NAME_OUT_STLDBG = $(OUTPUT_DIR_STLDBG)\$(LIB_NAME_STLDBG)


# Static libraries:

A_NAME              = $(LIBNAME)_$(COMPILER_NAME)_a$(RELEASE_SUFFIX).$(ARCH)
A_NAME_OUT          = $(OUTPUT_DIR_A)\$(A_NAME)

A_NAME_DBG          = $(LIBNAME)_$(COMPILER_NAME)_a$(DBG_SUFFIX).$(ARCH)
A_NAME_OUT_DBG      = $(OUTPUT_DIR_A_DBG)\$(A_NAME_DBG)

A_NAME_STLDBG       = $(LIBNAME)_$(COMPILER_NAME)_a$(STLDBG_SUFFIX).$(ARCH)
A_NAME_OUT_STLDBG   = $(OUTPUT_DIR_A_STLDBG)\$(A_NAME_STLDBG)
