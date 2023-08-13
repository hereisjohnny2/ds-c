mkdir -p bin

gcc stack.c stack_test.c -o bin/stack
gcc queue.c queue_test.c -o bin/queue
gcc linked_list.c linked_list_test.c -o bin/linked_list

bin/stack
bin/queue
bin/linked_list
