package main

type yx struct{
	y int
	x int
}

func BFS(start yx, goal yx, nodes map[yx]string) int{
	next := []yx{start}
	visited := make(map[yx]bool)
	route := make(map[yx]int)
	route[start] = 0
	visited[start] = true
	for len(next) > 0 {
		node := next[0]
		next = next[1:]
		if node.x == goal.x && node.y == goal.y {
			return route[node]
		}
		up := yx{node.y -1, node.x }
		down := yx{node.y + 1 , node.x}
		left := yx{node.y , node.x-1}
		right := yx{node.y , node.x+1}
		if !visited[up] && nodes[up] == "." {
			next = append(next, up)
			route[up] = route[node] +  1
			visited[up] = true
		}
		if !visited[down] && nodes[down] == "." {
			next = append(next, down)
			route[down] = route[node]+  1
			visited[down] = true
		}
		if !visited[right] && nodes[right] == "." {
			next = append(next, right)
			route[right] = route[node] + 1
			visited[right] = true
		}
		if !visited[left] && nodes[left] == "." {
			next = append(next, left)
			route[left] = route[node] +1
			visited[left] = true
		}

	}
	return route[goal]

}
