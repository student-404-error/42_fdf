#include <stdio.h>
#define SIZE 5

void	bfs(int matrix[5][5], int x, int y)
{
	static int cnt;
	if (x < 0 || y < 0 || x >= SIZE || y >= SIZE )
		return ;
	printf("[%d][%d]: %d\n", x, y, matrix[x][y]);
	bfs(matrix, x + 1, y);
	bfs(matrix, x, y + 1);
}

int	main(void)
{
	int	matrix[SIZE][SIZE];
	
	for (int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++)
			matrix[i][j] = i + j;
	for (int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}
	bfs(matrix, 0, 0);
}
