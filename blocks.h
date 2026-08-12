//#include "../theme.h"
// Modify this file to change what commands output to your statusbar, and recompile using the make command.
// https://glyphsearch.com
// https://www.nerdfonts.com/cheat-sheet

static const Block blocks[] = {
	// ======================================================= //
  /*Icon*/  /*Command*/  /*Update Interval*/  /*Update Signal*/

  //{"^lm()^lm(kitty watch sensors) ", "sensors k10temp-pci-00c3 | grep -o '+.*C'",	3,		0},

  {"^lm()^lm(kitty btop)󰘚 ", "free -h | awk '/^Mem/ { print $3 }' | sed s/i//g", 3, 0},

  {"^lm()^lm(kitty btop)󰍛 ", "echo \"$[100-$(vmstat 1 1 | tail -1 | awk '{print $15}')]\"%", 3, 0},

  {"^rm()^us()^ds()^lm()^us()^ds()󰂀 ", "cat /sys/class/power_supply/BAT0/capacity | tr -d '\n'; echo '%'", 30, 0},

	{"^rm()^us()^ds()^lm()^us(pkill -RTMIN+5 someblocks;brightnessctl set 5%+)^ds(pkill -RTMIN+5 someblocks;brightnessctl set 5%-)󰃟 ", "brightness_100", 15, 5},

	{"^rm()^us()^ds()^lm()^lm(kitty alsamixer)^rm(kitty pavucontrol)^ds(pamixer -d 2;pkill -RTMIN+6 someblocks)^us(pamixer -i 2;pkill -RTMIN+6 someblocks)󰕾 ", "pamixer --get-volume-human", 15, 6},

	{"^lm()^rm()^us()^ds()^lm(kitty khal interactive)", "date '+%d/%m %H:%M'", 30, 7},

	{"^lm()^rm()^us()^ds()^lm(toggle_tray_tui)", "echo ' 󰣇  '", 0, 0},
};

// sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = "   ";
static unsigned int delimLen = 3;
