docker build -t bi-tbcnn docker
docker run -v $(pwd):/e -w /e --entrypoint bash --rm -it bi-tbcnn -c ./run
