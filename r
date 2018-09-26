docker build -t bi-tbcnn docker
docker run -v $(pwd):/e -w /e --entrypoint bash -it yijun/bi-tbcnn -c run
