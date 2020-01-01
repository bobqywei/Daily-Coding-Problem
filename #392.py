def recurse_find_perimeter(row, col, grid, visited):
    if visited[row][col] is True:
        return 0
    visited[row][col] = True

    perimeter_increase = 4
    neighbors = [(row-1, col), (row, col-1), (row, col+1), (row+1, col)]
    for i, j in neighbors:
        if i >= 0 and i < len(grid) and j >= 0 and j < len(grid[0]):
            if grid[i][j] == 1:
                perimeter_increase -= 1
                perimeter_increase += recurse_find_perimeter(i, j, grid, visited)
    return perimeter_increase

def get_island_perimeter(grid):
    visited = []
    for i in range(len(grid)):
        visited.append([False] * len(grid[0]))

    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] == 1:
                return recurse_find_perimeter(i, j, grid, visited)
            else:
                visited[i][j] = True
    raise NotImplementedError


if __name__ == "__main__":
    grid = [[0, 1, 1, 1],
            [1, 1, 0, 1],
            [0, 1, 0, 0],
            [0, 0, 0, 0]]

    print(get_island_perimeter(grid))
