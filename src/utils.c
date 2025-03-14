#include "header.h"

// Helper function: Find median of stack
int find_median(t_stack *a, int range)
{
	int size = range;
	int *copy = malloc(sizeof(int) * (range));
	if (!copy)
		return 0;
	
	// Copy stack elements
    for (int i = 0; i < range; i++)
    {
        copy[i] = a->stack[a->top - i]; // Copy top 'range' elements
    } 

	// Sort copy (simple insertion sort for small arrays)
	for (int i = 1; i < range; i++) {
		int key = copy[i];
		int j = i - 1;
		while (j >= 0 && copy[j] > key) {
			copy[j + 1] = copy[j];
			j--;
		}
		copy[j + 1] = key;
	}

	int median;
	if (size % 2 == 1)
		median = copy[size / 2];
	else
		median = ceil((copy[size / 2 + 1] + copy[size / 2]) / 2);
	free(copy);
	return median;
}

int is_sorted(int *arr, int range, int top)
{
    if (range < 2 || top < 1)  
        return (1);
    for (int i = top; i > top - range + 1; i--)  
    {
        if (arr[i] > arr[i - 1])  
            return (0);
    }
    return (1);
}

int is_sorted_rev(int *arr, int range, int top)
{
    if (range < 2 || top < 1)  
        return (1);
    for (int i = top; i > top - range + 1; i--)  
    {
        if (arr[i] < arr[i - 1])  
            return (0);
    }
    return (1);
}
