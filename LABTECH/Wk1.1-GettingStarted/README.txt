 
In Unix files can be (pre)viewed, moved, copied, renamed, and
protected with relatively few commands. This is just a simple text file to
demonstrate the some of the more relevant commands for working with files.

This file also contains some notes on the commands for file management and
setting permissions on  files.
Files, Files, and more Files, oh my.
***************************************************************************

All of this information comes from the Unix manual pages. I won't cover
everything about each command or even all of the possible commmands for each
section but you can always look up these and other commands by typing

	man [commandName]
	
into the command line interpreter.

The general structure for running each of these commands is

    command [-Option(s)] [File(s)]

You may occasionally hear me use the term flags interchangeably with options.
For most, if not all commands, the options should be listed together.

For example, the artistic style program provides a way for programmers to
"beautify" their programs, or simply to ensure that their program follows the
style guide that has been laid out for them by their company (or professor).
It provides a very large range of options and formats that can be applied to a program.
The astyle commands and options that you will be required to run is listed
below.

      	    	astyle -cpfHs4 -xC75 --style=otbs  view.c
		   ^      ^	 ^    ^	             ^
		command	Options  more-Options       File

***************************************************************************

Commands for Viewing the contents of a file

cat - conCATenate file contents and print on the standard output device
     
     Useful Options:  v  Verbose
     	    	      e	 mark the end of a line with $
		      t  should tab characters as ^I

more - displays the contents of specified file, allows forward movement
screen by screen.  Generally run without options (though you can run
'man more' to see what they are) Movement Commands:
       Spacebar -  Page down
       b	-  Page up
       d	-  1/2 page down
       u	-  1/2 page up
       Return	-  1 Line down
       q	-  q

       Another program that works similarly to more is the  less program.
       Counterintuitively, less can do more things than more (it was created
       after, and uses both more and vi to help accomplish its tasks). For
       example, it can perform forward and backward incremental search.

 
head - show the beginning of some output or specified file
     Pass in some numeric flag to specify how many lines you wish to see

     	     	  head -20
        Shows the first 20 lines of a file.  With no flags passed to it,
	it will default to 10 lines.

tail - show the end of some output or specified file
     Works just like head except it shows the end of the output.
     Options: f  will cause tail to follow a file's progress

file - identify a file's contents
     Will open and attempt to figure out what a file is (format of file)

wc - word count
   Will count the number of lines, words, and chars in a file

**********************************************
Commands for manipulating the files/directories themselves

touch
	Updates the modification time of the file to 'right now' according to
	the system clock.  Think of it like poking the file.  If the file
	doesn't exist, then it will be created.

mkdir - Creates a directory.
      Useful Options: p	creates a path to the specifed directory. AKA it will
      create all the folders specified in the path.

      mkdir -p Levy/ClassA/Assignment4
      creates the top-level Levy directory and the subdirectory Levy/ClassA to
      hold the Assignment4 directory

rmdir - Removes an empty directory
      The safest way to remove some directory is to use this command.  Why?
      Because using rm -r will remove EVERYTHING in a directory and all of
      its subdirectories. And once something has been removed, its gone
      forever. MUCH safer to go inside the folder to remove files specifically
      first.

cp - copies files or directories

     A command we will be using a lot!  cp will copy source files or
     directories named in the first argument(s) (can be specified with a path)
     to the location specified in the second argument.  Multiple source files
     may be copied at once to a single target directory. For example,

     Useful flags:
     	    -R  recursive.   Recursively copy the specified directory and all
	    of its subdirectories (aka the entire subtree).

	    -i   Inquire.  Ask before copying over (stomping) another file

	    Example:
		cp -R ~levyj63/LABTECH/Wk1.1-Connecting .
	 	^   ^		^   ^			^
	      copy Recurse  This Directory	  to my current directory
		    	 
mv - move files or directories

   mv moves a specified file or directory (first argument) to the specified
   location in the second argument.  Note that this can also RENAME a file or
   directory by simply changing the name of the file in the second argument
   and not specifying a new path/location.

   Useful flags - i  Inquire.  Ask before overwriting a file.

rm - remove files or directories
   **NOTE** remove is FOREVER.

   Useful options
   	  
		-i Inquire.  Ask before removing

   	  	-r/-R Recurse. Removes the entire directory subtree. CAUTION

		-f    Force.   Forces removal WITHOUT ASKING.  EXTREME CAUTION
		

   rm -rf* (Especially from the root folder) is a command you should basically
   NEVER run unless you are ok with risking losing literally EVERYTHING (in
   your account).
   
   Read this and read the top answer to see what could happen
   if you were to try it.
   https://www.quora.com/What-would-happen-if-I-ran-sudo-rm-rf-*-on-the-root-folder-of-my-computer

