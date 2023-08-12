# ----------------------------
# Makefile Options
# ----------------------------

NAME = Snake
ICON = icon.png
DESCRIPTION = "Snake game by Guyane"
COMPRESSED = NO

CFLAGS = -Wall -Wextra -Oz
CXXFLAGS = -Wall -Wextra -Oz

# ----------------------------

include $(shell cedev-config --makefile)
