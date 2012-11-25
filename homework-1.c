/* this is a simplest c program */

int global = 1;

int main(void)
{
    int local = 2;
}

//error1: homework-1.c:9: error: expected ‘,’ or ‘;’ before ‘return’
//error2: homework-1.c:9: error: ‘global’ undeclared (first use in this function)
//error3: homework-1.c:8: warning: incompatible implicit declaration of built-in function ‘printf’
//error4: homework-1.c:2:17: error: stdio: No such file or directory
//error5: homework-1.c:10: error: expected declaration or statement at end of input
//error6: homework-1.c:1:1: error: unterminated comment
//error7: homework-1.c:7: error: expected ‘;’, ‘,’ or ‘)’ before ‘{’ token
