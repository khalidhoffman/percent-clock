#include <QtWidgets>
#include "TimePoint.h"
#include "TextDisplay.h"


#ifndef PERCENT_CLOCK_CLOCK_H
#define PERCENT_CLOCK_CLOCK_H

class ClockWindow : public QWidget {

public:
    ClockWindow();

    void mousePressEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);

    void paintEvent(QPaintEvent *);

private:

    QString appTitle = QApplication::translate("toplevel", "Clock");
    TextDisplay *timeDisplay;
    TextDisplay *percentageDisplay;
    QAction *quitAction;
    Qt::WindowFlags flags = Qt::Window;
    QPoint dragPosition;
    QTimer *timer;
    QVBoxLayout *layout;
    QString *percentageText;
    QString *currentTimeText;
    TimePoint *endTime;
    TimePoint *startTime;
    int startHour = 9;
    int endHour = 18;
    int windowWidth = 240;
    int windowHeight = 240;

    std::string getPercentage();

    std::string getTime();

    void setTimeBoundaries();
};

#endif //PERCENT_CLOCK_CLOCK_H
