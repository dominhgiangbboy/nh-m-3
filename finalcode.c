#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
int main(void)
{
 pid_t child_1, child_2,child_3,child_0;
 int child_status;
 int n;

/*
* Thong tin sinh vien 
*/

	 printf("\nThanh vien nhom: ");
	 printf("\nHo va ten          MSSV       Lop     Khoa ");
	 printf("\nPham Van Doan     20150944   Dt 08    K60: ");
	 printf("\nHoang Ngoc Ha     20151140   Dt 04    K60: ");
	 printf("\nPham Thi Dung     20150589   Dt 04    K60: ");
	 printf("\nDo Minh Giang     20141216   Dt 03    K59: ");	
	 printf("\nDuong Quang Dinh  20150935   Dt 10    K60: ");
	 printf("\n");

	sleep (5);
 // Táº¡o tiáº¿n trÃ¬nh con

	/*
	* Ghi hÃ¬nh
	*/


child_0 = fork();
	 switch ( child_0 ) {
	 case -1: // fork khÃ´ng táº¡o Ä‘Æ°á»£c tiáº¿n trÃ¬nh má»›i
	 printf("\nKhong the tao tien trinh moi");
	 exit( 1 );
	 case 0: // fork thÃ nh cÃ´ng, chÃºng ta Ä‘ang á»Ÿ trong tiáº¿n trÃ¬nh con
	

	//Quay camera

	 system( "ffmpeg -f alsa -i plughw:CARD=Webcam,DEV=0 -f video4linux2 -vcodec mjpeg -s 640x480 -i /dev/video0 -y -t 20 -sameq /tmp/test.mp4" );
	// Plughw:CARD=Webcam,DEV=0 phai duoc thay bang mot phan cung bang cau lenh arecord -L trong linux se hien len list cac phan cung cua webcam

	//Quay mÃ n hÃ¬nh 

	system ("sudo open simplescreenrecorder");  //sleep(2);
	
	//GhÃ©p video
	system ("ffmpeg -f concat -i video.txt -c copy video.mp4");
	 getppid() ;

	 exit( 0 ); // MÃ£ lá»—i tráº£ vá» cá»§a tiáº¿n trÃ¬nh con

	 default: // fork thÃ nh cÃ´ng, chÃºng ta Ä‘ang á»Ÿ trong tiáº¿n trÃ¬nh cha

	wait( &child_status );

	 printf("Ghi xong, tien trinh con 0 hoan thanh.\n");
	 
	 }


	/*
	* NÃ©n video H264
	*/

child_1 = fork();
	 switch ( child_1 ) {
	 case -1: 
	 printf("\nKhong the tao tien trinh moi");
	 exit( 1 );
	 case 0: 

	 system( "ffmpeg -i video.mp4 -vf scale=1280:-1 -c:v libx264 -preset veryslow -crf 24 -strict -2 output.mp4" );
	// sleep( 3 );

	 exit( 0 ); 

	 default: 
 	wait( &child_status );

	/*
	 sleep(10);
	 system ("killall ffmpeg");
	*/
	 printf("Nen xong, tien trinh con 1 hoan thanh.\n");

	 sleep(5);
	 }

	/*
	* Play back
	*/

 child_2 = fork();
	 switch ( child_2 ) {
	 case -1: 
	 printf("\nKhong the tao tien trinh moi");
	 exit( 1 );
	 case 0: 

	 system("ffplay video.mp4"); 
	
	 getppid() ;

	 exit( 0 ); 

	 default: 

	for(n=0;n<10;n++){

	  system( "ps -o %mem,%cpu -p $(pidof ffplay)" );	
	  sleep(3);		
	
	}

	 sleep(2); 
	 printf("\nCac thu vien lien ket dong la: \n");
	 system("ldd BtHDH");

	// sleep(400); 
	// system ("killall ffplay");
	sleep(2); 
	 printf("Tien trinh con 2 hoan thanh.\n");
	 }

	/*
	* Hiá»ƒn thá»‹ dung lÆ°á»£ng, time phÃ¡t
	*/

child_3 = fork();
	 switch ( child_3 ) {
	 case -1: 
	 printf("\nKhong the tao tien trinh moi");
	 exit( 1 );
	 case 0: 
	
	 printf("Dung lÆ°á»£ng video lÃ  :\n");
	 system("du -ah video.mp4");
	 
	 printf("Thoi gian phat video : \n");
	 system ("mediainfo --Inform='Video;%Duration/String3%' video.mp4");
	 printf("Sinh vien tiep theo ghi hinh : \n");
	
	 sleep(2);
	//getppid() ; 

	 exit( 0 ); 

	 default: 
	 wait( &child_status );		
	 sleep(2);

	 printf("Tien trinh con 3 hoan thanh.\n");
	 }

	/*
	* Dong gop cac thanh vien
	*/
	 printf("Thanh vien		Dong gop(%)\n");
	 printf("Pham Van Doan			35% \n");
	 printf("Do Minh Giang			30% \n");
	 printf("Pham Thi Dung 			25% \n");
	 printf("Hoang Ngoc Ha 			5% \n");
	 printf("Duong Quang Dinh		5% \n");
	 exit( 0 ); 

 return ( 0 );
}
