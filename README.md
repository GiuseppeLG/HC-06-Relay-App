# HC-06 Relay App
A Qt based app for MacOS and Android that connect HC-06 Bluetooth module to 2-channel relay to switch on-off also 220V without external power with smartphone or Mac.

## Prototype Layout
If you want to run sketch in this repository, you can connect components like this.

![prototypes_layout](https://user-images.githubusercontent.com/14968550/57195455-0e09c200-6f53-11e9-98e2-ed537e94bbd2.PNG)


## Config
There is not much you can configure. A minimal setup looks like the following:

```c++
#define rele1 9
#define rele2 10
int rxPin = 3;
int txPin = 2;
```

If you want to, you can specify the socket message, but you have to edit also qt project:

```c++ 
//where you find this in .ino
if(message == "1")

// you have to edit this in mainwindow.cpp
socket -> write("1");
```

## Limitations
As you can read [here](https://doc.qt.io/qt-5/qtbluetooth-index.html) there are some limitations to the Bluetooth in Windows.

Then, i have spent little time on the aesthetics of the Android app, so mobile graphics are not responsive. 

## App Layout

![app_layout](https://user-images.githubusercontent.com/14968550/57195451-ffbba600-6f52-11e9-9cd4-e2f05b4ae07b.JPG)

When bluetooth HC-06 find, its mac address is shown. You have to double click on the corrispondet row and it connects automatically.
Then, you have to send ON or OFF command simply press button. 

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
This software is free.
[GPL](http://www.gnu.org/licenses/gpl.html)
