#include "mymessage.h"

#include <QHBoxLayout>
#include <QSpacerItem>
#include <QFontMetrics>

MyMessage::MyMessage(const QString& message, QWidget* parent)
    : QTextEdit(parent)
{
    setReadOnly(true);
    setText(message);
    QFontMetrics metrics(font());

    #if (QT_VERSION >= QT_VERSION_CHECK(5, 11, 0))
        int textWidth = metrics.horizontalAdvance(message);
    #else
        int textWidth = metrics.width(message);  // Use width() in older Qt versions
    #endif

    setFixedWidth(50 * metrics.averageCharWidth() < textWidth + 10 ? 50 * metrics.averageCharWidth() : textWidth + 10);
    setFixedHeight((metrics.height() * message.length()) / 50 + metrics.height() + 10);
}

MyMessage::~MyMessage()
{
}
