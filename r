docker build -t bi-tbcnn docker
docker run -v $(pwd):/e -w /e --entrypoint bash -it bi-tbcnn -c ./run
