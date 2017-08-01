#ifndef LIBSHIMMER_MACROS_ACCESSOR_MACROS_H
#define LIBSHIMMER_MACROS_ACCESSOR_MACROS_H

#define FLUENT( CLASS, TYPE, NAME )            \
public:                                        \
    virtual CLASS& NAME ( const TYPE &NAME ) { \
        _ ## NAME = NAME; return *this;        \
    }                                          \
    virtual CLASS& NAME ( TYPE && NAME ) {     \
        _ ## NAME = NAME; return *this;        \
    }                                          \
    virtual const TYPE NAME() const {          \
        return _ ## NAME;                      \
    }                                          \
    virtual TYPE NAME() {                      \
        return _ ## NAME;                      \
    }                                          \
private:                                       \
    TYPE _ ## NAME

#define GETTER( TYPE, NAME )           \
public:                                \
    virtual const TYPE &NAME() const { \
        return _ ## NAME;              \
    }                                  \
    virtual TYPE NAME() {              \
        return _ ## NAME;              \
    }                                  \
private:                               \
    TYPE _ ## NAME

#define GETTER_OVERRIDE( TYPE, NAME ) \
public:                               \
    virtual TYPE NAME() override {    \
        return _ ## NAME;             \
    }                                 \
private:                              \
    TYPE _ ## NAME

#endif // ifndef LIBSHIMMER_MACROS_ACCESSOR_MACROS_H
