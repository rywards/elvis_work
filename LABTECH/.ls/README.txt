 This lesson will not be held for all sections.
Make sure you read the associated reading assignment if you are unsure
of how to use editors in Unix.

There will be no direct questions on the mid-term regarding this lesson but you
will be expected to use editors and execute programs throughout the entirety
of this course and it will be critical to success in the class.

Environment variables in Unix are variables that are assigned automatically
in your shell when you log in.  While there will be no questions concerning
them, understanding what they are and what they describe will be helpful to
all students.  Please read over this notes file to get an understanding of
what is discussed.

Topics covered:
Editors (Vi and Emacs)

Editing in Vi and Emacs

Environment Variables in Bash

How to execute programs in Bash:

1) Make sure the program has been given the correct execute permissions
(discussed in depth next class)
	   a) if you wrote in a program in a compiled language, the output from
	   compilation should be executable already
	   b)if you wrote a script, or copied a pre-written file,  you may
	   have to set execute permissions on the file using the chmod utility
	   (discussed in depth next class)

	   c) Once the program has
./programName  (Runs executable programName in the current directory)

/home/levyj63/LABTECH/Wk5.1-Functions+Pointers/hello  (runs program hello at the specified path location)


Variables in Bash are set on the command line by typing:
variableName=value


Environment variables are special vairables in Unix that are set up when you
log into an instance of the shell (Bash, csh, sh, etc).  Different shells
have different sets of Environment variables.  As you might suspect,
environment variables describe a particular environment.  Different users
may have different values for these.


What separates Environment variables from regular variables is the export
command.  Exporting a variable tells Bash to keep track of it.

export variableName=value

Once exported, Bash will track this variable's value (even in sub-shells)
until you log out of your current session.

If you need them to be permanent (last across sessions) you need to include
the export command in either your .bashrc or .bash_profile files.

Environment variables can be unset, or changed.  They help descirbe your
environment's current configuration.   
You can view the value of any variable in Unix by echoing them (note the $)

echo $HOME

This will print (on my account) /home/levyj63/
On your account, it will print *your* home folder.

You can view all environment variables by typing the printenv command at
the command line.

Examples:

HOME -  describes a user's "home". In my case it is /home/levyj63/

PATH - describes what directories Bash should look at when you type a command
(NOTE: This one of the big differences between an installed program in Unix
and one that has been compiled and is executable.  An installed program has
had its path added to the PATH variable.  You should never, for now, delete
from the PATH variable.)

LANG - describes the language setting for this environment

HISTFILE - describes the path to the history file

HISTSIZE -  the number of lines in the $HISTFILE

