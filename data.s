        .data
     .globl	_color_palette
     .phrase       
  _color_palette:
	incbin  "a256.pal"
    
	.globl	_sprite_fire0
	.phrase
_sprite_fire0:
	incbin	"fire0.rgb" 
	.phrase
_sprite_fire1:
	incbin	"fire1.rgb" 
	.phrase
_sprite_fire2:
	incbin	"fire2.rgb" 
	.phrase
_sprite_fire3:
	incbin	"fire3.rgb" 
	.phrase
_sprite_fire4:
	incbin	"fire4.rgb" 
	.phrase
_sprite_fire5:
	incbin	"fire5.rgb" 
	.phrase
_sprite_fire6:
	incbin	"fire6.rgb" 
	.phrase
_sprite_fire7:
	incbin	"fire7.rgb" 
	.phrase
_sprite_fire8:
	incbin	"fire8.rgb" 
	.phrase
_sprite_fire9:
	incbin	"fire9.rgb" 

        
	.globl	_fire_animation
    .long
_fire_animation:   
    dc.l	_sprite_fire0
    dc.l	_sprite_fire1
    dc.l	_sprite_fire2
    dc.l	_sprite_fire3
    dc.l	_sprite_fire4
    dc.l	_sprite_fire5
    dc.l	_sprite_fire6
    dc.l	_sprite_fire7
    dc.l	_sprite_fire8
    dc.l	_sprite_fire9
        
