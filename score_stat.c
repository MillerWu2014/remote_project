#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calPoints(char **ops, int opsSize){
    int score = 0;
    int i;
    for (i=0; i<opsSize; i++){
        if (strcmp(ops[i], "C") == 0){
            printf("%s\n", ops[i]);
        }
        printf("%s\n", ops[i]);
    }
    return score;
}

int expressiveWords(char * S, char ** words, int wordsSize){
    int s_length = strlen(S);
    int j = 0, i = 0, count = 1;
    char s;
    int a[s_length];
    char m[100];
    for (i=0; i<s_length; i++){
        if (i==0){
            s = S[i];
        } else {
            if (s==S[i]){
                count+=1;
            } else {
                count = 1;
                s = S[i];
            }
        }
        a[i] = count;
    }

    int k = 0;
    for(j=0; j<s_length; j++){
        if (a[j]==1){
            m[k] = S[j];
            k++;
        } 
        else if ((a[j]==2) && (j+1<s_length) && (a[j+1]<2))
        {
            m[k] = S[j];
            k++;
        } 
        else if ((a[j]==2) && (j+1>s_length))
        {
            m[k] = S[j];
            k++;
        }
        
        else
        {
            continue;
        }
    }

    int x = 0, ans = 0;
    for (; x<wordsSize; x++){
        char *z = words[x];
        if (strcmp(z, m) ==0){
            ans++;
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    char *scores[] = {"5","-2","4","C","D","9","+","+"};
    // int s = calPoints(scores, 8);
    // printf("The scores: %d.", s);
    char *S = "lee";  //"heeellooo";
    char *words[] = {"le"};  // {"hello", "hi", "helo"};

    int r = expressiveWords(S, words, 3);
    printf("%d\n", r);

    return 0;
}
