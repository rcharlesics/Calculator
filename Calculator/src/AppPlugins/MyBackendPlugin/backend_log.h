#ifndef BACKEND_LOG_H
#define BACKEND_LOG_H

#include <QLoggingCategory>

Q_DECLARE_LOGGING_CATEGORY(backend)

#define logDebug() qCDebug(backend, )
#define logInfo() qCInfo(backend, )
#define logWarning() qCWarning(backend, )
#define logCritical() qCCritical(backend, )

#endif // BACKEND_LOG_H
