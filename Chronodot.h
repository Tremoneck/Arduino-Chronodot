// Code by JeeLabs http://news.jeelabs.org/code/
// Released to the public domain! Enjoy!
//
// Modified for Chronodot / DS3132 with 
//   temperature data by Stephanie Maks
//   http://planetstephanie.net/

#ifndef CHRONODOT_H
#define CHRONODOT_H

// Simple general-purpose date/time class (no TZ / DST / leap second handling!)
class DateTime {
public:
    DateTime (uint32_t t =0);
    DateTime (uint16_t year, uint8_t month, uint8_t day,
                uint8_t hour =0, uint8_t min =0, uint8_t sec =0);
    DateTime (const char* date, const char* time);
    uint16_t year() const       { return yOff; }
    uint8_t month() const       { return m; }
    uint8_t day() const         { return d; }
    uint8_t hour() const        { return hh; }
    uint8_t minute() const      { return mm; }
    uint8_t second() const      { return ss; }
    uint8_t dayOfWeek() const;

    // 32-bit times as seconds since 1/1/2000
    long secondstime() const;   

protected:
    uint8_t yOff, m, d, hh, mm, ss;
};

// Chronodot based on the DS3231 chip connected via I2C and the Wire library
class Chronodot {
public:
  static uint8_t begin(void);
    static void adjust(const DateTime& dt);
    uint8_t isrunning(void);
    static DateTime now();
	static int16_t getTemperatur();
};
#endif CHRONODOT_H