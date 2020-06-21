#include <stdio.h>
#include <crypt.h>
#include <string.h>

void main() {
  char *passwd_hash = "$6$EIDXJYFDNXMG0OhX$StTDbvmZnBUOmqykWyYUlCe9xBlICCgCEVpvQGQc7.RCo1GW8DOvcSzFH991Ek82AkgFpBhtgg1uRhBMcDctA1";
  char *input_pwd = "bobisawesome";

  if (strncmp(passwd_hash, crypt(input_pwd, passwd_hash), strlen(passwd_hash)) == 0)
    printf("Password matches the hash!\n");
}
