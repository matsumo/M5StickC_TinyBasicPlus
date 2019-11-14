Tiny Basic Plus for M5StickC and CardKB HAT
==============

A C implementation of Tiny Basic, with a focus on support for
Arduino.  It was originally written by Gordon Brandly in the form
of "68000 Tiny Basic", and then ported to C by Michael Field as
"Arduino Basic", though still called "Tiny Basic" in the source
files.

TinyBasic Plus is an extension and modification upon the original
"Tiny Basic" by adding support for a few more devices, configurable
at build time.  It is designed for use on the Arduino, although
builds will soon be easily possible for other platforms through
command line makefiles.  Provided is a makefile that builds for 
unix-ey type OSes.  It has only been tested for Darwin (OS X).

Features added include support for fileio (SPIFFS Library), autorunning
a program from the SPIFFS, support for keyboard (CardKB HAT), smaller
 footprint (PROGMEM), support for pin data IO for yourprogram. 



# Authors and Contributors

- Tiny Basic 68k - Gordon Brandly [Project Page (via archive.org)](https://web.archive.org/web/20170306113457/http://members.shaw.ca:80/gbrandly/68ktinyb.html)
- Arduino Basic / Tiny Basic C - Michael Field [Project Page](http://hamsterworks.co.nz/mediawiki/index.php/Arduino_Basic)
- Tiny Basic Plus - Scott Lawrence <yorgle@gmail.com> [Github Page](http://github.com/BleuLlama/TinyBasicPlus)
- M5Stack TinyBasicPlus - 0x1abin [Github Page](https://github.com/0x1abin/M5Stack_TinyBasicPlus)




# Licensing

Mike Field based his C port of Tiny Basic on the 68000 Tiny BASIC which carried 
the following license:

~~~
******************************************************************
*                                                                *
*               Tiny BASIC for the Motorola MC68000              *
*                                                                *
* Derived from Palo Alto Tiny BASIC as published in the May 1976 *
* issue of Dr. Dobb's Journal.  Adapted to the 68000 by:         *
*       Gordon Brandly                                           *
*       12147 - 51 Street                                        *
*       Edmonton AB  T5W 3G8                                     *
*       Canada                                                   *
*       (updated mailing address for 1996)                       *
*                                                                *
* This version is for MEX68KECB Educational Computer Board I/O.  *
*                                                                *
******************************************************************
*    Copyright (C) 1984 by Gordon Brandly. This program may be   *
*    freely distributed for personal use only. All commercial    *
*                      rights are reserved.                      *
******************************************************************
~~~

