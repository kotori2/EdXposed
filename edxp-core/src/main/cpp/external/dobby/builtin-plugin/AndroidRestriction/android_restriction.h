#ifndef ANDROID_RESTRICTION_H
#define ANDROID_RESTRICTION_H

#include <stdint.h>
#include <vector>

#ifdef __cplusplus
extern "C" {
#endif

typedef void *soinfo_t;

soinfo_t linker_dlopen(const char *filename, int flag);

char *linker_soinfo_get_realpath(soinfo_t soinfo);

uintptr_t linker_soinfo_to_handle(soinfo_t soinfo);

void linker_iterate_soinfo(int (*cb)(soinfo_t soinfo));

void linker_disable_namespace_restriction();

#ifdef __cplusplus
}
#endif

std::vector<soinfo_t> linker_get_solist();

#endif