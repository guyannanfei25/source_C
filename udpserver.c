#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>


struct location_info
{
         char longitude[20];//GPS经度
         char latitude[20];//GPS纬度
         double speed;//列车时速，km/h
};



int main()
{
	struct location_info recv;
	int recvLen,companyfd;
	struct sockaddr_in companyaddr;
	companyfd=socket(AF_INET,SOCK_DGRAM,0);
	bzero(&companyaddr,sizeof(companyaddr));
	companyaddr.sin_family=AF_INET;
	companyaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	companyaddr.sin_port=htons(6688);
	bind(companyfd,(const struct sockaddr *)&companyaddr,sizeof(struct sockaddr_in));
	int i,j;
	while(1)
	{
		if((recvLen=recvfrom(companyfd,&recv,sizeof(recv),0,NULL,NULL))>=0)
		{
		
			printf("\nrecv longitude is %s\n",recv.longitude);
			printf("recv latitude is %s\n",recv.latitude);
			printf("recv speed is %f\n\n",recv.speed);
		}
	}
	
	
}
