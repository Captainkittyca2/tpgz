#include <stdio.h>
#include "libtp_c/include/system.h"
#include "libtp_c/include/link.h"
#include "libtp_c/include/controller.h"
#include "controller.h"
#include "fonts/consolas.h"
#include "font.h"
#include "fifo_queue.h"
#include "menu.h"

static Font Consolas;
bool visible = false;

extern "C" {

void init() {
    Consolas = Font(f_Consolas, consolas_bytes);
}

void game_loop() {
    if (tp_mPadStatus.sval == (Controller::Pad::R | Controller::Pad::DPAD_DOWN)) {
        visible = true;
    }
}

void draw() {
    Consolas.setupRendering();
    FIFOQueue::renderItems(Queue, Consolas);
    MainMenu::render(Consolas);
}
}