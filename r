if [ "$1" == "clean" ]; then
#	sudo rm -rf code ast vec model
	sudo rm -rf ast vec model
fi
if [ ! -d code ]; then
	mkdir -p code
	docker run -v $(pwd):/e -w /e --entrypoint bash -it yijun/bi-tbcnn -c crawler/run
fi 
if [ ! -d ast ]; then
	mkdir -p ast
	docker run -v $(pwd):/e -w /e --entrypoint bash -it yijun/bi-tbcnn -c parser/run
fi
if [ ! -d vec ]; then
	mkdir -p vec
	docker run -v $(pwd):/e -w /e --entrypoint bash -it yijun/bi-tbcnn -c ast2vec/run
fi
if [ ! -d model ]; then
	mkdir -p model
	docker run -v $(pwd):/e -w /e --entrypoint bash -it yijun/bi-tbcnn -c bi-tbcnn/run
fi
