#include <stdio.h>
#include <math.h>

struct point{
	int x;
	int y;
	
};

int main(){
	struct point p1,p2;
	int xDiff, yDiff;
	
	
	printf("Write first point of X , Y : ");
	scanf("%d %d", &p1.x, &p1.y);
	
	printf("Write second point of X , Y : ");
	scanf("%d %d", &p2.x, &p2.y);
	
	if(p1.x > p2.x && p1.y > p2.y){
		xDiff = p1.x - p2.x;
		yDiff = p1.y - p2.y;
	}else{
		xDiff = p2.x - p1.x;
		yDiff = p2.y - p1.y;
	}
	
	double distance = 0;
	distance = sqrt(xDiff * xDiff + yDiff * yDiff);
	printf("distance is : %.2f", distance);
	
	return 0;
}