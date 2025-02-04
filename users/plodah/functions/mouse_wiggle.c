#if defined(PLODAH_MSWIGGLE_ENABLE)

  #define PLODAH_MSWIGGLE_TIMEOUT 200
  #define PLODAH_MSWIGGLE_DEBOUNCE 25
  #define PLODAH_MSWIGGLE_COOLDOWN 1000
  #define PLODAH_MSWIGGLE_WIGGLES 5

  uint8_t countMwShakeX = 0;
  bool lastMwDirecX = false;
  uint16_t lastMwShakeX  = 0;
  uint16_t lastMwSwitch = 0;

  void plodah_wigglereset(void){
    countMwShakeX = 0;
    lastMwShakeX  = 0;
  }

  int plodah_wigglecheck(report_mouse_t mouse_report) {

    if( timer_read() > lastMwSwitch + PLODAH_MSWIGGLE_COOLDOWN ) {
      if ( timer_read() > lastMwShakeX + PLODAH_MSWIGGLE_TIMEOUT ) {
          countMwShakeX = 0;
      }
      if (timer_read() > lastMwShakeX + PLODAH_MSWIGGLE_DEBOUNCE){
        if( abs(mouse_report.x) > abs(mouse_report.y) && abs(mouse_report.y) < 1 ){
          if( mouse_report.x >= 1 && !lastMwDirecX) {
              countMwShakeX++;
              lastMwShakeX = timer_read();
              lastMwDirecX = !lastMwDirecX;
          }

          if( mouse_report.x <= -1 && lastMwDirecX) {
              countMwShakeX++;
              lastMwShakeX = timer_read();
              lastMwDirecX = !lastMwDirecX;
          }
        }
      }

      if( countMwShakeX > PLODAH_MSWIGGLE_WIGGLES ) {
          countMwShakeX = 0;
          lastMwSwitch = timer_read();
          return 1;
      }

    }
    return 0;
  }

#endif
