#include<iostream>
#include<iomanip>
#include <vector>
#include <algorithm>
//Schachbrett
const int N = 8;
int board[N][N];

//Spring
int moveX[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int moveY[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

//check if the grid can be visited
bool isValid(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= N) {
		return false;
	}
	if (board[x][y] != 0) {
		return false;
	}
	return true;
}

//print
void printboard() {
	std::cout << "\n board：\n" << std::endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cout << std::setw(3) << board[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
int countValidMoves(int x, int y) {
	int count = 0;
	for (int i = 0; i < 8; ++i) {
		if (isValid(x + moveX[i], y + moveY[i])) {
			count++;
		}
	}
	return count;
}
//findPath

bool findPath(int x, int y, int moveCount) {
	board[x][y] = moveCount;
	if (moveCount == N * N) {
		return true;
	}

	std::vector<std::pair<int, std::pair<int, int>>> nextMoves;
	for (int i = 0; i < 8; i++) {
		int nextX = x + moveX[i];
		int nextY = y + moveY[i];
		if (isValid(nextX, nextY)) {
			int onwardMoves = countValidMoves(nextX, nextY);
			nextMoves.push_back( {onwardMoves, {nextX, nextY}});
		}
	}

	std::sort(nextMoves.begin(), nextMoves.end());


	for (auto const& move : nextMoves) {
		int nextX = move.second.first;
		int nextY = move.second.second;
		if (findPath(nextX, nextY, moveCount + 1)) {
			return true;
		}
	}

	board[x][y] = 0;
	return false;
}
void initBoard() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[i][j] = 0;
		}
	}
}
int main() {
	initBoard();
	int startX = 2;
	int startY = 2;
	std::cout<< "start from:"<<startX<<startY<<std::endl;
	if (findPath(startX, startY, 1)) {
		std::cout << "it works!" << std::endl;
		printboard();
	} else {
		std::cout << "can not find path" << std::endl;
	}

	return 0;
}
