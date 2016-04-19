# Checkroids

<h1>Checkeroids Report</h1>
<i>Team #35: Sebastian Perez (Leader), Carlos Avogadro, Yazan Mansour, Jose Diaz, Leena Flood, Lauren Arfaras </i>

- <b>What we accomplished</b>:

We successfully created a board and piece class, that held all of the necessary functions and properties for both the board and piece objects. Then we created a main file that merged all of the functions together to make a successful checkeroids game. In our program an eight by eight board will be displayed on the terminal, with specified coordinates input you will be allowed to choose the legal position you would like your checker piece to be. 

- <b> What problems we ran into</b>:

<i>Segmentation Fault</i>

One major problem we continually encountered was segmentation faults, due to a null pointer trying to be accessed. To fix this error we went through each one of our pointers and made sure that we were not trying to access information from a null pointer.

<i>File and Time Management</i>

Another issue we came across was that we needed people to finish with their portion of the project before others could start. For example, the ‘board.cpp’ and the ‘piece.cpp’ file could not be created until the ‘board.h’ and ‘piece.h’ files were created because the structure of the board and piece object were necessary to be able to create the corresponding functions. Therefore, the limited number of files in the project left members without work to do for a certain amount of time, so time management was an important factor in the development of the project.

- <b>What we would have liked to do</b>:

We would to have implemented a graphical interface. We were unsuccessful in including the sfml library in attempts of using the GUI. Also we would have liked to implement color in the terminal as we knew we would not be using the GUI, yet that only works for command shells that support ANSI escape codes , such as most of them in Linux and UNIX. Since most of our group members did not use Linux and UNIX we were unable to implement colors.

- <b>What we learned</b>: 

We learned to collaborate as a team to develop a well structured multi-object program.This will benefit later in our career as software engineers, as the waterfall method is used in most businesses.  
We learned how to use Github code a project together. Many of us were not familiar with Github, so one of our first group meetings was covering the basics of using Github and creating a repository for our project. 
Our debugging skills significantly improved due to this project. We became more proficient at detecting and testing for flaws within our code. 

We learned to implement a group chat on Slack messenger, which connected to Github, to keep the group updated on the progress of the code. Each time a group member updated the code, it would notify the group.
We learned how to keep the user knowledgeable on how the code is progressing as they ran the program.
We also learned the importance of documentation as we were able to work off our partners code. With proper documentation and assuming the reader doesn't know much we are able to fully grasp where our partners left off.
We were also able to incorporate code from PA3 as we read a file to display the instructions 

