#include <QtWidgets>
#include <QGraphicsDropShadowEffect>

#ifndef PERCENT_CLOCK_TEXTDISPLAY_H
#define PERCENT_CLOCK_TEXTDISPLAY_H

class TextDisplay : public QLabel {
public:
    TextDisplay(QString text, QWidget *parent);;

    void setFontSize(char *fontSize);

    void setTextShadowColor(char *colorHexValue);

    void setTextShadowBlur(int blurAmount);

    void setTextShadowOffset(int xOffset, int yOfset);

private:
    std::string colorStyle;
    std::string styles;
    QGraphicsDropShadowEffect *textShadow;

    void updateStyles();
};

#endif //PERCENT_CLOCK_TEXTDISPLAY_H
