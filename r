if [ "$1" == "clean" ]; then
#	sudo rm -rf code ast vec model
	sudo rm -rf ast vec model
fi
if [ ! -d code ]; then
	mkdir -p code
	docker run -v $(pwd)/input:/input:ro -v $(pwd)/code:/code -it yijun/bi-tbcnn:crawler
fi 
if [ ! -d ast ]; then
	mkdir -p ast
	docker run -v $(pwd)/code:/code:ro -v $(pwd)/ast:/ast -it yijun/bi-tbcnn:parser
fi
if [ ! -d vec ]; then
	mkdir -p vec
	docker run -v $(pwd)/input:/input:ro -v $(pwd)/ast:/ast:ro -v $(pwd)/vec:/vec -it yijun/bi-tbcnn:ast2vec
fi
if [ ! -d model ]; then
	mkdir -p model
	docker run -v $(pwd)/input:/input:ro -v $(pwd)/vec:/vec:ro -v $(pwd)/model:/model -it yijun/bi-tbcnn:bi-tbcnn
fi
