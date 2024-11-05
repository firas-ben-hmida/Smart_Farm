#include "numberformatdelegate.h"

Numberformatdelegate::Numberformatdelegate(QObject *parent):
    QStyledItemDelegate(parent)
    {
    }

    QString Numberformatdelegate::displayText(const QVariant &value, const QLocale &locale) const
    {
    QString formattedNum = locale.toString(value.toDouble(), 'f', 0);
    return formattedNum;
    }

