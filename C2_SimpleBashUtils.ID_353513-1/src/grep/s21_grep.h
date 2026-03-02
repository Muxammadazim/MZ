#ifndef S21_GREP_H
#define S21_GREP_H

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
  int multiple_files;  // 1 tadan ko'p fayl bo'lsa 1 bo'ladi
} Flags;

// Prototipni to'g'irladik: char *pattern o'rniga regex_t *reg
void parse_flags(int argc, char *argv[], Flags *flags, char *pattern);
void process_file(Flags flags, char *path, regex_t *reg);

#endif
