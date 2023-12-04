#ifndef ANALYST_GLOBAL_H
#define ANALYST_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(ANALYST_LIBRARY)
#define ANALYST_EXPORT Q_DECL_EXPORT
#else
#define ANALYST_EXPORT Q_DECL_IMPORT
#endif

#endif // ANALYST_GLOBAL_H
