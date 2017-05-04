#include "Clock.h"

ClockWindow::ClockWindow() {
    layout = new QVBoxLayout;
    quitAction = new QAction(QWidget::tr("E&xit"), this);
    timer = new QTimer(this);
    flags |= Qt::FramelessWindowHint;
    flags |= Qt::WindowStaysOnTopHint;

    startTime = new TimePoint(9);
    endTime = new TimePoint(18);

    currentTimeText = new QString(getTime().c_str());
    percentageText = new QString(getPercentage().c_str());

    timeDisplay = new TextDisplay(*percentageText, this);
    percentageDisplay = new TextDisplay(*currentTimeText, this);

    timeDisplay->setTextShadowColor("#FFFFFF");
    timeDisplay->setTextShadowBlur(8);
    timeDisplay->setTextShadowOffset(0, 2);
    percentageDisplay->setFontSize("80px");
    percentageDisplay->setTextShadowColor("#FFFFAA");
    layout->addWidget(percentageDisplay);
    layout->addWidget(timeDisplay);
    timer->start(1000);
    quitAction->setShortcut(QWidget::tr("Ctrl+Q"));


    addAction(quitAction);
    move(1280, 120);
    resize(240, 240);
    setLayout(layout);
    setWindowTitle(appTitle);
    setStyleSheet("background:transparent;");
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(flags);
    setContextMenuPolicy(Qt::ActionsContextMenu);
    connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));

};

void ClockWindow::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
}

void ClockWindow::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton) {
        move(event->globalPos() - dragPosition);
        event->accept();
    }
}

void ClockWindow::paintEvent(QPaintEvent *) {
    delete percentageText;
    delete currentTimeText;

    percentageText = new QString(this->getPercentage().c_str());
    currentTimeText = new QString(this->getTime().c_str());
    timeDisplay->setText(*currentTimeText);
    percentageDisplay->setText(*percentageText);
}


std::string ClockWindow::getPercentage() {
    char text[5];
    time_t currentTime;
    time(&currentTime);
    double totalDuration = difftime(endTime->toTimeT(), startTime->toTimeT());
    double elapsedDuration = difftime(currentTime, startTime->toTimeT());
    double elapsedPercentage = 100 * elapsedDuration / totalDuration;

    if (elapsedPercentage > 100) {
        elapsedPercentage = 100;
    } else if (elapsedPercentage < 0) {
        elapsedPercentage = 0;
    }

    sprintf(text, "%.f%%", elapsedPercentage);
    std::string percentElapsedText(text);

    return percentElapsedText;
}

std::string ClockWindow::getTime() {
    time_t currentTime;
    time(&currentTime);
    char text[11];
    struct tm *currentTimeInfo = localtime(&currentTime);

    strftime(text, 11, "%I:%M:%S%p", currentTimeInfo);
    return text;
}
