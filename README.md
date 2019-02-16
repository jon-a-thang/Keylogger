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
