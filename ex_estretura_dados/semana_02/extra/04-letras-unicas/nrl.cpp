#include <iostream>
using namespace std;

int nrl(const char s[], char low[]){
    char alfa [26];
    char dois [27] = "abcdefghijklmnopqrstuvwxyz";
    int i = 0;
    int res = 0;
    int len;

    for (int j = 0;j < 26;j++){
        alfa[j] = 0;
        len += 1;
    }

    while (s[i] != '\0'){
        switch (s[i]){
            case('a'): case('A'):
            alfa[0] += 1;
            break;
            
            case('b'): case('B'):
            alfa[1] += 1;
            break;

            case('c'): case('C'):
            alfa[2] += 1;
            break;

            case('d'): case('D'):
            alfa[3] += 1;
            break;

            case('e'): case('E'):
            alfa[4] += 1;
            break;

            case('f'): case('F'):
            alfa[5] += 1;
            break;

            case('g'): case('G'):
            alfa[6] += 1;
            break;

            case('h'): case('H'):
            alfa[7] += 1;
            break;

            case('i'): case('I'):
            alfa[8] += 1;
            break;

            case('j'): case('J'):
            alfa[9] += 1;
            break;

            case('k'): case('K'):
            alfa[10] += 1;
            break;

            case('l'): case('L'):
            alfa[11] += 1;
            break;

            case('m'): case('M'):
            alfa[12] += 1;
            break;

            case('n'): case('N'):
            alfa[13] += 1;
            break;

            case('o'): case('O'):
            alfa[14] += 1;
            break;

            case('p'): case('P'):
            alfa[15] += 1;
            break;

            case('q'): case('Q'):
            alfa[16] += 1;
            break;

            case('r'): case('R'):
            alfa[17] += 1;
            break;

            case('s'): case('S'):
            alfa[18] += 1;
            break;

            case('t'): case('T'):
            alfa[19] += 1;
            break;

            case('u'): case('U'):
            alfa[20] += 1;
            break;

            case('v'): case('V'):
            alfa[21] += 1;
            break;

            case('w'): case('W'):
            alfa[22] += 1;
            break;

            case('x'): case('X'):
            alfa[23] += 1;
            break;

            case('y'): case('Y'):
            alfa[24] += 1;
            break;

            case('z'): case('Z'):
            alfa[25] += 1;
            break;

            default:
            break;
        }
        i++;
    
    }

    i = 0;

    for (int k = 0; k < 26;k++){
        if (alfa[k] == 1){
            res += 1;
            low[i] = dois[k];
            i++;
        }
    }

    i = 0;

    if (res == 0){
        while (low[i] != '\0'){
            low [i] = '\0';
            i++;
        }
    }

    return res;

}


int main(){

  const char s[] = "  F C U P  F E U P  Porto  ";
  char l[27] = { -1 };
  int r = nrl(s, l);
  cout << '\"' << s << "\" " << r << " \"" << l << "\"\n";



  return 0;
}