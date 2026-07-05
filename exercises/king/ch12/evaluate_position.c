/*
 * Exercise 18. Write the evaluate_position function described in Exerise 13 of
 * Chapter 9. Use pointer arithmetic--not subscripting--to visit array elements.
 * Use a single loop instead of nested loops.
 */

int evaluate_position(char board[8][8])
{
    int wsum = 0, bsum = 0;
    char *p;

    for (p = *board; p < *board + 8 * 8; p++) {
        switch (*p) {
            case 'Q': 
                wsum += 9; break;
            case 'q': 
                bsum += 9; break;
            case 'R': 
                wsum += 5; break;
            case 'r': 
                bsum += 5; break;
            case 'B': 
                wsum += 3; break;
            case 'b': 
                bsum += 3; break;
            case 'N': 
                wsum += 3; break;
            case 'n': 
                bsum += 3; break;
            case 'P': 
                wsum += 1; break;
            case 'p': 
                bsum += 1; break;
            default:
                break;
        }
    }

    return wsum - bsum;
}
