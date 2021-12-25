# ESP8266-Light-Controller

Control your lights using an ESP8266!

## How to use
This project was made using [PlatformIO](https://platformio.org/install/integration).


 They support wide variety of IDE's & text editors, I personally used VSC version. (If you're using Code OSS, you will need to install code marketplace to find it in extensions, you can find it on [Aur](http://aur.archlinux.org/packages/code-marketplace)).
 Connect your ESP8266 via usb, PlatformIO should automatically detect it. 
 
 *Linux users might need to add themselves to uucp (arch) dialout (debian) group, you can do that by running `sudo usermod -a -G uucp $USER`*.

 After that just hit the upload button and you're good to go!
 If you connect to the serial monitor you will be able to see your IP ex. 192.168.8.101.

 Once you navigate to the IP in your web browser you will be able to turn the relay on or off.

 ## Wiring
 Here's how you should wire the d1-mini to the relay for this to work.
 ![image](/tools/wiring.png)

## Extra
in tools folder there's a script called `minify.sh`, you can use that to automatically generate index.h file from index.html