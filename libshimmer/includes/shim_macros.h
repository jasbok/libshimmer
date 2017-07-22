#ifndef SHIM_MACROS_H
#define SHIM_MACROS_H

#include <dlfcn.h>

#define DLSYM(FUNC) namespace sym {                                     \
                static auto FUNC = [](){                                \
                    auto dlsym_ptr = dlsym(RTLD_NEXT, #FUNC);           \
                    if(!dlsym_ptr){                                     \
                        printf("Unable to find function: %s\n", #FUNC); \
                        abort();                                        \
                    }                                                   \
                    return (FUNC##_Handle)(dlsym_ptr);                  \
                }();                                                    \
            }

#define HANDLE_TYPEDEF(RET, FUNC, ARGS...) typedef RET (*FUNC##_Handle)(ARGS)

#define SHIM(RET, FUNC, ARGS...)     \
    HANDLE_TYPEDEF(RET, FUNC, ARGS); \
    DLSYM(FUNC);                     \
    RET FUNC (ARGS)

#ifdef DEBUG

#define SHIM_LOG(MAX)                        \
    static unsigned int _SHIM_LOG_COUNT = 0; \
    if (_SHIM_LOG_COUNT++ < MAX)             \
        printf("=> Handle: %s (%u/%u)\n", __FUNCTION__, _SHIM_LOG_COUNT, MAX)

#else
#define SHIM_LOG(MAX)
#endif


#endif
