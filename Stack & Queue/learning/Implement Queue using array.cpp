void MyQueue :: push(int x)
{
        // Your Code
        rear++;
        arr[rear] = x;
        
}

//Function to pop an element from queue and return that element.
int MyQueue :: pop()
{
        // Your Code
        if(front != rear){//not at same index
            front++;
            
            int x = arr[front];
            return x;
        }
        else{
            return -1;
        }
}
