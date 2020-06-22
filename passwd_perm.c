#include <stdio.h>

/* prints permutations */
void perm(char *passwd, size_t pos, size_t max_len) {
  char c;
  for (c = 'a'; c < 'z'; c++) {
    passwd[pos] = c;
    printf("%.*s\n", pos + 1, passwd);
    if (pos < max_len - 1) {
      perm(passwd, pos + 1, max_len);
    }
  }
}

/*
 * 'a'-'z', max_len=3, time=0.028s
 * 'a'-'z', max_len=4, time=0.910s
 * 'a'-'z', max_len=5, time=24.103s
 * 'a'-'z', max_len=6, time=685.476s=11m 25.476s
 */
const size_t MAX_PASSWD_LEN = 6;
void main() {
  char passwd[MAX_PASSWD_LEN];
  perm(passwd, 0, MAX_PASSWD_LEN);
}
