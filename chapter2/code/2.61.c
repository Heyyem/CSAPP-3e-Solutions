#include <stdio.h>

int A(int x) {
  return !~x;
}

int B(int x) {
  return !x;
}

int C(int x) {
  return A(x | ~0xff);
}

int D(int x) {
  return B((x >> ((sizeof(int)-1) << 3)) & 0xff);
}

int main(int argc, char* argv[]) {
  // test nums for A B C D
  int test_nums[] = {~0, 0, 0x1234ff, 0x1234};

  for (int i = 0; i < 4; i++) {
    int x = test_nums[i];

    if (A(x)) {
      printf("%x matchs A\n", x);
    }
    if (B(x)) {
      printf("%x matchs B\n", x);
    }
    if (C(x)) {
      printf("%x matchs C\n", x);
    }
    if (D(x)) {
      printf("%x matchs D\n", x);
    }
  }

  return 0;
}