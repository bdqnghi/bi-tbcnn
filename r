proxy="--build-arg http_proxy=http://wwwcache.open.ac.uk:80 --build-arg https_proxy=http://wwwcache.open.ac.uk:80"
if [ "$http_proxy" == "" ]; then
 proxy=
fi
docker build $proxy -t bi-tbcnn docker
docker run -v $(pwd):/e -w /e --entrypoint bash --rm -it bi-tbcnn -c ./run
