# Keylogger
A program that will track and log all the keystrokes of a user on a system.

## Requirements

### The included header files
```
#include <linux/input.h>
#include <sys/stat.h>
```

### Run Requirements
- Bash
- C
- In *keylog.c* it may be required for some users to change the event depending entirely on which one is registered for the keyboard.

```
// Users should check to make sure their keyboard is event1
// (check to see what event keyboard is) --> cat /proc/bus/input/devices|more
// (see listing of input dev) --> ls -l /dev/input
int file_d = open("/dev/input/event1", O_RDONLY);
```

- The folder *Keylogger* must be placed on the Desktop for *startsystemd.sh* to run properly
- startsystemd.sh must be run with UID 0 (sudo or root).

```
make
sudo ./startsystemd.sh
```

## Author
[Jonathan Jang](http://github.com/jwj3767)

## License
This project is licensed under the MIT License - see the [LICENSE.md](https://github.com/jwj3767/Keylogger/blob/master/LICENSE) file for details
