using System.Collections;
using System.Collections.Generic;
using System.Transactions;

public class LinkedList<T>
{
    public Node<T> head;
    
    public LinkedList()
    {
        head = null;
    }
    public void Queue(T data)
    {
        if(head == null)
        {
            head = new Node<T>(data);
        }
        else
        {
            Node<T> current = head;
            while(current.next != null)
            {
                current = current.next;
            }
            current.next = new Node<T>(data);
        }
    }

    public T Pop()
    {
        if (head == null)
        {
            return default(T);
        } else
        {
            Node<T> current = head;
            if (current.next == null)
            {
                head = null;
                return current.nodeData;
            }
            else
            {
                head = current.next;
                return current.nodeData;
            }

        }
    }

    public Node<T> Peek()
    {
        if (head == null)
        {
            return null;
        } else
        {
            return head;
        }
    }
   
}

public class Node<T>
{
    public Node<T> next;
    public T nodeData;

    public Node(T data)
    {
        nodeData = data;
    }
}
