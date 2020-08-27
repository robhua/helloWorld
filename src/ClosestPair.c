#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	int x;
	int y;
}Point;

float bruceFore(Point P[], int n) {
	//TODO
	return 0;
}

float stripClosest(Point P[], int n, float d) {
	//TODO
	return 0;
}

float min (float x, float y) {
	return (x < y) ? x : y;
}

float closestPair(Point P[], int n) {
	if (n < 3) {
		return bruceFore(P, n);
	}

	int mid = n/2;
	Point midPoint = P[mid];
	float dl = closestPair(P, mid);
	float dr = closestPair(P + mid, n - mid);
	float d = min(dl, dr);

	Point strip[n];
	int j;
	//TODO Find strip

	return min (d, stripClosest(strip, j, d));
}

float closest(Point P[], int n) {
	//TODO Sort by X;

	return closestPair(P, n);
}
