SRC += ed1621.c

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


SRC += keycodes.c \
			 matrix.c