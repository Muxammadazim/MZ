#define _GNU_SOURCE  // <-- getline ishlashi uchun BU SHART!
#include "s21_grep.h"

// Flaglarni o'qish
void parse_flags(int argc, char *argv[], Flags *flags, char *pattern) {
  int opt;
  while ((opt = getopt(argc, argv, "e:ivclnhsf:o")) != -1) {
    switch (opt) {
      case 'e':
        flags->e = 1;
        if (strlen(pattern) > 0) strcat(pattern, "|");
        strcat(pattern, optarg);
        break;
      case 'i':
        flags->i = 1;
        break;
      case 'v':
        flags->v = 1;
        break;
      case 'c':
        flags->c = 1;
        break;
      case 'l':
        flags->l = 1;
        break;
      case 'n':
        flags->n = 1;
        break;
      case 'h':
        flags->h = 1;
        break;
      case 's':
        flags->s = 1;
        break;
      case 'o':
        flags->o = 1;
        break;
      default:
        fprintf(stderr, "usage: s21_grep [options] template [file_name]\n");
        exit(1);
    }
  }
}

// Faylni qayta ishlash
void process_file(Flags flags, char *path, regex_t *reg) {
  FILE *file = fopen(path, "r");
  if (file == NULL) {
    if (!flags.s) perror(path);
    return;
  }

  char *line = NULL;
  size_t len = 0;
  int read;
  int line_count = 0;
  int match_count = 0;

  while ((read = getline(&line, &len, file)) != -1) {
    // Qator oxiridagi enterni olib tashlash (regex to'g'ri ishlashi uchun)
    if (line[read - 1] == '\n') line[read - 1] = '\0';

    line_count++;
    int success = regexec(reg, line, 0, NULL, 0);
    int match = 0;

    if (success == 0 && !flags.v) match = 1;
    if (success != 0 && flags.v) match = 1;

    if (match) {
      match_count++;
      if (!flags.c && !flags.l) {
        if (!flags.h && flags.multiple_files) printf("%s:", path);
        if (flags.n) printf("%d:", line_count);
        printf("%s\n", line);
      }
    }
    // Keyingi aylanish uchun enterni qaytarib qo'yish shart emas,
    // chunki getline o'zi yangisini o'qiydi.
  }

  if (flags.c) {
    if (!flags.h && flags.multiple_files) printf("%s:", path);
    printf("%d\n", match_count);
  }

  if (flags.l && match_count > 0) {
    printf("%s\n", path);
  }

  free(line);
  fclose(file);
}

int main(int argc, char *argv[]) {
  Flags flags = {0};
  char pattern[4096] = {0};

  parse_flags(argc, argv, &flags, pattern);

  // Agar -e bo'lmasa, pattern argumentdan olinadi
  if (!flags.e) {
    if (optind < argc) {
      strcat(pattern, argv[optind]);
      optind++;
    }
  }

  if (strlen(pattern) == 0) return 0;

  if (argc - optind > 1) flags.multiple_files = 1;

  regex_t reg;
  int cflags = REG_EXTENDED;
  if (flags.i) cflags |= REG_ICASE;

  if (regcomp(&reg, pattern, cflags) != 0) {
    fprintf(stderr, "Error compiling regex\n");
    return 1;
  }

  while (optind < argc) {
    process_file(flags, argv[optind], &reg);
    optind++;
  }

  regfree(&reg);
  return 0;
}
