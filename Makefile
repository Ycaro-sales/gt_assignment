TEST_FOLDER = ./tests/Bat1/
TEST_SCRIPT = ./Bat1.sh
test: dijkstra prim floyd_warshall kosaraju kruskal
	(cd $(TEST_FOLDER) && $(TEST_SCRIPT))

dijkstra:
	(cd ./dijkstra && make)

prim:
	(cd ./prim && make)

floyd_warshall:
	(cd ./floyd_warshall && make)

kosaraju:
	(cd ./kosaraju && make)
	
kruskal:
	(cd ./kruskal/ && make)

