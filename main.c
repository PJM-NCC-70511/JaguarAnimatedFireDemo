#include <jagdefs.h>
#include <jagtypes.h>

#include <stdlib.h>

#include <interrupt.h>
#include <display.h>
#include <sprite.h>

#include <screen.h>

#include <joypad.h>

#include <console.h>

extern phrase color_palette;
extern phrase sprite_fire0;

#define SPRITEW 64
#define SPRITEH 64

#define ANIM_FIRE_LENGTH 9

extern phrase *fire_animation[ANIM_FIRE_LENGTH];


#define WIDTH 320
#define HEIGHT 200

/* 
    Animate Fire Demo using custom variable to control the frames.    
*/

int main(int argc, char *argv[]) {
  TOMREGS->vmode = RGB16|CSYNC|BGEN|PWIDTH4|VIDEN;
  init_interrupts();
  init_display_driver();
  display *d = new_display(0);
  d->x = 16;
  d->y = 16;


    //load color palette
    memcpy((void *)TOMREGS->clut1, &color_palette, 256*sizeof(uint16_t));
    FILE *console = open_console(d, 0, HEIGHT, 4);
    fprintf(console, "Animated Fire Demo\n");    
  
  
  // Normal Fire Animation
  sprite *s01 = new_sprite(SPRITEW,SPRITEH,0,64,DEPTH16,&sprite_fire0);
  attach_sprite_to_display_at_layer(s01, d, 0);
  // Reverse Frame Fire Animation
  sprite *s02 = new_sprite(SPRITEW,SPRITEH,66,64,DEPTH16,&sprite_fire0);
  attach_sprite_to_display_at_layer(s02, d, 0);
  // Mirror Fire Animation, Set the reflect flag, add width to x position
  sprite *s03 = new_sprite(SPRITEW,SPRITEH,132+SPRITEW-1,64,DEPTH16,&sprite_fire0);
  attach_sprite_to_display_at_layer(s03, d, 0);
  s03->reflect = 1;
  // Zoom Fire Animation. Set the scaled flag.
  sprite *s04 = new_sprite(SPRITEW,SPRITEH,198,64,DEPTH16,&sprite_fire0);
  attach_sprite_to_display_at_layer(s04, d, 0);
  s04->scaled = 1;  
  show_display(d);    

  //Variable for the frame index
  int aframe = 0;
  
  while(1) {
    vsync();
    aframe++;
    // When the animated frame index exceeds number of frame, reset to 0
    if (aframe>ANIM_FIRE_LENGTH) {
    aframe=0;
    }
    s01->data = fire_animation[aframe];
    //Subtract Frame Number from Length of Array to animate in reverse order
    s02->data = fire_animation[ANIM_FIRE_LENGTH-aframe];
    s03->data = fire_animation[aframe];
    s04->data = fire_animation[aframe];

    s04->vscale = 0b01000000;
    s04->hscale = 0b01000000;
  }
}


