
/*************************************************************
  This sketch implements a simple serial receive terminal
  program for monitoring serial debug messages from another
  board.
  
  Connect GND to target board GND
  Connect RX line to TX line of target board
  Make sure the target and terminal have the same baud rate
  and serial stettings!

  The sketch works with the ILI9341 TFT 240x320 display and
  the called up libraries.
  
  The sketch uses the hardware scrolling feature of the
  display. Modification of this sketch may lead to problems
  unless the ILI9341 data sheet has been understood!

  Updated by Bodmer 21/12/16 for TFT_eSPI library:
  https://github.com/Bodmer/TFT_eSPI
  
  BSD license applies, all text above must be included in any
  redistribution
 *************************************************************/

#include <M5StickC.h>

#define TEXT_WIDTH 6 // Width of text to be printed and scrolled
#define TEXT_HEIGHT 8 // Height of text to be printed and scrolled
#define YMAX 80 // Bottom of screen area
#define XMAX 156

#define YCHAR (YMAX / TEXT_HEIGHT)
#define XCHAR (XMAX / TEXT_WIDTH)

unsigned char vram[YCHAR][XCHAR];

uint16_t yDraw = 0;

// Keep track of the drawing x coordinate
uint16_t xPos = 0;


void termInit() {
  // Setup the TFT display
  // M5.begin();
  M5.Axp.ScreenBreath(8);   // screen brightness (7-15)
  M5.Lcd.setRotation(3);
  M5.Lcd.setTextFont(1);    // Adafruit 8pixel ASCII font
  M5.Lcd.fillScreen(TFT_BLACK);
  
  // Setup baud rate and draw top banner
  // Serial.begin(115200);
  
  // M5.Lcd.setTextColor(TFT_WHITE, TFT_BLUE);
  // M5.Lcd.fillRect(0,0,320,TEXT_HEIGHT, TFT_BLUE);
  // M5.Lcd.drawCentreString(" Serial Terminal - 115200 baud ",320/2,0,2);

  // Change colour for scrolling zone text
  M5.Lcd.setTextColor(TFT_WHITE, TFT_BLACK);

  // Zero the array
  memset(vram, XCHAR * YCHAR, 0);
}


void termPutchar(unsigned char data) {
  //  These lines change the text colour when the serial buffer is emptied
  //  These are test lines to see if we may be losing characters
  //  Also uncomment the change_colour line below to try them
  //
  //  if (change_colour){
  //  change_colour = 0;
  //  if (selected == 1) {M5.Lcd.setTextColor(TFT_CYAN, TFT_BLACK); selected = 0;}
  //  else {M5.Lcd.setTextColor(TFT_MAGENTA, TFT_BLACK); selected = 1;}
  //}

  // while (Serial.available()) 
  {
    // data = Serial.read();
    // If it is a CR or we are near end of line then scroll one line
    if (data == '\r' || xPos>=XCHAR) {
      xPos = 0;
      yDraw = scroll_line(); // It can take 13ms to scroll and blank 16 pixel lines
    }
    if(data == '\b' && xPos > 0){
      xPos--;
    }
    if (data > 31 && data < 128) {
      vram[yDraw][xPos] = data;
      M5.Lcd.drawChar(data, xPos * TEXT_WIDTH, yDraw * TEXT_HEIGHT);
      xPos ++;
    }
    //change_colour = 1; // Line to indicate buffer is being emptied
  }
}

void printString(unsigned char *str)
{
  while(*str) termPutchar(*str++);
}

// ##############################################################################################
// Call this function to scroll the display one text line
// ##############################################################################################
int scroll_line() {
  if(yDraw < (YCHAR-1)){
    return yDraw+1;
  }else{
    memcpy(vram, &vram[1][0], XCHAR * (YCHAR - 1));
    memset(&vram[YCHAR - 1][0], 0, XCHAR);
    M5.Lcd.fillScreen(TFT_BLACK);
    for(int y=0; y<YCHAR; y++){
      for(int x=0; x<XCHAR; x++){
        if(vram[y][x] > 31 && vram[y][x] < 128) M5.Lcd.drawChar(vram[y][x], x * TEXT_WIDTH, y * TEXT_HEIGHT);
      }
    }
    return YCHAR-1;
  }
}
