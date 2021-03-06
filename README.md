# Arduino bike blink project
Arduino nano with 2 RGB led strips, attached to bag pack and operated by 4 channel RF control.
This project made for rear signaling when riding a bike.
![N|Handle image](https://github.com/sdebby/Arduino_bike_blink/blob/master/Images/15.jpg)

The remote control connected to the front handle with Velcro.
![N|Handle image](https://github.com/sdebby/Arduino_bike_blink/blob/master/Images/26.jpg)

# Hardware
* [Arduino nano v3.0](http://www.ebay.com/itm/162002876661?_trksid=p2057872.m2749.l2649&ssPageName=STRK%3AMEBIDX%3AIT)
* 4 channel RC controller HG-208GV [Ebay](http://www.ebay.com/itm/302026064369?_trksid=p2057872.m2749.l2649&ssPageName=STRK%3AMEBIDX%3AIT)
* RGB led strip: [Ebay](http://www.ebay.com/itm/5M-30LED-M-WS2812B-5050-RGB-LED-Strip-Light-Non-Waterproof-AddrKGsable-/252915006533?hash=item3ae2e8bc45:g:co0AAOSwT-FZCDmO)
* breadboard.
* small LED.
* Resistors.
* [Power bank USB battery pack](http://www.ebay.com/itm/5600mAh-Portable-Backup-Power-Bank-Battery-Charger-for-iPhone-6-6s-plus-5s-5c-/251696640957)

# Software
Using Neopixel librery: 
https://learn.adafruit.com/adafruit-neopixel-uberguide/neomatrix-library

# Schematics
![N|Schemaic image](https://github.com/sdebby/Arduino_bike_blink/blob/master/Code/170406%20Bike_Blink_v0_bb.jpg)

# Limitations
** When connecting to power bank USB charger, the PowerBankPresent value needed to be true- so it will keep the LED pin on HIGH, otherwise the power bank charger will stop working.

# Video
[![YT_Video](https://img.youtube.com/vi/kdwFtUYQnUo/0.jpg)](https://www.youtube.com/watch?v=kdwFtUYQnUo)
