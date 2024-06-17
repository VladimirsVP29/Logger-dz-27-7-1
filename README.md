# Logger dz 27-7-1
Logging of messages.

The Logger class was added to the program, through which all work with the log file is passed.
Messages are saved to the log.txt file. When a logger object is created, the file is opened,
and when it is destroyed, the file is closed (RAII concept).

The class implements methods:
- writing a line of logs to a file and
- reading one line from a file.

Writing and reading are thread-safe - if several threads are called at the same time. 
with writing to a file and reading from a file, there are no interlocks and data races.
