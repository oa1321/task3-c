#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TXT 1024 //so you will be able to get 1024 chars
#define WORD 31 //one above max

//just used to see if we alredy started the gematry .
int first = 0;
int first2 = 0;
int first3 = 0;
//scanning the data from the user.
void scan(char Word[WORD], char text[TXT]){
    int i=0;
    for(i=0; i<WORD; i++){
        scanf("%c",&Word[i]);
        if(Word[i]=='\n' || Word[i]=='\t' || Word[i]==' '){
            Word[i] = '\0';
            break;
        }
    }
    for(i=0; i<TXT; i++){
        scanf("%c",&text[i]);
        if(text[i]=='~'){
            text[i] = '\0';
            break;
        }
    }

}

//returns the gim value of a char , returns 0 if not a b c.....
int ret_gim(char this_char){

    if(this_char<=90 && this_char>=65){
            return(this_char-64);  
    }
    else if(this_char>=97 && this_char<=122){
        return(this_char-96);
    }
    else{
        return 0;
    }
}

//calc thr gimatry value of the minumum string of text[i:j] abd printing if equal to gim we got 
int calc_gim(int gim,int i,int j,char text[TXT]){
    while(text[i]==' ' ||text[i]=='\n' ||text[i]=='\t'||ret_gim(text[i])==0){
        i++;
    }
    while(text[j]==' ' ||text[j]=='\n' ||text[j]=='\t'||text[j]=='\0'||ret_gim(text[i])==0){
        j--;
    }
    int sum = 0;
    for(int k=i;k<=j;k++){
        sum+=ret_gim(text[k]);
    }
    if(sum == gim){
        if(first != 0){
            printf("~");
        }
        first = 1;
        for(int k=i;k<=j;k++){
        printf("%c",text[k]);
        }
        return 0;
    }
    return 1;
}

//finds all the substrings that are equal to the word gim
void gim(char Word[WORD], char text[TXT]){
    printf("Gematria Sequences: ");
    int word_gim=0;
    int i = 0;
    while(Word[i] != '\0'){
        int this_char = Word[i];
        if(this_char<=90 && this_char>=65){
            word_gim+=(this_char-64);  
        }
        else if(this_char>=97 && this_char<=122){
            word_gim+=(this_char-96);
        }
        i++;
    }
    for(i = 0; i<TXT ; i++){
        if(ret_gim(text[i]) == 0){
            i++;
        }
        for(int j = i; j<TXT ; j++){
            if(ret_gim(text[i]) == 0){
            break;
            }
            if(calc_gim(word_gim,i,j,text) == 0){
                break;
            }
            
        } 
    }
}

