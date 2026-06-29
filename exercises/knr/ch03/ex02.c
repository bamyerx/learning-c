/*
 * Exercise 3-2 from K&R: Write a function escape(s,t) that converts characters
 * like newline and tab into visible escape sequences like \n and \t as it
 * copies the string t to s. Use a switch. Write a function for the other
 * direction as well, converting escape sequences into the real characters.
 */

#define MAXSTR 1000

void escape(char s[], char t[])
{
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++)
        switch (s[i]) {
        case '\a': 
            t[j++] = '\\';
            t[j++] = 'a';
            break;
        case '\b': 
            t[j++] = '\\';
            t[j++] = 'b';
            break;
        case '\f': 
            t[j++] = '\\';
            t[j++] = 'f';
            break;
        case '\n': 
            t[j++] = '\\';
            t[j++] = 'n';
            break;
        case '\r': 
            t[j++] = '\\';
            t[j++] = 'r';
            break;
        case '\t': 
            t[j++] = '\\';
            t[j++] = 't';
            break;
        case '\v': 
            t[j++] = '\\';
            t[j++] = 'v';
            break;
        default:   
            t[j++] = s[i];
            break;
        }
    t[j] = '\0';
}

void unescape(char s[], char t[])
{
    int i, j;
    
    for (i = j = 0; s[i] != '\0'; i++) {
        if (s[i] == '\\') 
            switch (s[i + 1]) {
            case 'a': 
                t[j++] = '\a';
                i++;
                break;
            case 'b': 
                t[j++] = '\b';
                i++;
                break;
            case 'f': 
                t[j++] = '\f';
                i++;
                break;
            case 'n': 
                t[j++] = '\n';
                i++;
                break;
            case 'r': 
                t[j++] = '\r';
                i++;
                break;
            case 't': 
                t[j++] = '\t';
                i++;
                break;
            case 'v': 
                t[j++] = '\v';
                i++;
                break;
            default:  
                t[j++] = s[i];
                break;
            }
        else 
            t[j++] = s[i];
    }
    t[j] = '\0';
}
