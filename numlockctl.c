#include <stdio.h>
#include <string.h>
#include <X11/Xlib.h>
#include <X11/extensions/XTest.h>
#include <X11/XKBlib.h>
#include <X11/keysym.h>


int get_numlock_state(Display *dpy) {
    unsigned n;
    XkbGetIndicatorState(dpy, XkbUseCoreKbd, &n);
    return (n & 0x02) != 0;
}

void toggle_numlock(Display *dpy) {
    KeyCode numlock = XKeysymToKeycode(dpy, XK_Num_Lock);
    XTestFakeKeyEvent(dpy, numlock, True, 0);
    XTestFakeKeyEvent(dpy, numlock, False, 0);
    XFlush(dpy);
}

int main(int argc, char *argv[]) {
    if (argc != 2 || (strcmp(argv[1], "true") != 0 && strcmp(argv[1], "false") != 0)) {
        fprintf(stderr, "Uso: %s true|false\n", argv[0]);
        return 1;
    }

    Display *dpy = XOpenDisplay(NULL);
    if (!dpy) {
        fprintf(stderr, "Error opening display.\n");
        return 1;
    }

    int desired_state = strcmp(argv[1], "true") == 0 ? 1 : 0;
    int current_state = get_numlock_state(dpy);

    if (current_state != desired_state) {
        toggle_numlock(dpy);
    }

    XCloseDisplay(dpy);
    return 0;
}
