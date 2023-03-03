GAMEPLAY

The gameplay for the game is simple. You need to collect all the hearts in order to win. 
If the monster touches you while you are collecting the hearts then you die.
If you touch the red buzzer then the speed of the monster will increase. 
Collect all the hearts to win.

Extra Code Systems Developed

NOTE - You can uncomment all the Log:;print to see the log information in the output window.

1.There is a Log system developed in order to easily log information and debug what is going on. You can find the Log.h class.

2.Input controller class is developed to make it easier for the players to understand the control system. 
It has methods like controller.GetKeyPressS() to make it easier for the user. This also enables the user to have more controllers.

3.There is a Delay class implemented in the application class. It is used to introduce delay and timer mechanics in the game.
Currently this mechanic is not required in the game. However, this is functional.

4.Use of Eigen (external library) to Test my matrix. used random matrices and compared with this external library.

5.Created an application class that handles initialization, update and destruction of the complete game engine. 

6.Implemented the temporary vector while using the job system to create gameobjects and then transferred to actual mastermap.

7.Scaling of gameobjects implemented. Users can scale the gameobjects directly from the json file. 

8.Implemented an AI moveto function on the monster which is also used in the game. It is currently in the physics class.