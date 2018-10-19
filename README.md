# Producer Consumer Prog

A simple multi-threaded program using pThread library, with 4 threads doing the following:
1. read input from stdin,
2. replacing white spaces with asterisk,
3. converting all lower cases to upper, and
4. writing to stdout.

Queue is used for communication between these modules.

## Task List

This project is divided in the following major modules.

* **queue**: This data structure holds a buffer for storing strings. Any instance of the queue can be accessed only in exclusion. pThread library is used to implement monitors for mutual exclusion in this structure. The interface exposes 3 methods.
    * CreateStringQueue: Creates a queue with the buffer size as passed in parameter.
    * EnqueueString: Add string to queue if space is available. If no space available, WAIT.
    * DequeueString: Remove a string from queue if queue is not empty. If queue is empty, WAIT.
    * PrintQueueStats: Print counts of total queued, de-queued, blocked, etc. variable.

NOTE: Re-iterating that fact that, queue instance can be accessed only by one thread at a time, if that thread acquires the monitor lock on that queue.

* **reader**: Read characters from stdin.
    * passes the input line by line to the processor queue (munch1).
    * if the read input exceeds reader buffer size, prints it to stderr and continue.

* **munch1, munch2**: Both of these are string manipulation modules.
    * munch1 reads from the queue connecting it to the reader.
    * munch1 replaces all whitespaces with *
    * Post replacement, munch1 enqueues replaced (updated) string to the queue connecting it with munch2.
    * munch1 reads from the queue connecting it to munch1.
    * munch2 converts all lower case characters to upper case.
    * Post replacement, munch2 enqueues replaced (updated) string to the queue connecting it with the writer.
    
* **writer**: Writes the final output to stdout.
    * writer reads from the queue connecting it to munch2.

* **main.c** is the driver module for the entire project.

## Authors

* **Arpit Jain**
* **Anshu Verma**
