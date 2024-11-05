#include "numero.h"


numero::numero(QObject *parent) :
QStyledItemDelegate(parent)
{
}

QString numero::displayText(const QVariant &value, const QLocale &locale) const
{
QString formattedNum = locale.toString(value.toDouble(), 'f', 0);
return formattedNum;
}
