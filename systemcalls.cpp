#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
//#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

//#define path1 "C:\Users\Shumbul\Desktop\Programming\Serm 4 os\"
//#define path2 "C:\Users\Shumbul\Desktop\Programming\Serm 4 os\test2.txt"

//creat,write,open,lseek,read,dup,,access,link,chmod,,chown,unlink,close
//excel,fork,wait,exit,getuid,getgid,getegid,getpid,getppid,signal,kill,alarm,chdir
int main()
{
	char string[100]="Content for the file";
	
	//creat() system call
	int filedescriptor1 = creat("test1.txt",S_IRWXU);
	if(filedescriptor1<0)
		perror("Error");
	else
		printf("File created: %d\n",filedescriptor1 );

	// open() system call
	int filedescriptor = open("test1.txt",O_CREAT | O_RDWR,S_IRWXU);
	if(filedescriptor<0)
		perror("Error");
	else
		printf("File created: %d\n",filedescriptor );

	// write() system call
	int size_wrote = write(filedescriptor,string,strlen(string));
	if(size_wrote<0)
		perror("error");
	else
		printf("Content :%s \nwritten to file with size %d\n",string,size_wrote );

	// lseek() system call
	lseek(filedescriptor,0,SEEK_SET);
	char buf[100];

	// read() system call
	int size_read = read(filedescriptor, buf, 100);

	buf[size_read]='\0';
	if(size_read<0)
		perror("error");
	else
		printf("String read: %d\n%s\n",size_read,buf);

	// dup() system call
	 int duplicated = dup(filedescriptor);

	 if(duplicated<0)
	 	perror("error");
	 else
	 	printf("Old Descriptor=%d\nNew Descriptor=%d\n",filedescriptor,duplicated);

	 // access() F_OK system call
	 int existing = access("test1.txt",F_OK);
	 if(existing<0)
	 	perror("error");
	 else
	 	printf("File exists\n");
		
		 // access() R_OK system call
	 int read_permit = access("test1.txt",R_OK);
	 if(read_permit<0)
	 	perror("error");
	 else
	 	printf("read permission\n");	 
	 // access() W_OK system call
	 int write_permit = access("test1.txt",W_OK);
	 if(write_permit<0)
	 	perror("error");
	 else
	 	printf("write permission\n");
	 // access() X_OK system call
	 int execute_permit = access("test1.txt",X_OK);
	 if(execute_permit<0)
	 	perror("error");
	 else
	 	printf("execute permission\n");

	/* 
	// link() system call
	 int linked = link("test1.txt","test2.txt");
	 if(linked!=0)
	 	perror("error");
	 else
	 	printf("Link created successfully\n");

	 	*/
	// chmod() system call 
	int chmod_permit = chmod("test1.txt",S_IRWXU); //removed S_IRWXG
	if(chmod_permit<0)
		perror("error");
	else
		printf("RWX permission to group given\n");

	 	/*
	// chown() system call
	int chown_permit = chown("test1.txt",1002,1002);
	if(chown_permit<0)
		perror("error");
	else
		printf("student is the new owner\n");

	 	*/

	 // unlink() system call
	 int unlinked = unlink("test2.txt");
	 if(unlinked!=0)
	 	perror("error");
	 else
	 	printf("UnLink done successfully\n");

	// close() system call
	int closed = close(filedescriptor);
	if(closed<0)	
		perror("error");
	else
		printf("File closed successfully\n");
    
    return 0;
	
}
