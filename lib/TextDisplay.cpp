#include "TextDisplay.h"

TextDisplay::TextDisplay(QString text, QWidget *parent = 0) : QLabel::QLabel(text, parent) {
    colorStyle = "color: #333333;";
    styles = colorStyle;
    textShadow = new QGraphicsDropShadowEffect(this);
    textShadow->setBlurRadius(16);
    textShadow->setOffset(2, 2);

    setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    updateStyles();
}

void TextDisplay::setFontSize(char *fontSize) {
    styles = colorStyle + ";font-size:" + fontSize;
    updateStyles();
}

void TextDisplay::setTextShadowColor(char *colorHexValue) {
    textShadow->setColor(QColor(colorHexValue));
    setGraphicsEffect(textShadow);
}

void TextDisplay::setTextShadowBlur(int blurAmount) {
    textShadow->setBlurRadius(blurAmount);
    setGraphicsEffect(textShadow);
}

void TextDisplay::setTextShadowOffset(int xOffset, int yOffset) {
    textShadow->setOffset(xOffset, yOffset);
    setGraphicsEffect(textShadow);
}


void TextDisplay::updateStyles() {
    setStyleSheet(QString(styles.c_str()));
}