//check if a word in a text is same to one of the 2 word we recived
void check_abtsh_same(int i,int j,char text[TXT],char word1[WORD],char word2[WORD]){
    while(text[i]==' ' ||text[i]=='\n' ||text[i]=='\t'||ret_gim(text[i])==0){
        i++;
    } 
    while(text[j]==' ' ||text[j]=='\n' ||text[j]=='\t'||text[j]=='\0'||ret_gim(text[i])==0){
        j--;
    }
    int size = 0;
    while(word1[size]!='\0'){
        size++;
    }

    char neww[j-i+2];
    int runner =0;
    for(int k=i; k<=j;k++){
        if(text[k]!=' ' && text[k]!='\n' && text[k]!='\t' && text[k]!='\0'){
            neww[runner] = text[k];
            runner++;
        }
    }
    neww[runner] = '\0';
    if(size == runner){
        if(strncmp(neww, word1,size)==0){
            if(first2 != 0){
                printf("~");
            }
            first2 = 1;
            for(int k=i;k<=j;k++){
            printf("%c",text[k]);
            }
        }
        else if(strncmp(neww, word2,size)==0){
            if(first2 != 0){
                printf("~");
            }
            first2 = 1;
            for(int k=i;k<=j;k++){
            printf("%c",text[k]);
            }
        }
    }
}
//the main abtsh func sends 2 indexes of a min string to check_abtsh and also create the abtsh words
void abtsh(char Word[WORD], char text[TXT]){
    char rev_word[WORD];
    char temp[WORD];
    strcpy(rev_word,Word);
    strcpy(temp,Word);
    printf("\nAtbash Sequences: ");
    int k=0;
    while(Word[k]!='\0'){
        if(Word[k]<=90 && Word[k]>=65){
            Word[k] = 91-Word[k]+64;
        }
        else if(Word[k]>=97 && Word[k]<=122){
            Word[k] = 123-Word[k]+96;
            
        }
        else{
            Word[k] = Word[k];
        }
        k++;
    }
    k--;
    int f=0;
   
    while(rev_word[f]!='\0'){
        rev_word[f]=Word[k];
        f++;
        k--;
    }
    for(int i = 0; i<TXT ; i++){
        if(ret_gim(text[i]) == 0){
            i++;
        }
        for(int j = i; j<TXT ; j++){
            if(ret_gim(text[j]) == 0){
            break;
            }
            check_abtsh_same(i,j,text,Word,rev_word);

        } 
    }
    printf("\n");
    strcpy(Word,temp);
}
//check if second word is anagram of the first 
int is_anagrams(char word1[WORD],char word2[WORD]){
    int i = 0;
    int ret = 0;
    while(word1[i]!='\0'){
        int j = 0;
        int check_is_there = 0;
        while(word2[j]!='\0'){
            if(word1[i]==word2[j] && check_is_there == 0){
                word2[j] = ' ';
                check_is_there = 1;
            }
            j++;
        }
        if (check_is_there == 0)
        {
            ret = 1;
        }
        i++;
    }
    int j=0;
    while(word2[j]!='\0' && ret == 0){
        if(word2[j]!='\0' && word2[j]!=' ' && word2[j]!='\n' && word2[j]!='\t'){
            printf("%c , fail",word2[j]);
            return 1;
        }
        j++;
    } 
    return ret;
}
//print the word in text from i to j if is is an anagrams
void check_anagram_same(int i,int j,char text[TXT],char word[WORD]){
    while(text[i]==' ' ||text[i]=='\n' ||text[i]=='\t' ||text[i]=='\0'){
        i++;
    } 
    while(text[j]==' ' ||text[j]=='\n' ||text[j]=='\t'||text[j]=='\0'){
        j--;
    }
    int size = 0;
    while(word[size]!='\0'){
        size++;
    }

    char neww[j-i+2];
    int runner =0;
    for(int k=i; k<=j;k++){
        if(text[k]!=' ' &&text[k]!='\n' &&text[k]!='\t'&&text[k]!='\0'){
            neww[runner] = text[k];
            runner++;
        }
        
    }
    neww[runner] = '\0';
    if(size == runner){
        //check if contains same chars
        if(is_anagrams(word,neww)==0){
            if(first3 != 0){
                printf("~");
            }
            first3 = 1;
            for(int k=i;k<=j;k++){
            printf("%c",text[k]);
            }
        }
    }
}
//chaecks all the words that are anagram to word in text
void anagram(char Word[WORD], char text[TXT]){
    printf("Anagram Sequences: ");
    for(int i = 0; i<TXT ; i++){
        if(text[i]==' ' ||text[i]=='\n' ||text[i]=='\t' ||text[i]=='\0'){
            i++;
        }
        for(int j = i; j<TXT ; j++){
            if(text[j]==' ' ||text[j]=='\n' ||text[j]=='\t' ||text[j]=='\0'){
                j++;
            }
            else{
            check_anagram_same(i,j,text,Word);
            }
        } 
    }
}


int main() {
   // printf() displays the string inside quotation
   char word[WORD] = {' '};
   char text[TXT] = {' '};
   scan(word,text);
   gim(word,text);
   abtsh(word,text);
   anagram(word,text);
   return 0;
}
