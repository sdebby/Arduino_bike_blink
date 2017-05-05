# Arduino_bike_blink
Arduino nano with RGB led strips operated by RF control.
This project made for rear signaling when riding a bike.

This project uses:
* Arduino nano v3.0
* 4 channel RC controller HG-208GV (Ebay:http://www.ebay.com/itm/302026064369?_trksid=p2057872.m2749.l2649&ssPageName=STRK%3AMEBIDX%3AIT )
* RGB led strip: (Ebay: http://www.ebay.com/itm/5M-30LED-M-WS2812B-5050-RGB-LED-Strip-Light-Non-Waterproof-AddrKGsable-/252915006533?hash=item3ae2e8bc45:g:co0AAOSwT-FZCDmO )
* breadboard.
* small LED.
* Resistors

Using Neopixel librery: 
https://learn.adafruit.com/adafruit-neopixel-uberguide/neomatrix-library

** When connecting to power bank USB charger, the PowerBankPresent value needed to be true- so it will keep the LED pin on HIGH, otherwise the power bank charger will stop working.
