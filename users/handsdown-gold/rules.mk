SRC += handsdown-gold.c \
			 keycodes.c \
			 matrix.c

ifeq ($(strip $(COMBO_ENABLE)), yes)
	SRC += combo.c
endif

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
	SRC += tapdances.c
endif

ifeq ($(strip $(BONGO_CAT_ENABLE)), yes)
	SRC += bongo_cat.c
endif

CUSTOM_OLED_DRIVER ?= yes
ifeq ($(strip $(OLED_DRIVER_ENABLE)), yes)
    ifeq ($(strip $(CUSTOM_OLED_DRIVER)), yes)
        SRC += oled.c
    endif
endif


