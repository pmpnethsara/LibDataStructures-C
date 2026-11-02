int isEmpty(int size)
{
    return size == 0;
}
int isFull(int size, int maxSize)
{
    return size == maxSize;
}
void enqueue(int queue[], int maxSize, int *size, int value)
{
    if(isFull(*size, maxSize))
    {
        printf("Queue is full. Cannot enqueue %d\n", value);
        return;
    }
    queue[*size] = value;
    (*size)++;
}
int dequeue(int queue[], int *size)
{
    if (!isEmpty(*size))
    {
        int value = queue[0];
          (*size)--;
        for (int i = 0; i < *size; i++)
        {
            queue[i] = queue[i + 1];
        }
        return value;
    }
    return -1; // Error value
}