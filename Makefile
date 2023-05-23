include	Makefile.config

PROJECT=animatefire
SRCC=main.c
SRCS=data.s
SRCH=
OBJS=$(SRCC:.c=.o) $(SRCS:.s=.o)
OTHEROBJS=
SRCFRAMES=fire0.png fire1.png fire2.png fire3.png
SRCFRAMES+=fire4.png fire5.png fire6.png fire7.png
SRCFRAMES+=fire8.png fire9.png 

RGBFRAMES=$(SRCFRAMES:.png=.rgb)
DATA=ship1.png
DATA+=ship2.png
DATA+=$(SRCFRAMES)
EXTRAS=ship1.rgb ship2.rgb
EXTRAS+=$(RGBFRAMES)
RMVLIBS=display.o interrupt.o rmvlib.a

include Makefile.example

data.o: a256.pal $(RGBFRAMES) 


%.rgb: %.png
	$(CONVERTER) -rgb --binary --overwrite $<
    

