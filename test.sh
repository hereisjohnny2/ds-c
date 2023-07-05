mkdir -p bin

gcc stack.c stack_test.c -o bin/stack
gcc queue.c queue_test.c -o bin/queue

bin/stack
bin/queue
