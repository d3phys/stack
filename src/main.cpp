#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include "include/stack.h"
#include "include/log.h"


int main() 
{
        stack_t stk = {};
        create_log();
//j        int i = 'u'<< sizeof(4);
//        log("I:   %c", i);
//        log("I:   %d", i);

$       (construct_stack(&stk, 10);)

$       (push_stack(&stk, 'f');) 
        log_dump(&stk);
        stk.capacity = 4;
        log_dump(&stk);
        
        pop_stack(&stk);
        pop_stack(&stk);
        pop_stack(&stk);
        pop_stack(&stk);
        pop_stack(&stk);
        pop_stack(&stk);
        pop_stack(&stk);
        pop_stack(&stk);
        pop_stack(&stk);

        /*void *d = calloc(2, sizeof(float));
        log("d: 0x%lx\n", (size_t)d);
        void *a = calloc(2, sizeof(int));
        log("A: 0x%lx\n", (size_t)a);
        void *b = calloc(3, sizeof(char));
        log("B: 0x%lx\n", (size_t)b);
        void *c = calloc(1, sizeof(char));
        log("C: 0x%lx\n", (size_t)c);
        free(a);
        free(b);
        free(c);
        free(d);
        */
        // heap debug functions

        /*
        push_stack(&stk, 21);
        push_stack(&stk, 21);
        log_dump(&stk);
        pop_stack(&stk);
        pop_stack(&stk);
        pop_stack(&stk);
        pop_stack(&stk);

        log("Sum: %d\n", pop_stack(&stk) +  pop_stack(&stk));
        //push_stack(&stk, 32);
*/
        destruct_stack(&stk);
        
        return 0;
}
