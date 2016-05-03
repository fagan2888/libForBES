wget http://faculty.cse.tamu.edu/davis/SuiteSparse/SuiteSparse-4.4.6.tar.gz -O ./libs/SuiteSparse.tar.gz
tar xvf ./libs/SuiteSparse.tar.gz -C ./libs
rm -rf ./libs/SuiteSparse.tar.gz
cd ./libs/SuiteSparse
make
cd ../../