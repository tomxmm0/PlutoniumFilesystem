# PlutoniumFilesystem
This plugin adds additional functionality to ChaiScript that allows you to read and write files into your computer.

**Installation**

* Download the latest release from https://github.com/StaRT1337/PlutoniumFilesystem/releases
* Drag the DLL into %localappdata%/Plutonium/storage/iw5/plugins

**Usage**
```js
/*
  Creates a file handler.

   First param: File path
   Second param: Mode 
*/
var file = Filesystem("helloworld.txt", "w+");


/*
   Writes/appends into file.

   First param: string to write
*/
file.Write("Hello, World!")


/*
   Reads the contents of the file.
*/
var contents = file.Read();

print(contents) // Hello, World!
```

**Notes**
* All available file modes are shown [here.](https://i.imgur.com/l9e0EY3.png)
  * The plugin will only create a file handle if the file already exists. therefore modes like ```r+``` and ```w+``` will act the same.
* For security measures, the file must be within the game folder (Not exactly in it, could also be in a folder that's within the game folder).
* For people who wish to build from source, make sure to set the C++ version to latest, set the run time library to ```/MT``` and only compile as Release and x86.
* While the plugin automatically closes the file handle as it goes out of scope, to manually close it use the ```.Close()``` method.