******Directory Shorthand Notation********

.  means the path to the current directory.The one you are inside of, currently
.. means the directory directly above . in the hierarchy of directories

These can be used in pathnames to specify files, move about the directories,
etc.
	
******************************************************************
Commands for examining your Directory

pwd - Print Working Directory.  The working directory is the one you are
currently within, aka .   

ls - list files and directories.
This is commonly used with a variety of options
     -l		 long form listing (detailed)
     -d		 list the current directory( . )
     -r		 Reverse the order of output
     -t		 sort the files by time
     -a		 show all files, including "hidden" files
     -F		 mark files and directories with special chars
     		     Executables have  * at the end of their name
		     Directories have / at the end of their name
     -s		 include size in blocks

find -  unusual among these programs, because the other programs require that
option flags appear before the names of files that they work on; in "find",
the flags that control behaviour come after the list of directories to be
searched. So you would type "find [directory list] [predicate list]".

"find" will examine every file in the directories named, and will test those
files against the predicate list. If each of the tests is found to be true,
then the file's name is printed.

If no directories are named, "find" will search the current directory. If no
predicates are listed, "find" will print the name of every file.

The most useful predicates include:
		
-atime [+-]number
       True if the file was accessed number days ago. A plus means "more than
       number", and a minus means "less than number".

-mtime [+-]number
       As above, but this tests when the contents of the file were modified.

-ctime [+-]number
       As above, but this tests when the file's inode was changed. For example,
       if you change the permissions on a file, that affects ctime but not
       mtime.
       
-name 'name'
      True if the file is named name. Shell filename matches (such as *, ?,
      and []) can be used. There is another version, -iname, which does
      case-insensitive searches.
      
-user 'loginid '
      True if the file is owned by the user loginid.

-size [+-]'number[c]'
      True if the file is of size number disk blocks. As with the time
      comparisons, a plus means that the file is bigger than number, and a
      minus means that the file is smaller than number. A "c" at the end of
      the number means that you want the number of Characters, not disk blocks.
      
-exec 'command;'
      If other tests are found true, this will execute command. To specify the
      name of the file as part of the command, you have to use "{}". Do not
      omit the semicolon at the end of the command.

Predicates can be grouped with parentheses; an exclamation point ("!") means "not". Two predicates together are combined with logical AND; to get logical OR, use "-o" in between them.

locate - find files by name
       Requires  that you know the name of the file you are looking for.
***************************************************
Setting a file's permissions.

File permissions describe WHO is allowed to do what to a given file.  There are
three basic actions anyone can take with a file.

Read:  	    Look at the contents of the file
Write: 	    Modify the file
Execute:    Run the file as a program.

if you type "ls -l" into the command line you can see the permissions for a
file or directory that exists within your current directory.

like this

-rwxr-x--x 1 levyj63 domain users  557 Jan 12 18:54 make_folders <- a file
drwxrwxr-x 2 levyj63 domain users 4096 Jan 15 11:34 Stats <- a Directory
 ^	 ^  
This space describes the permissions on the file or directory.

Its specified in memory with 9 bits, 3 sets of three.
the first set describes permissions for User (Read Write Execute)
the second set describes permissions for Group (Read Execute)
the third set describes permissions for Others (or World)

Because each permission is a set of 3 bits, we can convert them from binary to
octal (base 8) numbers because 2^3 = 8.

In this case make_folders has a permission of 751
Stats has a permission of 755

We can change a files permission with the chmod (Change Mode) command.
To remove execute permissions for everyone for  make_folders we can run

   chmod 644 make_folders

However this requires setting all bits (User, Group, Other) at once.  This can
be inconvenient sometimes.  You may want to turn off some bits and leave others
alone.  This is possible with chmod but you may have to step back and do the
math. When this is the case, you can use the mnemonic method. If we run the
following command on make_folders (with 755 permissions)

     chmod o-x make_folders 

And then ls -l

    -rwxr-xr-- 1 levyj63 domain users  557 Jan 12 18:54 make_folder

We can see that execute permissions have only been removed for others.  To add execution permission back for others, we can run

 chmod o+x make_folders

to result in

-rwxr-xr-x 1 levyj63 domain users  557 Jan 12 18:54 make_folders


