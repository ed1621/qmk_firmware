SRC += ed1621.c

ifeq ($(strip $(COMBO_ENABLE)), yes)
	SRC += ed1621_COMBO.c
endif

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
	SRC += ed1621_TAPDANCES.c
endif

ifeq ($(strip $(BONGO_CAT_ENABLE)), yes)
	SRC += ed1621_bongo_cat.c
endif

CUSTOM_OLED_DRIVER ?= yes
ifeq ($(strip $(OLED_DRIVER_ENABLE)), yes)
    ifeq ($(strip $(CUSTOM_OLED_DRIVER)), yes)
        SRC += ed1621_OLED.c
    endif
endif


SRC += ed1621_KEYCODES.c \
		ed1621_MATRIX.c \
