#ifndef CONSTANTS_H
#define CONSTANTS_H

const float SCREEN_WIDTH = 800;
const float SCREEN_HEIGHT = 600;
const float WORK_PANEL = SCREEN_WIDTH*4/5;
const float SIDE_BAR = SCREEN_WIDTH*1/5;

const int SB_MOUSE_POSITION = 0;
const int SB_MOUSE_CLICKED = SB_MOUSE_POSITION + 1;
const int SB_DIRECTION = SB_MOUSE_CLICKED + 1;
const int SB_SPEED = SB_DIRECTION + 1;
const int SB_SIZE = SB_SPEED + 1;
const int SB_COLOR = SB_SIZE + 1;
const int SB_SYSTEM = SB_COLOR + 1;

const int MAX_RADIUS = 25;
const int MIN_RADIUS = 5;

#endif // CONSTANTS_H
