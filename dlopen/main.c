#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main()
{
    void    *handle = NULL;
    int     (*_g_echo)();
    int j = 0;

    handle = dlopen("./libecho.so", RTLD_LAZY);
    if(!handle) {
        fprintf(stderr, "dlopen - %s\n", dlerror());
        exit(-1);
    }

    _g_echo = (int(*)())dlsym(handle, "echo");
    if(!_g_echo) {
        fprintf(stderr, "dlsym - %s\n", dlerror());
        exit(-1);
    }

    (*_g_echo)();

    if (0 != dlclose(handle)) {
        fprintf(stderr, "dlsym - %s\n", dlerror());
        exit(-1);
    }

    exit(0);
}
