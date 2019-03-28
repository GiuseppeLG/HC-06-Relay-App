# HC-06 Relay App
A Qt based app for MacOS and Android that connect HC-06 Bluetooth module to 2-channel relay to switch on-off also 220V without external power with smartphone or Mac.

## Prototype Layout
If you want to run sketch in this repository, you can connect components like this.

<p align="center">
  <img src="https://github.com/GiuseppeLG/HC-06-Relay-App/blob/master/prototypes_layout.PNG" height="400" title="hover text">
</p>

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

<p align="left">
<img src="https://github.com/GiuseppeLG/HC-06-Relay-App/blob/master/app_layout.JPG" height="400" title="hover text">
</p>

When bluetooth HC-06 find, its mac address is shown. You have to double click on the corrispondet row and it connects automatically.
Then, you have to send ON or OFF command simply press button. 

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
This software is free.
[GPL](http://www.gnu.org/licenses/gpl.html)
