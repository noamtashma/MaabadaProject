#include "buffer.h"

#define A 0 /* absolute */
#define E 1 /* external */
#define R 2 /* relocatable */

char *opcodes[16] = 
{"mov"
,"cmp"
,"add"
,"sub"
,"not"
,"clr"
,"lea"
,"inc"
,"dec"
,"jmp"
,"bne"
,"red"
,"prn"
,"jsr"
,"rts"
,"stop"};

typedef struct {
	int group :2; /* the amount of operands for this instruction */
	int opcode:4;
	int source:2; /* source operand */
	int target:2; /* target operand */
	int mode  :2; /* E/R/A */
} instr_h; /* the instruction header - the first word of each instruction */
	
int get_opcode() {
  int i;
  for(i = 0;i < 16;i++) {
    int j;
    for (j = 0;opcodes[i][j];j++) {
      int c = getc();
      if (c != opcodes[i][j])
      {
	ungetc(c);
	for (j-- ; j >= 0; j--)
	  ungetc(opcodes[i][j]);
	break;
      }
    }
    if (j != -1) /* if parsing succeeded */
      return i;
  }
  puts("unrecognized opcode");
  return -1;
}

void main(void) {
  puts("abc");
}
