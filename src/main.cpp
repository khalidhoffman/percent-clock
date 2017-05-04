#include "Clock.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    ClockWindow *clock = new ClockWindow();

    clock->show();
    return app.exec();
}
