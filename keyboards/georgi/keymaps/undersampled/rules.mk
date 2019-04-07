#----------------------------------------------------------------------------
# make georgi:undersampled:dfu
# Make sure you have dfu-programmer installed!
#----------------------------------------------------------------------------

#Debug options
NO_REPEAT              = no
VERBOSE                = yes
KEYBOARD_SHARED_EP     = yes

#Build options
CUSTOM_MATRIX          = yes
MOUSEKEY_ENABLE        = no
MIDI_ENABLE            = yes
NKRO_ENABLE            = yes
STENO_ENABLE           = no

#debug/fw size options
CONSOLE_ENABLE         = no
DEBUG_MATRIX_SCAN_RATE = no
DEBUG_MATRIX           = no
NO_PRINT               = yes

# A bunch of stuff that you shouldn't touch unless you
# know what you're doing.
#
# No touchy, capiche?
SRC += matrix.c i2c_master.c
ifeq ($(strip $(DEBUG_MATRIX)), yes)
    OPT_DEFS += -DDEBUG_MATRIX
endif
ifeq ($(strip $(NO_REPEAT)), yes)
    OPT_DEFS += -DNO_REPEAT
endif
ifeq ($(strip $(NO_PRINT)), yes)
    OPT_DEFS += -DNO_PRINT
endif
