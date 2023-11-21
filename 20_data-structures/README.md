# Data Structures

## Stack (First In Last Out)

1. **PUSH**: Add a item to the **END** of the list
2. **POP**: Removes the item at the **END** of the list

## Queue (First In First Out)

1. **ENQUEUE**: Add a item to the **END** of the list
2. **DEQUEUE**: Removes the item at the **START** of the list

## (CLRS) Building a queue with two stacks

How can we implement a queue with two stacks?

A queue should supports 2 operations, ENQUEUE and DEQUEUE.

ENQUEUE works the same way as stack's PUSH, it inserts an item at the end of the array

DEQUEUE works differently from stack's POP, since it removes the first item of the array, while stack's POP removes the last.

To be able to remove the first item from a stack, we need to remove all the items from the stack. Since we have 2 stacks, we can move all but the first item to the second stack (stack B), and then move them again to the first stack (stack A).

This would make the time cost of ENQUEUE O(1), and the time cost of DEQUEUE O(2N)

However, there is a possible optimization for DEQUEUE where we don't imediatelly move all the items again from stack B to stack A, and take advantage of the fact that stack B is in inverse order to execute DEQUEUE in O(1).

We would then, move items from B to A whenever a ENQUEUE command is called.

This would make both ENQUEUE and DEQUEUE work at worst on O(N), and at best on O(1) when calling the same command more than once.

Here is an example ilustrating the states of stacks A and B through a series of command calls

```
    ENQUEUE(1) - A: 1      B:
    ENQUEUE(2) - A: 1 2    B:
    ENQUEUE(3) - A: 1 2 3  B:
    DEQUEUE()  - A:        B: 3 2
    ENQUEUE(4) - A: 2 3 4  B:
    DEQUEUE()  - A:        B: 4 3
    DEQUEUE()  - A:        B: 4
```

## (CLRS) Building a stack with two queues

This would work similarly to "queue with two stacks", with the difference lying in the "REMOVE" operation

PUSH would add items to queue A, while POP would require us to move all but the last item to queue B

The difference here is that we don't need to move the items again to PUSH. Since the queue preserves the order, we can just start using QUEUE B as the target for new PUSH operations.

This would make the time cost of PUSH O(1), and the time cost of POP O(N).

Here is an example ilustrating the states of queues A and B through a series of command calls

```
    PUSH(1) - A: 1      B:
    PUSH(2) - A: 1 2    B:
    PUSH(3) - A: 1 2 3  B:
    POP()   - A:        B: 1 2
    PUSH(4) - A:        B: 1 2 4
    POP()   - A: 1 2    B:
    POP()   - A:        B: 1
```
