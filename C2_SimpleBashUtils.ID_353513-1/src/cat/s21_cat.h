#ifndef S21_CAT_H
#define S21_CAT_H

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Flaglar strukturasi
typedef struct {
  int b;  // --number-nonblank
  int e;  // -e (implies -v)
  int n;  // --number
  int s;  // --squeeze-blank
  int t;  // -t (implies -v)
  int v;  // -v
} Flags;

// Funksiyalar
void parse_flags(int argc, char *argv[], Flags *flags);
void read_file(char *argv[], Flags *flags);

#endif
