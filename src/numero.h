#ifndef NUMERO_H
#define NUMERO_H


#include <QStyledItemDelegate>

class numero : public QStyledItemDelegate
{
Q_OBJECT
public:
explicit numero (QObject *parent = 0);
virtual QString displayText(const QVariant &value, const QLocale &locale) const;

signals:

public slots:

};
#endif // NUMERO_H


