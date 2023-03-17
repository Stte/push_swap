# push_swap

https://user-images.githubusercontent.com/17783118/225594577-dd74b659-a922-4aad-b04a-663706727691.mov

- Sort data from lowest to highest
- Use only allowed operations
- Two stacks
- Do the least amount of moves

At the beginning:
- The stack a contains a random amount of negative and/or positive numbers
which cannot be duplicated.
- The stack b is empty.

---

The goal is to sort in ascending order numbers into stack a.
To do so you have the following operations at your disposal:


- Push the first element between the stacks
	- **pa (push a)**: Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
	- **pb (push b)**: Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.

- Swap the first 2 elements at the top of stacks
	- **sa (swap a):** Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
	- **sb (swap b):** Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
	- **ss** : sa and sb at the same time.

- Rotate stacks
	- **ra (rotate a)**: Shift up all elements of stack a by 1. The first element becomes the last one.
	- **rb (rotate b)**: Shift up all elements of stack b by 1. The first element becomes the last one.
	- **rr** : ra and rb at the same time.

- Reverse rotate stacks
	- **rra (reverse rotate a)**: Shift down all elements of stack a by 1. The last element becomes the first one.
	- **rrb (reverse rotate b)**: Shift down all elements of stack b by 1. The last element becomes the first one.
	- **rrr** : rra and rrb at the same time.

---

Allowed external functions:
read, write, malloc, free, exit
