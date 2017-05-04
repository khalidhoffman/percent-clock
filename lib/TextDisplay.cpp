#include "TextDisplay.h"

TextDisplay::TextDisplay(QString text, QWidget *parent = 0) : QLineEdit::QLineEdit(text, parent) {
    colorStyle = "color: #333333;";
    styles = colorStyle;

    setReadOnly(true);
    setFrame(false);
    setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    updateStyles();
}

void TextDisplay::setFontSize(char *fontSize) {
    styles = colorStyle + ";font-size:" + fontSize;
    updateStyles();
}


void TextDisplay::updateStyles() {
    setStyleSheet(QString(styles.c_str()));
}
