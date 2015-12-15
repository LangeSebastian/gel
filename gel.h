#ifndef GEL_H
#define GEL_H

#ifdef QPM_USE_NS

#undef _GET_OVERRIDE
#undef _QPM_BEGIN_NAMESPACE_1
#undef _QPM_BEGIN_NAMESPACE_2
#undef _QPM_BEGIN_NAMESPACE_2
#undef _QPM_BEGIN_NAMESPACE_4
#undef QPM_BEGIN_NAMESPACE
#undef _QPM_END_NAMESPACE_1
#undef _QPM_END_NAMESPACE_2
#undef _QPM_END_NAMESPACE_2
#undef _QPM_END_NAMESPACE_4
#undef QPM_END_NAMESPACE

#define _GET_OVERRIDE(_1, _2, _3, _4, NAME, ...) NAME

#define _QPM_BEGIN_NAMESPACE_1(a) \
    namespace a {
#define _QPM_BEGIN_NAMESPACE_2(a, b) \
    _QPM_BEGIN_NAMESPACE_1(a) namespace b {
#define _QPM_BEGIN_NAMESPACE_3(a, b, c) \
    _QPM_BEGIN_NAMESPACE_2(a, b) namespace c {
#define _QPM_BEGIN_NAMESPACE_4(a, b, c, d) \
    _QPM_BEGIN_NAMESPACE_3(a, b, c) namespace d {

#define QPM_BEGIN_NAMESPACE(...) _GET_OVERRIDE(__VA_ARGS__, \
    _QPM_BEGIN_NAMESPACE_4, \
    _QPM_BEGIN_NAMESPACE_3, \
    _QPM_BEGIN_NAMESPACE_2, \
    _QPM_BEGIN_NAMESPACE_1)(__VA_ARGS__)

#define _QPM_END_NAMESPACE_1 };
#define _QPM_END_NAMESPACE_2 } };
#define _QPM_END_NAMESPACE_3 } } };
#define _QPM_END_NAMESPACE_4 } } } };

#define QPM_END_NAMESPACE(...) _GET_OVERRIDE(__VA_ARGS__, \
    _QPM_END_NAMESPACE_4, \
    _QPM_END_NAMESPACE_3, \
    _QPM_END_NAMESPACE_2, \
    _QPM_END_NAMESPACE_1)

#else
#define QPM_BEGIN_NAMESPACE(...)
#define QPM_END_NAMESPACE(...)
#endif // QPM_USE_NS

#include <QtQml>
#include "jsonlistmodel.h"
#include "collection.h"

QPM_BEGIN_NAMESPACE(com, cutehacks, gel)

void registerEngine(QQmlEngine *engine)
{
    qmlRegisterType<JsonListModel>("com.cutehacks.gel", 1, 0, "JsonListModel");
    qmlRegisterType<Collection>("com.cutehacks.gel", 1, 0, "Collection");
}

QPM_END_NAMESPACE(com, cutehacks, gel)

#endif // GEL_H

