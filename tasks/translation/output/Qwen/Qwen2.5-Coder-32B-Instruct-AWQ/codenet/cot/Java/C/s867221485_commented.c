#include <stdio.h>
#include <string.h>

/**
 * Created by Santa.
 */
int main() {
  int N;
  char s[1000]; // Assuming a maximum length for the string

  scanf("%d", &N);
  getchar(); // To consume the newline character after the integer

  fgets(s, sizeof(s), stdin);
  s[strcspn(s, "\n")] = 0; // Remove the newline character from the string

  int flag = 0;
  int ans = 0;
  int hen = 0;
  int sha = 0;
  int dot = 0;
  int temp = 0;
  int first = 1;
  for (int i = 0; i < N; i++) {
    if(s[i] == '#'){
      first = 0;
      if(sha <= dot){
        ans += sha;
        sha = 0;
        dot = 0;
        first = 1;
      } else {
        // temp += dot;
      }
      sha++;
    } else {
      dot++;
    }
  }

  if(sha <= dot){
    ans += sha;
    dot = 0;
  } else {
    // temp += dot;
  }

  printf("%d\n", ans + dot);
  return 0;
}
// End of Code
