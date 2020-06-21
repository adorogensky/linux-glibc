#include <shadow.h>
#include <stdio.h>
#include <unistd.h>

/*
 * this program just prints password hash from /etc/shadow for user 'bob'
 * e.g.
 * sudo useradd bob
 * sudo passwd bob // bobisawesome
 * sudo ./run passwd_hash.c
 * */
void main() {
  struct spwd *sp_ent = getspnam("bob");
  if (!sp_ent) perror("getspnam"), _exit(1);
  printf("password hash: %s\n", sp_ent -> sp_pwdp);
  endspent();
}
