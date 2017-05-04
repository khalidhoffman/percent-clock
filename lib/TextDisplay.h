#include <QtWidgets>

#ifndef PERCENT_CLOCK_TEXTDISPLAY_H
#define PERCENT_CLOCK_TEXTDISPLAY_H

class TextDisplay : public QLineEdit {
public:
    TextDisplay(QString text, QWidget *parent);;

    void setFontSize(char *fontSize);

private:
    std::string colorStyle;
    std::string styles;

    void updateStyles();
};

#endif //PERCENT_CLOCK_TEXTDISPLAY_H
