#ifndef DEFINES_H
#define DEFINES_H

#include <QString>
#include <QTranslator>

const QString connectInfoStart = QTranslator::tr("Enter connection options. If you want to save connection information - check the box below");
const QString connectInfoNoName = QTranslator::tr("User Name can not be empty");
const QString connectInfoNoPass = QTranslator::tr("Password field is empty. Continue without password?");
const QString connectInfoNoPort = QTranslator::tr("Connection Port can not be empty");
const QString connectInfoNoHost = QTranslator::tr("Host Name can not be empty");
const QString connectInfoNoDb = QTranslator::tr("Dsta Base name can not be empty");

#endif // DEFINES_H
