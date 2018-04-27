MOUSEKEY_ENABLE = yes
TAP_DANCE_ENABLE = yes
CONSOLE_ENABLE=yes

KEYLOGGER_ENABLE = yes
AUTOLOG_ENABLE ?= yes

BOOTMAGIC_ENABLE = yes
DEBUG_ENABLE = yes
COMMAND_ENABLE = yes# Commands for debug and configuration

ifndef QUANTUM_DIR
  include ../../../../Makefile
endif
