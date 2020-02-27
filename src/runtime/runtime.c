#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *getString(char *s)
{
  size_t sLen = strlen(s);
  char *buf = malloc(sLen + 1 + sizeof(int32_t));
  int32_t *refCnt = (int32_t *) buf;
  *refCnt = 1;
  refCnt += 1;
  char *bufStr = (char *) refCnt;
  strcpy(bufStr, s);
  return bufStr;
}

void refString(char *s)
{
  size_t sLen = strlen(s);
  if (sLen != 0) {
    int32_t *refCnt = (int32_t *) s;
    refCnt -= 1;
    *refCnt += 1;
  }
}

void derefString(char *s)
{
  size_t sLen = strlen(s);
  if (sLen != 0) {
    int32_t *refCnt = (int32_t *) s;
    refCnt -= 1;
    *refCnt -= 1;
    if (*refCnt <= 0) {
      s = (char *) refCnt;
	      free(s);
	    }
	  }
	}

	void printInt(int x)
	{
	  printf("%d\n", x);
}

void printString(const char *s)
{
  puts(s);
}

void error()
{
  puts("runtime error");
  exit(1);
}

int readInt()
{
  int x;
  scanf("%d\n", &x);
  return x;
}

char *readString()
{
  char *line = NULL;
  size_t linecap = 0;
  getline(&line, &linecap, stdin);
  char *lp = line;
  while (*lp != '\n')
    lp++;
  *lp = '\0';
  char *ret = getString(line);
  free(line);
  return ret;
}

char *concatStrings(char *s1, char *s2)
{
  size_t s1Len = strlen(s1);
  size_t s2Len = strlen(s2);
  char *buf = malloc(s1Len + s2Len + 1);
  strcpy(buf, s1);
  strcat(buf, s2);
  char *ret = getString(buf);
  free(buf);
  return ret; 
}

