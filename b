docker login -u yijun
for machine in crawler parser ast2vec bi-tbcnn; do
	docker build -t bi-tbcnn:$machine $machine
	docker tag bi-tbcnn:$machine yijun/bi-tbcnn:$machine
	docker push yijun/bi-tbcnn:$machine
done
