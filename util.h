#define print_bytes(x)                                                         \
  {                                                                            \
    int len = sizeof(x);                                                       \
                                                                               \
    typeof(x) y = x;                                                           \
    char* ptr   = (char*)(void*)&y;                                            \
    char buffer[150];                                                          \
    for (int i = 0; i < 150; ++i)                                              \
      buffer[i] = 0;                                                           \
    char* h        = buffer;                                                   \
    unsigned int p = 1;                                                        \
    for (int i = 0; i < len; ++i, ++ptr) {                                     \
      for (int j = 0; j < 8; ++j, p <<= 1, ++h) {                              \
        *h = p & *ptr ? '1' : '0';                                             \
      }                                                                        \
      p    = 1;                                                                \
      *h++ = ' ';                                                              \
    }                                                                          \
    for (len = 0; buffer[len]; ++len)                                          \
      ;                                                                        \
    for (int i = 0, j = len - 1, tmp; i < j; ++i, --j)                         \
      tmp = buffer[i], buffer[i] = buffer[j], buffer[j] = tmp;                 \
    puts(buffer + 1);                                                          \
  }
