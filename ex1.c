#include <stdio.h>
// FUNCTION isPentagonal(x, n = 1)
//     IF x < 1 THEN
//         RETURN false
//     END IF
    
//     pentagonal = (3 * n * n - n) / 2
    
//     IF pentagonal equals x THEN
//         RETURN true
//     END IF
    
//     IF pentagonal > x THEN
//         RETURN false
//     END IF
    
//     RETURN isPentagonal(x, n + 1)
// END FUNCTION

// FUNCTION checkPentagonalArray(array)
//     FOR EACH number IN array
//         IF isPentagonal(number) THEN
//             PRINT number + " is a pentagonal number"
//         ELSE
//             PRINT number + " is not a pentagonal number"
//         END IF
//     END FOR
// END FUNCTION

// MAIN PROGRAM
//     array = [1, 5, 12, 22, 35, 8, 20]
//     checkPentagonalArray(array)
// END PROGRAM