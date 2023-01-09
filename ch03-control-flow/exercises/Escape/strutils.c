#include "strutils.h"
#include <assert.h>
#include <string.h>

// Exercise 3-2: Write a function escape(s, t) that converts characters like
//  newline and tab into visible escape sequences like \n and \t as it copies
//  the string t to s. Use a switch. Write a function for the other direction
//  as well, converting escape sequences into the real characters.

void escape(char s[], char t[]) {
  int i = 0;
  int j = 0;
  while (t[i] != '\0') {
    int c = t[i];
    switch (c) {
      case '\a': {
        s[j++] = '\\';
        s[j++] = 'a';
        break;
      }
      case '\b': {
        s[j++] = '\\';
        s[j++] = 'b';
        break;
      }
      case '\f': {
        s[j++] = '\\';
        s[j++] = 'f';
        break;
      }
      case '\t': {
        s[j++] = '\\';
        s[j++] = 't';
        break;
      }
      case '\v': {
        s[j++] = '\\';
        s[j++] = 'v';
        break;
      }
      case '\r': {
        s[j++] = '\\';
        s[j++] = 'r';
        break;
      }
      case '\n': {
        s[j++] = '\\';
        s[j++] = 'n';
        break;
      }
      case '\\': {
        s[j++] = '\\';
        s[j++] = '\\';
        break;
      }
      case '\'': {
        s[j++] = '\\';
        s[j++] = '\'';
        break;
      }
      case '\"': {
        s[j++] = '\\';
        s[j++] = '\"';
        break;
      }
      case '\?': {
        s[j++] = '\\';
        s[j++] = '\?';
        break;
      }
      default: {
        s[j++] = c;
        break;
      }
    }

    i++;
  }

  // Add '\0'
  s[j] = t[i];
}

void unescape(char s[], char t[]) {
  int i = 0;
  int j = 0;

  while (t[i] != '\0') {
    int c = t[i];
    switch (c) {
      case '\\': {
        if (t[i + 1] != '\0') {
          i++;
          switch (t[i]) {
            case 'a': {
              s[j++] = '\a';
              break;
            }
            case 'b': {
              s[j++] = '\b';
              break;
            }
            case 'f': {
              s[j++] = '\f';
              break;
            }
            case 't': {
              s[j++] = '\t';
              break;
            }
            case 'v': {
              s[j++] = '\v';
              break;
            }
            case 'r': {
              s[j++] = '\r';
              break;
            }
            case 'n': {
              s[j++] = '\n';
              break;
            }
            case '\\': {
              s[j++] = '\\';
              break;
            }
            case '\'': {
              s[j++] = '\'';
              break;
            }
            case '\"': {
              s[j++] = '\"';
              break;
            }
            case '\?': {
              s[j++] = '\?';
              break;
            }
            default: {
              s[j++] = '\\';
              s[j++] = t[i];
              break;
            }
          }
        }
        break;
      }
      default: {
        s[j++] = c;
        break;
      }
    }

    i++;
  }
  
  // Add '\0'
  s[j] = t[i];
}
