#include "s21_cat.h"

// Faylni qayta ishlash funksiyasi
void process_file(FILE *file, Flags flags) {
  int ch;
  int last_ch = '\n';  // Oldingi belgi (boshida enter deb olamiz)
  int squeeze = 0;     // Bo'sh qatorlarni sanash uchun
  int line_num = 1;    // Qator raqami

  while ((ch = fgetc(file)) != EOF) {
    // 1. Squeeze (-s): Bo'sh qatorlarni qisqartirish
    if (flags.s && ch == '\n' && last_ch == '\n') {
      squeeze++;
      if (squeeze > 1) {
        continue;
      }
    } else {
      squeeze = 0;
    }

    // 2. Raqamlash (-n, -b)
    if (last_ch == '\n' && squeeze <= 1) {
      if (flags.b) {
        if (ch != '\n') {
          printf("%6d\t", line_num++);
        }
      } else if (flags.n) {
        printf("%6d\t", line_num++);
      }
    }

    // 3. Maxsus belgilar (-e, -t, -v)
    if (ch == '\n') {
      if (flags.e) {
        printf("$");
      }
    } else if (ch == '\t') {
      if (flags.t) {
        printf("^I");
        last_ch = ch;
        continue;
      }
    } else if (flags.v) {
      // Bosilmaydigan belgilarni (control characters) ko'rsatish
      if ((ch >= 0 && ch < 32) && ch != 9 && ch != 10) {
        printf("^%c", ch + 64);
        last_ch = ch;
        continue;
      } else if (ch == 127) {
        printf("^?");
        last_ch = ch;
        continue;
      }
    }

    // 4. Belgini chiqarish
    printf("%c", ch);
    last_ch = ch;
  }
}

// Faylni ochish funksiyasi
void read_file(char *path[], Flags *flags) {
  FILE *file = fopen(*path, "r");
  if (file == NULL) {
    fprintf(stderr, "s21_cat: %s: No such file or directory\n", *path);
  } else {
    process_file(file, *flags);
    fclose(file);
  }
}

// Flaglarni o'qish funksiyasi
void parse_flags(int argc, char *argv[], Flags *flags) {
  int opt;
  int option_index = 0;
  struct option long_options[] = {{"number-nonblank", no_argument, NULL, 'b'},
                                  {"number", no_argument, NULL, 'n'},
                                  {"squeeze-blank", no_argument, NULL, 's'},
                                  {NULL, 0, NULL, 0}};

  while ((opt = getopt_long(argc, argv, "+benstTvE", long_options,
                            &option_index)) != -1) {
    switch (opt) {
      case 'b':
        flags->b = 1;
        break;
      case 'e':
        flags->e = 1;
        flags->v = 1;
        break;
      case 'E':
        flags->e = 1;
        break;
      case 'n':
        flags->n = 1;
        break;
      case 's':
        flags->s = 1;
        break;
      case 't':
        flags->t = 1;
        flags->v = 1;
        break;
      case 'T':
        flags->t = 1;
        break;
      case 'v':
        flags->v = 1;
        break;
      default:
        fprintf(stderr, "usage: s21_cat [-benstuv] [file ...]\n");
        exit(1);
    }
  }
}

int main(int argc, char *argv[]) {
  Flags flags = {0};
  parse_flags(argc, argv, &flags);

  // Argumentlar tugagan joydan boshlab fayllarni o'qish
  while (optind < argc) {
    read_file(&argv[optind], &flags);
    optind++;
  }

  return 0;
}
